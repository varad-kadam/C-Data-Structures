#include<iostream>
using namespace std;

class Heap
{
    int marks_max[20];
    // 2*i = left child 2*i+1 = right child i/2 = parent
    public :
    int n, elem;
    int j=1;
    char ch;

    void add()
    {
        do
        {
            cout<<"\nEnter marks of Student "<<j<<" : "<<endl;
            cin>>elem;
            marks_max[j]= elem;
            insert_maxhp(marks_max,j);
            j++;

            cout<<"\nDo you want to continue to add?: ";
            cin>>ch;
        }while(ch=='y');
    }

    bool insert_maxhp(int a[],int q)
    {
        int i =q;
        int elem = a[q];
        while((i>1) && (a[i/2]<elem))
        {
            a[i]=a[i/2];
            i/=2;
        }
        a[i]=elem;
        return true;
    }

    void display()
    {
        cout<<"\nThe MAX HEAP Formed is: "<<endl;
        for(int p=1;p<j;p++)
        {
            cout<<marks_max[p]<<" ";
        }
        cout<<"\nThe Maximum Marks are: "<<marks_max[1]<<endl;
    }
};

int main()
{
    Heap A;
    A.add();
    A.display();
}
