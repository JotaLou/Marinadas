// Lenguajes de programación, tema 8, página 324 (PDF)

#include <iostream>     
#include <complex>      //Para trabajar con números complejos como clase (objeto)
#include <array>
#include <vector>
#include <cmath>
#include <string>
#include <limits>


/*----------------Function Declarations------------------*/
void ex8_1();
void ex8_2();
void ex8_4();
void ex8_5();
/*------------------------------------------------------*/

int main()
{

    return 0;
}


// Ejercicio 8.1 pagina 324 (PDF)
void ex8_1(){
    double a, b, c;
    double discriminante;  
        
    std::array<std::complex<double>, 2> solutions;      //(-b+-sqrt(discriminante))/2a
    std::complex<double> im{0, 1};      // Unidad Imaginaria          

    std::cout << "Introduzca los coeficientes de una ecuacion cuadratica de la forma ax^2+bx+c=0.\nIntroduzca el coficiente a: ";
    std::cin >> a;
    std::cout << "Introduzca el coeficiente b: ";
    std::cin >> b;
    std::cout << "Introduzca el coeficiente c: ";
    std::cin >> c;
    discriminante = b*b - (4*a*c);  //b^2-4ac
    if(discriminante >= 0){
        std::cout << "\nTiene soluciones reales.\n";
        solutions[0] = (-b+sqrt(discriminante))/(2*a);
        solutions[1] = (-b-sqrt(discriminante))/(2*a);
        std::cout << "Las soluciones son:\n x1 = " << std::real(solutions[0]) << "; x2 = " << std::real(solutions[1]);
    }
    else {
        std::cout << "\nTiene soluciones complejas.\n";
        solutions[0] = (-b+sqrt(abs(discriminante))*im)/(2*a);
        solutions[1] = (-b-sqrt(abs(discriminante))*im)/(2*a);
        std::cout << "Las soluciones son:\nx1 = " << solutions[0] << 
            " ; modulo: " << std::abs(solutions[0]) << " ; argumento: " << std::arg(solutions[0]) << 
            "\nx2 = " << solutions[1] <<
            " ; modulo: " << std::abs(solutions[1]) << " ; argumento: " << std::arg(solutions[1]);
    }
}

// Ejercicio 8.2 pagina 324 (PDF)
void ex8_2(){
    int a,b,c;      // Con enteros porque comparar punto flotante es HORRIBLE
    std::cout << "Introduzca la longitud del primer lado del triangulo: ";
    std::cin >> a;
    std::cout << "Introduzca la longitud del segundo lado del triangulo: ";
    std::cin >> b;
    std::cout << "Introduzca la longitud del tercer lado del triangulo: ";
    std::cin >> c;
    if((a == b) && (b == c)){        // En serio, nunca compares doubles o floats
        std::cout << "\nEquilatero.";   //* Aquí estaría "bien" porque es metido por teclado
        return ;                        //*  pero en el momento que hay un cálculo no puedes 
    }                                   //*  confiar en que dos puntos flotantes sean iguales
    if(a == b || a == c){
        std::cout << "\nIsosceles.";
        return ; 
    }
    std::cout << "\nEscaleno.";
}

// Ejercicio 8.4 pagina 324 (PDF)
void ex8_4(){
    char tipoSerie; // Esta notación se llama camelCase. (NO se mezclan estilos, es para que los veas)
    unsigned int n_terminos; // Esta notación se llama snake_case   
    long double temp = 0.0;     
    std::cout << "Introduzca el tipo de serie ('g'/'a'/'b'): "; //Versión fácil acepta un caracter
    std::cin.get(tipoSerie);    // Pillar sólo un caracter y almacenarlo en tipoSerie
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer de entrada
    std::cout << "\nIntroduzca el numero de terminos: ";
    std::cin >> n_terminos;

    switch(tipoSerie){
        case 'g': {
            std::cout << "\nSerie geometrica, " << n_terminos << " terminos:  ";
            for(int i=0; i < n_terminos; i++)  // Ojito con cuando poner '<=' o '<'
                temp += 1.0/(std::pow(2,i));
            std::cout << temp;
            break;
        }
        case 'a': {
            std::cout << "\nSerie armonica, " << n_terminos << " terminos:  ";
            for(int i=1; i <= n_terminos; i++){
                temp += 1.0/i;
            }
            std::cout << temp;
            break;
        }
        case 'b': {
            std::cout << "\nSerie armonica alterna, " << n_terminos << " terminos:  ";
            for(int i=1; i <= n_terminos; i++){
                if(i%2)     // Si es término impar es positivo
                    temp += 1.0/i;
                else        // si no, es negativo
                    temp -= 1.0/i;
            }
            std::cout << temp;
            break;
        }
        default: {
            std::cout << "\nNo se ha seleccionado ninguna serie. Introduzca 'g', 'a' o 'b'";
        }
    }
}

// Ejercicio 8.5 pagina 325 (PDF)
void ex8_5(){
    unsigned int numberOfPrimes;    // Cantidad de números primos que queremos calcular (input)
    unsigned int currentIndex = 3;  // Índice para llevar la cuenta de por qué número vamos
    std::vector<unsigned int> primes;   // Vector para guardar los números primos
    std::cout << "Introduzca la cantidad de numeros primos a calcular: ";
    std::cin >> numberOfPrimes;
    primes.push_back(2);    // Añadimos el 2 como primer número primo (premisa enunciado)
    
    while(primes.size() < numberOfPrimes){
        for(int i=0; i<=primes.size(); i++){
            if(!(bool)(currentIndex % primes[i]))    // Comprobamos la divisibilidad por cada primo ya calculado
                break;                              //  ***(MUY INEFICIENTE)***
            if(i == primes.size()){
                primes.push_back(currentIndex); // Si no es divisible por ninguno de los primos ya calculados lo añadimos
                break;
            }
        }
        currentIndex++;
    }
    std::cout << "\n";
    for(int i=0; i < primes.size(); i++)    // Mostrar los resultados en pantalla
        std::cout << primes[i] << "\n";
}