#include "types.h"
#include "stat.h"
#include "user.h"

int dump[10000000];

int
main(int argc, char **argv)
{
	int i;
	int pid;
	int before, after;

	printf(1, "TEST4: ");

	for(i=0;i<10;i++){
		before = freemem();
		pid = fork();
		if(pid == 0)
			break;
		after = freemem();

		if(before - after == 1){
			printf(1, "WRONG\n");
			exit();
		}
	}

	if(pid > 0)
		sleep(100);

	if(pid == 0){
		exit();
	}
	else{
		for(i=0;i<10;i++)
			wait();
		printf(1, "OK\n");
	}

	exit();
}
