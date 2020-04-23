#pragma once
#include <string>
#include <iostream>
#include "Node.hpp"
namespace family{  
class Tree{
   // Node *root;
public:
    Node *root;
   Tree (string s); 
//   void preorder(Node* node);
   Tree& addFather(string child,string father);
   void addF(Node* child, string name, string father,int a, int b);
   void addM(Node* child, string name, string mother,int a,int b);
   Tree& addMother(string child, string mother);
   string relation (string name);
   void relationHelp(string name, Node* root , int* level , int* gender);
   string find (string relate);
   void findHelp(string name, Node* root , string* tag);
   void display();
   void printPreorder(Node* root);
   void remove (string name);
   void removeHelp(string name , Node* root);
   void deleteTree(Node* root);
   Node* search(Node* root, string name);
};
}