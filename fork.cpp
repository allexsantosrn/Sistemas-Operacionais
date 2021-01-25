#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	
	std::cout << "Eu sou o pai, meu número de processo: " << getpid() << std::endl;;
    pid_t pid;
    pid = fork();
    int enter;

    
    if (pid < 0) {

    	std::cout << "Erro!!!";

    }

    else if (pid == 0) {

    	//Processo filho
       	std::cout << "P0 - Número do Processo Filho: " << getpid() << " ,sou filho de:  " << getppid() << std::endl;;
    	
    }

    else {

    	//Processo pai
    	std::cout << "P1 - Número do Processo Pai: " << getpid() << std::endl;
    	
    }


    std::cin >> enter;

    return 0;
    
}
