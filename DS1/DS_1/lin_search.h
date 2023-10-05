int lin_search(int a[20],int n,int b)
{
    int z=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]==b)
        {
            z=i;
        }
    }
    return z;
}