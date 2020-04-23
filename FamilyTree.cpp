#include "FamilyTree.hpp"
#include <iostream>
using namespace family;

Tree:: Tree (string s)
{
    this->root = new Node(s);
}

Tree& Tree::addFather(string name, string father)
{
	addF(root, name,father,0,-1);
    return *this;
}

void Tree::addF(Node* child, string name, string father,int a, int b)
{
    if(search(root , name) == NULL)
    {
        throw("");
    }
    if(child == NULL){return;}
    if (child->getName() == name)
    {
        if(child->getFather() != NULL)
        {
            __throw_runtime_error("there is alredy a father");
        }
        else
        {
            a++;
            child->addFatherNode(father);
            child->getFather()->setLevel(a);
            child->getFather()->setGender(0);
            return;
        }
    }
    else
    {
        a++;
        if(child->getFather() != NULL)
        {
            addF(child->getFather(), name, father,a,0);
        }
        
        
        if(child->getMother() != NULL)
        {
            addF(child->getMother(), name, father,a,0);
        }
        
    }
    
    // __throw_out_of_range("");
}

Tree& Tree::addMother(string name, string mother)
{
    addM(root, name,mother,0,1);
    return *this;
}

void Tree::addM(Node* child, string name, string mother,int a,int b)
{
    if(search(root , name) == NULL)
    {
        throw("");
    }
    if(child == NULL){return;}
    if (child->getName() == name)
    {
        if(child->getMother() != NULL)
        {
            __throw_out_of_range("there is alredy a mother");
        }
        else
        {
            a++;
            child->addMotherNode(mother);
            child->getMother()->setLevel(a);
            child->getMother()->setGender(1);
            return;
        }  
    }
    else
    {
        a++;
        if(child->getFather() != NULL)
        {
            addM(child->getFather(), name, mother,a,1);
        }
        if(child-> getMother() != NULL)
        {
            addM(child->getMother(), name, mother,a,1);
        }
    }
}


string Tree:: relation(string name)
{
    // a private cases for root-grandfather/grandmother
    Node* temp = new Node("");
    if(root->getName() == name){return "me";}
    if(root->getFather() != NULL)
    {
        temp = root->getFather();
        if((temp->getName() == name) && (temp->getGender() == 0)){return "father";}
        if((temp->getFather() != NULL) && (temp->getFather()->getName() == name) && (temp->getFather()->getGender() == 0)){return "grandfather";}
        if((temp->getMother() != NULL) && (temp->getMother()->getName() == name) && (temp->getMother()->getGender() == 1)){return "grandmother";}
    }
    if(root->getMother() != NULL)
    {
        temp = root->getMother();
        if((temp->getName() == name) && (temp->getGender() == 1)){return "mother";}
        if((temp->getFather() != NULL) && (temp->getFather()->getName() == name) && (temp->getFather()->getGender() == 0)){return "grandfather";}
        if((temp->getMother() != NULL) && (temp->getMother()->getName() == name) && (temp->getMother()->getGender() == 1)){return "grandmother";}
    }
    // the other cases, for all the 'great-'
    int level = -1;
    int gender = -1;
    relationHelp(name , root , &level , &gender);
    if(level == -1 && gender == -1){return "unrelated";}
    if(gender == 0)
        {
            string s = "great-";
            string s1 = "grandfather";
            for(int i = 1; i < level-2; i++)
                {
                    s += s;
                }
            return s.append(s1);
            }
            else
            {
                string s = "great-";
                string s1 = "grandmother";
                for(int i = 1; i < level-2; i++)
                {
                    s += s;
                }
                return s.append(s1);
            } 
}

void Tree:: relationHelp(string name, Node* root , int* level , int* gender)
{
    if(root == NULL){return;}
    if(root->getName() == name)
    {
        *level = root->getLevel();
        *gender = root->getGender();
        return;
    }
    relationHelp(name, root->getFather() , level , gender);
    relationHelp(name , root->getMother() , level , gender);
}

string Tree::find(string name)
{
    if(root != NULL && name=="me"){return root->getName();}
    if((root->getFather() != NULL) && (name == "father")){return root->getFather()->getName();}
    if((root->getMother() != NULL) && (name == "mother")){return root->getMother()->getName();}
    if ((root->getMother()->getMother() != NULL) && (name == "grandmother")){return root->getMother()->getMother()->getName();}
    if((root->getFather()->getFather() != NULL) && (name=="grandfather")){return root->getFather()->getFather()->getName();}
    string tag = "";
    findHelp(name, root , &tag);
    if(tag == "")
    {
        throw("");
    }
    return tag;
}

void Tree::findHelp(string name, Node* root , string* tag)
{
    if(root == NULL){return;}
    if ((root->getMother() != NULL) && (root->getMother()->getMother() != NULL) && (name == "grandmother"))
    {
        *tag = root->getMother()->getMother()->getName();
        return;
    }
    if((root->getFather() != NULL) && (root->getFather()->getFather() != NULL) && (name=="grandfather"))
    {
        *tag = root->getFather()->getFather()->getName();
        return;
    }
        if((root->getFather() != NULL) && (root->getFather()->getMother() != NULL) && (name=="grandmother"))
    {
        *tag = root->getFather()->getMother()->getName();
        return;
    }
        if ((root->getMother() != NULL) && (root->getMother()->getFather() != NULL) && (name == "grandfather"))
    {
        *tag = root->getMother()->getFather()->getName();
        return;
    }
    
    if((name!="grandmother" && name!="grandfather") && (name.length()<6 || name.substr(0,6)!="great-")) throw("");
    if(root->getMother() != NULL)
    {
        if(name != "grandmother" && name != "grandfather")
        {
            findHelp(name.substr(6),root->getMother() , tag);
        }
    }
    if(root->getFather() != NULL)
    {
        if(name != "grandmother" && name != "grandfather" && *tag == "")
        {
            findHelp(name.substr(6),root->getFather() , tag);
        }
    }
}


void Tree::remove(string name){
        if (root->getName() == name)
        {
            throw("you cant delete the root");
        }
       // Node* temp = search(root,name);
        if ( search(root,name) == NULL)
        {
            throw("this name is not exist");
        }
        else
        {
            removeHelp(name , root);
        }
}


void Tree::deleteTree(Node* root) //this function was taken from "GeeksForGeeks", https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
{
    if(root != NULL)
    {
        deleteTree(root->getFather()); 
        deleteTree(root->getMother());
        delete root; 
        root = NULL;
    }
}

void Tree::removeHelp(string name , Node* root)
{
    if(root != NULL && root->getName() == name)
    {
        deleteTree(root);
    }
    else
    {
        if(root->getFather() != NULL)
        {
            removeHelp(name , root->getFather());
        }
        if(root->getMother() != NULL)
        {
            removeHelp(name , root->getMother());
        }
    }
}


void Tree::display(){
    printPreorder(root);
}

void Tree::printPreorder(Node* root) // this function was taken from "GeeksForGeeks", https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/?ref=rp 
{ 
    if (root == NULL) 
        return; 
  
    /* first print data of node */
    cout << root->getName() << " "; 
  
    /* then recur on left sutree */
    printPreorder(root->getFather());  
  
    /* now recur on right subtree */
    printPreorder(root->getMother()); 
} 

Node* Tree::search(Node* root, string name) {

        Node* temp=new Node("");
        if (root==NULL){
            return root;
        }
        if (root->getName() == name){
            return root;
        }
        else{
            temp=search(root->getFather(),name);
        
            if(temp==NULL){
            
             temp=search(root->getMother(),name);
            }
        }
        return temp;
        
    }