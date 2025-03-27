
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<array>
#include<vector>

#include "Prs_run.h"
#include "Vlr_ins.h"
#include "Motor.h"

using namespace std;




/**
 * @brief inicia gestor random
 * 
 */
void inicializar_ran(){
    srand(time(NULL));
}




int main(){
    
    inicializar_ran();

    std::vector<string>listan = {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};

    Motor mt;


    mt.set_aval_address();
    
    Prs_run *pr;
    pr = new Prs_run();
    pr->set_name_prs("prueba");

    Vlr_ins *vi;
    vi = new Vlr_ins("SET", "89IPu85", 80, "NULL", "NULL");
    vi->set_vlr();
    vi->set_ubm(listan);

    vi->mostrar_set();
    
    int limite = 100;


    cout<<"hola cpp, imprimo el nombre del objeto Prs_run " + pr->get_name_prs()<<endl;
    cout<<"hola cpp, imprimo el valor del objeto Vlr_ins " + to_string(vi->get_valor())<<endl;

    delete pr, vi;

    return 0;
}