#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
	printf("Eu sou o pai: %d\n",getpid());
    pid_t pid;
    pid = fork();
    
    
    if (pid < 0) {

    	fprintf(stderr, "Criação Falhou!!");
        exit(-1);
    }

    else if (pid == 0) {

    	//Processo filho
    	printf("P0 - Número do Processo Filho: %d\n", getpid()); 
        exit(0);       
    	
    }

    else {

    	//Processo pai
    	printf("P1 - Número do Processo Pai: %d\n", getpid());
        wait(NULL);
        printf("Processo Filho Finalizado \n");
        exit(0);
    	
    }

    return 0;
    
}
