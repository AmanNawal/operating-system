#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
int pid=fork();
if(pid>0)
{
exit(0);
}
else if(pid==0)
{
sleep(50);
}
}
