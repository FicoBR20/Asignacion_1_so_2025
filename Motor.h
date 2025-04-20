#ifndef MOTOR_H
#define MOTOR_H

#include "Ciclo_basico.h"
#include <map>

#pragma once


/**
 * @brief Clase que genera arreglos que contienen
 * registros a ser leidos y procesados.
 * 
 */
class Motor
{
public:
    Motor();
    ~Motor();
    
    
    int number_aleat(int lmt);
    bool esta_dentro(string bus, vector <string> mnum);
    std::vector<string> set_mem_finales(vector<string>rcs);
    std::vector<string> set_inst_finales(vector<string>irc);
    
    std::vector<string> get_mem_finales();       // retorna el conjunto de direcciones de memoria a usar. (i.e "D1", "D2" ..etc, toma 5 de 10 disponibles)
    std::vector<std::string> get_inst_finales();   // retorna el conjunto de nombres de las instrucciones a usar. (i.e "LDR", "ADD"...etc )
    

    
    
    
    
    
private:
    static const int CANT_DIR=5;                //total de direcciones de memoria a usar, de un total de 10 disponibles para escoger.
    vector<string>mem_finales;                  //memorias a usar
    vector<string>inst_finales;                 //instrucciones a usar

};

#endif