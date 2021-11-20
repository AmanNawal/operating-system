#include<stdio.h>

struct process
{
int at,bt,ct,tat,start_time,status,wt,rt,rem_time;
}ps[100];



int findmn(int n,int currenttime)
{
int mn=-1;
int mini=100000;

for(int i=0;i<n;i++)
{
if(ps[i].at<=currenttime)
{
if(ps[i].status==0 && ps[i].rem_time<mini)
{
mini=ps[i].rem_time;
mn=i;
}
else if(ps[i].status==0 && ps[i].rem_time==mini)
{
if(ps[i].at<ps[mn].at)
{
mini=ps[i].rem_time;
mn=i;
}
}
}
}
return mn;
}

int main()
{
int n;
scanf("%d",&n);

printf("At\n");
for(int i=0;i<n;i++)
scanf("%d",&ps[i].at);

printf("bt\n");
for(int i=0;i<n;i++)
{
scanf("%d",&ps[i].bt);
ps[i].rem_time=ps[i].bt;
}
int completed=0;
int currenttime=0;
int idealtime=0;
int firstprocess=1;
int prev=0;

while(completed!=n)
{
int mn=findmn(n,currenttime);
if(mn!=-1)
{
if(ps[mn].rem_time==ps[mn].bt)//
{
ps[mn].start_time=currenttime;
if(firstprocess==1)
{

firstprocess=0;

}
else
{
idealtime+=ps[mn].start_time-prev;
}
}

prev=currenttime;
ps[mn].rem_time-=1;
currenttime++;
prev=currenttime;
if(ps[mn].rem_time==0)
{
ps[mn].ct=currenttime;
ps[mn].tat=ps[mn].ct-ps[mn].at;
ps[mn].wt=ps[mn].tat-ps[mn].bt;
ps[mn].rt=ps[mn].start_time-ps[mn].at;
completed++;
ps[mn].status=1;  //


}
}
else
{
currenttime++;
}
}
printf("AT  BT  CT  TAT  WT  RT:\n");
for(int i=0;i<n;i++)
{
printf("%d   %d   %d   %d   %d   %d:\n",ps[i].at,ps[i].bt,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
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
float cpu_utilization=(float)(length_cycle-idealtime)/length_cycle;
printf("%.2f cpu_utilization %d idealtime\n",cpu_utilization,idealtime);
}
