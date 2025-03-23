/**
 * Archivo: lectora.cpp
 * Autor: federico.barbetti@correounivalle.edu.co
 * Fecha creacion: 2025-03-22
 * Fecha ultima modificacion: 2025-03-22
 * Licencia: GNU-GPL
 */

 #include<iostream>
 #include<fstream>
 #include<vector>
 #include<algorithm>
 #include<sstream>
 #include<string>


using namespace std;


string contenedor = "/home/fede/Documents/univalle_homeworks/s2025-SistemasOPerativos/Assignament_1/memo_1.txt";

string* ptr = &contenedor;

/**
 * @brief Construct a new std::vector<string>lectura archivo object
 * Funcion que usa una referencia a un archivo de texto formateado, procediendo
 * a leerlo y asi generar un vector de strings con el contenido
 * del mismo.
 * 
 */
std::vector<string>lectura_archivo(){

    vector<string>datosLimpios;                //recolectara los datos leidos
    
    ifstream mylector(*ptr);                      //objeto stream de lectura
    
    char muestra_simbolo;                               //contenedor de cada simbolo leido
    
    std::string st5;                     //receptor de cadena formateada with final symbol
    
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
                        
                        getline(mylector, st5,'\n');
                        datosLimpios.push_back(st5);    //fill vector
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
    cout<<"El size del vector es; "<<datosLimpios.size()<<endl;
    
    for(string x : datosLimpios){
        cout<<"El string es :\n"<<x<<" \ny el size del vector es; "
        <<datosLimpios.size()<<endl;
    }

    return datosLimpios;
  
}

int main(int argc, char const *argv[]){

    vector<string>registros_leidos;                //recolectara los datos leidos

    registros_leidos = lectura_archivo();

    cout<<"Gracias a Dios"<<endl;

    return 0;
}
