#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>


int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Usage: execl <int1>\n");
		exit(0);
	}
	
	pid_t pid;
	pid = fork();
	
	if(pid < 0){
		printf("Fork Failed\n");
		exit(0);
	}
	else if(pid == 0){
		printf("Child: \n");
		printf("Child Process id: %d\n", getpid());
		printf("Child Parent Process id: %d\n", getppid());
		execv("sum", argv);
		exit(0);		
	}
	else{
		wait(0);
		printf("\nParent: \n");
		printf("Parent Process id: %d\n", getpid());
		printf("Parent child Process id: %d\n", pid);
	}
	
	return 0;	
}
