#ifndef ERREUR_H
#define ERREUR_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

// Exception personnalisée pour message d'erreur pour chaque cas  
class Erreur : public exception {
    string msg;
public:
    Erreur(const string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

#endif