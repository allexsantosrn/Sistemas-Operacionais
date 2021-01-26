#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>



int main(){

	time_t t1, t2;
	
	std::cout << "Iniciando contagem" << std::endl;

	t1 = time(NULL);

	sleep(10);

	t2 = time(NULL);

	std::cout << t2-t1 << std::endl;


return 0;

}
