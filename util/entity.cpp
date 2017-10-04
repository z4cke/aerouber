/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "entity.h"

std::string& operator <<(std::string &s, const entity& e ){
    s = std::to_string(e.a) + " " + std::to_string(e.b) +  " " + std::to_string(e.c);
    return s;
}
