/**
 * @file M_memory.h
 * @author federico.barbetti@correounivalle.edu.co
 * @brief clase que representa los registros a ser ejecutados por el procesador
 * @version 0.1
 * @date 2025-04-19
 * @details :ninguna relacion con otras clases
 * 
 * @copyright GNU-GPL
 * 
 */

#ifndef M_MEMORY_H
#define M_MEMORY_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#pragma once


/**
 * @brief Clase que representa los registros dispuestos en la memoria primcipal
 * para ser ejecutadas
 * 
 */
class M_memory
{
public:
    M_memory(string mn, string da, string t1, string t2, string t3);
    M_memory();
    ~M_memory();
    void set_mname(string sn);
    void set_dir_adr(string vl);
    void set_tag1(string sn);
    void set_tag2(string vl);
    void set_tag3(string vl);

    string get_mname();
    string get_dir_adr();
    string get_tag1();
    string get_tag2();
    string get_tag3(); 

    void mostrar_memoria();

private:
    std::string m_name;             // Atributo que idenfica el tipo de la tarea a ejecutarse en el registro
    std::string dir_adr;            // indica la direccion de memoria en donde reside el registro
    std::string tag_1;              // campo de libre uso para el objeto
    std::string tag_2;              // campo de libre uso para el objeto
    std::string tag_3;              // campo de libre uso para el objeto

};

#endif