#include<stdio.h>
#include<unistd.h>
int main(){
    char * temp[3];
    temp[0] = "ls";
    temp[1] = "-l";
    temp[2] = NULL;
    // execv("/bin/ls", temp);
    execlp("/bin/ls", "ls", NULL); // a.out   execv.c
    printf("This statement won't print.");
    return 0;

    /*
     gcc execv.c 
    rajan@Rajans ~/g/o/execSysCall (main)> ls -l
    total 80
    -rwxr-xr-x@ 1 rajan  staff  33592 Jul 20 12:26 a.out*
    -rw-r--r--@ 1 rajan  staff    215 Jul 20 12:25 execv.c
    rajan@Rajans ~/g/o/execSysCall (main)> ./a.out
    total 80
    -rwxr-xr-x@ 1 rajan  staff  33592 Jul 20 12:26 a.out
    -rw-r--r--@ 1 rajan  staff    215 Jul 20 12:25 execv.c
    */
}