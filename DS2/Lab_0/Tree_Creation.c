#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

void preorder(struct node *root);
void postorder(struct node *root);
void inorder(struct node *root);

int main()
{
    int a,ch,n,lr,wo=0,w=0,w1=1;
    
    struct node *rootemp;
    struct node *root;
    
    root=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data for root node:");
    scanf("%d",&a);
    root->data=a;
    root->left=NULL;
    root->right=NULL;
 

    printf("\nDo you want to make a node?\n1.Yes\n2.No\n");
    scanf("%d",&ch);
    while(ch==1)
    {
        struct node *curr;
        curr=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the value of node:");
        scanf("%d",&n);
        curr->data=n;
        curr->left=NULL;
        curr->right=NULL;
        rootemp=root;
        
        do
        {
            while(w1==1)
            {
                printf("\nAdd to 1.Left or 2.Right of %d:",rootemp->data);
                scanf("%d",&lr);
                if(lr==1)
                {
                    if(rootemp->left!=NULL)
                    {
                        rootemp=rootemp->left;
                    }
                    else
                    {
                        rootemp->left=curr;
                        w=1;
                        break;
                    }
                }
                else if(lr==2)
                {
                    if(rootemp->right!=NULL)
                    {
                        rootemp=rootemp->right;
                    }
                    else
                    {
                        rootemp->right=curr;
                        w=1;
                        break;
                    }
                }
                else
                {
                    printf("\nInvalid choice!");
                }
            }
        }
        while(w==0);
        printf("\nDo you want to make another node? 1.Yes or 2.No:");
        scanf("%d",&ch);
    }
    printf("\nPreorder sequence is:\t");
    preorder(root);
    printf("\nPostorder sequence is:\t");
    postorder(root);
    printf("\nInorder sequence is:\t");
    inorder(root);
    
    return 0;
}

    
void preorder(struct node *root)
{
    if(root!=NULL)
        {  
            printf("%d\t",root->data);
            preorder(root->left);
            preorder(root->right);
        }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void inorder(struct node*root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}