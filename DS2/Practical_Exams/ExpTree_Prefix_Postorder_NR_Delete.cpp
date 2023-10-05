#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

struct node* constructTreePreF(char expression[]);
bool operator1(char c);
void postorder(struct node *root);
void Delete_Tree(struct node* root);

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

int main()
{
    char expression[10];
    struct node *root;
    
    cout<<"\nEnter the Expression For PreFix Tree Creation: "<<endl;
    cin.getline(expression,10);
    root=constructTreePreF(expression);
    
    cout<<"\nBy PreFix, Postorder Expression is: ";
    postorder(root);
    
    cout<<"\nDo you want to Delete Tree [0. Yes/1. No]? "<<endl;
    Delete_Tree(root);
}

struct node* constructTreePreF(char expression[10])
{
    struct node *t1,*t2,*T;
    stack<node*>st;
    
    for(int i=strlen(expression)-1;i>=0;i--)
    {
        if(!operator1(expression[i]))
        {
            T=new node;
            T->data=expression[i];
            T->left=T->right=NULL;
            st.push(T);
        }
        else
        {
            T=new node;
            T->data=expression[i];
            //T->left=T->right=NULL;
            t1=st.top();
            st.pop();
            
            t2=st.top();
            st.pop();
            
            T->left=t1;
            T->right=t2;
            st.push(T);
        }
    }
    T=st.top();
    st.pop();
    
    return T;
}

bool operator1(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/')
    {
        return true;
    }
    return false;
}

void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }
}

void Delete_Tree(struct node* root)
{
    if(root!=NULL)
    {
        Delete_Tree(root->left);
        Delete_Tree(root->right);
        cout<<"\nDeleted Node is: "<<root->data<<endl;
        delete root;
    }
}

/*
Output:
Enter the Expression For PreFix Tree Creation: 
*+52-64

By PreFix, Postorder Expression is: 52+64-*
Do you want to Delete Tree [0. Yes/1. No]? 

Deleted Node is: 5

Deleted Node is: 2

Deleted Node is: +

Deleted Node is: 6

Deleted Node is: 4

Deleted Node is: -

Deleted Node is: *
*/