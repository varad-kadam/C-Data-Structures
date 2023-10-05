#ifndef COMPACT_H_
#define COMPACT_H_
int compact(int a[6][6],int m,int n,int b[6][3])
{
	b[0][0]=m;
	b[0][1]=n;
	int k=1;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=a[i][j];
				k++;
			}
		}
	}
	b[0][2]=k-1;
	return k;
}
#endif