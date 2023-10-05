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
                cout<<"\nAdd "<<newnode->data<<" to which side of "<<temp->data<<"\n1.Left\n2.Right\n";
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
                    cout<<"Wrong choice";
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

void inorder(struct node *root)
{
    node *temp;
    stack<node *>st;
    temp=root;
    
    while(temp!=NULL || st.empty()==0)
    {
        while(temp!=NULL)
        {
            st.push(temp);
            temp=temp->left;
            
        }
        temp=st.top();
        st.pop();
        cout<<temp->data<<",";
        temp=temp->right;
    }
}

int main() 
{
    
  struct node *root=NULL;
  root= create(root);
  
  cout<<"\nInorder is :- ";
  inorder(root);
}