//Ubuntu (Linux Based) by Amit Singh 
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
int tq=4;
sem_t lo1,lo2,lo3;
int switcher=0,c1=0,c2=0,r1[200],r2[200],r3[200],u1,u2,u3;
float wait1=0,wait2=0,wait3=0,time1=0,time2=0,time3=0;
struct element
{
	int n,n1,n2;
	int bt[200],bt1[200],bt2[200],bt3[200],pr[200];
	int p[200],p1[200],p2[200];
	int wt[200];	
}*s,p;
void *round(struct element *s)
{
sem_wait(&lo1);
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
      for (int i = 0; i < s->n ; i++)
{
        tat[i] = s->bt1[i] + s->wt[i];
	switcher++;
	sleep(1);//jumping statements
}
   	printf("\n");
   	printf(" Round Robin Scheduling : ");
	for(i=0;i<o;i++)
	{
		printf("%d ",k[i]);
		r1[i]=k[i];
		u1++;
	}
printf("\n ID\tBurst Time\tWaiting Time\tTurnAround Time   --------Round Robin Execution");
	 for (int i=0; i<s->n; i++)
	 {
	 	total_wt = total_wt + s->wt[i];
      	total_tat = total_tat + tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\n",i,s->bt1[i],s->wt[i],tat[i]);
	 }
	 float kq=total_wt/s->n;
	 float kw=total_tat/s->n;
	 wait1=kq;
	 time1=kw;
	 printf("\n\n Average Waiting time : %f",kq);
	 printf("\n\n Average Turnaround time : %f",kw);
c1+=kq;
c2+=kw;
	 printf("\n\n\n");
sem_post(&lo1);
	 pthread_exit(NULL);
}
void *prior(struct element *s)
{
sem_wait(&lo2);
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
{
            s->wt[i]+=s->bt2[j];
} 
        total+=s->wt[i];
    }
    avg_wt=total/n;

	printf("\n Priority Scheduling gives : ");
	    for (i = 0 ; i <  n; i++)
{
        printf("%d ",s->p1[i]);
	r2[i]=s->p1[i];
	u2++;
}
        for(i=0;i<n;i++)
    {
        tat[i]=s->bt1[i]+s->wt[i];     
	if(tat[i]%10<5)
{
if(tat[i]<10)
{
continue;
}
else
{
switcher++;
sleep(1);
}
}
printf("\n Priority\tID\tBurst Time\tWaiting Time\tTurnAround Time   --------Priority Wise Execution");
        total+=tat[i];
        printf("\n Details : %d\t%d\t%d\t%d\t%d\n",s->pr[i],s->p1[i],s->bt1[i],s->wt[i],tat[i]);
    }
    avg_tat=total/n;   
    wait2=avg_wt;
    time2=avg_tat;
    printf("\n\n Average Waiting Time : %f",avg_wt);
    printf("\n\n Average Turnaround Time : %f",avg_tat);
c1+=avg_wt;
c2+=avg_tat;
    printf("\n\n\n");
sem_post(&lo2);
    pthread_exit(NULL);
}
void *firstcome(struct element *s)
{
sem_wait(&lo3);
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
	r3[i]=i;
u3++;
    	printf("%d ",i);
	}
	
	for(i=0;i<n;i++)
	{
        total_wt = total_wt + s->wt[i];
        total_tat = total_tat + tat[i];
	if((int)total_wt%10<5)
{
	if(total_wt<10)
{
continue;
}
else
{
switcher++;
sleep(1);
}
}
printf("\n ID\tBurst Time\tWaiting Time\tTurnAround Time   --------FCFS Execution");
        printf("\n Details : %d\t%d\t%d\t%d\n",s->p2[i],s->bt3[i],s->wt[i],tat[i]);
	}
	avg_tat=total_tat/n; 
	avg_wt=total_wt/n;    
    printf("\n\n Average Waiting Time : %f",avg_wt);
    printf("\n\n Average Turnaround Time : %f",avg_tat);
	printf("\n\n\n");
c1+=avg_wt;
c2+=avg_tat;
wait3=avg_wt;
time3=avg_tat;
sem_post(&lo3);
	pthread_exit(NULL);
}
int main()
{
sem_init(&lo1,0,1);
sem_init(&lo2,0,1);
sem_init(&lo3,0,1);
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
	for(i=0;i<s->n2;i++)//t
	{
		s->p2[i]=i;
		printf("\n Enter the burst time of process %d : ",i);
		scanf("%d",&s->bt3[i]);
	}
			sem_wait(&lo3);
			sem_wait(&lo2);
			pthread_create(&p1,NULL,round,s);
			sem_post(&lo2);
			sem_post(&lo3);//a
			sleep(1);
			pthread_create(&p2,NULL,prior,s);
			sleep(1);			
			pthread_create(&p3,NULL,firstcome,s);
			pthread_join(p1,NULL);//join
			pthread_join(p2,NULL);
			pthread_join(p3,NULL);//i
printf("\n\n\n\n");
printf("\n1 > Total Sum of All the Avg Waiting Time of Queues : %d",c1);
printf("\n2 > Total Sum of All the Avg Turn Around Time of Queues : %d",c2);
printf("\n3 > Total Waiting Time in over all queue is : %f",(float)c1/3);
printf("\n4 > Total Turn Around Time in over all program : %f",(float)c2/3);
printf("\n5 > Total Switching in program : %d\n\n",switcher);
printf("\n6 > Round Robin Order Execution (Pids)-> ");
for(i=0;i<u1;i++)
printf("%d - ",r1[i]);
printf("\n- > Avg Waiting Time -> %f",wait1);
printf("\n- > Avg Turn Around Time -> %f",time1);
printf("\n7 > Priority Scheduling Order Execution (Pids) -> ");
for(i=0;i<u2;i++)//m
printf("%d - ",r2[i]);
printf("\n- > Avg Waiting Time -> %f",wait2);
printf("\n- > Avg Turn Around Time -> %f",time2);
printf("\n8 > First Come First Serve (Pids) -> ");
for(i=0;i<u3;i++)
printf("%d - ",r3[i]);
printf("\n- > Avg Waiting Time -> %f",wait3);
printf("\n- > Avg Turn Around Time -> %f",time3);
printf("\n\n\n\n");
}
