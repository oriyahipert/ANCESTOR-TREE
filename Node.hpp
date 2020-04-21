#include <string>
#include <iostream>
using namespace std;

class Node{
    string name;
    Node* father;
    Node* mother;
public:
    Node(string r);
    string getName();
    Node* getFather();
    Node* getMother();
    void addFather (string father); 
    void addMother (string mother); 
    void removeFather ();  
    void removeMother ();  
    ~Node();
};