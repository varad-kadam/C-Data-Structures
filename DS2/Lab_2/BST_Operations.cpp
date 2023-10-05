#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *root)
{
    int ch2,il;
    
    root=new node;
    struct node *temp;
    temp=new node;
    
    cout << "\nEnter the data for the root node in BST: ";
    cin >> root->data;
    root->left=NULL;
    root->right=NULL;
    
    cout << "\nDo you want to make a new node?\n1.Yes\n2.No\n" << endl;
    cin >> ch2;

    while(ch2==1)
    {
        temp=root;
        struct node *newnode;
        newnode=new node;
        
        cout << "\nEnter data for the node: ";
        cin >> newnode->data;
        newnode->left=NULL;
        newnode->right=NULL;
        il=0;
        
        while(il==0)
        {
            if(newnode->data < temp->data)
            {
                if(temp->left==NULL)
                {
                    temp->left=newnode;
                    il=1;
                }
                
                else
                {
                    temp=temp->left;
                }
            }
            
            else if(newnode->data > temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right=newnode;
                    il=1;
                }
                
                else
                {
                    temp=temp->right;
                }
            }
            
            else
            {
                cout << "\nYou cannot enter the same number more than once in BST" << endl;
                il=1;
            }
        }
        
        cout << "\nDo you want to make another node?\n1.Yes\n2.No\n" << endl;
        cin >> ch2;
        cout << endl;
    }
    return root;
}

void r_preorder(struct node *root)
{
    if(root!=NULL)
    {
        cout << root->data << " - ";
        r_preorder(root->left);
        r_preorder(root->right);
    }
}

void BFT(struct node *root)
{
    struct node *temp;
    queue < node *> lvl;
    lvl.push(root);
    
    while(lvl.empty()==0)
    {
        temp=new node;
        temp=lvl.front();
        lvl.pop();
        cout<<temp->data<<" - ";
        
        if(temp->left!=NULL)
        {
            lvl.push(temp->left);
        }
        
        if(temp->right!=NULL)
        {
            lvl.push(temp->right);
        }
    }
}

void search(struct node *root,int sc)
{
    struct node *temp;
    temp=root;
    int c=0;
    
    while(temp!=NULL)
    {
        if(temp->data==sc)
        {
            cout << "\nThe number you are searching for exists." << endl;
            c=1;
            break;
        }
        
        else if(sc < temp->data)
        {
            temp=temp->left;
        }
        
        else
        {
            temp=temp->right;
        }
    }
    
    if(c==0)
    {
        cout << "\nThe number is not there in the tree." << endl;
    }
}

struct node *copy(struct node *root)
{
    struct node *temp=NULL;
    //temp=new node;
    if(root!=NULL)
    {
        temp=new node;
        temp->data=root->data;
        temp->left=copy(root->left);
        temp->right=copy(root->right);
    }
    
    return temp;
}

struct node *mirror(struct node *root)
{
    if(root==NULL)
    {
        return root;
    }
    
    else
    {
        struct node *temp;
        temp=root->left;
        root->left=root->right;
        root->right=temp;
        mirror(root->left);
        mirror(root->right);
    }
    
    return root;
}

struct node *findmin(struct node *root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    
    return root;
}

struct node *Delete(struct node *root,int value)
{
    struct node *temp;
    temp=new node;
    
    if(root==NULL)
    {
        return NULL;
    }
    
    if(value < root->data)
    {
        root->left =Delete(root->left,value);
    }
    
    else if(value > root->data)
    {
        root->right=Delete(root->right,value);
    }
    
    else if(value == root->data)
    {
        if(root->right == NULL && root-> left == NULL)
        {
            delete root;
            root=NULL;
        }
        else if(root->right == NULL)
        {
            temp=root;
            root=root->left;
            delete temp;
        }
        else if(root->left == NULL)
        {
            temp=root;
            root=root->right;
            delete temp;
        }
        else
        {
            temp=findmin(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    
    else
    {
        cout << "\nThe number you are looking to delete does not exist." << endl;
    }
    return root;
}

int main()
{
    int choice,w,choice2,sc;
    
    struct node *root=NULL;
    root=create(root);
    struct node *root2=NULL;
    root2=new node;
    
    if(root!=NULL)
    {
        cout << "\nThe breadth first traversal is:" << endl;
        BFT(root);
        cout << "\nThe recursive preorder is:" << endl;
        r_preorder(root);
    }

    do
    {
        cout << "\nWhat do you wanna do now?" << endl;
        cout << "\n1.Search BST" << endl;
        cout << "\n2.Copy BST" << endl;
        cout << "\n3.Delete a node" << endl;
        cout << "\n4.Mirror BST in copy" << endl;
        cin >> choice2;
        
        switch(choice2)
        {
            case 1:
            {
                cout << "\nEnter the number you want to search for: ";
                cin >> sc;
                cout << endl;
                search(root,sc);
                break;
            }
            case 2:
            {
                cout << "\nCopying the BST..." << endl;
                root2=copy(root);
                cout << "\nBST copied" << endl;
                cout << "\nNow printing" << endl;
                r_preorder(root2);
                break;
            }
            case 3:
            {
                int value;
                cout << "\nEnter the number you want to delete:";
                cin >> value;
                cout << endl;
                root=Delete(root,value);
                r_preorder(root);
                break;
            }
            case 4:
            {
                cout << "\nMirroring....." << endl;
                root2=mirror(root2);
                cout << "\nMirrored BST is:" << endl;
                r_preorder(root2);
                break;
            }
            default:
            {
                cout << "\nWrong choice in selection" << endl;
                break;
            }
        }
        
        cout << "Wanna go again?\n1.Yes\n2.No\n";
        cin >> w;
        cout << endl;
    }while(w==1);
}