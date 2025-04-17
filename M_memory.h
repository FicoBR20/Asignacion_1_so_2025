#ifndef M_MEMORY_H
#define M_MEMORY_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#pragma once


/**
 * @brief Clase que representa las instrucciones consignadas en la memoria primcipal
 * para ser ejecutadas
 * 
 */
class M_memory
{
public:
    M_memory(string kk, string mm);
    M_memory();
    ~M_memory();
    void set_mname(string sn);
    void set_vvalue(string vl);
    string get_mname();
    string get_vvalue();

    int convert_int(string di);
    void mostrar_memoria();

private:
    std::string m_name;
    std::string v_value;

};

#endif