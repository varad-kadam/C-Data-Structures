#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class gnode
{
    string name;
    int vertex;
    gnode *next;
    friend class graph;
};

class graph
{
    public:
    gnode *head[10];
    int i,n=0;
    graph()
    {
        cout<<"Enter the number of friends: ";
        cin>>n;
        for(i=0;i<n;i++)
        {
            head[i]=new gnode;
            head[i]->vertex=i;
            cout<<"Enter the name at index "<<i<<": ";
            cin>>head[i]->name;
        }
    }

    void create();
    void display();
    void dfs();
    void bfs();
};

void graph::create()
{
    int ch,v;
    int i=0;
    gnode *temp,*curr;
    string name2;
    for(i=0;i<n;i++)
    {
        temp=head[i];
        do
        {
           cout<<"\nEnter the friend connected to "<<head[i]->name<<": ";
           cin>>name2;
           cout<<"\nEnter their index no: ";
           cin>>v;
           curr=new gnode;
           curr->name=name2;
           curr->vertex=v;
           curr->next=NULL;
           temp->next=curr;
           temp=temp->next;
           cout<<"\nDo you want to connect more friends to "<<head[i]->name<<"? [1. Yes/0. No] ";
           cin>>ch;
        } while (ch==1);
    }
}

void graph::display()
{
    int i;
    gnode *temp;
    for(i=0;i<n;i++)
    {
        temp=head[i];
        while(temp!=NULL)
        {
            cout<<temp->vertex<<"."<<temp->name<<" ->";
            temp=temp->next;
        }
        cout<<"\n";
    }
}

void graph::bfs()
{
    int vis=0;
    gnode *temp;
    int visited[10];
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;
    }
    queue <int> q;
    q.push(vis);
    visited[vis]=1;
    while(q.empty()==false)
    {
        vis=q.front();
        q.pop();
        cout<<head[vis]->vertex<<"."<<head[vis]->name<<"\t";
        temp=head[vis]->next;
        while(temp!=NULL)
        {
            if(visited[temp->vertex]==0)
            {
                q.push(temp->vertex);
                visited[temp->vertex]=1;
            }
            temp=temp->next;
        }
    }
}

void graph::dfs()
{
    int v=0;
    int visited[10];
    int i;
    for(i=0;i<n;i++)
    {
        visited[i]=0;


    }
    stack<int> st;
    st.push(v);
    cout<<head[v]->vertex<<"."<<head[v]->name<<"\t";
    visited[v]=1;
    while(st.empty()==false)
    {
        gnode *temp=head[v]->next;
        while(temp!=NULL)
        {
            if(visited[temp->vertex]==0)
            {
                st.push(temp->vertex);
                cout<<temp->vertex<<"."<<temp->name<<"\t";
                visited[temp->vertex]=1;
                v=temp->vertex;
                temp=head[v];
            }
            temp=temp->next;
        }
        v=st.top();
        st.pop();

    }
}

int main()
{
    graph g;
    g.create();
    g.display();
    cout<<"\nbfs:\n";
    g.bfs();
    cout<<"\ndfs:\n";
    g.dfs();
}