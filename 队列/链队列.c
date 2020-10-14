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

void InitQueue(LinkQueue *Q);
void DestroyQueue(LinkQueue *Q);
void ClearQueue(LinkQueue *Q);
char QueueEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
char GetHead(LinkQueue Q,int *e);
void EnQueue(LinkQueue *Q,int e);
char DeQueue(LinkQueue *Q,int *e);

int main()
{

}

//---------