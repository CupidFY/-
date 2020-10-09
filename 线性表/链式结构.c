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

//------------建立空线性链表L--------
void InitList_L(LNode *L)
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
		exit(0);
	L->next=NULL;
}
//--------逆位序输入n个元素的值,建立带表头结点的单链线性表L-------------                 
void CreateList_L(LNode *L,int n)        //头插法
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
//-----------当第i个元素存在时,其值赋给e并返回O,否则返回E------
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
//------------在带头结点的单链线性表L中第i个位置之前插入元素e
void ListInsert_L(LNode *L,int i,int e)
{
	LinkList p,s;
	int j;
	p = L;
	j = 0;
	while(p && j<i-1)      //寻找第i-1个结点
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
//--------在带头结点的单链线性表L中,删除第i个元素,并由e返回其值
void ListDelete_L(LNode *L,int i,int *e)
{
	LinkList p,q;
	int j;
	p = L;
	j = 0;
	while(p->next && j<i-1)     //寻找第i个结点,并令p指向其前驱
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i-1)  //删除位置不合理
		exit (0);
	q = p->next;
	p->next = q->next;
	*e =q->data;
	free(q);
}
//-------------归并La和Lb得到新的单链表Lc,Lc的元素也按值非递减排列
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
//-----------输出线性单链表L的元素----------
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