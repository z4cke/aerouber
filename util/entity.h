/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   entity.h
 * Author: simjoh161
 *
 * Created on October 4, 2017, 2:32 PM
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>


class entity {
public:
    entity(int a, int b, int c):a(a), b(b), c(c){}
    
    friend std::string& operator <<(std::string &s, const entity& e );
    
private:
    int a, b, c;
};

#endif /* ENTITY_H */

