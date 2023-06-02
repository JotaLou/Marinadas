// Lenguajes de programación, tema 8, página 324 (PDF) Parte 2


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <bitset>   // Para trabajar con números binarios
#include <stdlib.h> // Para exit(), atoi() y cosas así
#include <cstdint>  // Para tipos de datos mejorados (uint64_t, etc..)
#include <limits>

//* Constantes Ejercicio 8.6
constexpr unsigned int NUMBER_OF_BITS = 8; // Esta es la manera C++ moderna de hacerlo, con C se usaría #define NUMBER_OF_BITS 8
//* Constantes Ejercicio 8.8
const std::string fileName = "E:\\Documentos\\Codigo\\Marino\\inputs.txt";
//* Constantes Ejercicio 8.9
#ifndef PI      // Directivas de preprocesador, esto es MUY C, en C++ se suele considerar algo a evitar
#define PI 3.14159265358979323846   // En el estándar moderno de 2020 se define mejor pi, pero no creo que lo uséis
#endif
//* Constantes Ejercicio 8.10
const std::string measuresFile = "medidas.txt";
const std::string filteredFile = "filtrado.txt";
constexpr int FILTER_ORDER = 5;
/*----------------Function Declarations------------------*/
void ex8_6();
void ex8_8();
void ex8_9();
void ex8_10();
/*------------------------------------------------------*/

int main(void)
{

    return 0;
}

// Ejercicio 8.6 página 326 (PDF)
void ex8_6(){
    std::string input;
    unsigned int result = 0;
    std::cout << "Por favor introduzca un numero binario de " << NUMBER_OF_BITS << " bits: ";
    std::cin >> input;
    if(input.size() != NUMBER_OF_BITS){
        std::cout << "El numero introducido no es de 8 digitos";
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<input.size(); i++){
        if(input[i] != '1' && input[i] != '0'){
            std::cout << "El numero introducido no es binario.";
            exit(EXIT_FAILURE);
        }
        if(input[i] == '1'){
            result +=  1 << (input.size()-(i+1));
        }
    }
    std::cout << "El numero decimal es: " << result << " ; (En binario: " << std::bitset<8>(result) << ")";

}
// Ejercicio 8.8 página 327 (PDF)
void ex8_8(){
    std::vector<double> inputs;
    double media = 0, varianza = 0, desviacionEstandar = 0;
    std::ifstream fileStream(fileName);

    if(!fileStream.is_open()){          // Comprobamos si se pudo abrir el archivo
        std::cerr << "No se pudo abrir el fichero \"" << fileName << "\".";
        exit(EXIT_FAILURE);
    }

    for(double n; fileStream >> n; )   //Esto es un while enmascarado que define una variable cuya vida es la duración del bucle 
        inputs.push_back(n);
    if(fileStream.eof())            //Si llegamos al final del archivo lo cerramos, todo ok
        fileStream.close();
    else if(fileStream.badbit){      //Puedes comprobar los flags o usar el método bad()
        std::cerr << "Error al leer el archivo.";
        fileStream.close();
        exit(EXIT_FAILURE);
    }
    else if(fileStream.failbit){    //Lo mismo, puedes usar fail()
        fileStream.close();
        std::cerr << "Error, datos no numericos encontrados.";
        exit(EXIT_FAILURE);
    }
    std::cout.precision(10);
    std::cout << "Datos: ";
    for(int i=0; i<inputs.size(); i++){
        media += inputs[i];
        std::cout << inputs[i] << " ; ";
    }
    std::cout << std::endl;
    varianza = media;       // De momento es la suma de todos los elementos
    media /= inputs.size();
    varianza = varianza - varianza*inputs.size();
    varianza = std::pow(varianza,2) / (inputs.size()-1);
    desviacionEstandar = std::sqrt(varianza);
    std::cout << "Media: " << media << " ; Varianza: " << varianza << " ; Desviacion Estandar: " << desviacionEstandar << std::endl;
}

// Ejercicio 8.9 página 327 (PDF)
void ex8_9(){
    char metodo;
    unsigned int iteraciones;
    double resultado;
    std::cout << "Escoja el metodo de calculo a utilizar; Leibniz(l)/Brent-Salamin(b): ";
    std::cin.get(metodo);

    switch(metodo){
        case 'l': {
            std::cout << "Introduzca el numero de elementos de la serie: ";
            std::cin >> iteraciones;
            resultado = 0.0;
            for(int i=0; i < iteraciones; i++){
                resultado += std::pow(-1, i) / (2*i + 1); 
            }
            resultado = resultado * 4.0;
            std::cout.precision(15);
            std::cout << "La aproximacion de pi mediante el metodo de Leibniz con " << iteraciones << " elementos es: " << resultado;
            std::cout << "\nEl error con respecto al valor conocido de pi (" << PI << ") es: " << std::abs(PI-resultado);
            exit(EXIT_SUCCESS);
        }
        case 'b': {
            std::cout << "Introduzca el numero de iteraciones: ";
            std::cin >> iteraciones;
            double a,b,p,t;
            double a_old = 1.0;     //Aquí mezclar snake_case tiene sentido porque camelCase es confuso con variables de una letra 
            double b_old = 1.0/std::sqrt(2.0);      // "aOld" es un nombre horrible de variable
            double t_old = 1.0/4.0;
            double p_old = 1.0;
            for(int i=1; i<=iteraciones; i++){
                // Calculamos los nuevos coeficientes con respecto a los anteriores
                a = (a_old+b_old)/2.0;
                b = std::sqrt(a_old*b_old);
                p = 2*p_old;
                t = t_old - p_old*std::pow((a_old-a),2);
                // Actualizamos los coeficientes anteriores
                a_old = a;
                b_old = b;
                p_old = p;
                t_old = t;
            }
            resultado = std::pow(a+b,2) / (4*t);
            std::cout.precision(15);
            std::cout << "La aproximacion de pi mediante el metodo de Bren-Salamin con " << iteraciones << " iteraciones es: " << resultado;
            std::cout << "\nEl error con respecto al valor conocido de pi (" << PI << ") es: " << std::abs(PI-resultado);
            exit(EXIT_SUCCESS);
        }
        default:{
            std::cout << "El caracter introducido no se corresponde con los metodos disponibles.";
            exit(EXIT_FAILURE);
        }
    }
}

