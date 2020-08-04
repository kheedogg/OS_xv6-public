#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv){
	int pid1;
	int pid2;
	int mypid;

	setnice(1, 19);
	setnice(getpid(), 2);

	pid1 = fork();

	if(pid1 == 0){	//Child
		printf(1, "##### State 4 #####\n");
	}
	else{			//Parent
		setnice(pid1, 10);
		printf(1, "##### State 1 #####\n");

		pid2 = fork();

		if(pid2 == 0){	//Grand-Child
			printf(1, "##### State 3 #####\n");
		}
		else{			//Parent
			setnice(pid2, 5);
			printf(1, "##### State 2 #####\n");
		}
	}

	mypid = getpid();
	printf(1, "PID %d is finished\n", mypid);

	exit();
}

