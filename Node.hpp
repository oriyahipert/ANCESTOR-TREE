#include <string>
#include <iostream>
using namespace std;

class Node{
    string name;
    Node* father;
    Node* mother;
    int level;
    int gender;
public:
    Node(string r);
    string getName();
    Node* getFather();
    Node* getMother();
    int getLevel();
    int getGender();
    void setLevel(int l);
    void setGender(int g);
    void addFatherNode (string father); 
    void addMotherNode (string mother); 
    void removeFather ();  
    void removeMother ();  
    ~Node();
};