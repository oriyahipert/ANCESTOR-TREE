#include "FamilyTree.hpp"
#include <iostream>
using namespace family;
//using namespace std;
Tree& family::Tree::addFather(string name, string father){
    return *this;

}
Tree& family::Tree::addMother(string name, string mother){
    return *this;
}
string family::Tree:: relation(string name){
    return "relation";
}
string family::Tree::find(string name){
    return "find";
}
void family::Tree::remove(string name){

}
void family::Tree::display(){
}


//    string relation (string name){
//        return "name";
//    }
//    string find (string relate){
//        return "relate";
//    }
//    void display(){
//        printf("family");
//    }
//    void remove (string name){
//        printf("remove");
//    }
