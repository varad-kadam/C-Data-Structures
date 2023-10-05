int bin_search(int a[20],int n,int b)
{
    int z=-1,low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==b)
        {
            z=mid;
            break;
        }
        else if(b<a[mid])
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return z;
}