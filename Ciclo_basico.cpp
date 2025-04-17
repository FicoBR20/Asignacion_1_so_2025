#include "Ciclo_basico.h"


Ciclo_basico::Ciclo_basico(){
    pc=99;
    mar=0;
    acum=0;
    alu=0;
    vector<string>icr;
    vector<string>mdr;
    vector<string>un_control;
}
Ciclo_basico::Ciclo_basico(int dm)
{
    this -> pc = dm;
}

Ciclo_basico::~Ciclo_basico()
{
    cout<<"..termina objeto CB...\n\n";
}

void Ciclo_basico::set_pc(int cou){
    pc=cou;
}
void Ciclo_basico::set_mar(int ma){
    mar=ma;
}
void Ciclo_basico::set_acum(int ac){
    acum=ac;
}
void Ciclo_basico::set_alu(int al){
    alu=al;
}
void Ciclo_basico::set_icr(M_memory dm){
    string dato1 = dm.get_mname();
    icr.push_back(dato1);
    string dato2 = dm.get_vvalue();
    icr.push_back(dato2);

}

/**
 * @brief PENDIENTE DE AJUSTAR CUANDO SE OPERA UNA
 * INSTRUCCION LOAD Y SE ENVIA AL ACUMULADOR LA CANTIDAD
 * DEBE SER IGUAL A LA CANTIDAD ENVIADA OSEA EL ENTERO
 * 
 * @param me 
 */
void Ciclo_basico::set_mdr(M_memory me){
    string dato1 = me.get_mname();
    mdr.push_back(dato1);
    string dato2 = me.get_vvalue();
    mdr.push_back(dato2);

}
void Ciclo_basico::set_un_control(M_memory mc){
    string dato1 = mc.get_mname();
    un_control.push_back(dato1);
    string dato2 = mc.get_vvalue();
    un_control.push_back(dato2);

}

int Ciclo_basico::get_pc(){
    return pc;
}
int Ciclo_basico::get_mar(){
    return mar;
}
int Ciclo_basico::get_acum(){
    return acum;
}
int Ciclo_basico::get_alu(){
    return alu;
}
std::vector<string> Ciclo_basico::get_icr(){
    return icr;
}
std::vector<string> Ciclo_basico::get_mdr(){
    return mdr;
}
std::vector<string> Ciclo_basico::get_un_control(){
    return un_control;
}


string Ciclo_basico::mostrar_vector(vector<string>vect){

    string entrega = "";
    stringstream recolecta;
    for (string st: vect)
    {
        recolecta<<st;
    }
    recolecta>>entrega;
    return entrega;
    
}

void Ciclo_basico::mostrar_ciclo_basico(){
    cout<<"Ciclo basico: " + to_string(get_pc()) + to_string(get_mar()) + to_string(get_acum()) + to_string(get_alu()) + mostrar_vector(get_icr()) + mostrar_vector(get_mdr()) + mostrar_vector(get_un_control()) + " hola final\n";
}


//operaciones


