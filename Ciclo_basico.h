#ifndef CICLO_BASICO_H
#define CICLO_BASICO_H

# include "M_memory.h"
# include <vector>

#pragma once

/**
 * @brief Clase que representa el ciclo basico de instruccion
 * 
 */
class Ciclo_basico
{
public:
    Ciclo_basico();
    Ciclo_basico(int cont);
    ~Ciclo_basico();

    void set_pc();
    void set_mar(string ma);
    void set_acum(int ac);
    void set_alu(int al);
    void set_icr(M_memory* mem);
    void set_mdr(M_memory* muc);
    void set_un_control(M_memory* mkl);

    int get_pc();
    std::string get_mar();
    int get_acum();
    int get_alu();
    std::vector<string> get_icr();
    std::vector<string> get_mdr_name_add();
    std::vector<string> get_un_control();


    string mostrar_vector(vector<string>vs);
    void mostrar_ciclo_basico();
    void set_instrucciones(vector<M_memory*>lm);
    string get_Set_value(string ddb);             //obtener el valor del Set (3er campo)





private:
    int pc;             //contador de programas
    std::string mar;            //manejador de memoria
    int acum;           //acumulador
    int alu;            //totalizador
    std::vector<string> icr;        //instruction to process
    std::vector<string> mdr;        //instruction to process
    std::vector<string> un_control;        //instruction to process

    vector<M_memory*>info_men;      //listado de instrucciones a realizar


};

#endif