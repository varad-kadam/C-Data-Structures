#include<stdio.h>
#include"insertion.h"
#include"selection.h"
#include"shell.h"

int main()
{
    int i,n,j,ch,flag=0;
    int a[20];

    do
    {

        printf("\nEnter the total number of students\n:");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            printf("Enter roll nos of student %d\t",i+1);
            scanf("%d",&a[i]);
        }
        printf("\nYou have entered the roll nos\n");
        for (j=0;j<n;j++)
        {
            printf("\n%d",a[j]);
        }


        printf("\nENTER \n 1.) FOR SELECTION SORT \n 2.) FOR INSERTION SORT \n 3.) FOR SHELL SORT \n4.)For exit\n");
        scanf("%d",&ch);
          switch(ch)
          {
            case 1:
              flag=selection(a,n);
              break;
            case 2:
              flag=insertion(a,n);
              break;
            case 3:
              flag=shell(a,n);
              break;
            case 4:
              return(0);
          }
    }while(flag==1);
}