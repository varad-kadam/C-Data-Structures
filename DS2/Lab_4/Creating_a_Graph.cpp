#include<iostream>
using namespace std;

class gnode
{
	int vertex;
	gnode *next;
	friend class Graph;
};

class Graph
{
	public:
	
	gnode *head[10];
	int i, n;
	Graph()
	{
		cout<<"Enter the number of vertex: ";
		cin>>n;
		
		for(i=0;i<n;i++)
		{
			head[i] = new gnode;
			head[i]->vertex = i;
		}
	}
	
	void create();
	void display();
};

void Graph::create()
{
	int v;
	gnode *temp;
	gnode *curr;
	char ch;
	
	for(i = 0; i < n; i++)
	{
		temp = head[i];
		do
		{
			cout<<"Enter the vertex connected to head["<<i<<"]: ";
			cin>>v;
			curr = new gnode;
			curr -> vertex = v;
			curr -> next = NULL;
			temp -> next = curr;
			temp = temp -> next;
			
			cout<<"Do you want to add another vertex(y/n): ";
			cin>>ch;
		}while(ch =='y');
	}
}

void Graph::display()
{
	gnode *temp;
	for(i=0;i<n;i++)
	{
		temp = head[i];
		while(temp != NULL)
		{
			cout<<temp->vertex<<"->";
			temp = temp->next;
		}
		cout<<endl;
	}
}

int main()
{
	Graph g;
	g.create();
	g.display();
	return 0;
}
