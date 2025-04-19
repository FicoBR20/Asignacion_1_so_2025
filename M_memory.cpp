/**
 * @file M_memory.cpp
 * @author federico.barbetti@correounivalle.edu.co
 * @brief clase que representa los registros a ser ejecutados por el procesador
 * @version 0.1
 * @date 2025-04-19
 * @details :ninguna relacion con otras clases
 * 
 * @copyright GNU-GPL
 * 
 */


#include "M_memory.h"

M_memory::M_memory(string sna, string di, string ta1, string ta2, string ta3){
    this -> m_name = sna;
    this -> dir_adr = di;
    this -> tag_1 = ta1;
    this -> tag_2 = ta2;
    this -> tag_3 = ta3;
}

M_memory::M_memory()
{

}

M_memory::~M_memory()
{
    cout<<"... destroy M_memory..\n\n";

}
void M_memory::set_mname(string sn){
    m_name = sn;
}
void M_memory::set_dir_adr(string vl){
    dir_adr = vl;
}
void M_memory::set_tag1(string tt){
    tag_1 = tt;
}
void M_memory::set_tag2(string pp){
    tag_2 = pp;
}
void M_memory::set_tag3(string mt){
    tag_3 = mt;
}

string M_memory::get_mname(){
    return m_name;
}
string M_memory::get_dir_adr(){
    return dir_adr;
}
string M_memory::get_tag1(){
    return tag_1;
}
string M_memory::get_tag2(){
    return tag_2;
}
string M_memory::get_tag3(){
    return tag_3;
}

// funciones auxiliares

/**
 * @brief 
 * 
 */
void M_memory::mostrar_memoria(){
    cout<<"Contenido en la posicion de memoria: " + get_mname() + " " + get_dir_adr() + " " + get_tag1() + " " + get_tag2() + " " + get_tag3() + "  \n";
}
