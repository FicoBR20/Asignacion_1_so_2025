#ifndef VLR_INS_H
#define VLR_INS_H

#include<iostream>
#include<string>
#include<vector>

using namespace std;

#pragma once

/**
 * @brief Clase que representa la instruccion
 * SET
 * 
 */
class Vlr_ins{
    private:
        std::string name_reg;        //identificacion de la instruccion.
        std::string ubi_memoria;     //direccion de memoria de la instruccion.
        int info_valor;         //valor entero a ser transado.
        std::string campo1;          //campo adicional a ser usado.
        std::string campo2;          //campo adicional a ser usado.

    public:
        Vlr_ins(string nam, string mem, int vlr, string c1, string c2);
        Vlr_ins();
        ~Vlr_ins();

        void set_name_vi();
        void set_ubm(std::vector<std::string> ubi);
        void set_vlr(int vl);
        void set_cp1();                             // default NULL
        void set_cp2();                             // default NULL
        string get_name_reg();
        string get_ubi_mem();
        int get_valor();
        string get_cam1();
        string get_cam2();

        void mostrar_set();


};

#endif