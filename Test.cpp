#include "doctest.h"
#include "FamilyTree.hpp"
using namespace family;
#include <string>
using namespace std;
    
TEST_CASE ("root is Noa"){
Tree T1 ("Noa");
T1.addFather("Noa" , "Tuval");
T1.addMother("Noa" ,"Adi");
T1.addFather("Tuval" , "Reuven");
T1.addMother("Tuval" , "Sarah");
T1.addFather("Adi" , "Avraham");
T1.addMother("Adi" , "Hana");
T1.addFather("Reuven", "Yosef");
T1.addMother("Reuven" , "Hava");
T1.addMother("Hava", "Rachel");
CHECK(T1.relation("Tuval") == string("father"));
CHECK(T1.relation("Adi") == string("mother"));
CHECK(T1.relation("Reuven ") == string("grandfather"));
CHECK(T1.relation("Sarah") == string("grandmother"));
CHECK(T1.relation("Avraham") == string("grandfather"));
CHECK(T1.relation("Hana") == string("grandmother"));
CHECK(T1.relation("Yosef") == string("great-grandfather"));
CHECK(T1.relation("Hava") == string("great-grandmother"));
CHECK(T1.relation("Rachel") == string("great-great-grandmother"));
CHECK(T1.relation("Yael") == string("unrelated"));
CHECK(T1.relation("Noa") == string("me"));
CHECK(T1.find("father") == string("Tuval"));
CHECK(T1.find("mother") == string("Adi"));
CHECK(T1.find("grandfather") == string("Reuven"));
CHECK(T1.find("grandfather") == string("Avraham"));
CHECK(T1.find("grandmother") == string("Sarah"));
CHECK(T1.find("grandmother") == string("Hana"));
CHECK(T1.find("great-grandfather") == string("Yosef"));
CHECK(T1.find("great-grandmother") == string("Hava"));
CHECK(T1.find("great-great-grandmother") == string("Rachel"));

T1.remove("Hava"); // remove Hava and Rachel from the tree
CHECK(T1.relation("Rachel") == string ("unrelated"));
CHECK(T1.relation("Hava") == string ("unrelated"));
CHECK(T1.relation("Tuval") == string ("father"));
T1.remove("Tuval"); // remove Tuval, Sarah, Reuven and Yosef from the tree
CHECK(T1.relation("Tuval") == string ("unrelated"));
CHECK(T1.relation("Sarah") == string ("unrelated"));
CHECK(T1.relation("Reuven") == string ("unrelated"));
CHECK(T1.relation("Yosef") == string ("unrelated"));
T1.remove("Adi"); // remove Adi, Hana and Avraham from the tree
CHECK(T1.relation("Adi") == string ("unrelated"));
CHECK(T1.relation("Avraham") == string ("unrelated"));
CHECK(T1.relation("Hana") == string ("unrelated"));
}

