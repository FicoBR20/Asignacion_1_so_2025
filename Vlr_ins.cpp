#include "Vlr_ins.h"

Vlr_ins::Vlr_ins(string nm, string mm, int vl, string ca1, string ca2){
    this -> name_reg = nm;
    this -> ubi_memoria = mm;
    this -> info_valor = vl;
    this -> campo1 = ca1;
    this -> campo2 = ca2;
    cout<<"..const1.."<<endl;
}

Vlr_ins::Vlr_ins(){ //constructor con 1 parametro
    cout<<"..const2.."<<endl;
};

Vlr_ins::~Vlr_ins(){
    cout<<"..destruyendo.."<<endl;
}

void Vlr_ins::set_name_vi(string sr){
    name_reg = "SET";
}

void Vlr_ins::set_ubm(){

    int dir_select = rand() % 5;


    ubi_memoria = "c2";
}

void Vlr_ins::set_vlr(int vl){
    info_valor = vl;
}

void Vlr_ins::set_cp1(){
    campo1 = "NULL";
}

void Vlr_ins::set_cp2(){
    campo2 = "NULL";
}


string Vlr_ins::get_name_reg(){
    return name_reg;
}

string Vlr_ins::get_ubi_mem(){
    return ubi_memoria;
}

int Vlr_ins::get_valor(){
    return info_valor;
}

string Vlr_ins::get_cam1(){
    return campo1;
}

string Vlr_ins::get_cam2(){
    return campo2;
}





