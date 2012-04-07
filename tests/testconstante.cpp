#include "testconstante.hpp"

#include <Constante>

CPPUNIT_TEST_SUITE_REGISTRATION( TestConstante );

void TestConstante::constructeurValeur()
{
    Constante& c = *new Constante(5);
    CPPUNIT_ASSERT((double)c == 5.);
}

void TestConstante::derivee()
{
    Variable* v = Variable::getVariable('x');
    Constante& c = *new Constante(5);
    CPPUNIT_ASSERT((double)(*c.derivee(v)) == 0.);
}

void TestConstante::primitive()
{
    Variable* v = Variable::getVariable('x');
    Constante& c = *new Constante(5);
    Fonction* f = c.primitive(v);
    CPPUNIT_ASSERT(typeid(*f) == typeid(MonomeSimple));
    MonomeSimple* m = dynamic_cast<MonomeSimple*>(f);
    CPPUNIT_ASSERT(m);
    if(!m) return;
    CPPUNIT_ASSERT(*m == *(new MonomeSimple(v,5)));
}

void TestConstante::clone()
{
    Constante& c = *new Constante(5);
    CPPUNIT_ASSERT((double)c == 5.);
    Constante* c2 = c.clone();
    CPPUNIT_ASSERT(c == *c2);
}

void TestConstante::afficher()
{
    std::ostringstream oss;
    Constante& c = *new Constante(5);
    c.afficher(oss);
    CPPUNIT_ASSERT(oss.str() == "5");
}
