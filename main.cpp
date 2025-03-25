
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>
#include<array>
#include<vector>

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
 * @brief Entrega un numero entero aleatorio
 * en el rango [0;lim]
 * @param lim 
 * @return int 
 */
int termino_alea(int lim){

    int aleato = rand() % lim;

    cout<<"soy aleato "<<to_string(aleato)<<endl;

    return aleato;

}

bool esta_dentro(int buscado,std::vector<int>listanumerica){

    bool existe;


    for (int x : listanumerica)
    {
        if (buscado==x) 
        {
            existe=true;
            cout<<" si esta dentro " + existe<<endl;
            return existe;
        }
        
    }
    cout<<"...NO esta dentro ...." + existe <<endl;
    return existe;
    
}






/**
 * @brief total de posiciones de memoria
 * que se usaran del total de disponibles
 * Debe ser <= 10
 *  */
const int cant_dir = 5;
/**
 * @brief funcion que selecciona aleatoriamente
 * 5 posiciones de memoria de las disponibles
 * 
 * @return std::array<string,5> 
 */
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
    std::array<string,cant_dir> usadas = {"cahondo", "roch", "pujs", "dfus", "fse"}; //array with length 5


    int lmt = usadas.size();

    while (lmt<6)
    {
        int temp; // recepciona int random

        for (int i = 0; i < lmt; i++)
       {
           int aleatorio = rand() % disponibles.size();
           usadas.at(i)=disponibles.at(aleatorio);
           disponibles.at(aleatorio)="BAD";

           cout<<"Posiciones seleccionadas" + to_string(aleatorio)<<endl;
       }


        cout<<"voy sumando bien"<<endl;
        lmt ++;
    }
    

    cout<<" aqui voy "<<endl;

    for (string mem : usadas)
    {
        cout<<"Las que se van a usar " + mem <<endl;
    }

    for (string mem : disponibles)
    {
        cout<<"Como quedan las disponibles " + mem <<endl;
    }
    

    return usadas;
}






int main(){

    inicializar_ran();

    avalaible_address();

    termino_alea(5);

    std::vector<int>listan = {1,2,3,4};

    esta_dentro(2, listan);
    esta_dentro(4,listan);
    esta_dentro(6,listan);


    

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
