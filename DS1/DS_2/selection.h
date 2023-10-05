int selection(int a[],int n)
{
    int min,temp,k,i,j,z;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
               min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    printf("After sorting:");
    for(k=0;k<n;k++)
    {
        printf("%d\t",a[k]);
    }
    printf("\n TOP 5 ARE \n");
    {
        for(z=n-1;z>n-6;z--)
        {
            printf("\t%d",a[z]);
        }
    }
    char c;
    printf("\nDo you want to continue if yes enter Y\n");
    scanf(" %c",&c);
    if(c=='Y')
    {
        return 1;
    }
    return 0;

}