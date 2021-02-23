#include <iostream>
#include <cmath>
#include <pthread.h>
#include <stdio.h>
#include <vector>

int t, n, trapezio_por_thread;
double h;
//double a=0, b=10, area=0; //Parâmetros para função 1
double a=0, b = 2 * M_PI; //Parâmetros para função 2
std::vector<double> vetor_trapezios; //Vetor acumulador das áreas dos trapézios

//Função exemplo 1
double func1(double x){

  return 5; 
}


//Função exemplo 2
double func2(double x){

  return sin(2*x) + cos(5*x);
}

//Calcular trapézio
double calcularTrapezio(double inicio, double fim){

  double base = fim - inicio;
  //double inicioCalculado = func1(inicio);
  //double fimCalculado = func1(fim);
  double inicioCalculado = func2(inicio);
  double fimCalculado = func2(fim);
  
  return (base * (inicioCalculado + fimCalculado)/2);
}

void* trap_threads(void* tid){

  int trapeziosThread;
  double local_a, local_b; 
  int posicaoThread = (int) (size_t) tid;

    //Ajuste necessário quando há variãção de trapézios por threads
    if(posicaoThread == t-1) {

      trapeziosThread = n-( posicaoThread *trapezio_por_thread);
    }

    else {

      trapeziosThread = trapezio_por_thread;
    }
    
  local_a = a + (posicaoThread * h * trapezio_por_thread);
  
  for(int i=0; i < trapeziosThread; i++){

    local_b = local_a + h;
    
    vetor_trapezios[(posicaoThread * trapezio_por_thread) + i] = calcularTrapezio(local_a, local_b);

    local_a = local_b;
  }

  pthread_exit(NULL);
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
  vetor_trapezios.resize(n);  

  h = (b-a)/n;

  for(i=0; i< t; i++) {
    // Criando as threads
    status = pthread_create(&threads[i], NULL, trap_threads, (void *)(size_t) i);

    if (status != 0) {

      printf("Erro na criação da thread. Código de Erro: %d\n", status);
      return 1;      
    }
    
  }

  for(i=0; i< t; i++) {

      pthread_join(threads[i], &thread_return);
  }

  double area_total = 0;

  //Função que soma todos os valores do vetor
  for(i=0; i< vetor_trapezios.size(); i++) {

    area_total = area_total + vetor_trapezios.at(i);
  }

  std::cout.precision(2);
  std::cout << "Área total (Resultado da Integral): " << std::scientific << area_total << std::endl;

  return 0;
}