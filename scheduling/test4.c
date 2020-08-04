#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv){
	int pid1;
	int pid2;
	int i, j, k;
	int mypid;

	setnice(1, 19);
	setnice(getpid(), 2);

	pid1 = fork();

	if(pid1 == 0){
		for(i = 0; i < 10; i++){
			printf(1, "##### State %d #####\n", (i*3)+2);
			yield();
		}
	}
	else{
		pid2 = fork();

		if(pid2 == 0){
			for(j = 0; j < 10; j++){
				printf(1, "##### State %d #####\n", (j*3)+3);
				yield();
			}
		}
		else{
			for(k = 0; k < 10; k++){
				printf(1, "##### State %d #####\n", (k*3)+1);
				yield();
			}
		}
	}

	mypid = getpid();
	printf(1, "PID %d is finished\n", mypid);

	exit();
}

