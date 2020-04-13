#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;
    
    TEST_CASE("root is Noa"){
Tree T1 ("Noa");
T1.addFather("Noa" , "Tuval");
T1.addMother("Noa" ,"Adi");
T1.addFather("Tuval" , "Reuven");
T1.addMother("Tuval" , "Sarah");
T1.addFather("Adi" , "Avraham");
T1.addMother("Adi" , "Sarah");
T1.addFather("Reuven", "Yosef");
T1.addMother("Reuven" , "Hava");
T1.addMother("Hava", "Rachel");
CHECK(T1.relation("Tuval") == string("father"));
CHECK(T1.relation("Adi") == string("mother"));
CHECK(T1.relation("Reuven ") == string("grandfather"));
CHECK(T1.relation("Sarah") == string("grandmother"));
CHECK(T1.relation("Avraham") == string("grandfather"));
CHECK(T1.relation("Sarah") == string("grandmother"));
CHECK(T1.relation("Yosef") == string("great-grandfather"));
CHECK(T1.relation("Hava") == string("great-grandmother"));
CHECK(T1.relation("Rachel") == string("great-great-grandmother"));
CHECK(T1.relation("Yael") == string("unrelated"));
CHECK(T1.relation("Noa") == string("me"));
}


TEST_CASE("root of oriya") {
    Tree T ("Or");
    T.addFather("Or", "Hila");
    T.addMother("Or", "Tomer");
    T.addMother("Hila", "Ayala");
    T.addFather("Hila", "Amit");
    T.addFather("Tomer", "Yosef");
    T.addMother("Tomer", "Rivka");
    T.addFather("Yosef", "Levi");
    T.addFather("Yosef", "Ora");
    CHECK(T.relation("Tomer") == string("father"));
    CHECK(T.relation("Hila") == string("mother"));
    CHECK(T.relation("Yosef") == string("grandfather"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Amit") == string("grandfather"));
    CHECK(T.relation("Ayala") == string("grandmother"));
    CHECK(T.relation("Levi") == string("great-grandfather"));
    CHECK(T.relation("Ora") == string("great-grandmother"));
    CHECK(T.relation("Hava") == string("unrelated"));
    CHECK(T.relation("Miri") == string("unrelated"));

    bool exceptionThrown = false;
    //string text = "uncle";
    try
    {
        T.find("uncle");
    }
    catch(const exception &e) 
    {   
        exceptionThrown = true;
    }
    CHECK(exceptionThrown);

 bool exceptionThrown1 = false;
    try
    {
        T.find("sister");
    }
    catch(const exception &e) 
    {   
        exceptionThrown1 = true;
    }
    CHECK(exceptionThrown);


 bool exceptionThrown2 = false;
    try
    {
        T.find("aunt");
    }
    catch(const exception &e) 
    {   
        exceptionThrown2 = true;
    }
    CHECK(exceptionThrown);
}

TEST_CASE("root is Levi"){
Tree T2 ("Levi");
T2.addFather("Levi" , "Yuval");
T2.addMother("Levi" ,"Adi");
T2.addFather("Yuval" , "Mor");
T2.addMother("Yuval" , "Sapir");
T2.addFather("Adi" , "Miki");
T2.addMother("Adi" , "Roni");
T2.addFather("Mor", "Yoni");
T2.addMother("Mor" , "Rivka");
T2.addMother("Rivka", "Rachel");
CHECK(T2.relation("Yoval") == string("father"));
CHECK(T2.relation("Adi") == string("mother"));
CHECK(T2.relation("Mor") == string("grandfather"));
CHECK(T2.relation("Sapir") == string("grandmother"));
CHECK(T2.relation("Miki") == string("grandfather"));
CHECK(T2.relation("Roni") == string("grandmother"));
CHECK(T2.relation("Yoni") == string("great-grandfather"));
CHECK(T2.relation("Rivka") == string("great-grandmother"));
CHECK(T2.relation("Rachel") == string("great-great-grandmother"));
CHECK(T2.relation("Sarah") == string("unrelated"));
CHECK(T2.relation("Levi") == string("me"));


}




