#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace family{  
class Tree{
    string root;
   public:
   Tree (string s){
       this->root=s;
   }; 
   Tree& addFather(string child,string father);
   Tree& addMother(string child, string mather);
   string relation (string name);
   string find (string relate);
   void display();
   void remove (string name);
};
}