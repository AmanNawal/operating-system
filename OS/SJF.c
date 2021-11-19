#include<stdio.h>

struct process
{
int at,bt,tat,wt,ct,start_time,rt;
int status;
}ps[100];



int minindex(int n,int sz)
{


int mn=-1;
int minimum=1000000;

for(int i=0;i<sz;i++)
{

if(ps[i].at<=n)
{
if(ps[i].status==0 && ps[i].bt<minimum)
{
minimum=ps[i].bt;
mn=i;
}


else if(ps[i].bt==minimum && ps[i].status==0)
{
if(ps[i].at<ps[mn].at)
{
mn=i;
minimum=ps[i].bt;
}

}
}
}
return mn;
}




void main()
{
int n;
printf("enter total number of processes:\n");
scanf("%d",&n);

printf("enter the arrival time:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&ps[i].at);
ps[i].status=0;
}

printf("enter the burst time:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&ps[i].bt);
}

int completed=0;
int currenttime=0;
int idealtime=0;
int firstprocess=1;
int start_time=0;
int prev;
while(completed!=n)
{
int mn=minindex(currenttime,n);
if(mn!=-1)
{
printf("mn %d ps[mn].at %d currenttime %d",mn,ps[mn].at,currenttime);

printf("\n");
ps[mn].start_time=currenttime;
ps[mn].ct=ps[mn].start_time+ps[mn].bt;
ps[mn].tat=ps[mn].ct-ps[mn].at;
ps[mn].wt=ps[mn].tat-ps[mn].bt;
ps[mn].rt=ps[mn].wt;
currenttime=ps[mn].ct;
ps[mn].status=1;

completed++;
if(firstprocess==1)
{
idealtime=0;
firstprocess=0;

}
else
{
idealtime+=ps[mn].start_time-prev;
}
prev=currenttime;
}
else
{
currenttime++;
//printf("DONE");

}
}
int maxx=-1;
int minn=10000;
for(int i=0;i<n;i++)
{
if(ps[i].ct>maxx)
{
maxx=ps[i].ct;
}
if(ps[i].at<minn)
{
minn=ps[i].at;
}
}

int length_cycle=maxx-minn;
int cpu_utilization=(length_cycle-idealtime)/length_cycle;
printf("%d cpu_utilization %d idealtime\n",cpu_utilization,idealtime);

for(int i=0;i<n;i++)
{
printf("%d     %d     %d     %d     %d     %d   \n",ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
}

}
