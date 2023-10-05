#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *BTCreate(struct node *root);
void bft(struct node *root);
void mirror(struct node *tempc);
int longestpath(struct node *root);
struct node *copy(struct node *root);
struct node *deleteNode(struct node *root, int val);
struct node *findMin(struct node *root);


int main()
{
	struct node *root = NULL;
	struct node *tempc = NULL;
	struct node *del= NULL;

	int i,j=1, val;
	while(j == 1)
	{
		cout << "\nWhat do you want to do: "<<endl<<"1. Create Binary Search Tree "<<endl;
		cout << "2. Display the tree "<< endl<< "3. Make a copy of the BST "<< endl <<"4. Display copy "<<endl<<"5. Mirror image and display "<<endl;
		cout << "6. Find number of nodes in longest path from root "<<endl<<"7. delete a node "<<endl;
		cin >> i;
		switch (i)
		{
            case 1:
                root = BTCreate(root);
                break;
            case 2:
                cout << "\nThe bft is: " << endl;
                bft(root);
                cout<< endl;
                break;
            case 3:
                tempc = copy(root);
                break;
            case 4:
                cout << "\nThe bft for copy is: " << endl;
                bft(tempc);
                cout<< endl;
                break;
            case 5:
                tempc = root;
                mirror(tempc);
                cout << "\nThe bft for mirror of copy is: " << endl;
                bft(tempc);
                cout<<endl;
                break;
            case 6:
                longestpath(root);
                cout<<"\nFind number of nodes in longest path from root: "<<longestpath(root);
                break;
            case 7: 
                cout<<"\nEnter the value to delete: ";
                cin>>val;
                del = deleteNode(root, val);
                break;
            default:
                cout<<"\nInvalid Choice";
                break;
		}
		cout <<"Do you want to choose another option?[0. No/1. Yes]: ";
		cin >> j;
	}
	return 0;
}

struct node *BTCreate(struct node *root)
{
	struct node *temp;
	struct node *newNode;
	int flag = 0,x;
	char ch2;
	do
	{
		if (root == NULL)
		{
			root = new node;
			cout << ("\nEnter the value of root node: ");
			cin >> x;
			
            root-> data=x;
			root->left = NULL;
			root->right = NULL;
		}
		else
		{
			temp = root;
			newNode = new node;
			cout<< ("\nEnter the value of new node: ");
			cin >>x;
			
            newNode->data=x;
			newNode ->left = NULL;
			newNode ->right = NULL;
			
            while(flag == 0)
			{
				if (newNode -> data < temp -> data)
				{
					if (temp -> left == NULL)
					{
						temp ->left = newNode;
						flag = 1;
					}
					else
					{
						temp = temp -> left;
					}
				}
				else if (newNode -> data > temp -> data)
				{
					if (temp -> right == NULL)
					{
						temp ->right = newNode;
						flag = 1;
					}
					else
					{
						temp = temp -> right;
					}
				}
			}
			flag=0;
		}

		cout<<("Do you want to continue(y/n): ");
		cin >> ch2;
	}while(ch2 == 'y');
	return root;
}


void bft(struct node *root)
{
	struct node *temp;
	queue <node *> q;
	q.push(root);
	
    while(q.empty() == 0)
	{
		temp = q.front();
		q.pop();
		cout << temp -> data <<" ";
		if(temp->left != NULL)
		{
			q.push(temp->left);
		}
		if(temp->right != NULL)
		{
			q.push(temp->right);
		}
	}
}

int longestpath(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    queue<node*> q;
    q.push(root);
    
    struct node* front=NULL;
    int height=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size>0)
        {
            //cout<<"size="<<size<<endl;
            front=q.front();
            q.pop();
            
            if(front->left!=NULL)
            {
                q.push(front->left);
            }
            if(front->right!=NULL)
            {
                q.push(front->right);
            }
            size--;
        }
        height++;
    }
    return height;
}

struct node *copy(struct node *root)
{
	struct node *temp;
	if(root == NULL)
    {
        return 0;
    }
	else
	{
		temp = new node;
		
        temp-> data = root -> data;
		temp->left = copy(root->left);
		temp-> right = copy(root->right);
	}
	return temp;
}

void mirror(struct node *tempc)
{
	if(tempc == NULL)
    {
        return;
    }
	else
	{
		struct node *temp;
		
        temp = tempc -> left;
		tempc -> left = tempc -> right;
		tempc -> right = temp;
		
        mirror(tempc ->left);
		mirror(tempc -> right);

	}
}

struct node *findMin(struct node *root)
{
	if(root->left == NULL && root->right == NULL)
	{
		return root;
	}
	else
    {
        findMin(root -> left);
    }
}

struct node *deleteNode(struct node *root, int val)
{
	struct node *temp;
	if(root == NULL)
	{
		return 0;
	}
	if(val < root -> data)
	{
		root -> left = deleteNode(root->left, val);
	}
	else if(val > root -> data)
	{
		root -> right = deleteNode(root -> right, val);
	}
	else if(val == root -> data)
	{
		if(root -> left == NULL && root -> right == NULL)
		{
			delete root;
			root = NULL;
		}
		else if(root -> left == NULL)
		{
			temp = root;
			root = root -> right;
			delete temp;
			temp = NULL;
		}
		else if(root -> right == NULL)
		{
			temp = root;
			root = root -> left;
			delete temp;
			temp = NULL;
		}
		else
		{
			temp = findMin(root -> right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}