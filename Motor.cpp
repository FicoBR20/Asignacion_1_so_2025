#include "Motor.h"


Motor::Motor()
{
    CANT_DIR;

}

Motor::~Motor()
{

}


/**
 * @brief Funcion auxiliar que entrega un numero entero aleatorio
 * en el rango [0;lmt]
 * @param lmt 
 * @return int 
 */
int Motor::number_aleat(int lmt){
    int aleato = rand() % lmt;
    return aleato;

}

/**
 * @brief Funcion booleana auxiliar que determina si un string
 * se encuentra dentro de un vector de strings
 * 
 * @param buscado 
 * @param my_num 
 * @return true 
 * @return false 
 */
bool Motor::esta_dentro(string buscado, vector <string> my_num){
    
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
 * @brief configuracion del conjunto de direcciones
 * de memoria a usar.
 * 
 */
vector<string> Motor::set_mem_finales(vector<string>recursos){

    string receptor = "";

    int temp = recursos.size();

    for (int i = 0; i < CANT_DIR; i++)
    {
        int sel_dir = number_aleat(temp);

        receptor = recursos.at(sel_dir);

        if (esta_dentro(receptor,mem_finales))
        {
            cout<<" pucha.. borro todo y recomienzo..\n";
            mem_finales.clear();
            set_mem_finales(recursos);
        }
        else
        {
            mem_finales.push_back(receptor);
        }

    }

    if (mem_finales.size()==5)
    {
        
        for (string stg : mem_finales)
        {
            cout<<"La memoria es: " + stg + " el size es: " + to_string(mem_finales.size())+ "\n";
        }
    }
    


    return mem_finales;
    

}

vector<string>st_verificado(string sel, int chec, vector<string>sbs){
    chec --;
    if (chec > 0)
    {
        sbs.push_back(sel);
    }
    return sbs;
}

vector<string> Motor::set_inst_finales(vector<string>rbh){

    vector<string>list_str;

    int i_set = 5;
    int i_ldr = number_aleat(3)+1;
    int i_add = number_aleat(4)+1;
    int i_str = number_aleat(3)+1;;
    int i_shw = number_aleat(2)+1;;
    int i_pau = number_aleat(2)+1;;
    int i_end = 1;
    int i_inc = 1;
    int i_dec = 1;

    int sum_elem = i_set + i_ldr + i_add + i_str + i_shw + i_pau +i_end + i_inc + i_dec;

    std::map<string, int> parejas = {{"SET", i_set}, {"LDR", i_ldr},{"ADD", i_add},{"STR", i_str},{"SHW", i_shw},{"PAUSE",i_pau},{"END", i_end},{"INC", i_inc},{"DEC", i_dec}};

    int lim_sel = rbh.size();

    
    for (int i = 0; i < sum_elem; i++)
    {
        int asig_p = number_aleat(lim_sel);
        string temp = rbh.at(asig_p);
        int sec = parejas.at(temp);
        st_verificado(temp,sec,list_str);
    }

    //verificacion

    for (string stt : list_str)
    {
        cout<<"Las instrucciones son: " + stt + " \n";
    }

    return list_str;

}



std::vector<std::string> Motor::get_mem_finales(){

    return mem_finales;
}

std::vector<std::string> Motor::get_inst_finales(){

    return inst_finales;
}






