#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

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
        for(;;);
    	
    }

    else {

    	//Processo pai
    	printf("P1 - Número do Processo Pai: %d\n", getpid());
        for(;;);
    	
    }

    return 0;
    
}
