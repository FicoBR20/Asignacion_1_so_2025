
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>

#include "Prs_run.h"
#include "Vlr_ins.h"

using namespace std;
/**
 * @brief inicia gestor random
 * 
 */
void inicializar_ran(){
    srand(time(NULL));
}

/**
 * @brief total de posiciones de memoria
 * que se usaran del total de disponibles
 *  */
const int cant_dir = 5;

string avalaible_address[](){

    /**
     * @brief arreglo con las posiciones de memoria
     * disponibles
     */
    std::string aval_addr[10] = {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
    /**
     * @brief Posiciones de memoria
     * seleccionadas para usar
     */
    std::string addr_mem[cant_dir]{};






    return fin_mem[5];
}






int main(){

    inicializar_ran();
    

    Prs_run *pr;
    pr = new Prs_run();
    pr->set_name_prs("prueba");

    Vlr_ins *vi;
    vi = new Vlr_ins("SET", "89IPu85", 80, "NULL", "NULL");
    vi->set_vlr(180);
    
    int limite = 100;

    
    for (int i = 0; i < 6; i++)
    {
        int aleatorio = rand() % limite;
        cout<<to_string(aleatorio)<<endl;
    }
    

    cout<<"hola cpp, imprimo el nombre del objeto Prs_run " + pr->get_name_prs()<<endl;
    cout<<"hola cpp, imprimo el valor del objeto Vlr_ins " + to_string(vi->get_valor())<<endl;

    delete pr, vi;

    return 0;
}
