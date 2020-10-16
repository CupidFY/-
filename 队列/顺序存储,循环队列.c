#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
	int *base;
	int front;      //为下标,头指针,若队列不为空,指向队列头元素
	int rear;       //为下标,尾指针,若队列不空,指向队列尾元素的下一个位置
}SqQueue;
//--------------------------------------------------------------------------------------------------
void InitQueue(SqQueue *Q);         //构造一个空队列Q
void DestroyQueue(SqQueue *Q);      //销毁队列Q,Q不再存在
void ClearQueue(SqQueue *Q);         //将Q清为空队列
char QueueEmpty(SqQueue Q);     //若队列Q为空队列,则返回T,否则返回F
int QueueLength(SqQueue Q);     //返回Q的元素个数,即队列长度
char GetHead(SqQueue Q,int *e);   //若队列不空,则用e返回Q的对头元素,并返回O,否则返回E
void EnQueue(SqQueue *Q,int e);   //插入元素e为Q的新的队尾元素
char DeQueue(SqQueue *Q,int *e);   //若队列不空,则删除Q的队头元素,用e返回其值,并返回O,否则返回E
void ScanfQueue(SqQueue *Q,int n);    //对队列Q进行入队操作,输入n个元素

int main()
{

}

//---------------构造一个空队列Q----------------
void InitQueue(SqQueue *Q)
{
	Q->base = (int *)malloc(MAXSIZE * sizeof(int));
	if(Q->base == NULL)
		exit (0);
	Q->front = Q->rear = 0;
}
//------------销毁队列Q,Q不再存在-------------
void DestroyQueue(SqQueue *Q)
{
	free(Q->base);
}    
//-------------将Q清为空队列---------  
void ClearQueue(SqQueue *Q)     
{
	Q->front = Q->rear = 0;
}    
//----------若队列Q为空队列,则返回T,否则返回F
char QueueEmpty(SqQueue Q) 
{
	if(Q.front == Q.rear)
		return 'T';
	return 'F';
}    
//---------返回Q的元素个数,即队列长度
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}   
//--------若队列不空,则用e返回Q的对头元素,并返回O,否则返回E  
char GetHead(SqQueue Q,int *e)
{
	if(Q.front != Q.rear)
	{
		*e = Q.base[Q.front];
		Q.front++;
		return 'O';
	}
	return 'E';
}   
//---------插入元素e为Q的新的队尾元素--------
void EnQueue(SqQueue *Q,int e)  
{
	if((Q->rear+1)%MAXSIZE == Q->front)
		exit (0);
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1)%MAXSIZE;
}
//------若队列不空,则删除Q的队头元素,用e返回其值,并返回O,否则返回E
char DeQueue(SqQueue *Q,int *e)  
{
	if((Q->rear+1)%MAXSIZE == Q->front)
		return 'E';
	*e = Q->base[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
}
//-----------对队列Q进行入队操作,输入n个元素
void ScanfQueue(SqQueue *Q,int n)    
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&(Q->base[Q->rear]));
		Q->rear++;
	}
}