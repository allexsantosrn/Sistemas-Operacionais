#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
	
	//Criação do pai
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
        
        //Criação do filho1
        std::cout << "Olá, eu sou o filho1, de PID:" << getpid() << " e acabei de nascer." << std::endl;
        std::cout <<"Sou filho de: " << getppid() << std::endl;
        sleep(12);

        pid = fork();

        if (pid < 0) {

            fprintf(stderr, "Criação Falhou!!");
            exit(-1);

        }

        else if (pid == 0) {
            
            //Criação do neto1 
            std::cout << "Olá, eu sou o neto1, de PID:" << getpid() << " e acabei de nascer." << std::endl;
            std::cout <<"Sou filho de: " << getppid() << std::endl;
            sleep(12); 

            //Morte do neto1
            std::cout << "Olá, eu sou o neto1, de PID: " << getpid() << " e estou morrendo." << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0);                    

        }

        else {

            //Morte do filho1
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
            
            //Criação do filho2 
            std::cout << "Olá, eu sou o filho2, de PID:" << getpid() << " e acabei de nascer." << std::endl;
            std::cout <<"Sou filho de: " << getppid() << std::endl;             
            sleep(14);

            pid = fork();

            if (pid < 0) {

                fprintf(stderr, "Criação Falhou!!");
                exit(-1);

            }

            else if (pid == 0) {

                //Criação do neto2
                std::cout << "Olá, eu sou o neto2, de PID:" << getpid() << " e acabei de nascer." << std::endl;
                std::cout <<"Sou filho de: " << getppid() << std::endl;
                sleep(18); 

                //Morte do neto2
                std::cout << "Olá, eu sou o neto2, de PID: " << getpid() << " e estou morrendo." << std::endl;
                std::cout << "Morri =(" << std::endl;
                exit(0);    

            }
            
            else {

            //Morte do filho2
            sleep(16);    
            std::cout << "Olá, eu sou o filho2, de PID: " << getpid() << " e estou morrendo." << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0); 

            }  


        }

        else {

            //Morte do pai
        	sleep(44);
        	std::cout << "Olá, eu sou o pai, de PID: " << getpid() << " e estou morrendo." << std::endl;
            std::cout << "Morri =(" << std::endl;
            exit(0);  

        }
    }    

    return 0;
    
}
