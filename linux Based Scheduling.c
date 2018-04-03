//Ubuntu (Linux Based)
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int tq=4;
struct element
{
	int n,n1,n2;
	int bt[200],bt1[200],bt2[200],bt3[200],pr[200];
	int p[200],p1[200],p2[200];
	int wt[200];	
}*s,p;
void *round(struct element *s)
{
	
	int i,cp[200];
	int pid=0;
	int k[200],o=0;
	int bt2[200];
	int complete=1;
	int tat[200];
	int total_wt=0;
	int total_tat=0;
	for(i=0;i<s->n;i++)
	{
		cp[i]=s->bt1[i];
	}
		for(i=0;i<s->n;i++)
	{
		bt2[i]=s->bt1[i];
	}
	int t=0;
	while(5>3)
	{
	    complete=1;
		for(i=0;i<s->n;i++)
		{
			if(cp[i]>0)
			{
			complete=0;
			if(cp[i]>tq)
			{
				t+=tq;
				cp[i]-=tq;
			}
			else
			{
				t=t+cp[i];
				s->wt[i]=t-bt2[i];
				cp[i]=0;
			if(cp[i]==0)
			{
				k[o]=i;
				o++;
			}
			}
		}
	}
			if(complete==1)
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
  //  raround(n,bt1,wt,tat);
      for (int i = 0; i < s->n ; i++)
        tat[i] = s->bt1[i] + s->wt[i];
   	printf("\n");
   	printf(" Round Robin Scheduling : ");
	for(i=0;i<o;i++)
	{
		printf("%d ",k[i]);
	}
	 for (int i=0; i<s->n; i++)
	 {
	 	total_wt = total_wt + s->wt[i];
      	total_tat = total_tat + tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\n",i,s->bt1[i],s->wt[i],tat[i]);
	 }
	 float kq=total_wt/s->n;
	 float kw=total_tat/s->n;
	 printf("\n\n Average Waiting time : %f",kq);
	 printf("\n\n Average Turnaround time : %f",kw);
	 printf("\n\n\n");
	 pthread_exit(NULL);
}
void *prior(struct element *s)
{
	int i,j,temp,pos;
	int tat[200],total=0,wt[200];
	float avg_wt=0,avg_tat=0;
	int n=s->n1;
	    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(s->pr[j]<s->pr[pos])
                pos=j;
        }
 
        temp=s->pr[i];
        s->pr[i]=s->pr[pos];
        s->pr[pos]=temp;
 
        temp=s->bt2[i];
        s->bt2[i]=s->bt2[pos];
        s->bt2[pos]=temp;
 
        temp=s->p1[i];
        s->p1[i]=s->p1[pos];
        s->p1[pos]=temp;
    }
    for(i=0;i<n;i++)
    {
        s->wt[i]=0;
        for(j=0;j<i;j++)
            s->wt[i]+=s->bt2[j];
 
        total+=s->wt[i];
    }
    avg_wt=total/n;
	printf("\n Priority Scheduling gives : ");
	    for (i = 0 ; i <  n; i++)
        printf("%d ",s->p1[i]);
        for(i=0;i<n;i++)
    {
        tat[i]=s->bt1[i]+s->wt[i];     
        total+=tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\t%d\n",s->pr[i],s->p1[i],s->bt1[i],s->wt[i],tat[i]);
    }
    avg_tat=total/n;   
    printf("\n\n Average Waiting Time : %f",avg_wt);
    printf("\n\n Average Turnaround Time : %f",avg_tat);
    printf("\n\n\n");
    pthread_exit(NULL);
}
void *firstcome(struct element *s)
{
	int i,p[200],tat[200],total=0;
	float avg_tat=0,avg_wt=0,total_wt=0,total_tat=0;
	int n=s->n2;
    s->wt[0] = 0;
    for (i = 1; i < n ; i++ )
        s->wt[i] =s->bt3[i-1] + s->wt[i-1];
       for (int  i = 0; i < n ; i++)
        tat[i] = s->bt3[i] + s->wt[i];
    printf("\n First Come First Serve : ");
    for(i=0;i<n;i++)
    {
    	s->p2[i]=i;
    	printf("%d ",i);
	}
	
	for(i=0;i<n;i++)
	{
        total_wt = total_wt + s->wt[i];
        total_tat = total_tat + tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\n",s->p2[i],s->bt3[i],s->wt[i],tat[i]);
	}
	avg_tat=total_tat/n; 
	avg_wt=total_wt/n;    
    printf("\n\n Average Waiting Time : %f",avg_wt);
    printf("\n\n Average Turnaround Time : %f",avg_tat);
	printf("\n\n\n");
	pthread_exit(NULL);
}
int main()
{
	s=&p;
	pthread_t p1,p2,p3;
	int i,j;
	//n,n1,n2;
	//p[200],bt1[200],bt2[200],bt3[200],tq=4,wt[200],wt1[200],pr[200];
	int com[200];
	printf("\n>Enter the details of first queue(highest priority)");
	printf("\n Enter the number of process in first queue : ");
	scanf("%d",&s->n);
	for(i=0;i<s->n;i++)
	{
		s->p[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&s->bt1[i]);
	}
	printf("\n>Enter the details of second queue(medium priority)");
	printf("\n Enter the number of process in second queue : ");
	scanf("%d",&s->n1);
	for(i=0;i<s->n1;i++)
	{
		s->p1[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&s->bt2[i]);
		printf("\n Enter the priority of process %d : ",i);
		scanf("%d",&s->pr[i]);
	}
	printf("\n>Enter the details of third queue(third priority)");
	printf("\n Enter the number of process in third queue : ");
	scanf("%d",&s->n2);
	for(i=0;i<s->n2;i++)
	{
		s->p2[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&s->bt3[i]);
	}
			pthread_create(&p1,NULL,round,s);
			pthread_create(&p2,NULL,prior,s);
			pthread_create(&p3,NULL,firstcome,s);
			pthread_join(p1,NULL);
			pthread_join(p2,NULL);
			pthread_join(p3,NULL);
			//round(bt1,tq,n,wt);
			//prior(bt2,pr,n1,p);
}

