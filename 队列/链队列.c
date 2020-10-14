#include <stdio.h>
#include <stdlib.h>
//------------�ṹ�嶨��---------
typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr;
//--------------
typedef struct {
	QueuePtr front;       //��ͷָ��
	QueuePtr rear;        //��βָ��
}LinkQueue;

void InitQueue(LinkQueue *Q);         //����һ���ն���Q
void DestroyQueue(LinkQueue *Q);      //���ٶ���Q,Q���ٴ���
void ClearQueue(LinkQueue *Q);         //��Q��Ϊ�ն���
char QueueEmpty(LinkQueue Q);     //������QΪ�ն���,�򷵻�T,���򷵻�F
int QueueLength(LinkQueue Q);     //����Q��Ԫ�ظ���,�����г���
char GetHead(LinkQueue Q,int *e);   //�����в���,����e����Q�Ķ�ͷԪ��,������O,���򷵻�E
void EnQueue(LinkQueue *Q,int e);   //����Ԫ��eΪQ���µĶ�βԪ��
char DeQueue(LinkQueue *Q,int *e);   //�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������O,���򷵻�E

int main()
{

}

//---------����һ���ն���Q--------
void InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front)
		exit(0);
	Q->front->next = NULL;
}
//---------���ٶ���Q,Q���ٴ���---------
void DestroyQueue(LinkQueue *Q)
{
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}
//-----------��Q��Ϊ�ն���--------
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
//--------------������QΪ�ն���,�򷵻�T,���򷵻�F-------
char QueueEmpty(LinkQueue Q)
{
	if(Q.front == Q.rear)
		return 'T';
	return 'F';
}
//----------����Q��Ԫ�ظ���,�����г���-------
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
//---------�����в���,����e����Q�Ķ�ͷԪ��,������O,���򷵻�E
char GetHead(LinkQueue Q,int *e)
{
	if(QueueEmpty(Q) == 'F')
	{
		*e = Q.front->data;
		return 'O';
	}
	return 'E';
}
//--------����Ԫ��eΪQ���µĶ�βԪ��---
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
//-----------�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������O,���򷵻�E
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