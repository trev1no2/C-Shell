#include <stdio.h>
#include <string.h> //strlen()
#include <stdlib.h> //malloc()

int printintro(){
	printf("\n*****************************************\n");
	printf("*\t\t\t\t\t*\n");
       	printf("* \t Welcome to my C Shell! \t*\n");
	printf("*\t\t\t\t\t*\n");
	printf("*****************************************\n");
	}

char *getUserInput(){
	char *buf = (char *)malloc(4096);
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

char *getParsedInput(char *tmp){
	int i = 0; 
	char *array = (char *)malloc(4096);

//	array[i] = strtok(tmp, " ");

//	while (array[i] != NULL)
//		array[++i] = strtok(NULL, " ");
//
//	for (int i = 0; i < 5; i++){
//		printf("{%s}\n", array[i]);
//	}
	return array;
}



int main(int argc, char *argv[]){
	
	//print intro to shell
	printintro();
	
	while(1){
		char *userInput = getUserInput();
		printf("{%s}\n" , userInput);
		char *parsedInput = getParsedInput(userInput);
		
	}

}
