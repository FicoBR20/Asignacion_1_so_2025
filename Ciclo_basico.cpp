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
 * @brief Construct a new Ciclo_basico::Ciclo_basico object
 * contruye un nuevo objeto con el parametro del atributo pc
 * @param dm 
 */
Ciclo_basico::Ciclo_basico(int dm)
{
    this -> pc = dm;
}
/**
 * @brief Destroy the Ciclo_basico::Ciclo_basico object
 * 
 */
Ciclo_basico::~Ciclo_basico()
{
    cout<<"..termina objeto CB...\n\n";
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
    acum = acum + ac;
}

/**
 * @brief configura el atributo alu
 * 
 * @param al 
 */
void Ciclo_basico::set_alu(int al){
    alu=al;
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
    cout<<"Ciclo basico:  PC: " + to_string(get_pc()) + "   MAR: " + get_mar() + "   ACUM: " + to_string(get_acum()) + "   ALU: " + to_string(get_alu()) + "   ICR:" + print_vector(icr) + "   MDR:" + print_vector(mdr) + "   UNIDAD DE CONTROL:" + print_vector(un_control) + " es todo.\n";
}

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


// funciones del motor



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
        else if (mm->get_mname()=="ADD")
        {
            set_mar_pc(get_pc());

            cout<<"soy add \n";
        }
        
        
    }
    
}



