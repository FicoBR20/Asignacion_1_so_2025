#ifndef MOTOR_H
#define MOTOR_H

#include "Vlr_ins.h"
#include "Prs_run.h"

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

private:
    string tip_date;            //identificacion de la instruccion
    string dir_mem;             //direccion de memoria
    string val_str;             //valor string en determinado campo
    int value_in;               //valor entero inicial almacenado en memoria
    int accum_reg;              //acumulador de sumas enteras
    int prog_count;             //acumulador de procesos ejecutados
    bool is_stop;               //informacion de parada o pausa del proceso.


};

#endif