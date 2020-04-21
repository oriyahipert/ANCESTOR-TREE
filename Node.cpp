#include "Node.hpp"
Node::Node(string name): name(name), father(NULL), mother(NULL) {
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
 void Node::addFather (string father){
     this->father= new Node(father);
 }
    void Node::addMother (string mother){
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
