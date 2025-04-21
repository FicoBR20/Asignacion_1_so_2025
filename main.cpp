/**
 * @file main.cpp
 * @author federico.barbetti@correounivalle.edu.co
 * @brief se procesa informacion para obtener el resultado
 * final del valor almacenado en el componente "alu"
 * @version 0.1
 * @date 2025-04-19
 * 
 * @copyright GNU-GPL
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include <cstdlib>
#include <ctime>


#include "Ciclo_basico.h"

using namespace std;

/**
 * @brief inicia gestor random
 * 
 */
void inicializar_ran(){
    srand(time(NULL));
}

vector<std::string> the_instructions {"SET", "LDR", "ADD", "INC", "DEC", "STR", "SHW", "PAUSE", "END"};

vector<std::string> the_aval_address {"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10"};

/**
 * @brief contenedor de los registros leidos
 * 
 */
std::vector<M_memory*>memoria_ocupada;


/**
 * @brief llenado de arreglo memoria_ocupada con los datos
 * leidos del archivo de texto.
 * 
 * @param cont 
 */
void lectura_archivo(string cont){
    
    ifstream mylector(cont);                  
    
    char muestra_simbolo;                     
    
    std::string st1, st2, st3, st4, st5;
    
    std::string for_used_lines = "";
    
    int curr_post = 0;


    if (mylector.is_open())
    {
        do
        {
            
            curr_post=mylector.tellg();  
            muestra_simbolo=mylector.get(); 
            getline(mylector, for_used_lines, '\n');
    
            if (!mylector.fail()) 
            {
    
                if ( muestra_simbolo != '#' || muestra_simbolo=='\n')
                {
                    mylector.seekg(curr_post, ifstream::beg);
                    
                    if(!for_used_lines.empty() && muestra_simbolo!='\0')
                    {
                        getline(mylector, st1,' ');
                        getline(mylector, st2,' ');
                        getline(mylector, st3,' ');
                        getline(mylector, st4,' ');
                        getline(mylector, st5,'\n');
                        //creando objetos
                        if (st1 == "SET")
                        {
                            M_memory *mm;
                            mm = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(mm);
                            
                        }
                        else if (st1 == "LDR")
                        {
                            M_memory *ff;
                            ff = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(ff);
                        }
                        else if (st1 == "ADD")
                        {
                            M_memory *dd;
                            dd = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(dd);
                        }
                        else if (st1 == "INC")
                        {
                            M_memory *ii;
                            ii = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(ii);
                        }
                        else if (st1 == "DEC")
                        {
                            M_memory *de;
                            de = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(de);
                        }
                        else if (st1 == "STR")
                        {
                            M_memory *st;
                            st = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(st);
                        }
                        else if (st1 == "SHW")
                        {
                            M_memory *sh;
                            sh = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(sh);
                        }
                        else if (st1 == "PAUSE")
                        {
                            M_memory *ps;
                            ps = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(ps);
                        }
                        else if (st1 == "END")
                        {
                            M_memory *en;
                            en = new M_memory(st1, st2, st3, st4, st5);
                            memoria_ocupada.push_back(en);
                        }
                        
                        
                    }
                
                    
                }
                    
            }
            
        } while (!mylector.fail());
        
    }
    mylector.close();

      
}

void iniciacion(string cal){

    
    inicializar_ran();
    
    //recurso de los datos contenidos en un archivo de texto.
    string ubicacion = cal;
    
    //captura de datos en vector.
    lectura_archivo(ubicacion);
    
    if (memoria_ocupada.size()>0)
    {
        cout<< "\x1B[32m"<<"\n\n================================ B I E N V E N I D O ================================================\n"<<endl;
        cout<<"=========================== PROGRAMA INICIADO EXITOSAMENTE ==========================================\n\n\033[0m";
        
        
        //procesamiento de datos.
        Ciclo_basico* cb;
        cb=new Ciclo_basico();
        cb->set_instrucciones(memoria_ocupada);         // tomamos los datos a procesar
        cb->load_instruction();                         // cargamos las operaciones sobre los datos
        
        int respuesta_final = cb->get_alu();            // total almacenado en la alu
        
        cout<<"\nEl total almacenado en la unidad logica es: " + to_string(respuesta_final) + " \n\n";
        
        delete cb;
        
    }
    else{
        std::cout << "\033[1;41;37m\nAdvertencia: Favor verifique los datos ingresados.\033[0m\n"<<endl;
    }

    

}


int main(int argc, char const *argv[])
{
    string started = "";

    if (argc<2)
    {
        std::cout << "\033[1;41;37m\nAVISO: Se debe ingresar como parametro el nombre del archivo de texto que contiene los datos a procesar\033[0m\n"<<endl;
        return 0;
    }
    else if (argc==2)
    {
        started = argv[1];
        cout<<"\nAVISO: El dato que usted ingreso es: " + started <<endl;
    }
    
    


    iniciacion(started);

    //Proceso de liberacion de la memoria
    
    for (M_memory* pm : memoria_ocupada)
    {
        pm = nullptr;
    }
    
    memoria_ocupada.clear();
    
    //Agradecimiento infinito.
    // cout<<"Gracias a Dios\n"<<endl;
    std::cout << "\033[1;34mGracias a Dios\n\n\033[0m" << std::endl;
    
    
    

    
    


    return 0;
}
