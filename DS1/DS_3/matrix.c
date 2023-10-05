#include<stdio.h>
#include"compact.h"
#include"simptrans.h"
#include"ftrans.h"

void accept(int a[6][6],int m,int n)
{
	for(int i=0;i<m;i++)
		{
			printf("\nEnter the elements of row %d",i);
			for(int j=0;j<n;j++)
			{
				printf("\n Element %d -",j);
				scanf("%d",&a[i][j]);
			}
		}
}
void display(int a[6][6],int m,int n)
{
	printf("\nThe Entered matrix is -\n");
		for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					printf(" %d ",a[i][j]);
				}
				printf("\n");
			}
}
void displayay(int b[10][3],int k)
{
		for(int i=0;i<k;i++)
			{
				for(int j=0;j<3;j++)
				{
					printf(" %d ",b[i][j]);
				}
				printf("\n");
			}
}
int main()
{
	int a[6][6],b[10][3],c[10][3],d[10][3],m,n,k;
	printf("Enter the number of rows -");
	scanf("%d",&m);
	printf("\nEnter the number of columns -");
	scanf("%d",&n);
	accept(a,m,n);
	display(a,m,n);
	k=compact(a,m,n,b);

	int ch;
	printf("Enter choice of matrix to be calcuclated:\n 1.Compact\n 2.Transpose\n 3.Fast Transpose\n");
	scanf("%d",&ch);

	switch(ch)
	{
		case 1:
		printf("\nThe compact matrix is -\n");
		displayay(b,k);
		simptrans(b,c);
		break;

		case 2:
		printf("\nThe transpose matrix is -\n");
		displayay(c,k);
		ftrans(b,d);
		break;

		case 3:
		printf("\nThe ftranspose matrix is -\n");
		displayay(d,k);
		break;
	}
	return 0;
}
