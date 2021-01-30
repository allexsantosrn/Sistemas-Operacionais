#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

using namespace std;

void nascimento(string nome){
    time_t tempo;
    struct tm *horariolocal;
    time(&tempo);
    horariolocal = localtime(&tempo);

    cout<< nome << " nasceu as " << horariolocal->tm_hour << ":" << horariolocal->tm_min << ":" << 
        horariolocal->tm_sec << endl;
    cout << "Meu PID=" << getpid() << " e meu pai tem o PID=" << getppid() << endl;
}

void morte(string nome, time_t nascimento, time_t morte){
    time_t tempo;
    struct tm *horariolocal;
    time(&tempo);
    horariolocal = localtime(&tempo);

    cout << nome << " de PID: " << getpid() << " e estou morrendo aos " << nascimento - morte << " anos." << endl;
    cout << "Morri as "<< horariolocal->tm_hour << ":" << horariolocal->tm_min << ":" << horariolocal->tm_sec << "." << endl;
}


int main(){
	
    time_t tempo[10];

	//Criação do pai
    nascimento("Pai");
    cout << endl;
    tempo[1] = time(0);

    sleep(14);

    //Criando o Filho1
    pid_t pid;
    pid = fork();
 
    if (pid < 0) {
    	fprintf(stderr, "Criação Falhou!!");
        exit(-1);
    }

    else if (pid == 0) {
        //Filho1 criado
        tempo[2] = time(0);
        nascimento("Filho1");
        cout << endl;
   
        sleep(12);

        //Criando o Neto1
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Criação Falhou!!");
            exit(-1);
        }

        else if (pid == 0) {
            
            //Neto1 criado
            tempo[4] = time(0);
            nascimento("Neto1");
            cout << endl;        

            sleep(12); 

            //Morte do Neto1
            tempo[5] = time(0);
            morte("Neto1", tempo[5], tempo[4]);
            cout << endl;
            exit(0);                    
        }

        else {

            //Morte do Filho1
            sleep(18);
            tempo[3] = time(0);
            morte("Filho1", tempo[3], tempo[2]);
            cout << endl;
            exit(0);          
        }           	
    }

    else {
        sleep(2);

        //Criando o Filho2 
        pid = fork();

        if (pid < 0) {
            fprintf(stderr, "Criação Falhou!!");
            exit(-1);
        }

        else if (pid == 0) {
            //Filho 2 criado
            tempo[6] = time(0); 
            nascimento("Filho2");
            cout << endl;
                      
            sleep(14);

            //Criando Neto2
            pid = fork();

            if (pid < 0) {
                fprintf(stderr, "Criação Falhou!!");
                exit(-1);
            }

            else if (pid == 0) {
                //Neto2 criado
                tempo[8] = time(0); 
                nascimento("Neto2");
                cout << endl;
                sleep(18); 

                //Morte do Neto2
                tempo[9] = time(0);
                morte("Neto2", tempo[9], tempo[8]);
                cout << endl;
                exit(0);                   
            }
            
            else {
            //Morte do Filho2
            sleep(16);
            tempo[7] = time(0);
            morte("Filho2", tempo[7], tempo[6]);    
            cout << endl;        
            exit(0); 
            }  


        }

        else {
            //Morte do Pai
        	sleep(44);
            tempo[2] = time(0);
            morte("Pai", tempo[2], tempo[1]);  
            cout << endl;        
            exit(0);  
        }
    }    

    return 0; 
}