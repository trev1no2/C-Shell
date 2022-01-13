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

char *getUserInput(){
	char *buf = malloc(4096);
	if(!buf){perror("MALLOC ERROR\n"); exit(0);}
	//Inside the actual shell loop. From here, we need to
	//1. Read the command from std in 
		//DONE
	//2. Separate the command into the actual program and its arguments
	//3. Execute the command w/ arguments
	printf("> ");
	fgets(buf, 4096, stdin);
	buf[strlen(buf)-1] = '\0';
	return buf;
}

void executeCommand(char **commandArgs){
	
	pid_t pid = fork();

	if(pid == -1){
		printf("Fork Failed, enter command again\n");
		return;
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
		return;
	}

}

int main(int argc, char *argv[]){
	
	//print intro to shell
	printintro();
	
	while(1){
	
	//----------//
		//1. Get user Input
		char *userInput = getUserInput();
		//uncomment for user input debugging
		//printf("{%s}\n" , userInput);
		
	//----------//
		int c;
		//2. Parsing user input
		char * token;
		char * array[4096];
		memset(array, 0, sizeof(array));
		
		for(c = 0; c < 100; c++){
			array[c] = strsep(&userInput, " ");
			if(array[c] == NULL)
				break;
			if(strlen(array[c]) == 0)
				c--;
		}
//		int i = 0;
//		array[i] = strtok(userInput, " ");
//
//		while(array[i] != NULL){
//			array[++i] = strtok(NULL, " ");
//		}
		
	//----------//
		//3. executing the command
		executeCommand(array);
		
	}//end of while loop
	return 0;
}
