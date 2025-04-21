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

    // lo nuevo

    string dato3 = me->get_tag1();
    mdr.push_back(dato3);
    string dato4 = me->get_tag2();
    mdr.push_back(dato4);
    string dato5 = me->get_tag3(); 
    mdr.push_back(dato5);               

}

/**
 * @brief funcion que configura el mdr con el valor
 * entero contenido en una posicion de memoria
 * 
 * @param vm 
 */
void Ciclo_basico::set_mdr_value(M_memory* vm){

    string st_aux1, st_aux2, st_aux3  = "";
    st_aux1 = get_Set_value(vm);
    mdr.clear();
    mdr.push_back(st_aux1);

    // LO NUEVO


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
    cout<<"\nCiclo basico:  PC: " + to_string(get_pc()) + "   MAR: " + get_mar() + "   ACUM: " + to_string(get_acum()) + "   ALU: " + to_string(get_alu()) + "   ICR:" + print_vector(icr) + "   MDR:" + print_vector(mdr) + "   UNIDAD DE CONTROL:" + print_vector(un_control) + " \n";
}

string Ciclo_basico::get_Set_value(M_memory* dm){   

    string value, recet, proof, auxil = "";

    proof = dm->get_dir_adr();

    for (M_memory* mpt : info_men)
    {
        recet = mpt->get_dir_adr();
        auxil = mpt->get_mname();

        if (recet==proof && auxil == "SET")
        {
            value = mpt->get_tag1();
        }
    
    }
    
    return value;
}




/**
 * @brief funcion que genera una pausa y solicita
 * ingresar enter para continuar con la ejecucion
 * del programa.
 * 
 */
void Ciclo_basico::myPause()
{
	std::cout << "\n......PROCESO PAUSADO....Por favor presione ENTER para continuar...\n\n"; 
	std::cin.clear();
	std::cin.sync();
	std::cin.get();
}

