#include "Node.hpp"
Node::Node(string name): name(name), father(NULL), mother(NULL),level(0),gender(-1) {
}
  string Node::getName(){
      return this->name;
  }
    Node* Node:: getFather(){
        return this->father;
    }
    Node* Node:: getMother(){
        return this->mother;
    }
     int Node:: getLevel(){
         return this->level;
     }
    int Node:: getGender(){
        return this->gender;
    }
    void Node:: setLevel(int l){
        this->level=l;
    }
    void Node:: setGender(int g){
        this->gender=g;
    }
 void Node::addFatherNode (string father){
     this->father= new Node(father);
 }
    void Node::addMotherNode (string mother){
        this->mother = new Node(mother);
    }
    void Node::removeFather (){
        delete(this->father);
        this->father=NULL;
    }
    void Node::removeMother (){
        this->mother=NULL;
    }
    Node::~Node(){
        if(this->father != NULL){
            delete(this->father);
        }
        if(this->mother != NULL){
            delete(this->mother);
        }
    }
