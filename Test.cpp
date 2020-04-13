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

}


