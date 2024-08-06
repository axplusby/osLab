#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int num) {
	printf("\nCtrl + c signal encountered!\n");
	exit(0);

}
int main() {

	signal(SIGINT,handler);

	while(1)
	{
		printf("Running process -> %d\n",getpid());
		sleep(2);
	}


	return 0;

}
