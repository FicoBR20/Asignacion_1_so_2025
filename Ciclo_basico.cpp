#include "Ciclo_basico.h"

/**
 * @brief posicion de lectura
 * 
 */
int pos_lect=0;


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


void Ciclo_basico::set_pc( int posc){
   
    pc=posc;
}
void Ciclo_basico::set_mar(string ma){
    mar=ma;
}


void Ciclo_basico::set_mar_pc(int ind){

    mar = to_string(ind);


}


void Ciclo_basico::set_acum(int ac){
    acum = acum + ac;
}
void Ciclo_basico::set_alu(int al){
    alu=al;
}
void Ciclo_basico::set_icr(M_memory* dm){
    icr.clear();
    string dato1 = dm->get_mname();
    icr.push_back(dato1);
    string dato2 = dm->get_dir_adr();
    icr.push_back(dato2);

}

/**
 * @brief funcion que genera 2 campos para el atributo mdr;
 * [ name , address ]
 * 
 * @param me 
 */
void Ciclo_basico::set_mdr(M_memory* me){      
    mdr.clear();
    string dato1 = me->get_mname();
    mdr.push_back(dato1);
    string dato2 = me->get_dir_adr();
    mdr.push_back(dato2);                 

}

/**
 * @brief funcion que genera el valor entero asociado a 
 * una posicion de memoria y se lo asigna a el arreglo mdr
 * quedando como unico termino en dicho arreglo
 * 
 * @param vm 
 */
void Ciclo_basico::set_mdr_value(M_memory* vm){

    string st_aux, recibe = "";
    recibe = vm->get_dir_adr();
    st_aux = get_Set_value(vm);
    mdr.clear();
    mdr.push_back(st_aux);

}







void Ciclo_basico::set_un_control(M_memory* mc){
    un_control.clear();
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
    cout<<"Ciclo basico:  PC: " + to_string(get_pc()) + "   MAR: " + get_mar() + "   ACUM: " + to_string(get_acum()) + "   ALU: " + to_string(get_alu()) + "   ICR:" + print_vector(icr) + "   MDR:" + print_vector(mdr) + "   UNIDAD DE CONTROL:" + print_vector(un_control) + " es todo.\n";
}

void Ciclo_basico::set_instrucciones(vector<M_memory*>lm){

    info_men = lm;

}
/**
 * @brief funcion que entrega el valor entero almacenado en una
 * direccion de memoria; el valor del entero lo entrega en formato string
 * 
 * @param db // direccion de memoria buscada
 * @return string 
 */
string Ciclo_basico::get_Set_value(M_memory* dm){      //db direccion buscada

    string value, recet, proof, auxil = "";

    proof = dm->get_dir_adr();

    for (M_memory* mpt : info_men)
    {
        recet = mpt->get_dir_adr();
        auxil = mpt->get_tag1();

        if (recet==proof && auxil != "NULL")
        {
            value = mpt->get_tag1();
        }
    
    }
    
    return value;
}



//Funciones del motor

/**
 * @brief entrega string concatenado de los miembros
 * de un vector<string>dado
 * 
 * @return string 
 */
string Ciclo_basico::print_vector(vector<string>vst){
    string rect = "";
    for (string ste : vst)
    {
        rect = rect + " " + ste;
    }

    return rect;
    
}




void Ciclo_basico::load_instruction(){

    int auxx;
    string recep, ayud = "";

    set_pc(0);

    for (M_memory* mm : info_men)
    {   
        if (mm->get_mname()=="SET")
        {
            pc++;
        }
        
        else if (mm->get_mname()=="LDR")
        {
            set_mar_pc(get_pc());
            set_mdr(mm);
            set_icr(mm);
            pc++;
            set_un_control(mm);
            set_mar(mm->get_dir_adr());
            set_mdr_value(mm);
            
            recep = mm->get_dir_adr();
            ayud = get_Set_value(mm);
            auxx = stoi(ayud);
            
            
            set_acum(auxx);
            mostrar_ciclo_basico();

            cout<<"Soy ldr \n";
        }
        
    }
    
}



