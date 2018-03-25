#include<stdio.h>
void round(int bt1[],int tq,int n,int wt[])
{
	int i,cp[200];
	int pid=0;
	int k[200],o=0;
	bool complete=true;
	for(i=0;i<n;i++)
	{
		cp[i]=bt1[i];
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
			}
			if(cp[i]>tq)
			{
				t+=tq;
				cp[i]-=tq;
			}
			else
			{
				t=t+cp[i];
				wt[i]=t-bt1[i];
				cp[i]=0;
				if(cp[i]==0)
				{
				k[o]=i;
				o++;
				}
			}
		}
			if(complete==true)
				break;
	}
	printf("\n");
//	for(i=0;i<o;i++)
//	{
//		printf("%d ",wt[i]);
//	}
//	printf("\n");
//	for(i=0;i<n;i++)
//	{
//		printf("%d ",k[i]);
//	}

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
   	printf("\n");
   	printf("Round Robin Schedulling : ");
	for(i=0;i<o;i++)
	{
		printf("%d ",k[i]);
	}

}
void firstcome(int bt2[],int wt[],int n)
{
	int i;
    wt[0] = 0;
    for (i = 1; i < n ; i++ )
        wt[i] =bt2[i-1] + wt[i-1];
    printf("\n First Come First Serve : ");
    for(i=0;i<n;i++)
    {
    	printf("%d ",i);
	}
}
int main()
{
	int i,j,n,n1,n2,p[200],bt1[200],bt2[200],bt3[200],tq=4,wt[200],wt1[200];
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
			round(bt1,tq,n,wt);
			firstcome(bt3,wt,n2);
}
