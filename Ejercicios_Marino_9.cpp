// Lenguajes de programación, tema 9, página 361 (PDF) 

#include <iostream>
#include <cstdint>

uint64_t potencia(double base, uint64_t exponente);

int main()
{
    uint64_t resultado;
    resultado = potencia(2.0, 3);

    std::cout << "resultado: " << resultado;

    return 0;
}


// Ejercicio 9.5 
uint64_t potencia(double base, uint64_t exponente){
    if(exponente == 0)
        return 1;
    else
        return base * potencia(base, exponente-1);  // te da base*base*base*...*1 (cuando llega a 0 el exponente)
}