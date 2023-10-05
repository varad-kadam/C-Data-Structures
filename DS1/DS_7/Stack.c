#include <stdio.h>
int top=-1;
int temp;

int full(int n)
{
	if(top==(n-1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int empty()
{
	if(top==-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void push(int st[],int data,int n)
{
	if(full(n)!=1)
	{
		top=top+1;
		st[top]=data;
	}
	else
	{
		printf("Stack is full");
	}
}

int pop(int st[])
{
	if(empty()!=1)
	{
		temp=st[top];
		top=top-1;
		return temp;
	}
	else
	{
		printf("Stack is empty");
		return -1;
	}
}

void display(int st[],int n)
{
	for(int i=0;i<=top;i++)
	{
		printf("%d \n",st[i]);
	}
}

int main()
{
	int n,w=1,ch=1,ch2=1,data,st[20];
	printf("Enter the max no. of elements-");
	scanf("%d",&n);
	do
	{
		printf("\n1.Push\n2.Pop\n3.Display\n");
		scanf("%d",&ch);
		switch(ch)
			{
				case 1:
				{
					do
					{
						printf("\nEnter the data:\n");
						scanf("%d",&data);
						push(st,data,n);
						printf("Repeat\n1.Yes \n2.No ");
						scanf("%d",&ch2);
					}
					while(ch2==1);
					break;
				}
				case 2:
				{
					int res=pop(st);
					printf("\nThe popped element is-%d\n",res);
					break;
				}
				case 3:
				{
					display(st,n);
					break;
				}
				default:
				{
					printf("\nWrong choice\n");
					break;
				}
			}
		printf("\nRepeat choices?\n1.Yes\n2.No\n");
		scanf("%d",&w);
	}
	while(w==1);
}