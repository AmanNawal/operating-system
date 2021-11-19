#include<stdio.h>
struct process
{
int at,bt,wt,tat,ct,rt,start_time,status;
}ps[100];

int minindex(int currenttime,int n)
{
int mn=-1;
int mini=10000;
for(int i=0;i<n;i++)
{
printf("at   %d    currenttime  %d\n",ps[i].at,currenttime);
if(ps[i].at<=currenttime)
{

if(ps[i].status==0 && ps[i].bt<mini)
{

mini=ps[i].bt;
mn=i;
}

else if(ps[i].status==0 && ps[i].bt==mini)
{
if(ps[i].at<ps[mn].at)
{
mini=ps[i].bt;
mn=i;
}
}
}
}

printf("%d:\n",mn);
return mn;
}

int main()
{
int n;
scanf("%d",&n);
printf("enter arrival time:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&ps[i].at);
ps[i].status=0;
}

printf("enter burst time:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&ps[i].bt);
}

int currenttime=0;
int completed=0;
int firstprocess=1;
int idealtime=0;
int prev=0;
while(completed!=n)
{
int mn=minindex(currenttime,n);

if(mn!=-1)
{

ps[mn].start_time=currenttime;
ps[mn].ct=ps[mn].start_time+ps[mn].bt;
ps[mn].tat=ps[mn].ct-ps[mn].at;
ps[mn].wt=ps[mn].tat-ps[mn].bt;
ps[mn].rt=ps[mn].wt;
ps[mn].status=1;
currenttime=ps[mn].ct;
completed++;
if(firstprocess==1)
{
firstprocess=0;
}
else
{
idealtime+=ps[mn].start_time-prev;
}

prev=ps[mn].ct;
}
else
{

currenttime++;
}


}
int lifecycle;
int mnn=10000,mxx=-1221;
for(int i=0;i<n;i++)
{
if(ps[i].at<mnn)
{
mnn=ps[i].at;
}
if(ps[i].ct>mxx)
{
mxx=ps[i].ct;
}
}
lifecycle=mxx-mnn;
float cpu_utilization=(float)(lifecycle-idealtime)/lifecycle;
printf("%.2f cpu_utilization %d idealtime\n",cpu_utilization,idealtime);

for(int i=0;i<n;i++)
{
printf("%d     %d     %d     %d     %d     %d   \n",ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
}
}
