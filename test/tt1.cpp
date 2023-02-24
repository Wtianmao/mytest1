#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct li_s
{
	li_s *next;
	int data;
};


int main()
{
	li_s *ph = NULL;
	li_s *pn = NULL;
	li_s *pc = NULL;
	int i = 0;
	while (-1 != scanf("%d", i))
	{
		pn = new li_s;
		li_s->data = i;
		if (ph == NULL)
		{
			ph = pn;
			pc = pn;
		}
		else
		{
			pc->next = pn;
			pc = pc->next;
		}
	}

	pc = ph;
	while (pc != NULL)
	{
		cout << pc->data << endl;
		pc = pc->next;
	}

	pc = ph;
	li_s *ptn = pc->next->next;
	while (pc != NULL)
	{
		pt = ph;
		ph = pc->next;
		pc = pc->next->next;
		ph->next = pt;
	}

	pc = ph;
	while (pc != NULL)
	{
		cout << pc->data << endl;
		pc = pc->next;
	}
	return 0;
}

