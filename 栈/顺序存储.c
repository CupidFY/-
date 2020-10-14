#include <stdio.h>
#include <stdlib.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//-------------定义结构体---------
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

//-----------------------------------
void InitStack(SqStack *S);//-------------构造一个空栈S----------------
void DestroyStack(SqStack *S);//-----------销毁栈S,S不再存在-------------
void ClearStack(SqStack *S);//--------------把S置为空栈----------
char StackEmpty(SqStack S);//-----------若栈S为空栈,则返回T,否则返回F-----
int StackLength(SqStack S);//-----------返回S的元素的个数,即栈的长度--------
char GetTop(SqStack S,int *e);//----------若栈不空,则用e返回S的栈顶元素,并返回O;否则返回E
void Push(SqStack *S,int e);//---------插入元素e为新的栈顶元素--------
char Pop(SqStack *S,int *e);//----若栈不空,则删除S的栈顶元素,用e返回其值,并返回O,或者返回E----
void ScanfStack(SqStack *S);//---------通过键盘输入创建一个栈S,输入负数时结束录入-----------
void PrintStack(SqStack S);//--------------输出栈S的元素-----------
void SetStack(SqStack *S,int n);//------------对栈S进行赋值-----------
//----------------------------------
int main()
{
	SqStack a;
	int e;
	InitStack(&a);
	SetStack(&a,5);
	printf("栈a是否为空栈\t%c\n",StackEmpty(a));
	PrintStack(a);
	printf("栈a的长度是%d\n",StackLength(a));
	Push(&a,10);
	PrintStack(a);
	printf("栈a的长度是%d\n",StackLength(a));
	Pop(&a,&e);
	PrintStack(a);
	printf("栈a的长度是%d\n",StackLength(a));
	return 0;
}


//-------------构造一个空栈S----------------
void InitStack(SqStack *S)
{
	S->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if(!S->base)
		exit (0);
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}
//-----------销毁栈S,S不再存在-------------
void DestroyStack(SqStack *S)
{
	free(S);
}
//--------------把S置为空栈----------
void ClearStack(SqStack *S)
{
	S->base = S->top;
}
//-----------若栈S为空栈,则返回T,否则返回F-----
char StackEmpty(SqStack S)
{
	if(S.base==S.top)
		return 'T';
	return 'F';
}
//-----------返回S的元素的个数,即栈的长度--------
int StackLength(SqStack S)
{
	int length;
	length = S.top -S.base;
	return length;
}
//----------若栈不空,则用e返回S的栈顶元素,并返回O;否则返回E
char GetTop(SqStack S,int *e)
{
	if(S.base != S.top)
	{
		*e = *(S.top-1);
		return 'O';
	}
	return 'E';
}
//---------插入元素e为新的栈顶元素--------
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
//----若栈不空,则删除S的栈顶元素,用e返回其值,并返回O,或者返回E----
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
//---------通过键盘输入创建一个栈S,输入负数时结束录入-----------
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
//--------------输出栈S的元素-----------
void PrintStack(SqStack S)
{
	if(S.base==S.top)
		printf("该栈是空栈\n");
	else
	{
		while(S.top != S.base)
		{
			printf("%d\t",*--S.top);
		}
		printf("\n");
	}
}
//------------对栈S进行赋值-----------
void SetStack(SqStack *S,int n)
{
	int i;
	printf("请输入%d个元素\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",S->top++);
	}
}