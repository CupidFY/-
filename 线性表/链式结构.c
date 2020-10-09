#include <stdio.h>
#include <stdlib.h>
typedef struct LNode{
	int data;
	struct LNode *next;
}LNode,*LinkList;              //LNode *p-----LinkList p

void InitList_L(LNode *L);
void CreateList_L(LNode *L,int n);
char GetElem_L(LinkList L,int i,int *p);
void ListInsert_L(LNode *L,int i,int e);
void ListDelete_L(LNode *L,int i,int *e);
void MergeList_L(LNode *La,LNode *Lb,LNode *Lc);
void PrintList_L(LinkList L);

int main()
{
	LNode *L;
	/*LNode *P;
	LNode *Q;
	L = (LNode *)malloc(sizeof(LNode));
	L->data = 1;
	L->next = NULL;
	P = (LNode *)malloc(sizeof(LNode));
	P->next = L;
	P->data = 6;
	Q = (LNode *)malloc(sizeof(LNode));
	Q->next = P;
	PrintList_L(Q);*/
	CreateList_L(L,2);
	PrintList_L(L);
	//p = L->next;
	//printf("%d",p->data);
	return 0;
}

//------------��������������L--------
void InitList_L(LNode *L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(0);
	L->next=NULL;
}
//--------��λ������n��Ԫ�ص�ֵ,��������ͷ���ĵ������Ա�L-------------                 
void CreateList_L(LNode *L,int n)        //ͷ�巨
{
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	for(i=n;i>0;--i)
	{
		p=(LinkList)malloc(sizeof(LNode));
		scanf("%d",&(p->data));
		p->next = L->next;
		L->next = p;
	}
}
//-----------����i��Ԫ�ش���ʱ,��ֵ����e������O,���򷵻�E------
char GetElem_L(LinkList L,int i,int *e)
{
	LinkList p;
	int j;
	p = L->next;
	j=1;
	while(p && j<i)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i)
		return 'E';
	*e = p->data;
	return 'O';
}
//------------�ڴ�ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
void ListInsert_L(LNode *L,int i,int e)
{
	LinkList p,s;
	int j;
	p = L;
	j = 0;
	while(p && j<i-1)      //Ѱ�ҵ�i-1�����
	{
		p = p->next;
		++j;
	}
	if(!p ||j>i-1)
		exit (0);
	s = (LinkList)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
}
//--------�ڴ�ͷ���ĵ������Ա�L��,ɾ����i��Ԫ��,����e������ֵ
void ListDelete_L(LNode *L,int i,int *e)
{
	LinkList p,q;
	int j;
	p = L;
	j = 0;
	while(p->next && j<i-1)     //Ѱ�ҵ�i�����,����pָ����ǰ��
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i-1)  //ɾ��λ�ò�����
		exit (0);
	q = p->next;
	p->next = q->next;
	*e =q->data;
	free(q);
}
//-------------�鲢La��Lb�õ��µĵ�����Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
void MergeList_L(LNode *La,LNode *Lb,LNode *Lc)
{
	LinkList pa,pb,pc;
	pa = La->next;
	pb = Lb->next;
	Lc = pc = La;
	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
		pc->next = pa ? pa:pb;
		free(Lb);
	}
}
//-----------������Ե�����L��Ԫ��----------
void PrintList_L(LinkList L)
{
	LinkList p;
	p = L->next;
	while(p->next != NULL){
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("%d\n",p->data);
}