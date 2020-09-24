//
//  main.cpp
//  Binary Tree
//
//  Not really created by Cara Drake - taken off CCLE to be used as the example main as instructed
//  Created by Cara Drake on 1/15/20.
// Collaberators: Eden Bui, Chloe Tu, as well as assistance form TA Jason Schuchardt and Big C++ for resources on how to write a BinarySearchTree
//"I pledge that I have neither given nor received unauthorized assistance on this assignment."
//  Copyright © 2020 Cara Drake. All rights reserved.
//
#include"BinarySearchTree.h"
#include <iostream>

int main() {
    
    //check default constructor:
    
    BinarySearchTree mybst;
    
    
    
    //create a BST with data:
    
    mybst.insert("Hi");
    
    mybst.insert("Hello");
    
    mybst.insert("Hey");
    
    mybst.insert("Hola");
    
    
    //check copy constructor:
    
    BinarySearchTree mybst2 (mybst);
    
    
    //check assignment operator:
   
   
    mybst = mybst2;
   // mybst.print();
    
    
    return 0;
}
