#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv){
	int pid;
	int ppid;
	int mypid;

	setnice(1, 19);
	setnice(getpid(), 10);

	ppid = getpid();
	pid = fork();

	if(pid == 0){
		printf(1, "##### State 2 #####\n");
		setnice(ppid, 2);
		printf(1, "##### State 4 #####\n");
	}
	else{
		printf(1, "##### State 1 #####\n");
		setnice(pid, 5);
		printf(1, "##### State 3 #####\n");
	}

	mypid = getpid();
	printf(1, "PID %d is finished\n", mypid);

	exit();
}

