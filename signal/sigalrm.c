
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int count = 0;

void handler(int n) {
	if (count < 10) {
		count++;
		printf("The count is %d\n",count);

	}
	else {
		printf("ending the program After 10 alarm Signal. \n");
		exit(0);
	}


}
int main() {

	struct sigaction sa;
	sa.sa_handler = handler;

	if (sigaction(SIGALRM, &sa, NULL) == -1 ){
		perror("sigaction");
		return 1;
	}


	while(1)
	{
		printf("Running Proces -> %d\n",getpid());
		// sleep(1);
		alarm(1);
		pause();
		// alarm(1);
	}


	return 0;

}
