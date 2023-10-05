#include<iostream>
using namespace std;

class Heap
{
    int marks_min[20];
    // 2*i = left child 2*i+1 = right child i/2 = parent
    public :
    int n,elem;
    int j=1;
    char ch;
    void add()
    {
        do
        {
            cout<<"\nEnter marks of Student "<<j<<" : "<<endl;
            cin>>elem;
            marks_min[j]= elem;
            insert_minhp(marks_min,j);
            j++;
            cout<<"\nDo you want to continue to add?: ";
            cin>>ch;
        }while(ch=='y');
    }

    bool insert_minhp(int a[],int n)
    {
        int i =n;
        int elem = a[n];
        
        while((i>1) && (a[i/2]>elem))
        {
            a[i]=a[i/2];
            i/=2;
        }
        a[i]=elem;
        return true;
    }

    void display()
    {
        cout<<"\nThe MIN HEAP Formed is: "<<endl;
        for(int p=1;p<j;p++)
        {
            cout<<marks_min[p]<<" ";
        }
        cout<<"The Minimum Marks are: "<<marks_min[1]<<endl;
    }
};

int main()
{
    Heap A;
    A.add();
    A.display();
}