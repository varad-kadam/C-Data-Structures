int insertion(int a[],int n)
{
    int key,i,j,k,z;
    for(i=1;i<n;i++)
    {
        key=a[i];
        j=i-1;
        while(j >=0 && a[j] > key)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=key;
    }



    printf("After sorting: ");
    for(k=0;k<n;k++)
    {
        printf("\t%d",a[k]);

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