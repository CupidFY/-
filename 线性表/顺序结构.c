#include <stdio.h>
#include <stdlib.h>
#define LIST_INIT_SIZE 100       //线性表存储空间的初始分配量
#define LISTINCREMENT   10         //线性表存储空间的分配增量
//--------线性表的动态分配顺序存储结构----------
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
	InitList(&A); //结构体名只是变量名，不是首地址
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

//-----------构造一个空的线性表L-----------
void InitList(SqList *L)
{
	L->elem = (int *)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!L->elem)
		exit (0);
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
}
//--------对空的线性表L进行赋值--------
void SetList(SqList *L,int leng)
{
	int i;
	for(i=0;i<leng;i++)
	{
		scanf("%d",&L->elem[i]);
	}
	L->length = leng;
}
//-----------输出线性表L的元素--------
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\n",L.elem[i]);
	}
}
//----------销毁线性表L------------------
void DestroyList(SqList *L)
{
	free(L);
}
//-------------将L重置为空表---------------
void ClearList(SqList *L)
{
	L->length = 0;
}
//--------------若L为空表，则返回TRUE,否则返回FALSE----------------
char ListEmpty(SqList *L)
{
	if(L->elem != 0)
		return 'T';
	else
		return 'F';
}
//---------返回L中数据元素个数-------------
int ListLength(SqList *L)
{
	return L->length;
}
//------------用e返回L中第i个数据元素的值------------------
int GetElem(SqList *L,int i,int *p)
{
	*p=L->elem[i-1];
	return *p;
}
/*----------返回L中第1个与e满足关系compare()的数据元素的位序。若这样的数据元素不存在，则返回值为0
int LocateElem(SqList *L,int e,compare())
{
}   */
//-------------若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
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
//-------------若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
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
//------------------在L中第i个位置之前插入新的数据元素,L的长度加1-------------------
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
	//q = &L->elem[i-1];         可以
	//q = L->elem[i-1];        不可以
	q = L->elem+i-1;
	for(p = L->elem + L->length-1;p>=q;p--)
	{
		*(p+1) = *p;
	}
	*q = e;
	++L->length;
}
//------------删除L的第i个元素,并用e返回其值,L的长度减1
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
//--------归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列
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