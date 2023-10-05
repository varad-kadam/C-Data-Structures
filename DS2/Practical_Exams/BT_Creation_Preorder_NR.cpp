#include <iostream>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *root)
{
    root=new node;
    int n,w=1,w1=1,l=0,ch;
    struct node *temp;
    
    temp=new node;
    cout<<"\nEnter the data for root node: ";
    cin>>root->data;
    root->left=NULL;
    root->right=NULL;
    
    cout<<"\nDo you want to make a new node?[1.Yes 2.No]: ";
    cin>>w;
    while(w==1)
    {
        struct node *newnode;
        newnode=new node;
        cout<<"\nEnter the data for new node :- ";
        cin>>n;
        
        newnode->data=n;
        newnode->left=NULL;
        newnode->right=NULL;
        
        temp=root;
        do
        {
            while(w1==1)
            {
                cout<<"\nAdd "<<newnode->data<<" to the side of "<<temp->data<<" \n1.Left\n 2.Right\n";
                cin>>ch;
                if(ch==1)
                {
                    if(temp->left==NULL)
                    {
                        temp->left=newnode;
                        l=1;
                        break;
                    }
                    else
                    {
                        cout<<"\nThe node is full";
                        temp=temp->left;
                    }
                }
                else if(ch==2)
                {
                    if(temp->right==NULL)
                    {
                        temp->right=newnode;
                        l=1;
                        break;
                        
                    }
                    else
                    {
                        cout<<"\nThe node is full";
                        temp=temp->right;
                    }
                }
                else
                {
                    cout<<"\nWrong choice";
                    l=1;
                    break;
                    
                }
            }
        }
        while(l==0);
        
        cout<<"\nDo you want to make another node?[1.Yes 2.No]: ";
        cin>>w;
        
    }
    return root;
}

void preorder(struct node *root)
{
    node *temp;
    stack<node *>s1;
    temp=root;
    if(temp==NULL)
    {
        return ;
        
    }
    else
    {
        s1.push(temp);
        while(s1.empty()==false)
        {
            temp=s1.top();
            s1.pop();
            if(temp->right!=NULL)
            s1.push(temp->right);
            if(temp->left!=NULL)
            s1.push(temp->left);
            cout<<temp->data<<" ";
        }
    }
    
}

int main() 
{
    
  struct node *root=NULL;
  root= create(root);

  cout<<"\npreorder is :- ";
  preorder(root);
}