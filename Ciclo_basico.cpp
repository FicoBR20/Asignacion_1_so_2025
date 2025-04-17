#include "Ciclo_basico.h"


Ciclo_basico::Ciclo_basico(){
    pc=0;
    mar="";
    acum=0;
    alu=0;
    vector<string>icr;
    vector<string>mdr;
    vector<string>un_control;

    vector<M_memory*>info_men;

}
Ciclo_basico::Ciclo_basico(int dm)
{
    this -> pc = dm;
}

Ciclo_basico::~Ciclo_basico()
{
    cout<<"..termina objeto CB...\n\n";
}

void Ciclo_basico::set_pc(){
    int contd = 0;
    for (M_memory* lm : info_men)
    {
        if (lm->get_mname()=="SET")
        {
            contd ++;
        }
        
    }
    pc=contd;
}
void Ciclo_basico::set_mar(string ma){
    mar=ma;
}
void Ciclo_basico::set_acum(int ac){
    acum=ac;
}
void Ciclo_basico::set_alu(int al){
    alu=al;
}
void Ciclo_basico::set_icr(M_memory* dm){
    string dato1 = dm->get_mname();
    icr.push_back(dato1);
    string dato2 = dm->get_dir_adr();
    icr.push_back(dato2);

}

/**
 * @brief PENDIENTE DE AJUSTAR CUANDO SE OPERA UNA
 * INSTRUCCION LOAD Y SE ENVIA AL ACUMULADOR LA CANTIDAD
 * DEBE SER IGUAL A LA CANTIDAD ENVIADA OSEA EL ENTERO
 * 
 * @param me 
 */
void Ciclo_basico::set_mdr(M_memory* me){       //[name, address, [address -> value]]
    string dato1 = me->get_mname();
    mdr.push_back(dato1);
    string dato2 = me->get_dir_adr();
    mdr.push_back(dato2);                   

    string dato3 = get_Set_value(dato2);        // se obtiene el valor inserto en la direccion de memoria referida
    mdr.push_back(dato3);

}







void Ciclo_basico::set_un_control(M_memory* mc){
    string dato1 = mc->get_mname();
    un_control.push_back(dato1);
    string dato2 = mc->get_dir_adr();
    un_control.push_back(dato2);

}

int Ciclo_basico::get_pc(){
    return pc;
}
string Ciclo_basico::get_mar(){
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
std::vector<string> Ciclo_basico::get_mdr_name_add(){
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
    cout<<"Ciclo basico:  PC: " + to_string(get_pc()) + " MAR: " + get_mar() + " ACUM: " + to_string(get_acum()) + " ALU: " + to_string(get_alu()) + " ICR: " + mostrar_vector(get_icr()) + " MDR: " + mostrar_vector(get_mdr_name_add()) + " UNIDAD DE CONTROL: " + mostrar_vector(get_un_control()) + " es todo.\n";
}

void Ciclo_basico::set_instrucciones(vector<M_memory*>lm){

    info_men = lm;

}

string Ciclo_basico::get_Set_value(string db){      //db direccion buscada

    string value = "";

    for (M_memory* mpt : info_men)
    {
        string st_recep = mpt->get_dir_adr();

        if (st_recep==db)
        {
            value = mpt->get_tag1();
        }
        
    }
    
    return value;
}



//operaciones