TEST_CASE("root of or") {
    Tree T ("Or");
    T.addFather("Or", "Hila");
    T.addMother("Or", "Tomer");
    T.addMother("Hila", "Ayala");
    T.addFather("Hila", "Amit");
    T.addFather("Tomer", "Yosef");
    T.addMother("Tomer", "Rivka");
    T.addFather("Yosef", "Levi");
    T.addMother("Yosef", "Ora");
    T.addFather("Rivka", "Avi");
    T.addMother("Rivka", "Tali");
    CHECK(T.relation("Tomer") == string("father"));
    CHECK(T.relation("Hila") == string("mother"));
    CHECK(T.relation("Yosef") == string("grandfather"));
    CHECK(T.relation("Rivka") == string("grandmother"));
    CHECK(T.relation("Amit") == string("grandfather"));
    CHECK(T.relation("Ayala") == string("grandmother"));
    CHECK(T.relation("Levi") == string("great-grandfather"));
    CHECK(T.relation("Ora") == string("great-grandmother"));
    CHECK(T.relation("Avi") == string("great-grandfather"));
    CHECK(T.relation("Tali") == string("great-grandmother"));
    CHECK(T.relation("Hava") == string("unrelated"));
    CHECK(T.relation("Miri") == string("unrelated"));
     CHECK(T.find("me") == string("Or"));
    CHECK(T.find("father") == string("Tomer"));
    CHECK(T.find("mother") == string("Hila"));
    CHECK(T.find("grandfather") == string("Yosef"));
    CHECK(T.find("grandmother") == string("Rivka"));
    CHECK(T.find("grandfather") == string("Amit"));
    CHECK(T.find("grandmother") == string("Ayala"));
    CHECK(T.find("great-grandfather") == string("Levi"));
    CHECK(T.find("great-grandmother") == string("Ora"));
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
T2.addFather("Roni", "Tomer");
T2.addMother("Roni" , "Ora");
T2.addMother("Rivka", "Rachel");
CHECK(T2.relation("Yoval") == string("father"));
CHECK(T2.relation("Adi") == string("mother"));
CHECK(T2.relation("Mor") == string("grandfather"));
CHECK(T2.relation("Sapir") == string("grandmother"));
CHECK(T2.relation("Miki") == string("grandfather"));
CHECK(T2.relation("Roni") == string("grandmother"));
CHECK(T2.relation("Yoni") == string("great-grandfather"));
CHECK(T2.relation("Rivka") == string("great-grandmother"));
CHECK(T2.relation("Tomer") == string("great-grandfather"));
CHECK(T2.relation("Ora") == string("great-grandmother"));
CHECK(T2.relation("Rachel") == string("great-great-grandmother"));
CHECK(T2.relation("Sarah") == string("unrelated"));
CHECK(T2.relation("Levi") == string("me"));
   CHECK(T2.find("me") == string("Levi"));
    CHECK(T2.find("father") == string("Yuval"));
    CHECK(T2.find("mother") == string("Adi"));
    CHECK(T2.find("grandfather") == string("Mor"));
    CHECK(T2.find("grandmother") == string("Sapir"));
    CHECK(T2.find("grandfather") == string("Miki"));
    CHECK(T2.find("grandmother") == string("Roni"));
    CHECK(T2.find("great-grandfather") == string("Yoni"));
    CHECK(T2.find("great-grandmother") == string("Rivka"));
     CHECK(T2.find("great-grandfather") == string("Tomer"));
    CHECK(T2.find("great-grandmother") == string("Ora"));
}

TEST_CASE("root of Miri") {
    Tree T3 ("Miri");
    T3.addFather("Miri", "Avi");
    T3.addMother("Miri", "Chen");
    T3.addMother("Chen", "Nava");
    T3.addFather("Chen", "Ido");
    T3.addFather("Ido", "Israel");
    T3.addMother("Ido", "Ita");
    T3.addFather("Ita", "Yosef");
    T3.addMother("Ita", "Rivka");
    T3.addFather("Nava", "Ami");
    T3.addMother("Nava", "Irit");
    T3.addFather("Yosef", "Nathan");
    CHECK(T3.relation("Avi") == string("father"));
    CHECK(T3.relation("Chen") == string("mother"));
    CHECK(T3.relation("Ido") == string("grandfather"));
    CHECK(T3.relation("Nava") == string("grandmother"));
    CHECK(T3.relation("Israel") == string("grandfather"));
    CHECK(T3.relation("Ita") == string("grandmother"));
    CHECK(T3.relation("Yosef") == string("great-grandfather"));
    CHECK(T3.relation("Rivka") == string("great-grandmother"));
    CHECK(T3.relation("Ami") == string("great-grandfather"));
    CHECK(T3.relation("Irit") == string("great-grandmother"));
    CHECK(T3.relation("Nathan") == string("great-great-grandfather"));
    CHECK(T3.relation("Hava") == string("unrelated"));
    CHECK(T3.relation("Or") == string("unrelated"));
    CHECK(T3.relation("Miri") == string("me"));
     CHECK(T3.find("me") == string("Miri"));
    CHECK(T3.find("father") == string("Avi"));
    CHECK(T3.find("mother") == string("Chen"));
    CHECK(T3.find("grandfather") == string("Israel"));
    CHECK(T3.find("grandmother") == string("Nava"));
    CHECK(T3.find("grandfather") == string("Yosef"));
    CHECK(T3.find("grandmother") == string("Ita"));
    CHECK(T3.find("great-grandfather") == string("Yosef"));
    CHECK(T3.find("great-grandmother") == string("Rivka"));
    CHECK(T3.find("great-grandfather") == string("Ami"));
    CHECK(T3.find("great-grandmother") == string("Irit"));
}
