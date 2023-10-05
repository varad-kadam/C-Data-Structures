#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

struct node* constructTreePostF(char expression[]);
bool operator1(char c);
void inorder(struct node *root);
void Delete_Tree(struct node* root);

struct node{
    char data;
    struct node* left;
    struct node* right;
};

int main()
{
    char expression[10];
    struct node *root;
    
    cout<<"\nEnter the Expression For PostFix Tree Creation: "<<endl;
    cin.getline(expression,10);
    root=constructTreePostF(expression);
    
    cout<<"\nBy PostFix Inorder Expression is: ";
    inorder(root);
    
    cout<<"\nDo you want to Delete Tree [0. Yes/1. No.]: "<<endl;
    Delete_Tree(root);
}

struct node* constructTreePostF(char expression[10])
{
    struct node *t1,*t2,*T;
    stack<node*>st;
    
    for(int i=0;i<strlen(expression);i++)
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
            
            T->left=t2;
            T->right=t1;
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

void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data;
        inorder(root->right);
    }
}

void Delete_Tree(struct node* root)
{
    if(root!=NULL)
    {
        Delete_Tree(root->left);
        Delete_Tree(root->right);
        cout<<"Deleted Node is "<<root->data<<endl;
        delete root;
    }
}

/*
Output:
Enter the Expression For PostFix Tree Creation: 
54-62+*

By PostFix Inorder Expression is: 5-4*6+2
Do you want to Delete Tree [0. Yes/1. No.]: 
Deleted Node is 5
Deleted Node is 4
Deleted Node is -
Deleted Node is 6
Deleted Node is 2
Deleted Node is +
Deleted Node is *
*/