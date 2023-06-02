// Lenguajes de programación, tema 6, página 249 (PDF)

#include <iostream>
#include <string>

/*----------------Function Declarations------------------*/
void ex6_1();
void ex6_2();
void ex6_5();
/*------------------------------------------------------*/

int main()
{
    //ex6_1();
    //ex6_2();
    //ex6_5();  

    return 0;
}


// Ejercicio 6.1 página 249 (PDF)
void ex6_1(){
    int n1,n2;
    std::cout << "Introduzca el primer numero: ";
    std::cin >> n1;

    std::cout << "\nIntroduzca el segundo numero: ";
    std::cin >> n2;

    std::cout << n1 << " + " << n2 << " = " << n1+n2 << std::endl;
    std::cout << n1 << " - " << n2 << " = " << n1-n2;
}

// Ejercicio 6.2 página 249 (PDF)
void ex6_2(){
    int n1,n2;
    std::cout << "Introduzca el primer numero: ";
    std::cin >> n1;
    std::cout << "\nIntroduzca el segundo numero: ";
    std::cin >> n2; 

    std::cout << n1 << " / " << n2 << " = " << n1/n2 << "\tResto: " << n1%n2; 
}

// Ejercicio 6.5 página 250 (PDF)
void ex6_5(){
    std::string nombre, apellido1, apellido2, nombreCompleto, apellidos;
    int i;

    std::cout << "Introduzca su nombre: ";
    std::cin >> nombre;
    std::cout << "\nIntroduzca su primer apellido :";
    std::cin >> apellido1;
    std::cout << "\nIntroduzca su segundo apellido :";
    std::cin >> apellido2;
    apellidos = apellido1 + " " + apellido2;    // también se podría usar el método append()
    nombreCompleto = nombre + " " + apellidos;
    std::cout << "\nNombre completo: " << nombreCompleto << std::endl;

    std::cout << "Es Juan?: ";
    if(nombre == "Juan")        //Si en un if, else, etc.. sólo hay una línea puedes omitir los corchetes
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
        
    std::cout << "Primer apellido comienza por 'M'?: ";
    if(*apellido1.begin() == 'M')   // begin te devuelve un puntero (un iterador en realidad),
        std::cout << "true" << std::endl;        //   por eso hay que dereferenciarlo con *
    else
        std::cout << "false" << std::endl;  //meter tanto endl con tan poco texto es malo (costoso)
                                            //  pero así te acostumbras a verlo y no '\n' todo el rato
    std::cout << "\nLongitud del nombre: " << nombre.length() << std::endl;

    if((i = nombre.find("an")) != -1){      // aquí meto una declaración en el if para no tener que 
        std::cout << "Indice de \"an\": " << i << std::endl;    //  computar el método find 2 veces 
    }
    else
        std::cout << "El nombre no contiene \"an\"";
}