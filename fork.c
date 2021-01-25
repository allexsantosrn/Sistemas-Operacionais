#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	
	printf("Eu sou o pai: %d\n",getpid());
    pid_t pid;
    pid = fork();
    int i;

    
    if (pid < 0) {

    	perror("Erro!!!!!!\n");

    }

    else if (pid == 0) {

    	//Processo filho
    	printf("P0 - Número do Processo Filho: %d\n", getpid());
    	
    }

    else {

    	//Processo pai
    	printf("P1 - Número do Processo Pai: %d\n", getpid());
    	
    }

    return 0;
    
}
