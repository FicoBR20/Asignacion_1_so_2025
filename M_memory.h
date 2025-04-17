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

    int convert_int(string di);
    void mostrar_memoria();

private:
    std::string m_name;
    std::string dir_adr;
    std::string tag_1;
    std::string tag_2;
    std::string tag_3;

};

#endif