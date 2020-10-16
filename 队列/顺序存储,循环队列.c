#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct {
	int *base;
	int front;      //Ϊ�±�,ͷָ��,�����в�Ϊ��,ָ�����ͷԪ��
	int rear;       //Ϊ�±�,βָ��,�����в���,ָ�����βԪ�ص���һ��λ��
}SqQueue;
//--------------------------------------------------------------------------------------------------
void InitQueue(SqQueue *Q);         //����һ���ն���Q
void DestroyQueue(SqQueue *Q);      //���ٶ���Q,Q���ٴ���
void ClearQueue(SqQueue *Q);         //��Q��Ϊ�ն���
char QueueEmpty(SqQueue Q);     //������QΪ�ն���,�򷵻�T,���򷵻�F
int QueueLength(SqQueue Q);     //����Q��Ԫ�ظ���,�����г���
char GetHead(SqQueue Q,int *e);   //�����в���,����e����Q�Ķ�ͷԪ��,������O,���򷵻�E
void EnQueue(SqQueue *Q,int e);   //����Ԫ��eΪQ���µĶ�βԪ��
char DeQueue(SqQueue *Q,int *e);   //�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������O,���򷵻�E
void ScanfQueue(SqQueue *Q,int n);    //�Զ���Q������Ӳ���,����n��Ԫ��

int main()
{

}

//---------------����һ���ն���Q----------------
void InitQueue(SqQueue *Q)
{
	Q->base = (int *)malloc(MAXSIZE * sizeof(int));
	if(Q->base == NULL)
		exit (0);
	Q->front = Q->rear = 0;
}
//------------���ٶ���Q,Q���ٴ���-------------
void DestroyQueue(SqQueue *Q)
{
	free(Q->base);
}    
//-------------��Q��Ϊ�ն���---------  
void ClearQueue(SqQueue *Q)     
{
	Q->front = Q->rear = 0;
}    
//----------������QΪ�ն���,�򷵻�T,���򷵻�F
char QueueEmpty(SqQueue Q) 
{
	if(Q.front == Q.rear)
		return 'T';
	return 'F';
}    
//---------����Q��Ԫ�ظ���,�����г���
int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}   
//--------�����в���,����e����Q�Ķ�ͷԪ��,������O,���򷵻�E  
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
//---------����Ԫ��eΪQ���µĶ�βԪ��--------
void EnQueue(SqQueue *Q,int e)  
{
	if((Q->rear+1)%MAXSIZE == Q->front)
		exit (0);
	Q->base[Q->rear] = e;
	Q->rear = (Q->rear + 1)%MAXSIZE;
}
//------�����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������O,���򷵻�E
char DeQueue(SqQueue *Q,int *e)  
{
	if((Q->rear+1)%MAXSIZE == Q->front)
		return 'E';
	*e = Q->base[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
}
//-----------�Զ���Q������Ӳ���,����n��Ԫ��
void ScanfQueue(SqQueue *Q,int n)    
{
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&(Q->base[Q->rear]));
		Q->rear++;
	}
}