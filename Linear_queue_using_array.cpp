#include<stdio.h>
#include<conio.h>
#define queuesize 3

struct Queue
{
	int front, rear;
	int item[queuesize];
}; 
typedef struct Queue queue;
queue q;

bool isempty()
{
	return(q.front == q.rear);
}

void insert(int data)
{
	int i;
	if(q.rear == queuesize -1)
	{
		if(q.front == -1)
		{
		printf("\n............Queue is Overflow............\n");
		return;
		}
		else
         {
           for (i=q.front+1; i<=q.rear; i++)
		   {
		   q.item[i-q.front-1] = q.item[i];
	       }
            q.rear = q.rear - q.front - 1;
            q.front = -1;
         }
    }
	q.rear += 1;
	q.item[q.rear] = data;
}

int remove()
{
	int data;
	if(isempty())
	{
		printf("\n............Queue is Underflow............\n");
		return -1;
	}
	q.front += 1;
	data = q.item[q.front];
	return(data);
}
void display()
{
	if (isempty())
	{
	printf("\n..........LIST is UNDERFLOW..........\n");
	return;
	}
	printf("\nThe queue contain:\n");
	int i = q.front;
	while(i++ != q.rear)
	{
		printf("%d\t",q.item[i]); 
	}
}
int main()
{
	q.front = q.rear = -1;
	char c, ch;
	int num;
	do
	{
	printf("\nPress 'a' for adding an element in the queue:\n");
	printf("Press 'r' for remove an element in the queue:\n");
	ch = getche();
	switch(ch)
	{
	case 'a': printf("\nEnter the element you want to enter in the queue:\n");
			  scanf("%d",&num);
			  insert(num);
			  display();
			  break;
	case 'r': printf("\nThe removing element from the queue is %d.",remove());
	          display();
			  break;
	default: printf("\nYou enter the invalid choice.\n");		            
	}
	printf("\nDo you want to edit the queue:\n");
	printf("Press 'y' for Yes and 'n' for No:\n");
	c = getche();
	}while(c != 'n' || c== 'y');
	return 0;
}
