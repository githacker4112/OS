#include<stdio.h>
void main()
{
	int al[10][10],av[10][10],max[10][10],n[10][10],p,r,c,i,j,ar,ac;
	printf("Enter how many Process :\n");
	scanf("%d",&p);
	printf("Enter the resorces :\n");
	scanf("%d",&r);
	printf("Enter Allocation matrix: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d",&al[i][j]);
		}
	}
	printf("Allocation Matrix :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d\t",al[i][j]);	
		}
		printf("\n");
	}
	printf("Enter Maximum matrix: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<p;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Maximum Matrix :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d\t",max[i][j]);	
		}
		printf("\n");
	}

	printf("Need Matrix is :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<p;j++)
		{
			n[i][j]=max[i][j]-al[i][j];
		
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<p;j++)
		{
			printf("%d\t",n[i][j]);	
		}
		printf("\n");
	} 
		
	printf("Enter Available matrix :\n");
	printf("Enter Rows and Column of Available Matrix :\n");
	scanf("%d %d",&ar,&ac);
	
	printf("Enter Available- matrix: \n");
	for(i=0;i<ar;i++)
	{
		for(j=0;j<ac;j++)
		{
			scanf("%d",&av[i][j]);
		}
	}
	printf("Available Matrix :\n");
	for(i=0;i<ar;i++)
	{
		for(j=0;j<ac;j++)
		{
			printf("%d\t",av[i][j]);	
		}
		printf("\n");
	}

	
}
