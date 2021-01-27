#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


int main(){
	
    time_t t1, t2, t3, t4, t5, t6, t7, t8, t9, tempo;
    struct tm *tm_ptr;
    time(&tempo);
    tm_ptr = localtime(&tempo);

	//Criação do pai
    std::cout << "Eu sou o pai, de PID: " << getpid() << "." << std::endl;
    std::cout << "E acabei de nascer " << "às " << tm_ptr->tm_hour << ":" << tm_ptr->tm_min << ":" << tm_ptr->tm_sec << "." << std::endl;
 
    t1 = time(NULL);
    sleep(14);

    pid_t pid;
    pid = fork();
   
    
    if (pid < 0) {

    	fprintf(stderr, "Criação Falhou!!");
        exit(-1);
    }

    else if (pid == 0) {
        
        //Criação do filho1
        t2 = time(NULL);
        time(&tempo);
        tm_ptr = localtime(&tempo);
        
        std::cout << "Olá, eu sou o filho1, de PID: " << getpid() << " e acabei de nascer " << "às " << tm_ptr->tm_hour << ":" << tm_ptr->tm_min << ":" << tm_ptr->tm_sec << "." << std::endl;
        std::cout <<"Sou filho de: " << getppid() << ", que foi pai aos " << t2-t1 << " anos." << std::endl;
   
        sleep(12);

        pid = fork();

        if (pid < 0) {

            fprintf(stderr, "Criação Falhou!!");
            exit(-1);

        }

        else if (pid == 0) {
            
            //Criação do neto1 
            t4 = time(NULL);
            time(&tempo);
            tm_ptr = localtime(&tempo);

            std::cout << "Olá, eu sou o neto1, de PID:" << getpid() << " e acabei de nascer " << "às " << tm_ptr->tm_hour << ":" << tm_ptr->tm_min << ":" << tm_ptr->tm_sec << "." << std::endl;
            std::cout <<"Sou filho de: " << getppid() << "." <<  std::endl;
            std::cout << "O pai1 foi avô aos " << t4-t1 << " anos." << std::endl;           

            
            sleep(12); 

            //Morte do neto1
            t5 = time(NULL);

            std::cout << "Olá, eu sou o neto1, de PID: " << getpid() << " e estou morrendo aos " << t5-t4 << " anos." << std::endl;
            std::cout << "Morri =(." << std::endl;
            exit(0);                    

        }

        else {

            //Morte do filho1
            sleep(18);
            t3 = time(NULL);

            std::cout << "Olá, eu sou o filho1, de PID: " << getpid() << " e estou morrendo aos " << t3-t2 << " anos." << std::endl;
            std::cout << "Morri =(." << std::endl;
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
            t6 = time(NULL); 
            time(&tempo);
            tm_ptr = localtime(&tempo);

            std::cout << "Olá, eu sou o filho2, de PID: " << getpid() << " e acabei de nascer " << "às " << tm_ptr->tm_hour << ":" << tm_ptr->tm_min << ":" << tm_ptr->tm_sec << "." << std::endl;
            std::cout <<"Sou filho de: " << getppid() << ", que foi pai aos " << t6-t1 << " anos." << std::endl;
                      
            sleep(14);

            pid = fork();

            if (pid < 0) {

                fprintf(stderr, "Criação Falhou!!");
                exit(-1);

            }

            else if (pid == 0) {

                //Criação do neto2
                t8 = time(NULL); 
                time(&tempo);
                tm_ptr = localtime(&tempo);

                std::cout << "Olá, eu sou o neto2, de PID:" << getpid() << " e acabei de nascer " << "às " << tm_ptr->tm_hour << ":" << tm_ptr->tm_min << ":" << tm_ptr->tm_sec << "." << std::endl;
                std::cout <<"Sou filho de: " << getppid() << "." <<  std::endl;
                std::cout << "O pai1 foi avô aos " << t8-t1 << " anos." << std::endl;      

               
                sleep(18); 

                //Morte do neto2
                t9 = time(NULL);

                std::cout << "Olá, eu sou o neto2, de PID: " << getpid() << " e estou morrendo aos " << t9-t8 << " anos." << std::endl;
                std::cout << "Morri =(." << std::endl;
                exit(0);    

            }
            
            else {

            //Morte do filho2
            sleep(16);
            t7 = time(NULL);

            std::cout << "Olá, eu sou o filho2, de PID: " << getpid() << " e estou morrendo aos " << t7-t6 << " anos." << std::endl;
            std::cout << "Morri =(." << std::endl;
            exit(0); 

            }  


        }

        else {

            //Morte do pai
        	sleep(44);
            t2 = time(NULL);

        	std::cout << "Olá, eu sou o pai, de PID: " << getpid() << " e estou morrendo aos " << t2-t1 << " anos." << std::endl;
            std::cout << "Morri =(." << std::endl;
            exit(0);  

        }
    }    

    return 0;
    
}
