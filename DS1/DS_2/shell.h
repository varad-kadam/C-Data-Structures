int shell(int a[],int n)
{
    int k,z;
   for (int interval=n/2;interval>0;interval/=2)
        {
        for(int i=interval;i<n;i+=1)
         {
         int temp = a[i];
         int j;
        for (j=i;j>=interval&&a[j-interval]>temp;j-=interval)
        {
         a[j]=a[j-interval];
        }
      a[j]=temp;
    }
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