string Ciclo_basico::print_vector(vector<string>vst){
    string rect = "";
    int cont = 0;
    for (string ste : vst)
    {
        rect = rect + " " + ste;
        cont ++;
        if (cont>1)
        {
            break;
        }
        
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


vector<M_memory*> Ciclo_basico::to_pause(){

    vector<M_memory*>losSets;

    for (M_memory* ref : info_men)
    {
        if (ref->get_mname()=="SET")
        {
            losSets.push_back(ref);
        }
        
    }

    string encabezado = "\nInformacion del estado de la memoria:\n\n";
    string stposc = "Posicion [ ";
    string tterm = " ] ";
    string ott = "[ ";

    stringstream stt;

    for (M_memory* pp : losSets)
    {
        stt<<stposc;
        string tempo = pp->get_dir_adr();
        stt<<tempo;
        stt<<tterm;
        stt<<ott;
        string ooo = pp->get_tag1();
        stt<<ooo;
        stt<<tterm;
    }
    encabezado = encabezado + stt.str();

    cout<<encabezado<<endl;

    // cout<<"Informacion del estado de la memoria usada\nDireccion de memoria [ " + pp->get_dir_adr() + " ] almacena [ " + pp->get_tag1() + " ] \n";
    
    myPause();
    

    
    return losSets;
}


void Ciclo_basico::load_instruction(){

    int vlr_1, vlr_2, vlr_3, vlr_4=0;
    string recep, stx_4, stx_1, stx_2, stx_3, stx_5, stx_6 = "";

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
            stx_4 = get_Set_value(mm);
            vlr_1 = stoi(stx_4);
            
            set_acum(vlr_1);

        }
        else if (info_men.at(i)->get_mname()=="ADD")
        {
            M_memory* mm = info_men.at(i);
            
            if (mm->get_tag1()=="NULL" && mm->get_tag2()=="NULL" && mm->get_tag3()=="NULL")
            {
                
                set_mar_pc(get_pc());
                set_mdr(mm);
                set_icr(mm);
                pc++;
                set_un_control(mm);
                set_alu(get_acum());
                set_mar(mm->get_dir_adr());
                set_mdr_value(mm);

                stx_1 = mm->get_dir_adr();
                mm = to_store(stx_1);
                stx_4 = mm->get_tag1();

                vlr_1 = stoi(stx_4);
                
                set_acum(vlr_1); 
                set_alu(get_alu() + get_acum());
                set_acum(get_alu());
            }
            else if (mm->get_tag1()!="NULL" && mm->get_tag2()=="NULL" && mm->get_tag3()=="NULL"){

                set_mar_pc(get_pc());
                set_mdr(mm);
                set_icr(mm);
                pc++;
                set_un_control(mm);
                set_alu(get_acum());
                set_mar(mm->get_dir_adr());
                set_mdr_value(mm);


                M_memory* tt = new M_memory();
                tt=mm;

                stx_1 = tt->get_dir_adr();
                tt = to_store(stx_1);
                stx_3 = tt->get_tag1();
                vlr_1 = stoi(stx_3);
                
                stx_2 = mm->get_tag1();
                mm = to_store(stx_2);
                stx_4= mm->get_tag1();
                vlr_2 = stoi(stx_4);

                vlr_3 = vlr_1 + vlr_2;

                set_acum(vlr_3); 
                set_alu(get_alu() + get_acum());
                set_acum(get_alu());

                tt = nullptr;
                delete tt;


            }

            else if (mm->get_tag1()!="NULL" && mm->get_tag2()!="NULL" && mm->get_tag3()=="NULL"){

                set_mar_pc(get_pc());
                set_mdr(mm);
                set_icr(mm);
                pc++;
                set_un_control(mm);
                set_alu(get_acum());
                set_mar(mm->get_dir_adr());
                set_mdr_value(mm);

                M_memory* tt = new M_memory();
                tt=mm;
                
                stx_1 = tt->get_dir_adr();
                tt = to_store(stx_1);
                stx_3 = tt->get_tag1();
                vlr_1 = stoi(stx_3);
                
                M_memory* rr = new M_memory();
                rr=mm;

                
                stx_2 = rr->get_tag1();
                rr = to_store(stx_2);
                stx_4= rr->get_tag1();
                vlr_2 = stoi(stx_4);

                vlr_3 = vlr_1 + vlr_2;

                stx_5 = mm->get_tag2();
                mm = to_store(stx_5);
                mm->set_tag1(to_string(vlr_3));

                mm->mostrar_memoria(); // se verifica nuevo valor

                
                set_acum(vlr_3); 
                set_alu(get_alu() + get_acum());
                set_acum(get_alu());



                tt = nullptr;
                delete tt;

                rr=nullptr;
                delete rr;



            }


        
        }
        else if (info_men.at(i)->get_mname()=="STR")
        {
            M_memory* mm = info_men.at(i);
            set_mar_pc(get_pc());
            set_mdr(mm);
            set_icr(mm);
            pc++;
            set_un_control(mm);
            set_mar(mm->get_dir_adr());
            set_mdr_value(mm);
            string stmem = " ";         
            stmem = mm->get_dir_adr();

            mm = to_store(stmem);

            mm->set_tag1(to_string(get_acum()));

        }
        else if (info_men.at(i)->get_mname()=="SHW")
        {
            M_memory* mm = info_men.at(i);
            set_mar_pc(get_pc());
            set_mdr(mm);
            set_icr(mm);
            pc++;
            set_un_control(mm);
            set_mar(mm->get_dir_adr());
            recep = mm->get_dir_adr();
            mm = to_store(recep);

            mm->mostrar_memoria();

        }
        else if (info_men.at(i)->get_mname()=="INC")
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

            stx_1 = mm->get_dir_adr();
            mm = to_store(stx_1);
            stx_4 = mm->get_tag1();

            vlr_1 = stoi(stx_4) + 1;

            mm->set_tag1(to_string(vlr_1));

            mm->mostrar_memoria();// se verifica nuevo valor
            
    

        }
        else if (info_men.at(i)->get_mname()=="DEC")
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

            stx_1 = mm->get_dir_adr();
            mm = to_store(stx_1);
            stx_4 = mm->get_tag1();

            vlr_1 = stoi(stx_4) - 1;

            mm->set_tag1(to_string(vlr_1));

            mm->mostrar_memoria();// se verifica nuevo valor
            

        }
        else if (info_men.at(i)->get_mname()=="PAUSE")
        {
            M_memory* mm = info_men.at(i);
                        
            set_mar_pc(get_pc());
            set_mdr(mm);
            set_icr(mm);
            pc++;
            set_un_control(mm);

            to_pause();
            

        }









        else if (info_men.at(i)->get_mname()=="END")
        {
            pc++;
            mostrar_ciclo_basico();
        }
        
        
        
    }
    

    
}



