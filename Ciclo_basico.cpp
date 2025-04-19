/**
 * @file Ciclo_basico.cpp
 * @author federico.barbetti@correounivalle.edu.co
 * @brief Clase que representa el ciclo basico de instrucciones de un procesador
 * @version 0.1
 * @date 2025-04-19
 * @details :relacion de composicion con la clase M_memory
 * 
 * 
 * @copyright GNU-GPL
 * 
 */

#include "Ciclo_basico.h"


/**
 * @brief Construct a new Ciclo_basico::Ciclo_basico object
 * inicializa atributos en el valor default
 */
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

/**
 * @brief Destroy the Ciclo_basico::Ciclo_basico object
 * 
 */
Ciclo_basico::~Ciclo_basico()
{
}

/**
 * @brief configura el atributo pc
 * 
 * @param posc 
 */
void Ciclo_basico::set_pc( int posc){
   
    pc=posc;
}

/**
 * @brief configura el atributo mar
 * 
 * @param ma 
 */
void Ciclo_basico::set_mar(string ma){
    mar=ma;
}

/**
 * @brief configura el atributo mar con el numero
 * del contador de programas
 * 
 * @param ind 
 */
void Ciclo_basico::set_mar_pc(int ind){

    mar = to_string(ind);


}

/**
 * @brief configura el acumulador
 * 
 * @param ac 
 */
void Ciclo_basico::set_acum(int ac){
    acum = ac;
}

/**
 * @brief configura el atributo alu
 * 
 * @param al 
 */
void Ciclo_basico::set_alu(int al){
    alu = al;
}

/**
 * @brief funcion que genera 2 campos para el atributo icr;
 * [name, address]
 * 
 * @param dm 
 */
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
 * @brief funcion que configura el mdr con el valor
 * entero contenido en una posicion de memoria
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


/**
 * @brief funcion que genera 2 campos para el atributo un_control
 * [name, address]
 * 
 * @param mc 
 */
void Ciclo_basico::set_un_control(M_memory* mc){
    un_control.clear();
    string dato1 = mc->get_mname();
    un_control.push_back(dato1);
    string dato2 = mc->get_dir_adr();
    un_control.push_back(dato2);
    
}

/**
 * @brief funcion que asigna el vector con las instrucciones
 * a procesar
 * 
 */
void Ciclo_basico::set_instrucciones(vector<M_memory*>lm){

    info_men = lm;

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



void Ciclo_basico::mostrar_ciclo_basico(){
    cout<<"Ciclo basico:  PC: " + to_string(get_pc()) + "   MAR: " + get_mar() + "   ACUM: " + to_string(get_acum()) + "   ALU: " + to_string(get_alu()) + "   ICR:" + print_vector(icr) + "   MDR:" + print_vector(mdr) + "   UNIDAD DE CONTROL:" + print_vector(un_control) + " \n";
}

string Ciclo_basico::get_Set_value(M_memory* dm){   

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

// funciones de proceso.

string Ciclo_basico::print_vector(vector<string>vst){
    string rect = "";
    for (string ste : vst)
    {
        rect = rect + " " + ste;
    }

    return rect;
    
}


M_memory* Ciclo_basico::to_store(std::string addr){

    M_memory* cambiante;

    for (M_memory* ref : info_men)
    {
        if (ref->get_dir_adr()==addr && ref->get_mname()=="SET")
        {
            cambiante = ref;
        }
        
    }
    
    return cambiante;
}


M_memory* Ciclo_basico::to_show(std::string dir){

    M_memory* mostrona;

    for (M_memory* reg : info_men)
    {
        if (reg->get_dir_adr()==dir && reg->get_mname()!="SHW")
        {
            mostrona = reg;
        }
        
    }
    
    return mostrona;
}


void Ciclo_basico::load_instruction(){

    int auxx;
    string recep, ayud = "";

    set_pc(0);


    for (int i = 0; i < info_men.size(); i++)
    {
        if (info_men.at(i)->get_mname()=="SET")
        {
            pc++;
        }
        else if (info_men.at(i)->get_mname()=="LDR")
        {
            M_memory* mm = info_men.at(i);
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

        }
        else if (info_men.at(i)->get_mname()=="ADD")
        {
            M_memory* mm = info_men.at(i);
            set_mar_pc(get_pc());
            set_mdr(mm);
            set_icr(mm);
            pc++;
            set_un_control(mm);
            set_alu(get_acum());
            set_mar(mm->get_dir_adr());
            set_mdr_value(mm);

            recep = mm->get_dir_adr();
            ayud = get_Set_value(mm);
            auxx = stoi(ayud);

            set_acum(auxx); 
            set_alu(get_alu() + get_acum());
            set_acum(get_alu());
        
        }
        else if (info_men.at(i)->get_mname()=="STR")
        {
            M_memory* mm = info_men.at(i);
            set_mar_pc(get_pc());
            set_mdr(mm);
            set_icr(mm);
            pc++;
            set_un_control(mm);
            set_mdr_value(mm);
            string stmem = " ";         
            stmem = mm->get_dir_adr();

            mm = to_store(stmem);

            mm->set_tag1(to_string(get_acum()));

            // mm->mostrar_memoria();

        }
        else if (info_men.at(i)->get_mname()=="SHW")
        {
            /* code */
            cout<<" soy show \n";
        }
        else if (info_men.at(i)->get_mname()=="END")
        {
            mostrar_ciclo_basico();
        }
        
        
        
    }
    

    
}



