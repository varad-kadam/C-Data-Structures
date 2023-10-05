#include<stdio.h>
int main()
{
    FILE *fp;
    int n,i;
    char out[3];
    
    fp=fopen("lab6.txt","w");
    printf("\nEnter number of nodes:");
    scanf("%d",&n);
    
    int var=n*3;
    char a[var];

    for(i=0;i<var;i=i+3)
    {
        char x=i,y=x+1,z=y+1;
        int b,c,d;
        
        printf("\nEnter node:");
        scanf("%s",&b);
        a[x]=b;

        printf("\nEnter left child:");
        scanf("%s",&c);
        a[y]=c;

        printf("\nEnter right child:");
        scanf("%s",&d);
        a[z]=d;
    }

    fwrite(a,1,sizeof(a),fp);
    fclose(fp);
    fp=fopen("lab6.txt","r");
    
    while(fgets(out,4,fp)!=NULL)
    {
        printf("\nThe Root Node Is %c\n",out[0]);
        if(out[1]=='0')
        {
            printf("\nThe Left Child of Node %c is NULL\n",out[0]);
        }
        else
        {
            printf("The Left Child of Node %c Is %c\n",out[0],out[1]);
        }
        if(out[2]=='0')
        {
            printf("The Right Child of Node %c is NULL\n",out[0]);
        }
        else
        {
            printf("The Right Child of Node %c is %c\n",out[0],out[2]);
        }
    }
    
    fclose(fp);
    return 0;
}