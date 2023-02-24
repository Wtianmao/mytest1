#include <iostream>
#include <openssl/bio.h>
#include <openssl/sha.h>
#include <openssl/hmac.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/buffer.h>
#include <string.h>
#include <memory>

using namespace std;

int Base64Encode(const unsigned char* in, int len, char* out_base64)
{
	if (!in || len <= 0 || !out_base64)//做校验，检验参数是否合法
		return 0;
	//内存源source  ， 从内存中读数据
	auto mem_bio = BIO_new(BIO_s_mem());//生成了一个内存的Bio，通过内存源来获取数据，结果要写在内存之中，做一下判断
	if (!mem_bio)return 0;

	//base64 filter 过滤器 ,从过滤器内写数据
	auto b64_bio = BIO_new(BIO_f_base64());
	if (!b64_bio)
	{
		BIO_free(mem_bio);
		return 0;
	}

	//形成BIO链表
	//b64-mem
	BIO_push(b64_bio, mem_bio);

	//写入到base64 filter 进行编码，结果会传递到链表的下一个节点
	//到mem中读取结果（从链表头部代表了整个链表,即从链表头部获取数据）
	int re = BIO_write(b64_bio, in, len);
	if (re <= 0)
	{
		//情况整个链表节点
		BIO_free_all(b64_bio);
		return 0;
	}

	//刷新缓存，写入链表的mem
	BIO_flush(b64_bio);

    BIO_set_flags(b64_bio, BIO_FLAGS_BASE64_NO_NL);//超过64字节不添加换行，编码的数据在一行中
     //默认结尾有换行符\n，超过64字节会再添加换行符
     
	int outsize = 0;
	//从链表源内存读取
	BUF_MEM* p_data = 0;
	BIO_get_mem_ptr(b64_bio, &p_data);
	if (p_data)
	{
		memcpy(out_base64, p_data->data,p_data->length);
		outsize = p_data->length;
	}
	BIO_free_all(b64_bio);
	return outsize;
}

int main()
{
	BIO *bio, *b64;

	char message[] = "Hello World \n";
	std::unique_ptr<char[]> cert_buf(new char[64]());

	Base64Encode((const unsigned char*)message, sizeof(message), cert_buf.get());

	printf("%s\n", cert_buf.get());

	return 1;
}

