// Lenguajes de programación, tema 4, página 161 (PDF)

#include <iostream> // std::cout, std::cin, etc... streams en general
#include <iomanip>  // std::setprecision y demás manipuladores de flujo(stream)

/*----------------Function Declarations------------------*/
void ex4_1();
/*------------------------------------------------------*/

int main()
{
    ex4_1();

    return 0;
}



// Ejercicio 4.1
void ex4_1 (){
    double uno = 1.000;
    double dos = 1.414;
    double tres = 1.732;
    double cuatro = 2.000;
    double cinco = 2.236;

    std::cout << "N\t\t" << "Raiz cuadrada\n";
    std::cout << std::fixed << std::setprecision(3);
    std::cout << "1\t\t" <<  uno << "\n";
    std::cout << "2\t\t" << dos << "\n";
    std::cout << "3\t\t" << tres << "\n";
    std::cout << "4\t\t" << cuatro << "\n";
    std::cout << "5\t\t" << cinco << "\n";
}

