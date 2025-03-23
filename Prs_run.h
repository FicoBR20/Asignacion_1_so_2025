#ifndef PRS_RUN_H
#define PRS_RUN_H

#include<iostream>
#include<string>

using namespace std;

#pragma once

/**
 * @brief Clase que representa las instruciones
 * LDR(load), ADD(addition), INC(increment), DEC(decrement),
 * STR(store), SHW(show), PAUSE(pause)
 * 
 */
class Prs_run
{
public:
    Prs_run(string nm, string dm, string cp1, string cp2);
    Prs_run();
    ~Prs_run();
    void set_name_prs(string sr);
    void set_mem(string ub);
    void set_cm1(string c1);             //valor default NULL
    void set_cm2(string c2);             //valor default NULL
    string get_name_prs();
    string get_dmem();
    string get_cp1();
    string get_cp2();

private:
    std::string name_prs;        //identificacion de la instruccion.
    std::string dir_memo;        //direccion de memoria de la instruccion.
    std::string campo1;          //campo adicional a ser usado.
    std::string campo2;          //campo adicional a ser usado.

};

#endif