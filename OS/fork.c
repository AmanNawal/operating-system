#include<stdio.h>
#include<unistd.h>  //consists of system calls succh as fork
#include<stdlib.h>
int main()
{
int p=fork();   //creates  processes in 2^n here two fork() functions are used so 2^2 =4 , 1 parent, 3 children 
int p2=fork();   //fork return 0 to the child process and +tive number to parent -tive in case of failure
if(p<0 || p2<0)
{
printf("failure in fork() system call\n");
exit(0);
}
else if(p==0 || p2==0)
{
//wait(NULL);
printf("child process id = %d\n",getpid());
}
else{
wait(NULL);         //makes our parent process wait until child process completes
printf("parent process id = %d\n",getpid());  //process id of calling process
}//getppid() process id of the parent

}
