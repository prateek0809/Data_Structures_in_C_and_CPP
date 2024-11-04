#include<stdio.h>
#include<stdlib.h>
int tower(int r, char beg, char aux, char end);

int tower(int r, char beg, char aux, char end)
{
	if(r==1)
	{
		printf("%c->%c, ",beg,end);
	}
	else
	{
		tower(r-1, beg, end, aux);
		tower(1, beg, aux, end);
		tower(r-1, aux, beg, end);
	}
	return 0;
}

int main()
{
	int ring;
	printf("Enter the number of rings:\n");
	scanf("%d",&ring);
	printf("\nThe method to transfer the %d rings from A to C is:\n",ring);
	tower(ring,'A','B','C');
	return 0;
}
