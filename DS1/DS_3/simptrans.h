#ifndef SIMPTRANS_H_
#define SIMPTRANS_H_
int simptrans(int b[10][3],int c[10][3])
{
	int m,n,t,k=1;
	m=b[0][0];
	n=b[0][1];
	t=b[0][2];
	c[0][0]=n;
	c[0][1]=m;
	c[0][2]=t;
	for (int i=0;i<n;i++)
	{
		for (int j=1;j<=t;j++)
		{
			if(i==b[j][1])
			{
				c[k][0]=b[j][1];
				c[k][1]=b[j][0];
				c[k][2]=b[j][2];
				k++;
			}
		}
	}
	return 0;
}


#endif