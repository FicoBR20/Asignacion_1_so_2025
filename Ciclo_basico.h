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

    // int iniciador();


    void set_pc(int ini);
    void set_mar(string ma);

    void set_mar_pc(int ind);

    void set_acum(int ac);
    void set_alu(int al);
    void set_icr(M_memory* mem);
    void set_mdr(M_memory* muc);

    void set_mdr_value(M_memory* vm);

    void set_un_control(M_memory* mkl);

    void set_instrucciones(vector<M_memory*>lm);

    int get_pc();
    std::string get_mar();
    int get_acum();
    int get_alu();
    std::vector<string> get_icr();
    std::vector<string> get_mdr();
    std::vector<string> get_un_control();


    //funciones del motor
    
    /**
     * @brief funcion que define las acciones
     * a ejecutar segun el atributo "mname" del
     * objeto M_memory
     * 
     */
    void load_instruction();

    /**
     * @brief muestra en consola el estado de todos
     * los atributos del objeto Ciclo_basico
     * 
     */
    void mostrar_ciclo_basico();

    /**
     * @brief funcion que devuelve un string del valor entero almacenado en una
     * direccion de memoria
     * 
     * @param pm // objeto con la direccion de memoria
     * @return string 
     */
    string get_Set_value(M_memory* pm);          



    /**
     * @brief funcion auxiliar entrega un string
     * tomando los campos de un vector<string>;
     * 
     * @return string 
     */
    string print_vector(vector<string>vst);



    /**
     * @brief funcion que entrega la direccion de
     * un objeto M_memory segun atributo configurado
     * 
     * @param addr 
     * @return M_memory* 
     */
    M_memory* to_store(std::string addr);






private:
    int pc;                             //contador de programas
    std::string mar;                    //registro de direcciones de memoria
    int acum;                           //acumulador
    int alu;                            //totalizador
    std::vector<string> icr;            //actualizador de registro en ejecucion
    std::vector<string> mdr;            //datos en direccion de memoria
    std::vector<string> un_control;     //asignador de gestion

    vector<M_memory*>info_men;          //lista de registros para ejecucion


};

#endif