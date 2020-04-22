#include "FamilyTree.hpp"
#include <iostream>
using namespace family;
//using namespace std;
     Tree:: Tree (string s) {
         this->root = new Node(s);
     }

//     void preorder(Node* temp) { 
//     if (!temp) 
//         return; 
//     preorder(temp->getName);
//     preorder(temp->getFather); 
//     preorder(temp->getMother); 
// } 

void Tree::addF(Node* child, string name, string father,int a, int b){
    	if (child->getName() == name){
            child->addFatherNode(father);
             child->getFather.setLevel(a);
            child->getFather.setGender(0);

        }
        else{
            a++;
            addF(child->getFather(), name, father,a,0);
            addF(child->getMother(), name, father,a,0);
            
        }
}

Tree& Tree::addFather(string name, string father){
		  addF(root, name,father,0,0);
          return *this;

}
void Tree::addM(Node* child, string name, string mother,int a,int b){
    	if (child->getName() == name){
            child->addMotherNode(mother);
             child->getMother.setLevel(a);
            child->getMother.setGender(1);
            
        }
        else{
            a++;
            addM(child->getFather(), name, mother,a,1);
            addM(child->getMother(), name, mother,a,1);
        }
}
Tree& Tree::addMother(string name, string mother){
    addM(root, name,mother,0,1);
    return *this;
}
string Tree:: relation(string name){
  return relationHelp(name,root);
}
string Tree:: relationHelp(string name, Node* root){
    if(root->getName == name){
        if(root->getLevel==0){
            return "me";
        }
        else if(root->getLevel == 1){
            if(root->getGender==0){
                return "father";
            }
            else  {
                return "mother";
            } 
        }
        else if(root->getLevel==2){
            if(root->getGender==0){
                return "grandfather";
            }
            else  {
                return "grandmother";
            } 
        }
        else{
            if(root->getGender==0){
                return (root->getLevel-2) * ("graet-") + "grandfather";
            }
            else  {
                return (root->getLevel-2) * ("graet-") + "grandmother";
            } 
        }
    }

}

string Tree::findHelp(string name, Node* root){
    int temp=-1;
    if(name=="me"){
        return root->getName();
    }
    else if(name == "father"){
        return root->getFather()->getName();
    }
    else if(name == "mother"){
        return root->getMother()->getName();
    }
    else if (name == "grandmother"){
            return root->getMother()->getMother()->getName();
    }
    else if(name=="grandfather"){
            return root->getFather()->getFather()->getName();
    }
    else
    {
        findHelp(name.substr(6),root->getMother());
        findHelp(name.substr(6),root->getFather());

    }
    
}
string Tree::find(string name){
    return findHelp(name, root);
}
void Tree::remove(string name){

}
void Tree::display(){
    //    if (root == NULL) 
    //     return; 
  
    // /* first print data of node */
    // cout << node->data << " "; 
  
    // /* then recur on left sutree */
    // printPreorder(node->left);  
  
    // /* now recur on right subtree */
    // printPreorder(node->right); 
  
}



