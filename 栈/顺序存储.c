#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//-------------����ṹ��---------
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

//-----------------------------------
void InitStack(SqStack *S);
void DestroyStack(SqStack *S);
void ClearStack(SqStack *S);
char StackEmpty(SqStack S);
int StackLength(SqStack S);
char GetTop(SqStack S,int *e);
void Push(SqStack *S,int e);
char Pop(SqStack *S,int *e);
void ScanfStack(SqStack *S);
void PrintStack(SqStack S);
//----------------------------------
int main()
{

}


//-------------����һ����ջS----------------
void InitStack(SqStack *S)
{
	S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if(!S->base)
		exit (0);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}
//-----------����ջS,S���ٴ���-------------
void DestroyStack(SqStack *S)
{
	free(S);
}
//--------------��S��Ϊ��ջ----------
void ClearStack(SqStack *S)
{
	S->base = S->top;
}
//-----------��ջSΪ��ջ,�򷵻�T,���򷵻�F-----
char StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 'T';
	return 'F';
}
//-----------����S��Ԫ�صĸ���,��ջ�ĳ���--------
int StackLength(SqStack S)
{
	int length;
	length = S.top -S.base;
	return length;
}
//----------��ջ����,����e����S��ջ��Ԫ��,������O;���򷵻�E
char GetTop(SqStack S,int *e)
{
	if(S.base != S.top)
	{
		*e = *(S.top-1);
		return 'O';
	}
	return 'E';
}
//---------����Ԫ��eΪ�µ�ջ��Ԫ��--------
void Push(SqStack *S,int e)
{
	if((S->top - S->base) >= S->stacksize)
	{
		S->base = (int *)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(int));
		if(!S->base)
			exit (0);
		S->top = S->base + S->stacksize;
		S->stacksize = S->stacksize + STACKINCREMENT;
	}
	*(S->top++) = e;
}
//----��ջ����,��ɾ��S��ջ��Ԫ��,��e������ֵ,������O,���߷���E----
char Pop(SqStack *S,int *e)
{
	if(S->base != S->top)
	{
		*e = *(--S->top);
		return 'O';
	}
	else
		return 'E';
}
//---------ͨ���������봴��һ��ջS,���븺��ʱ����¼��-----------
void ScanfStack(SqStack *S)
{
	int x;
	while(1){
		scanf("%d",&x);
		if(x<0)
			break;
		*S->top = x;
		S->top++;
	}
}
//--------------���ջS��Ԫ��-----------
void PrintStack(SqStack S)
{
	if(S.base==S.top)
		printf("��ջ�ǿ�ջ\n");
	else
	{
		while(S.top != S.base)
		{
			printf("%d\t",*--S.top);
		}
	}
}