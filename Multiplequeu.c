#include<stdio.h>
using namespace std; 
void *raround(int n,int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
 
void round(int bt1[],int tq,int n,int wt[])
{
	int i,cp[200];
	int pid=0;
	int k[200],o=0;
	int bt2[200];
	bool complete=true;
	int tat[200];
	int total_wt=0;
	int total_tat=0;
	for(i=0;i<n;i++)
	{
		cp[i]=bt1[i];
	}
		for(i=0;i<n;i++)
	{
		bt2[i]=bt1[i];
	}
	int t=0;
	while(true)
	{
	    complete=true;
		for(i=0;i<n;i++)
		{
			if(cp[i]>0)
			{
			complete=false;
			if(cp[i]>tq)
			{
				t+=tq;
				cp[i]-=tq;
			}
			else
			{
				t=t+cp[i];
				wt[i]=t-bt2[i];
				cp[i]=0;
			if(cp[i]==0)
			{
				k[o]=i;
				o++;
			}
			}
		}
	}
			if(complete==true)
				break;
	}
	printf("\n");
//completing the order of time  //Removing duplicates
	int k1,j;
	for (i = 0; i < o; i++) 
	{
      for (j = i + 1; j < o;) 
	  {
         if (k[j] == k[i]) 
		 {
            for (k1 = j; k1 < o; k1++) 
			{
               k[k1] = k[k1 + 1];
            }
            o--;
         } 
		 else
            j++;
      }
    }
    raround(n,bt1,wt,tat);
   	printf("\n");
   	printf(" Round Robin Scheduling : ");
	for(i=0;i<o;i++)
	{
		printf("%d ",k[i]);
	}
	 for (int i=0; i<n; i++)
	 {
	 	total_wt = total_wt + wt[i];
       	total_tat = total_tat + tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\n",i,bt1[i],wt[i],tat[i]);
	 }
	 float kq=total_wt/n;
	 float kw=total_tat/n;
	 printf("\n\n Average Waiting time : %f",kq);
	 printf("\n\n Average Turnaround time : %f",kw);
	 printf("\n\n\n");
}

void prior(int bt[],int pr[], int n,int p[])
{
	int i,j,temp,pos;
	int tat[200],total=0,wt[200];
	float avg_wt=0,avg_tat=0;
	    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
    avg_wt=total/n;
	printf("\n Priority Scheduling gives : ");
	    for (i = 0 ; i <  n; i++)
        printf("%d ",p[i]);
        for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     
        total+=tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    avg_tat=total/n;   
    printf("\n\n Average Waiting Time : %f",avg_wt);
    printf("\n\n Average Turnaround Time : %f",avg_tat);
    printf("\n\n\n");
}
void *fcfsar( int processes[], int n,int bt[], int wt[], int tat[])
{
    for (int  i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}
void firstcome(int bt2[],int wt[],int n)
{
	int i,p[200],tat[200],total=0;
	float avg_tat=0,avg_wt=0,total_wt=0,total_tat=0;
    wt[0] = 0;
    for (i = 1; i < n ; i++ )
        wt[i] =bt2[i-1] + wt[i-1];
    fcfsar(p,n,bt2,wt,tat);
    printf("\n First Come First Serve : ");
    for(i=0;i<n;i++)
    {
    	p[i]=i;
    	printf("%d ",i);
	}
	
	for(i=0;i<n;i++)
	{
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\n",p[i],bt2[i],wt[i],tat[i]);
	}
	avg_tat=total_tat/n; 
	avg_wt=total_wt/n;    
    printf("\n\n Average Waiting Time : %f",avg_wt);
    printf("\n\n Average Turnaround Time : %f",avg_tat);
	printf("\n\n\n");
}
int main()
{
	int i,j,n,n1,n2,p[200],bt1[200],bt2[200],bt3[200],tq=4,wt[200],wt1[200],pr[200];
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
		printf("\n Enter the priority of process %d : ",i);
		scanf("%d",&pr[i]);
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
			round(bt1,tq,n,wt);
			prior(bt2,pr,n1,p);
			firstcome(bt3,wt,n2);
}
