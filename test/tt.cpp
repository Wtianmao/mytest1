#include <iostream>
#include <unistd.h>
#include <stdio.h>
using namespace std;

typedef struct _li_s
{
	_li_s *next;
	int data;
}li_s;


int main()
{
	li_s *ph = NULL;
	li_s *pn = NULL;
	li_s *pc = NULL;
	int i = 0;
	while (0 != scanf("%d", &i))
	{
		if (i > 10)
		{
			break;
		}
		pn = new li_s;
		pn->data = i;
		if (ph == NULL)
		{
			ph = pn;
			pc = pn;
		}
		else
		{
			pc->next = pn;
			pc = pc->next;
			pc->next = NULL;
		}
	}

	pc = ph;
	while (pc != NULL)
	{
		cout << pc->data << endl;
		pc = pc->next;
	}

	pc = ph->next;
	while (pc != NULL)
	{
		pn = ph;
		ph = pc;
		if (ph == pn->next)
		{
			pn->next = NULL;
		}
		pc = pc->next;
		ph->next = pn;
	}

	pc = ph;
	while (pc != NULL)
	{
		cout << pc->data << endl;
		pc = pc->next;
	}
	return 0;
}

