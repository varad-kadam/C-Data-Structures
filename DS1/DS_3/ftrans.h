#ifndef FTRANS_H_
#define FTRANS_H_
void ftrans(int b[10][3],int d[10][3])
{
	int m,n,t;
	m=b[0][0];
	n=b[0][1];
	t=b[0][2];
	int x[n],y[n];
	d[0][0]=n;
	d[0][1]=m;
	d[0][2]=t;
	for(int i=0;i<n;i++)
	{
		x[i]=0;
	}
		for(int i=1;i<=t;i++)
		{
			x[b[i][1]]=x[b[i][1]]+1;
		}
		y[0]=1;
		for(int k=1;k<n;k++)
		{
			y[k]=y[k-1]+x[k-1];
		}
		for(int i=1;i<=t;i++)
		{
			int j=b[i][1];
			d[y[j]][0]=b[i][1];
			d[y[j]][1]=b[i][0];
			d[y[j]][2]=b[i][2];
			y[j]=y[j]+1;
		}
}


#endif