#include<math.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,req[50],mov=0,headptr;
    printf("Enter the number of requests\n");
    scanf("%d",&n);
    printf("Enter the request order\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the head position\n");
    scanf("%d",&headptr);
    for(i=0;i<n;i++)
    {
    	mov=mov+abs(headptr-req[i]);
    	headptr=req[i];
    }
    printf("\nTotal head movement = %d\n\n",mov);
}
