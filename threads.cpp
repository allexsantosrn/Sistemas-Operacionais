#include <iostream>
#include <cmath>
#include <pthread.h>
#include <cstdlib> //atoi
#include <stdio.h>
#include <vector>

#define PI 3.14159265

int t, n, trapezio_por_thread;
double h;
double a=0, b=10; //Parâmetros para função 1
//double a=0, b =2 * PI; //Parâmeros para função 2

//Função exemplo 1
double func1(double x){
  return 5; 
}


//Função exemplo 2
double func2(double x){
  return sin(2*x) + cos(5*x);
}


int main(int argc, char *argv[]) {
  
  std::cout << "Informe o número de threads:";
  std::cin >> t;

  std::cout << "Informe o número de trapézios:"; 
  std::cin >> n;

  pthread_t threads[t];
  void *thread_return;
  int status, i;

  trapezio_por_thread = (int) n/t;
  
  h = (b-a)/n;

  for(i=0; i< t; i++) {
    // Criando as threads
    status = pthread_create(&threads[i], NULL, threadintegral, (void *)(size_t) i);

    if (status != 0) {
      printf("Erro na criação da thread. Código de Erro: %d\n", status);
      return 1;
    }
  }

  for(i=0; i< t; i++) {
      pthread_join(threads[i], &thread_return);
  }

  std::cout << "Área Total: ";

  return 0;
}