#include<stdio.h>
int main()
{
	int n,p[200],bt1[200],n1,n2,bt2[200],bt3[200],i,tq=4,j,k=0,counter=0,comp[600]={0},time[600]={0},c,rr[200],l,yu=0,pid=0;
	int com[200];
	printf("\n>Enter the details of first queue(highest priority)");
	printf("\n Enter the number of process in first queue : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&bt1[i]);
	}
	printf("\n>Enter the details of second queue(medium priority)");
	printf("\n Enter the number of process in second queue : ");
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
	{
		p[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&bt2[i]);
	}
	printf("\n>Enter the details of third queue(third priority)");
	printf("\n Enter the number of process in third queue : ");
	scanf("%d",&n2);
	for(i=0;i<n2;i++)
	{
		p[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&bt3[i]);
	}
	l=n+n1+n2;
	for(j=0;j<2*n;j++)
	{
		//if(counter==0) // checking for first process;
		{
			//running for first queue so full time quanta will run
			//applying the round robin algo here
			counter++;
			bt1[j]=bt1[j]-tq;
			if(bt1[j]<=0)
			{
				bt1[j]=0;
				rr[j]=1;//1 says process done and 0 says false
				com[j]=pid;
				pid++;
			}
			else
			{
				k++;//process not completed
				rr[j]=0;
				bt1[j+k]=bt1[j];
			}
				comp[0]=0;
				comp[j]+=tq;
				time[j]+=tq;
		}
		
		
		
		
		for(int h=0;h<n;h++)
		{
			if(rr[h]==1)
			{
			yu++;	
			}
		}
		if(yu==n)
		{
		break;
		}	
		else
		{
			yu=0;
		}
	}
	for(j=0;j<2*n;j++)
	{
		printf("%d ",rr[j]);
	}
		for(j=0;j<2*n;j++)
	{
		printf("%d ",com[j]);
	}
}
