#include "FamilyTree.hpp"
#include <iostream>
using namespace family;
//using namespace std;
     Tree:: Tree (string s) {
         this->root = new Node(s);
     }

     void preorder(Node* temp) { 
    if (!temp) 
        return; 
    preorder(temp->getName);
    preorder(temp->getFather); 
    preorder(temp->getMother); 
} 

Tree& Tree::addFather(string name, string father){
		if (root->getName = name){
            root->addFather = new Node (father);
        }
        else{
            
            addFather()
        }   
			double select = generator.nextDouble();
			System.out.printf("%5.2f  ",select);
			if (select < 0.5){
				node.left = add(data, node.left);
				return node;
			}
			else{ 
				node.right = add(data, node.right);
				return node;
			}
		}
		else{
			return  new BTNode(data);
		}
	}

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

