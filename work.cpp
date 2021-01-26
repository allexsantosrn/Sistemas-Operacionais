#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
	
	
    std::cout << "Eu sou o pai, de PID: " << getpid() << std::endl;
    std::cout << "E acabei de nascer =D" << std::endl;
    sleep(14);
    
    pid_t pid;
    pid = fork();
   
    
    if (pid < 0) {

    	fprintf(stderr, "Criação Falhou!!");
        exit(-1);
    }

    else if (pid == 0) {
        
        std::cout << "Olá, eu sou o filho1, de PID:" << getpid() << " e acabei de nascer." << std::endl;
        std::cout <<"Sou filho de: " << getppid() << std::endl;
        sleep(12);

        pid = fork();

        if (pid < 0) {

            fprintf(stderr, "Criação Falhou!!");
            exit(-1);

        }

        else if (pid == 0) {
             
            std::cout << "Olá, eu sou o neto1, de PID:" << getpid() << " e acabei de nascer." << std::endl;
            std::cout <<"Sou filho de: " << getppid() << std::endl;
            sleep(12); 
            std::cout << "Olá, eu sou o neto1, de PID: " << getpid() << " e estou morrendo!!" << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0);                    

        }

        else {

            sleep(18);
            std::cout << "Olá, eu sou o filho1, de PID: " << getpid() << " e estou morrendo." << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0);          

        }     
       
           	
    }

    else {

        sleep(2);

        pid = fork();

        if (pid < 0) {

            fprintf(stderr, "Criação Falhou!!");
            exit(-1);

        }

        else if (pid == 0) {
             
            std::cout << "Olá, eu sou o filho2, de PID:" << getpid() << " e acabei de nascer." << std::endl;
            std::cout <<"Sou filho de: " << getppid() << std::endl;             
            sleep(14);

            pid = fork();

            if (pid < 0) {

                fprintf(stderr, "Criação Falhou!!");
                exit(-1);

            }

            else if (pid == 0) {

                std::cout << "Olá, eu sou o neto2, de PID:" << getpid() << " e acabei de nascer." << std::endl;
                std::cout <<"Sou filho de: " << getppid() << std::endl;
                sleep(18); 
                std::cout << "Olá, eu sou o neto2, de PID: " << getpid() << " e estou morrendo!!" << std::endl;
                std::cout << "Morri =(" << std::endl;
                exit(0);    

            }
            
            else {

            sleep(16);    
            std::cout << "Olá, eu sou o filho2, de PID: " << getpid() << " e estou morrendo." << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0); 

            }  


        }

        else {

        	sleep(44);
        	std::cout << "Olá, eu sou o pai, de PID: " << getpid() << " e estou morrendo!!" << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0);  

        }
    }    

    return 0;
    
}
