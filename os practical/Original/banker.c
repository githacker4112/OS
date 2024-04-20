#include<stdio.h>
void main()
{
int n,m,i,j,k,proc=-1,flag=1,rpn,grant=1,f=0;
printf("Enter the number of processes:");
scanf("%d",&n);
printf("Enter the number of resources:");
scanf("%d",&m);

int allocation[n][m],max[n][m],available[m],need[n][m],finish[n],work[m],sequence[n],request[m];

printf("Enter the allocation matrix:");
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		scanf("%d",&allocation[i][j]);

printf("\n *Allocation matrix*\n");
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	printf("\t %d",allocation[i][j]);
	printf("\n");
}

printf("\n Enter the max matrix:");
for(i=0;i<n;i++)
	for(j=0;j<m;j++)
		scanf("%d",&max[i][j]);

printf("\n *Max matrix*\n");
for(i=0;i<n;i++)
{
	for(j=0;j<m;j++)
	printf("\t %d",max[i][j]);
	printf("\n");
}

printf("\nEnter the available matrix:");
for(i=0;i<m;i++)
{
	scanf("%d",&available[i]);
	work[i]=available[i];
}

printf("\n *Available matrix*\n");
for(i=0;i<m;i++)
printf("\t %d",available[i]);
printf("\n\n");


printf("\n Is there any request?[1/0]:");
scanf("%d",&f);
if(f)
{
	printf("\n Enter process no:");
	scanf("%d",&rpn);
	printf("\n Enter request:");
	for(i=0;i<m;i++)
	scanf("%d",&request[i]);

printf("\n *Request matrix for process p%d*\n",rpn);
for(i=0;i<m;i++)
	printf("\t %d",request[i]);
	printf("\n");
}

//calculating need matrix
for(i=0;i<n;i++)
for(j=0;j<m;j++)
need[i][j]=max[i][j]-allocation[i][j];

//print need matrix
printf("\n ***need matrix***\n");
for(i=0;i<n;i++)
{
	for(j=0; j<m; j++)
	printf("\t%d",need[i][j]);
	printf("\n");
}

for(i=0;i<n;i++)
finish[i]=0;

//banker's alogorithm
outer:
	for(i=0;i<n;i++)
	{
	if(finish[i]==0)
	{
	for(j=0;j<m;j++)
	{
	if(need[i][j]>work[j])
	flag=0;
}
if(flag==0)
printf("\nprocess p%d must wait!\nResource not available...",i);
else
{
printf("\n process p%d added",i);
finish[i]=1;
sequence[++proc]=i;
for(k=0; k<m; k++)
work[k]=work[k]+allocation[i][k];
}
flag=1;
}
}
for(i=0; i<n; i++)
if(finish[i]==0)
goto outer;

printf("\n***safe sequence***\n");
for(i=0; i<n; i++)
printf("\tp%d",sequence[i]);
printf("\n\n");

for(i=0; i<m; i++)
if(request[i]>need[rpn][i] | request[i]>available[i])
{
grant=0;
break;
}
if(grant==1)
{
printf("\n request p%d can be granted immediately\n\n",rpn);
for(i=0;i<n;i++)
{
available[i]=available[i]-request[i];
allocation[rpn][i]=allocation[rpn][i]+request[i];
need[rpn][i]=need[rpn][i]-request[i];
work[i]=available[i];
}
for(i=0;i<n;i++)
finish[i]=0;
flag=1;
proc=-1;

outer2:
for(i=0;i<n;i++)
{
if(finish[i]==0)
{
for(j=0;j<m;j++)
{
if(need[i][j]>work[j])
flag=0;
}
if(flag==0)
printf("\n process p%d must wait!\nresources not avalible",i);
else
{
printf("\n process p%d added",i);
finish[i]=1;
sequence[++proc]=i;
for(k=0; k<m; k++)
work[k]=work[k]+allocation[i][k];
}
flag=1;
}
}
for(i=0;i<n;i++)
if(finish[i]==0)
goto outer2;
printf("\n*** new safe sequence ***\n");
for(i=0;i<n;i++)
printf("\tp%d",sequence[i]);
printf("\n\n");
}
else
printf("\nrequest p%d cannot be granted immediatly\n\n",rpn);
}
