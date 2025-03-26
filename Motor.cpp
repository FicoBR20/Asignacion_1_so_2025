#include "Motor.h"

Motor::Motor()
{

}

Motor::~Motor()
{

}

const int Motor::CANT_DIR=5;

/**
 * @brief Configuracion del contenido para el vector
 * de los nombres de las instrucciones
 * @return std::vector 
 */
std::vector<string> Motor::set_Vect_intr(){

    instru = {"LDR", "ADD", "INC", "DEC", "STR", "SHW", "PAUSE", "END"};

    return instru;
}



/**
 * @brief Entrega un numero entero aleatorio
 * en el rango [0;lmt]
 * @param lmt 
 * @return int 
 */
int number_aleat(int lmt){
    int aleato = rand() % lmt;
    cout<<" aleatorio es "<<to_string(aleato)<<endl;
    return aleato;

}

/**
 * @brief Funcion que informa si un string
 * se encuentra dentro de un vector de strings
 * 
 * @param buscado 
 * @param my_num 
 * @return true 
 * @return false 
 */
bool esta_dentro(string buscado, vector <string> my_num){
    
    bool existe = false;

    for (string dentro : my_num)
    {
        if (dentro == buscado)
        {
            existe = true;
        }
        
    }
    return existe;
    
}

/**
 * @brief Funcion que entrega un vector de string el cual
 * contiene las "direcciones de memoria" que se usaran, tomadas
 * del las direcciones disponibles
 * 
 * @return std::vector<string> 
 */
std::vector<string> Motor::avalaible_address(){

    /**
     * @brief vector con las direcciones de memoria
     * disponibles
     */
    std::vector<string> disponibles= {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};
    /**
     * @brief vector que contendra las posiciones de memoria
     * seleccionadas para usar
     */
    std::vector<string> usadas;

    /**
     * @brief varible auxiliar para el ciclo
     * toma el mismo valor del total de las posiciones
     * de memoria a usar
     *
     */
    int limite_memoria = CANT_DIR;

    /**
     * @brief variable receptora
     * para uso en el ciclo
     * 
     */
    string receptor = "";

    // ciclo

    /**
     * @brief Ciclo que configura el contenido
     * final con las direcciones de memoria a usar
     * 
     */
    for (int i = 0; i < limite_memoria; i++)
    {
        int sel_dir = number_aleat(disponibles.size());

        receptor = disponibles.at(sel_dir);

        if (esta_dentro(receptor,usadas))
        {
            usadas.clear();
            cout<<"...borrada..usadas.."<<endl;
            avalaible_address();
        }
        else
        {
            usadas.push_back(receptor);
        }

    }


    /**
     * @brief ciclo para verificacion del proceso
     * 
     * @param usadas 
     */
    for (string mem : usadas)
    {
        cout<<"Las que QUEDAN y se van a usar " + mem <<endl;
    }

    my_mfin = usadas;

    return my_mfin;
}




// /**
//  * @brief crear una instruccin de tipo SET
//  * 
//  */
// void Motor::generar_Set(){
//     Vlr_ins vset;
//     vset.set_name_vi(val);
//     int val = rand() % 100;
//     vset.set_vlr();
//     vset.set_ubm()

// }