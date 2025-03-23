#ifndef PRUEBA_H
#define PRUEBA_H

#pragma once

#include<iostream>
#include<string>

using namespace std;

class prueba
{
public:
    prueba();
    ~prueba();
    void setPrueba(string pr);
    void printPrueba();

private:
    std::string namePr;

};

#endif