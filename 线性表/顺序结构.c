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

void InitList(SqList *L);   //构造一个空的线性表L
void SetList(SqList *L,int length);  //对空的线性表L进行赋值
void PrintList(SqList L);  //输出线性表L的元素
void DestroyList(SqList *L);  //销毁线性表L
void ClearList(SqList *L);   //将L重置为空表
char ListEmpty(SqList *L);   //若L为空表，则返回T,否则返回F
int ListLength(SqList *L);   //返回L中数据元素个数
int GetElem(SqList *L,int i,int *p);  //用e返回L中第i个数据元素的值
//      int LocateElem(L,e,compare());
void PriorElem(SqList *L,int cur_e,int *pre_e);  //若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
void NextElem(SqList *L,int cur_e,int *next_e);    //若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，否则操作失败，next_e无定义
void ListInsert(SqList *L,int i,int e);      //在L中第i个位置之前插入新的数据元素,L的长度加1
void ListDelete(SqList *L,int i,int *e);       //删除L的第i个元素,并用e返回其值,L的长度减1
//void ListTraverse(L,visit());
void MergeList(SqList La,SqList Lb,SqList *p);  //归并La和Lb得到新的顺序线性表Lc,Lc的元素也按值非递减排列

int main(){
	SqList A,B,C;
	int x,y,pre,next;
	int a,b;
	char c = 'F';
	InitList(&A);
	InitList(&B);
	InitList(&C);
	printf("请输入线性表A的元素\n");
	SetList(&A,3);
	printf("请输入线性表B的元素\n");
	SetList(&B,4);
	printf("输入结束\n");
	printf("请输入在A中插入的位置及数据\n");
	scanf("%d %d",&x,&y);
	ListInsert(&A,x,y);
	printf("A中的元素\t");
	PrintList(A);
	printf("B中的元素\t");
	PrintList(B);
	PriorElem(&A,2,&pre);
	printf("A中2的前一个元素是%d\n",pre);
	NextElem(&B,5,&next);
	printf("B中5的下一个元素是%d\n",next);
	printf("请输入B中要删除的元素的位置\n");
	scanf("%d",&a);
	ListDelete(&B,a,&b);
	printf("B中的元素\t");
	PrintList(B);
	MergeList(A,B,&C);
	printf("合并后C中的元素\t");
	PrintList(C);
	ClearList(&B);
	printf("B是否被置为空表\t%c\n",ListEmpty(&B));
	printf("销毁表A,B,C\n");
	DestroyList(&B);
	DestroyList(&A);
	DestroyList(&C);
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
		scanf("%d",&L->elem[L->length]);
		L->length++;
	}
}
//-----------输出线性表L的元素--------
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}
//----------销毁线性表L------------------
void DestroyList(SqList *L)
{
	free(L->elem);
}
//-------------将L重置为空表---------------
void ClearList(SqList *L)
{
	L->length = 0;
}
//--------------若L为空表，则返回T,否则返回F----------------
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
	for(i=0;i<(L->length);i++)
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
	int *newbase;
	int p;
	if(i<1 || i>L->length +1)
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
	p = L->length;
	for(;p<i-1;p--)
	{
		L->elem[p] = L->elem[p-1];
	} 
	L->elem[p] = e;
	L->length++;
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