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
    static const int CANT_DIR;
    void set_instructions();                     // define nombres de las instrucciones.
    void set_aval_address();                     // define las posiciones de memoria a usar.
    std::vector<std::string> get_instructios();       // retorna el conjunto de nombres de las instrucciones a usar. (i.e "LDR", "ADD"...etc )
    std::vector<string> get_aval_address();       // retorna el conjunto de direcciones de memoria a usar. (i.e "D1", "D2" ..etc, toma 5 de 10 disponibles)
    

    
    

private:
    std::vector<std::string> the_instructions; // almacena los nombres de las instrucciones; i.e. "LDR", "ADD", "INC"
    std::vector<std::string> the_aval_address; //almacena las direcciones de memoria a usar. 
    int accum_reg;              //acumulador de sumas enteras
    int prog_count;             //acumulador de procesos ejecutados


};

#endif