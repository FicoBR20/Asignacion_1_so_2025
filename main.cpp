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


#include "Ciclo_basico.h"

using namespace std;

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

    //verificacion

    // for (int i = 0; i < memoria_ocupada.size(); i++)
    // {
    //     memoria_ocupada.at(i)->mostrar_memoria();
    // }
      
}


int main(int argc, char const *argv[])
{
    //recurso de los datos contenidos en un archivo de texto.
    string ubicacion = "/home/fede/Documents/univalle_homeworks/s2025-SistemasOPerativos/Laboratorio_1_2025/memo_1.txt";
    
    //captura de datos en vector.
    lectura_archivo(ubicacion);

    //procesamiento de datos.
    Ciclo_basico* cb;
    cb=new Ciclo_basico();
    cb->set_instrucciones(memoria_ocupada); // tomamos los datos a procesar
    cb->load_instruction(); // cargamos las operaciones sobre los datos

    int respuesta_final = cb->get_alu();

    cout<<"El total almacenado en la unidad logica es: " + to_string(respuesta_final) + " \n";

    
    
    //Proceso de liberacion de la memoria
    
    for (M_memory* pm : memoria_ocupada)
    {
        pm = nullptr;
    }
    
    memoria_ocupada.clear();
    delete cb;
    
    //Agradecimiento infinito.
    cout<<"Gracias a Dios"<<endl;

    return 0;
}
