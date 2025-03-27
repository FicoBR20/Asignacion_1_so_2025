#include "Prs_run.h"

Prs_run::Prs_run(string nm, string dm, string cp1, string cp2){
    this -> name_prs = nm;
    this -> dir_memo = dm;
    this -> campo1 = cp1;
    this -> campo2 = cp2;
    cout<<"...const1..."<<endl;
}

Prs_run::Prs_run(){
    cout<<"..const2.."<<endl;
}

Prs_run::~Prs_run(){
    cout<<"..destruyendo..."<<endl;
}

void Prs_run::set_name_prs(string nam){
    name_prs = nam;
}
void Prs_run::set_mem(string mm){
    dir_memo = mm;
}
void Prs_run::set_cm1(string cmp1){
    campo1 = cmp1;
}
void Prs_run::set_cm2(string cmp2){
    campo2 = cmp2;
}
string Prs_run::get_name_prs(){
    return name_prs;
}
string Prs_run::get_dmem(){
    return dir_memo;
}
string Prs_run::get_cp1(){
    return campo1;
}
string Prs_run::get_cp2(){
    return campo2;
}