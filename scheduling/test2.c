#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv){
	int pid;
	int mypid;

	setnice(1, 19);
	setnice(getpid(), 2);

	pid = fork();

	if(pid == 0){	//Child
		printf(1, "##### State 2 #####\n");
	}
	else{			//Parent
		setnice(pid, 10);	//Set nice value of Child
		printf(1, "##### State 1 #####\n");
		wait();				//Scheduling
		printf(1, "##### State 3 #####\n");
	}

	mypid = getpid();
	printf(1, "PID %d is finished\n", mypid);

	exit();
}

