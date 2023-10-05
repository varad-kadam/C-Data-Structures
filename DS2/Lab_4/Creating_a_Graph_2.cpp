#include <iostream>
#include <cstring>
#include <queue>
#include<stack>

using namespace std;

class gnode
{
	public:
	int vertex;
	string name;
	gnode *next;
	friend class graph;
};

class Graph
{
	public:
	gnode *head[10];
	int i,n=0;
	Graph()
	{
		cout << "\nEnter the number of vertices: ";
		cin >> n;
		
		for(i=0;i<n;i++)
		{
			head[i]=new gnode;
			head[i]->vertex=i;
			cout << "\nEnter the name at index " << i << ": ";
			cin >> head[i]->name;
		}
	}
	void create();
	void display();
	
	void bft();
	void dfs_nr();
};


void Graph::create()
{
	string naam;
	gnode *temp,*curr;
	int ch,v;
	for(int i=0;i<n;i++)
	{
		temp=head[i];
		do
		{
			cout << "\nEnter the friend connected to -> " << head[i]->name << ": ";
			cin >> naam;
			cout << "\nEnter their index no.: ";
			cin >> v;
			curr=new gnode;
			curr->name=naam;
			curr->vertex=v;
			temp->next=curr;
			temp=temp->next;
			cout << "\nWant to connect more friends?\n1.Yes\n2.No\n";
			cin >> ch;
		}
		while(ch==1);
	}
}

void Graph::display()
{
	gnode *temp;
	for(int i=0;i<n;i++)
	{
		temp=head[i];
		while(temp!=NULL)
		{
			cout << temp->vertex << "." << temp->name << " -> ";
			temp=temp->next;
		}
		cout << "NULL\n";
	}
}

void Graph::bft()
{
    // int front=0;
    // int rear=0;
	int vis=0;
	int visited[10];
	gnode *temp;
	
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
	
	queue<int> kyu;
	kyu.push(vis);
	visited[vis]=1;
	
	while(kyu.empty()==false)
	{
		vis=kyu.front();
		kyu.pop();
		cout << head[vis]->vertex << "." << head[vis]->name << "  ";
		temp=head[vis]->next;
		while(temp!=NULL)
		{
			if(visited[temp->vertex]==0)
			{
				kyu.push(temp->vertex);
				
				visited[temp->vertex]=1;
			}
				         //if (kyu.empty()==false) {
                //for (int i = front; i <= rear; i++)
                  //  cout <<kyu[i] << "  ";
                //cout << endl;
			    //}
			temp=temp->next;
		}
	}
}

void Graph::dfs_nr()        
{
    int v=0;
    int visited[10];
    for(int i = 0; i < n; i++)
         visited[i] = 0;
    stack <int> s;
    
	s.push(v);
    cout << head[v]->vertex << "\t";
    visited[v] = 1;
    
	while(s.empty() == false)
    {

    	gnode * temp = head[v]->next;
		
		// for testing
		cout << "value of temp" << temp->vertex << endl;
        
		while(temp != NULL)
        {
            if(!visited[temp->vertex])
            {
                s.push(temp->vertex);
                cout << temp->vertex << "\t";
                visited[temp->vertex] = 1;
                v=temp->vertex;
                temp=head[v];
				//temp=head[v]->next;
				cout<<"temp ka vertex"<<temp->vertex<<endl;
            }
            temp = temp->next;
			
			// for testing
			cout<<"temp ka vertex "<<temp->vertex<<endl;
        }
        
		v=s.top();
        // for debugging
		cout << "\nv= " << v << endl;
        s.pop();
    }   
}

int main()
{
	Graph g;
	
	g.create();
	g.display();
	
	cout << "\nbfs: " << endl;
	g.bft();
	
	cout << "\ndfs: " << endl;
	g.dfs_nr();
	
	return 0;
}