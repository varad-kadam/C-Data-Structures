#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void main()
{
    struct node *root,*temproot,*newnode;
    root=NULL;
    //root->data=0;
    int flag,n;
    char choice,con;
    
    do
    {
        flag=0;
        printf("\nEnter data:");
        scanf("%d",&n);

        if(root==NULL)
        {
            root=(struct node*)malloc(sizeof(struct node));
            root->data=n;
            root->right=NULL;
            root->left=NULL;
        }
        else
        {
            temproot=(struct node*)malloc(sizeof(struct node));
            newnode=(struct node*)malloc(sizeof(struct node));
            temproot=root;
            
            while(flag==0)
            {
                newnode->data=n;
                newnode->right=NULL;
                newnode->left=NULL;
                // printf("Do you want to connect %d on the left(L) or the right(R) of %d",n,temproot->data);
                //scanf(" %c",&choice);
                
                if(temproot->data==newnode->data)
                {
                    printf("\nERROR");
                    break;
                }
                else if(temproot->data>newnode->data)
                {
                    choice='L';
                }
                else
                {
                    choice='R';
                }
                if(choice=='R')
                {
                    if(temproot->right==NULL)
                    {
                        temproot->right=newnode;
                        temproot=temproot->right;
                        flag=1;
                    }
                    else
                    {
                        temproot=temproot->right;
                    }
                }
                else
                {
                    if(temproot->left==NULL)
                    {
                        temproot->left=newnode;
                        temproot=temproot->left;
                        flag=1;
                    }
                    else
                    {
                        temproot=temproot->left;
                    }
                }
            }
        }
        printf("\nDo you want to continue y/n?:");
        scanf(" %c",&con);
    }while(con=='y');
}