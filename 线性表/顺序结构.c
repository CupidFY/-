#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100       //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10         //���Ա�洢�ռ�ķ�������
//--------���Ա�Ķ�̬����˳��洢�ṹ----------
typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList;

void InitList(SqList *L);
void SetList(SqList *L,int length);
void PrintList(SqList L);
void DestroyList(SqList *L);
void ClearList(SqList *L);
char ListEmpty(SqList *L);
int ListLength(SqList *L);
int GetElem(SqList *L,int i,int *p);
//      int LocateElem(L,e,compare());
void PriorElem(SqList *L,int cur_e,int *pre_e);
void NextElem(SqList *L,int cur_e,int *next_e); 
void ListInsert(SqList *L,int i,int e);
void ListDelete(SqList *L,int i,int *e);
//void ListTraverse(L,visit());
void MergeList(SqList La,SqList Lb,SqList *p);


int main(){
	int i;
	int a;
	SqList A,B,C;
	InitList(&A); //�ṹ����ֻ�Ǳ������������׵�ַ
	InitList(&B);
	A.elem[0] = 5;
	A.elem[1] = 7;
	A.length=2;
	SetList(&B,3);
	//B.elem[0]=0;
	//B.elem[1]=7;
	//B.length=2;
	MergeList(A,B,&C);
	/*for(i=0;i<C.length;i++){
		printf("%d\n",C.elem[i]);
	}*/
	PrintList(C);
	/*ListInsert(&A,2,6);
	for(i=0;i<3;i++){
		printf("%d\n",A.elem[i]);
	}
	printf("\n");
	ListDelete(&A,3,&a);
	printf("%d\n",a);
	for(i=0;i<A.length;i++){
		printf("%d\n",A.elem[i]);
	}*/

	return 0;
}

//-----------����һ���յ����Ա�L-----------
void InitList(SqList *L)
{
	L->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L->elem)
		exit (0);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}
//--------�Կյ����Ա�L���и�ֵ--------
void SetList(SqList *L,int leng)
{
	int i;
	for(i=0;i<leng;i++)
	{
		scanf("%d",&L->elem[i]);
	}
	L->length = leng;
}
//-----------������Ա�L��Ԫ��--------
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\n",L.elem[i]);
	}
}
//----------�������Ա�L------------------
void DestroyList(SqList *L)
{
	free(L);
}
//-------------��L����Ϊ�ձ�---------------
void ClearList(SqList *L)
{
	L->length = 0;
}
//--------------��LΪ�ձ��򷵻�TRUE,���򷵻�FALSE----------------
char ListEmpty(SqList *L)
{
	if(L->elem != 0)
		return 'T';
	else
		return 'F';
}
//---------����L������Ԫ�ظ���-------------
int ListLength(SqList *L)
{
	return L->length;
}
//------------��e����L�е�i������Ԫ�ص�ֵ------------------
int GetElem(SqList *L,int i,int *p)
{
	*p=L->elem[i-1];
	return *p;
}
/*----------����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0
int LocateElem(SqList *L,int e,compare())
{
}   */
//-------------��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
void PriorElem(SqList *L,int cur_e,int *pre_e)
{
	int i;
	for(i=0;i<L->length;i++)
	{
		if(cur_e==L->elem[i] && i != 0)
		{
		*pre_e=L->elem[i-1];
		break;
		}
	}

}
//-------------��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
void NextElem(SqList *L,int cur_e,int *next_e)
{
	int i;
	for(i=0;i<(L->length)-1;i++)
	{
		if(cur_e==L->elem[i])
		{
		*next_e=L->elem[i+1];
		break;
		}
	}
}
//------------------��L�е�i��λ��֮ǰ�����µ�����Ԫ��,L�ĳ��ȼ�1-------------------
void ListInsert(SqList *L,int i,int e)
{
	int *newbase,*q,*p;
	if(i<1 || i>L->length)
		exit (0);
	if(L->length >= L->listsize)
	{
		newbase = (int *)realloc(L->elem,(L->listsize + LISTINCREMENT) * sizeof(int));
		if(!newbase)
		{
			exit (0);
		}
		L->elem = newbase;
		L->listsize = L->listsize + LISTINCREMENT;
	}
	//q = &L->elem[i-1];         ����
	//q = L->elem[i-1];        ������
	q = L->elem+i-1;
	for(p = L->elem + L->length-1;p>=q;p--)
	{
		*(p+1) = *p;
	}
	*q = e;
	++L->length;
}
//------------ɾ��L�ĵ�i��Ԫ��,����e������ֵ,L�ĳ��ȼ�1
void ListDelete(SqList *L,int i,int *e)
{
	int *p,*q;
	if(i<1 || i>L->length)
		exit (0);
	p = L->elem+i-1;
	*e = *p;
	q = L->elem + L->length-1;
	for(++p;p<=q;++p)
	{
		*(p-1) = *p;
	}
	--L->length;
}
//
/*void ListTraverse(SqList L,visit())
{
}*/
//--------�鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
void MergeList(SqList La,SqList Lb,SqList *Lc)
{
	int *pa,*pb,*pc;
	int *pa_last,pb_last;
	pa = La.elem;
	pb = Lb.elem;
	Lc->listsize = Lc->length = La.length+Lb.length;
	pc = Lc->elem = (int *)malloc(Lc->listsize*sizeof(int));
	if(!Lc->elem)
		exit (0);
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while(pa<=pa_last && pb<=pb_last)
	{
		if(*pa <= *pb)
			*pc++ = *pa++;
		else
			*pc++ = *pb++;
	}
	while(pa<=pa_last)
		*pc++ = *pa++;
	while(pb<=pb_last)
		*pc++ = *pb++;
}