#include<stdio.h>
#include"lin_search.h"
#include"bin_search.h"
int main()
{
    int a[20],ch,n,b,w=0;
    printf("Enter the No. of students \n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter roll no.%d \n",(i+1));
        scanf("%d",&a[i]);
    }
    printf("\n Entered list is \n");
    for(int i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    do
    {
        printf(" Enter the roll no to be searched \n");
        scanf("%d",&b);
        printf("Press \n 1.Linear Search \n 2.Binary Search \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                int z=lin_search(a,n,b);
                if(z!=-1)
                {
                    printf("The roll no is present at position %d \n",z);
                }
                else
                {
                    printf("The roll no is not present");
                }
                break;
            }
            case 2:
            {
                int z=bin_search(a,n,b);
                if(z!=-1)
                {
                    printf("The roll no is present at position %d \n",z);
                }
                else
                {
                    printf("The roll no is not present");
                }
                break;
            }
            default:
            {
                printf("Wrong choice \n");
                break;
            }
        }
        printf("Press \n 0.To go again \n 1.Stop \n");
        scanf("%d",&w);
    }
    while(w==0);
    return 0;
}