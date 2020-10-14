#include <stdio.h>
#include <stdlib.h>
//------------结构体定义---------
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
//--------------
typedef struct {
	QueuePtr front;       //队头指针
	QueuePtr rear;        //队尾指针
}LinkQueue;

void InitQueue(LinkQueue *Q);         //构造一个空队列Q
void DestroyQueue(LinkQueue *Q);      //销毁队列Q,Q不再存在
void ClearQueue(LinkQueue *Q);         //将Q清为空队列
char QueueEmpty(LinkQueue Q);     //若队列Q为空队列,则返回T,否则返回F
int QueueLength(LinkQueue Q);     //返回Q的元素个数,即队列长度
char GetHead(LinkQueue Q,int *e);   //若队列不空,则用e返回Q的对头元素,并返回O,否则返回E
void EnQueue(LinkQueue *Q,int e);   //插入元素e为Q的新的队尾元素
char DeQueue(LinkQueue *Q,int *e);   //若队列不空,则删除Q的队头元素,用e返回其值,并返回O,否则返回E

int main()
{

}

//---------构造一个空队列Q--------
void InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(0);
	Q->front->next = NULL;
}
//---------销毁队列Q,Q不再存在---------
void DestroyQueue(LinkQueue *Q)
{
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
//-----------将Q清为空队列--------
void ClearQueue(LinkQueue *Q)
{
	int *q;
	q = Q->front;
	Q->front = Q->front->next;
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	Q->front = Q->rear = q;
}
//--------------若队列Q为空队列,则返回T,否则返回F-------
char QueueEmpty(LinkQueue Q)
{
	if(Q.front == Q.rear)
		return 'T';
	return 'F';
}
//----------返回Q的元素个数,即队列长度-------
int QueueLength(LinkQueue Q)
{
	int i=0;
	LinkQueue P;
	P.front = Q.front;
	P.rear = Q.rear;
	P.front = P.front->next;
	if(P.front != P.rear)
	{
		i++;
		P.front = P.front->next;
	}
	i++;
	return i;
}
//---------若队列不空,则用e返回Q的对头元素,并返回O,否则返回E
char GetHead(LinkQueue Q,int *e)
{
	if(QueueEmpty(Q) == 'F')
	{
		*e = Q.front->data;
		return 'O';
	}
	return 'E';
}
//--------插入元素e为Q的新的队尾元素---
void EnQueue(LinkQueue *Q,int e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p)
		exit (0);
	p->data = e;
	Q->rear->next = p;
	p->next = NULL;
	Q->rear = p;
}
//-----------若队列不空,则删除Q的队头元素,用e返回其值,并返回O,否则返回E
char DeQueue(LinkQueue *Q,int *e)
{
	if(Q->front != Q->rear)
	{
		QueuePtr q;
		q = Q->front->next;
		*e = q->data;
		Q->front->next = q->next;
		free(q);
		return 'O';
	}
	return 'E';
}