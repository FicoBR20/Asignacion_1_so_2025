
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



// /**
//  * @brief total de posiciones de memoria
//  * que se usaran del total de disponibles
//  * Debe ser <= 10
//  *  */
// const int cant_dir = 5;

// /**
//  * @brief Entrega un numero entero aleatorio
//  * en el rango [0;lim]
//  * @param lim 
//  * @return int 
//  */
// int termino_alea(int lim){

//     int aleato = rand() % lim;

//     cout<<"soy aleato "<<to_string(aleato)<<endl;

//     return aleato;

// }


// /**
//  * @brief Funcion que informa si un string
//  * se encuentra dentro de un vector de strings
//  * 
//  * @param buscado 
//  * @param my_num 
//  * @return true 
//  * @return false 
//  */
// bool esta_dentro(string buscado, vector <string> my_num){
    
//     bool existe = false;

//     for (string dentro : my_num)
//     {
//         if (dentro == buscado)
//         {
//             existe = true;
//         }
        
//     }
//     return existe;
    
// }


// /**
//  * @brief Funcion que entrega un vector de string el cual
//  * contiene las "direcciones de memoria" que se usaran, tomadas
//  * del las direcciones disponibles
//  * 
//  * @return std::vector<string> 
//  */
// std::vector<string> avalaible_address(){

//     /**
//      * @brief vector con las direcciones de memoria
//      * disponibles
//      */
//     std::vector<string> disponibles= {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
//     /**
//      * @brief vector que contendra las posiciones de memoria
//      * seleccionadas para usar
//      */
//     std::vector<string> usadas;

//     /**
//      * @brief varible auxilidar para el ciclo
//      * toma el mismo valor del total de las posiciones
//      * de memoria a usar
//      *
//      */
//     int limite_memoria = cant_dir;

//     /**
//      * @brief variable receptora
//      * para uso en el ciclo
//      * 
//      */
//     string receptor = "";

//     // ciclo

//     /**
//      * @brief Ciclo que configura el contenido
//      * final con las direcciones de memoria a usar
//      * 
//      */
//     for (int i = 0; i < limite_memoria; i++)
//     {
//         int sel_dir = termino_alea(disponibles.size());

//         receptor = disponibles.at(sel_dir);

//         if (esta_dentro(receptor,usadas))
//         {
//             usadas.clear();
//             cout<<"...borrada..usadas.."<<endl;
//             avalaible_address();
//         }
//         else
//         {
//             usadas.push_back(receptor);
//         }

//     }


//     /**
//      * @brief ciclo para verificacion del proceso
//      * 
//      * @param usadas 
//      */
//     for (string mem : usadas)
//     {
//         cout<<"Las que QUEDAN y se van a usar " + mem <<endl;
//     }

//     return usadas;
// }






int main(){
    
    inicializar_ran();

    vector<string>listan = {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};

    Motor mt;

    mt.avalaible_address();
    
    Prs_run *pr;
    pr = new Prs_run();
    pr->set_name_prs("prueba");

    Vlr_ins *vi;
    vi = new Vlr_ins("SET", "89IPu85", 80, "NULL", "NULL");
    vi->set_vlr(180);
    
    int limite = 100;


    cout<<"hola cpp, imprimo el nombre del objeto Prs_run " + pr->get_name_prs()<<endl;
    cout<<"hola cpp, imprimo el valor del objeto Vlr_ins " + to_string(vi->get_valor())<<endl;

    delete pr, vi;

    return 0;
}
