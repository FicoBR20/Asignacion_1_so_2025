
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<string>

#include "Prs_run.h"
#include "Vlr_ins.h"

using namespace std;


int main(){

    Prs_run *pr;
    pr = new Prs_run();
    pr->set_name_prs("prueba");

    Vlr_ins *vi;
    vi = new Vlr_ins("SET", "89IPu85", 80, "NULL", "NULL");
    vi->set_vlr(180);
    
    int limite = 100;

    srand(time(0));
    
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
