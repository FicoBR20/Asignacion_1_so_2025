
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<array>

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

std::array<string,5> avalaible_address(){

    /**
     * @brief arreglo con las posiciones de memoria
     * disponibles
     */
    std::array<string,10> disponibles= {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
    /**
     * @brief Posiciones de memoria
     * seleccionadas para usar
     */
    std::array<string,5> usadas; //array with length 5


    int lmt = usadas.size();
    

    // for (int i = 0; i < lmt; i++)
    // {
    //     int aleatorio = rand() % lmt;
    //     cout<<to_string(aleatorio)<<endl;
    // }








    cout<<" aqui voy "<<endl;

    return usadas;
}






int main(){

    inicializar_ran();

    avalaible_address();
    

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
