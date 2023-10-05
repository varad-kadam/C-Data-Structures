#include<stdio.h>
int front=-1;
int rear=-1;
int cfront=0;
int crear=0;

int empty()
{
	if(rear==front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int full(int n)
{
	if(rear==(n-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void display(int q[])
{
	int f=front+1;
	if(empty()==1)
	{
		printf("\nQueue is empty\n");
	}
	else
	{
		while(f<=rear)
		{
			printf("%d \n",q[f]);
			f++;
		}
	}
}

void cdisplay(int q[],int n)
{
	int f=(front+1)%n;
	if(front==rear)
	{
		printf("\nQueue is empty\n");
	}
	else
	{
		while(f!=(rear))
		{
			printf("%d \n",q[f]);
			f=(f+1)%n;
		}
		printf("%d \n",q[f]);
	}
}

void cadd(int q[],int data,int n)
{
	if((rear+1)%n==front)
	{
		printf("\nQueue is full\n");
	}
	else
	{
		rear=(rear+1)%n;
		q[rear]=data;
	}
}

void add(int q[],int data,int n)
{
	if(full(n)==1)
	{
		printf("\nQueue is full\n");
	}
	else
	{
		rear=(rear+1);
		q[rear]=data;
	}
}

int delete(int q[])
{
	if(empty())
	{
		return -1;
	}
	else
	{
		front=front+1;
		int elem=q[front];
		return elem;
	}
}

int cdelete(int q[],int n)
{
	if(front==rear)
	{
		printf("\nQueue is empty\n");
		return 0;
	}
	else
	{
		front=(front+1)%n;
		int elem=q[front];
		return elem;
	}
}

int main()
{
	int q[20],a,c=1,ch,w,data,n;
	printf("\nEnter max no. of elements\n");
	scanf("%d",&n);
	do
	{
		printf("\n1.Linear queue\n2.Circular Queue\n");
		scanf("%d",&a);
		switch(a)
		{
			case 1://linear queue
			{
				printf("\n1.Add\n2.Display\n3.Delete\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1:
					{
						do
						{
							printf("\nEnter Data- ");
							scanf("%d",&data);
							add(q,data,n);
							printf("\n1.Repeat\n2.No\n");
							scanf("%d",&c);
						}
						while(c==1);
						break;
					}
					case 2:
					{
						display(q);
						break;
					}
					case 3:
					{
						delete(q);
						display(q);
						break;
					}
					default:
					{
						printf("\nWrong choice\n");
						break;
					}
				}
				printf("\nRepeat choices\n1.Yes\n2.No\n");
				scanf("%d",&w);
				break;
			}
			case 2://circular queue
			{
				printf("\n1.Add\n 2.display\n 3.Delete\n");
				scanf("%d",&ch);
				switch(ch)
				{
					case 1:
					{
						do
						{
							printf("\nEnter Data- ");
							scanf("%d",&data);
							cadd(q,data,n);
							printf("\n1.Repeat\n2.No\n");
							scanf("%d",&c);
						}
						while(c==1);
						break;
					}
					case 2:
					{
						cdisplay(q,n);
						break;
					}
					case 3:
					{
						cdelete(q,n);
						cdisplay(q,n);
						break;
					}
					default:
					{
						printf("\nWrong choice\n");
						break;
					}
				}
				printf("\nRepeat choices \n1.Yes\n2.No\n");
				scanf("%d",&w);
				break;
			}
		}
	}
	while(w==1);
	return 0;
}