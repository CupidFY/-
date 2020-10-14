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

void InitList(SqList *L);   //����һ���յ����Ա�L
void SetList(SqList *L,int length);  //�Կյ����Ա�L���и�ֵ
void PrintList(SqList L);  //������Ա�L��Ԫ��
void DestroyList(SqList *L);  //�������Ա�L
void ClearList(SqList *L);   //��L����Ϊ�ձ�
char ListEmpty(SqList *L);   //��LΪ�ձ��򷵻�T,���򷵻�F
int ListLength(SqList *L);   //����L������Ԫ�ظ���
int GetElem(SqList *L,int i,int *p);  //��e����L�е�i������Ԫ�ص�ֵ
//      int LocateElem(L,e,compare());
void PriorElem(SqList *L,int cur_e,int *pre_e);  //��cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
void NextElem(SqList *L,int cur_e,int *next_e);    //��cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
void ListInsert(SqList *L,int i,int e);      //��L�е�i��λ��֮ǰ�����µ�����Ԫ��,L�ĳ��ȼ�1
void ListDelete(SqList *L,int i,int *e);       //ɾ��L�ĵ�i��Ԫ��,����e������ֵ,L�ĳ��ȼ�1
//void ListTraverse(L,visit());
void MergeList(SqList La,SqList Lb,SqList *p);  //�鲢La��Lb�õ��µ�˳�����Ա�Lc,Lc��Ԫ��Ҳ��ֵ�ǵݼ�����

int main(){
	SqList A,B,C;
	int x,y,pre,next;
	int a,b;
	char c = 'F';
	InitList(&A);
	InitList(&B);
	InitList(&C);
	printf("���������Ա�A��Ԫ��\n");
	SetList(&A,3);
	printf("���������Ա�B��Ԫ��\n");
	SetList(&B,4);
	printf("�������\n");
	printf("��������A�в����λ�ü�����\n");
	scanf("%d %d",&x,&y);
	ListInsert(&A,x,y);
	printf("A�е�Ԫ��\t");
	PrintList(A);
	printf("B�е�Ԫ��\t");
	PrintList(B);
	PriorElem(&A,2,&pre);
	printf("A��2��ǰһ��Ԫ����%d\n",pre);
	NextElem(&B,5,&next);
	printf("B��5����һ��Ԫ����%d\n",next);
	printf("������B��Ҫɾ����Ԫ�ص�λ��\n");
	scanf("%d",&a);
	ListDelete(&B,a,&b);
	printf("B�е�Ԫ��\t");
	PrintList(B);
	MergeList(A,B,&C);
	printf("�ϲ���C�е�Ԫ��\t");
	PrintList(C);
	ClearList(&B);
	printf("B�Ƿ���Ϊ�ձ�\t%c\n",ListEmpty(&B));
	printf("���ٱ�A,B,C\n");
	DestroyList(&B);
	DestroyList(&A);
	DestroyList(&C);
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
		scanf("%d",&L->elem[L->length]);
		L->length++;
	}
}
//-----------������Ա�L��Ԫ��--------
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}
//----------�������Ա�L------------------
void DestroyList(SqList *L)
{
	free(L->elem);
}
//-------------��L����Ϊ�ձ�---------------
void ClearList(SqList *L)
{
	L->length = 0;
}
//--------------��LΪ�ձ��򷵻�T,���򷵻�F----------------
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
	for(i=0;i<(L->length);i++)
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