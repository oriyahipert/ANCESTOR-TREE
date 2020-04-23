#include <string>
#include <iostream>
using namespace std;

class Node{
    string name;
    Node* father;
    Node* mother;
    int level;
    int gender; // male-0, female-1
    int tag; // 0-wasn't, 1-was
public:
    Node(string name);
    string getName();
    Node* getFather();
    Node* getMother();
    int getLevel();
    int getGender();
    int getTag();
    void setFather(Node* n);
    void setMother(Node* n);
    void setLevel(int l);
    void setGender(int g);
    void setTag(int t);
    void addFatherNode (string father); 
    void addMotherNode (string mother); 
    void removeFather ();  
    void removeMother ();  
    ~Node();
};