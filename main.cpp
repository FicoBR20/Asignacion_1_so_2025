#include <iostream>
#include <string>
#include <vector>
#include<fstream>


#include "Ciclo_basico.h"

using namespace std;

// string contenedor = "/home/fede/Documents/univalle_homeworks/s2025-SistemasOPerativos/Assignament_1/memo_1.txt";

std::vector<M_memory*>memoria_ocupada;




/**
 * @brief funcion que lee un archivo de texto y transforma lo leido
 * en objetos M_memory para asi llenar el vector memoria ocupada
 * 
 * @param cont 
 */
void lectura_archivo(string cont){

    // vector<string>datosLimpios;                //recolectara los datos leidos
    
    ifstream mylector(cont);                      //objeto stream de lectura
    
    char muestra_simbolo;                               //contenedor de cada simbolo leido
    char comodin = ' ';                               //cambia el final del string a un espaciador.
    
    std::string st1, st2, st3, st4, st5;                     //receptor de cadena formateada with final symbol
    
    std::string for_used_lines = "";                         //contenedor de linea leida
    
    int curr_post = 0;                                  //contenedor de posicion de lectura



    if (mylector.is_open())
    {
        do
        {
            
            curr_post=mylector.tellg();             //posicion de lectura
            muestra_simbolo=mylector.get();         //actual caracter leido
            getline(mylector, for_used_lines, '\n');//buffer lector, string receptor, symbol reading stop condition
    
            if (!mylector.fail()) 
            {
    
                if ( muestra_simbolo != '#' || muestra_simbolo=='\n')//restriccion a comentarios con #
                {
                    mylector.seekg(curr_post, ifstream::beg); //se mueve la posicion de lectura referenciando el inicio
                    
                    if(!for_used_lines.empty() && muestra_simbolo!='\0') //terminador
                    {
                        /* code */

                        getline(mylector, st1,' ');
                        getline(mylector, st2,' ');
                        getline(mylector, st3,' ');
                        getline(mylector, st4,' ');
                        getline(mylector, st5,'\n');
                        // datosLimpios.push_back(st1);
                        // datosLimpios.push_back(st2);
                        // datosLimpios.push_back(st3);
                        // datosLimpios.push_back(st4);
                        // datosLimpios.push_back(st5);
                        
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

    /**
     * @brief se imprime el vector
     * para verificacion del resultado
     * 
     */
    // cout<<"El size del vector es; "<<datosLimpios.size()<<endl;
    
    // for(string x : datosLimpios){
    //     cout<<"El string es :\n"<<x<<" \ny el size del vector es; "
    //     <<datosLimpios.size()<<endl;
    // }

    for (int i = 0; i < memoria_ocupada.size(); i++)
    {
        memoria_ocupada.at(i)->mostrar_memoria();
    }
    
    

    // return datosLimpios;
  
}





int main(int argc, char const *argv[])
{
    //recurso de datos
    string ubicacion = "/home/fede/Documents/univalle_homeworks/s2025-SistemasOPerativos/Assignament_1/memo_1.txt";
    
    //llenado de memoria con datos leidos (vector memoria_ocupada)
    lectura_archivo(ubicacion);


    Ciclo_basico* cb;
    cb=new Ciclo_basico();
    cb->set_instrucciones(memoria_ocupada);
    cb->set_pc();



    //probador cout============

    cout<<"...prueba de proceso.." + to_string(cb->get_pc())+" \n";

    //========================

    
    cb->mostrar_ciclo_basico();

    for (M_memory* mm : memoria_ocupada)
    {
        mm->mostrar_memoria();
        
    }
    

    


    
    
    cout<<"Gracias a Dios"<<endl;

    for (M_memory* pm : memoria_ocupada)
    {
        pm=NULL;
        delete pm;
    }

    cout<<to_string(memoria_ocupada.size())<<endl;

    delete cb;
    

    
    return 0;
}
