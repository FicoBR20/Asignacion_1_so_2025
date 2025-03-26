#ifndef MOTOR_H
#define MOTOR_H

#include "Vlr_ins.h"
#include "Prs_run.h"
#include<vector>

#pragma once


/**
 * @brief Clase que representa la
 * ejecucion del proceso en el ciclo
 * basico de instruccion
 * 
 */
class Motor
{
public:
    Motor();
    ~Motor();
    static const int CANT_DIR;                      // define la cantidad de posiciones de memoria a usar.
    std::vector<std::string> set_Vect_intr();       // define el conjunto de nombres de tipo de instrucciones
    std::vector<string> avalaible_address();        // define el conjunto de memorias disponibles que se usaran. (i.e "D1", "D2" ..etc, toma 5 de 10 disponibles)

    
    
    // void generar_Set();                              // crear instruccion SET

private:
    std::vector<std::string> instru; // almacena los nombres de las instrucciones; i.e. "LDR", "ADD", "INC"
    std::vector<std::string> my_mfin; //almacena las direcciones de memoria a usar. 
    int accum_reg;              //acumulador de sumas enteras
    int prog_count;             //acumulador de procesos ejecutados


};

#endif