// Ejercicio 8.10 página 327 (PDF)
void ex8_10(){
        char token;
    std::vector <uint64_t> medidas;
    std::vector <uint64_t> medidasFiltradas;
    uint64_t temp = 0;
    std::ifstream inputStream(measuresFile, std::ios::in);
    if(!inputStream.is_open()){
        std::cout << "No se pudo abrir el fichero de medidas.";
        exit(EXIT_FAILURE);
    }

    for(std::string line; std::getline(inputStream, line); ){   // Extraes línea por línea
        token = line[1];                                //... Extraer token ('0b', '0x', etc)
        switch(token){
            case 'b':{ //Binario
                temp = 0;           // Inicializamos el dato temporal a 0 
                for(size_t i=2; i<line.length(); i++){  // Recopilamos el dato binario bit a bit
                    if(line[i] == '1')              // Vamos "rellenando" los 1s en su sitio
                        temp += 1 << (line.length()-(i+1)); 
                }
                medidas.push_back(temp);    // Guardamos la medida
                break;
            }
            case 'x':{ //Hexadecimal            // También "habría" que hacer octal, pero en realidad no se usa y me da la chapa
                temp = 0;                         //  (Es un 'subconjunto' de hexadecimal, iría de 3 en 3 cifras con valores hasta 7)
                for(size_t i=2; i<line.length(); i++){
                    switch(line[i]){
                        case '1':{
                            temp += 1 << (line.length()*4-(4*i+4));   // Cada cifra hexadecimal son 4 cifras binarias
                            break;                                      // (Ya sé que no explica del todo esa abominación de expresión)
                        }
                        case '2':{
                            temp += 2 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '3':{
                            temp += 3 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '4':{
                            temp += 4 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '5':{
                            temp += 5 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '6':{
                            temp += 6 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '7':{
                            temp += 7 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '8':{
                            temp += 8 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case '9':{
                            temp += 9 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case 'A':           // Como las etiquetas de switch son de salto, puedes encadenarlas
                        case 'a': {         // El bloque se ejecutará tanto si se da mayúscula como minúscula
                            temp += 10 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case 'B':
                        case 'b':{
                            temp += 11 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case 'C':
                        case 'c':{
                            temp += 12 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case 'D':
                        case 'd':{
                            temp += 13 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case 'E':
                        case 'e':{
                            temp += 14 << (line.length()*4-(4*i+4));
                            break;
                        }
                        case 'F':
                        case 'f':{
                            temp += 15 << (line.length()*4-(4*i+4));
                            break;
                        }
                    }
                }
                medidas.push_back(temp);
                break;
            }
            default:{ //Decimal
                medidas.push_back(std::stod(line));  // String to double conversion
            }
        }
    }
    inputStream.close();
    std::ofstream outputStream(filteredFile, std::ios::out);
    if(!outputStream.is_open()){
        std::cout << "No se pudo abrir el fichero de salida.";
        exit(EXIT_FAILURE);
    }
    temp = 0;
    for(size_t i=0, contador=0; i<medidas.size(); i++){
        contador++;
        temp += medidas[i];
        if(contador == FILTER_ORDER){ // Si llevamos N elementos, calculamos la medida filtrada    
            medidasFiltradas.push_back(temp/FILTER_ORDER);  // La suma de los elementos entre el nº de elementos
            temp = 0;
            contador = 0;
            continue;   // continue empieza la siguiente iteración del bucle (vuelve al for de arriba)
        }
        if(contador && i == medidas.size()-1)  // Si llegamos al final sin resolver algunos elementos
            medidasFiltradas.push_back(temp/contador);  
    }
    // DEBUG purposes print
    std::cout << "Orden de filtro: " << FILTER_ORDER << "\n";
    std::cout << "Medidas:\n";
    for(size_t i=0; i<medidas.size(); i++){
//      std::cout << i+1 << ": " << std::bitset<10>(medidas[i]) << '\n';
        std::cout << i+1 << ": " << medidas[i] << '\n';
    }
    std::cout << "Medidas Filtradas:\n";
    for(size_t i=0; i<medidasFiltradas.size(); i++){
        std::cout << i+1 << ": " << medidasFiltradas[i] << '\n';
    }
}