#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    
    printf("Eu sou o pai, de PID: %d\n",getpid());
    printf("E acabei de nascer!!\n");
    sleep(14);
    
    pid_t pid;
    pid = fork();
   
    
    if (pid < 0) {

        fprintf(stderr, "Criação Falhou!!");
        exit(-1);
    }

    else if (pid == 0) {


        printf("Olá, eu sou o filho1, de PID:%d, e acabei de nascer!!\n", getpid());
        printf("Sou filho de: %d.\n",getppid());
        sleep(12);

        pid = fork();

        if (pid < 0) {

            fprintf(stderr, "Criação Falhou!!");
            exit(-1);

        }

        else if (pid == 0) {

            printf("Olá, eu sou o neto1, de PID:%d, e acabei de nascer!!\n", getpid());
            printf("Sou filho de: %d.\n",getppid()); 
            sleep(12); 
            printf("Olá, eu sou o neto1, de PID:%d, e estou morrendo!!\n", getpid());
            printf("Morri =( !!\n");
            exit(0);          

        }

        else {

        sleep(18);
        printf("Olá, eu sou o filho1, de PID:%d, e estou morrendo!!\n", getpid());
        printf("Morri =( !!\n");
        exit(0);   

        }     
       
            
    }

    else {

        //Processo pai
        printf("O pai tá on!!!\n");
        exit(0);
            
    }

    return 0;
    
}
