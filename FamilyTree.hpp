#pragma once
#include <string>
#include <iostream>
#include "Node.hpp"
namespace family{  
class Tree{
    Node *root;
public:
   Tree (string s); 
  void Preorder(Node* node);
   Tree& addFather(string child,string father);
   Tree& addMother(string child, string mother);
   string relation (string name);
   string find (string relate);
   void display();
   void remove (string name);
};
}