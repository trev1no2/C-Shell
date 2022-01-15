#include <stdio.h>
#include <string.h>  //strlen()
#include <stdlib.h>  //malloc()
#include <unistd.h>  //execvp()
#include <sys/wait.h>//wait()

int printintro(){
	printf("\n*****************************************\n");
	printf("*\t\t\t\t\t*\n");
       	printf("* \t Welcome to my C Shell! \t*\n");
	printf("*\t\t\t\t\t*\n");
	printf("*****************************************\n");
	}

void executeCommand(char **commandArgs){
	
	pid_t pid = fork();

	if(pid == -1){
		printf("Fork Failed, enter command again\n");
	}
	if(pid == 0){//child
		//execute command here using execvp or execute file
		//int execvp(const char *file, char *const argv[]);
		int returnValue;
		returnValue = execvp(commandArgs[0], commandArgs);
		if (returnValue < 0)
			printf("Error retrieving command...\n");
		exit(0);
	}
	if(pid > 0){//parent
		wait(NULL);
		//return;
	}
	return;
}

int main(int argc, char *argv[]){
	
	//print intro to shell
	printintro();
	
	while(1){
	
	//----------//
		//1. Get user Input
		char *buf = malloc(4096);
		if(!buf){perror("MALLOC ERROR\n"); exit(0);}
		printf("> ");
		fgets(buf, 4096, stdin);
		buf[strlen(buf)-1] = '\0';
		//uncomment for user input debugging
		//printf("{%s}\n" , userInput);
	//----------//
		int c;
		//2. Parsing user input
		char *token;
		char *array[4096];
		for(c = 0; c < 100; c++){
			array[c] = strsep(&buf, " ");
			if(array[c] == NULL)
				break;
			if(strlen(array[c]) == 0)
				c--;
		}
		//uncomment to print out the command entered
		//for(int i = 0; i < 5; i++){printf("<%s>\n",array[i]);}
		char * exit = "exit";
		if(!strcmp(array[0], exit)){return 0;}
	//----------//
		//3. executing the command
		executeCommand(array);
		free(buf);
	}//end of while loop
	return 0;
}
