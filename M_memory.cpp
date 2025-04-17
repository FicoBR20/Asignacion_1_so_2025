#include "M_memory.h"

M_memory::M_memory(string mnam, string val){
    this -> m_name = mnam;
    this -> v_value = val;
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
void M_memory::set_vvalue(string vl){
    v_value = vl;
}
string M_memory::get_mname(){
    return m_name;
}
string M_memory::get_vvalue(){
    return v_value;
}

// funciones auxiliares

int M_memory::convert_int(string di){
    int conv;
    conv = stoi(di);
    return conv;

}

/**
 * @brief 
 * 
 */
void M_memory::mostrar_memoria(){
    cout<<" la memoria es: " + m_name + " " + v_value + "\n";
}
