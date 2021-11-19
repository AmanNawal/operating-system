#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int pid=fork();

if(pid>0)                  
{
//printf("id parent process %d ",getpid());             //parent process sleeps
sleep(50);
//printf("zombie\n");
}
else                                                  //child process becomes zombie because parent process is sleeping
{
//printf("id parent process %d ",getppid());
exit(0);
}
}


//  ./a.out & -> parent processid
//   pstree -p parentaddress -> child process
//   ps aux | grep childprocessid  ->tells us zombie or not
