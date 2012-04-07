#include "testmonomesimple.hpp"

#include <MonomeSimple>

CPPUNIT_TEST_SUITE_REGISTRATION( TestMonomeSimple );

void TestMonomeSimple::constructeurValeur()
{
    Variable* v = Variable::getVariable('x');
    MonomeSimple& m = *new MonomeSimple(v, 5.3, 2);
    CPPUNIT_ASSERT(m.exposant() == 2);
    CPPUNIT_ASSERT(m.multiplicateur() == 5.3);
    CPPUNIT_ASSERT(m.m_v == v);
}

void TestMonomeSimple::constructeurCopie()
{
    Variable* v = Variable::getVariable('x');
    MonomeSimple& mo = *new MonomeSimple(v, 5.3, 2);
    MonomeSimple& m = *new MonomeSimple(mo);
    CPPUNIT_ASSERT(m.exposant() == 2);
    CPPUNIT_ASSERT(m.multiplicateur() == 5.3);
    CPPUNIT_ASSERT(m.m_v == v);
}

void TestMonomeSimple::derivee()
{
    Variable* v = Variable::getVariable('x');
    Variable* w = Variable::getVariable('y');
    MonomeSimple& m = *new MonomeSimple(v, 5.3, 2);
    CPPUNIT_ASSERT(*m.derivee(v) == *new MonomeSimple(v, 10.6, 1));
    CPPUNIT_ASSERT(*m.derivee(w) == m);
}

void TestMonomeSimple::primitive()
{
    Variable* v = Variable::getVariable('x');
    Variable* w = Variable::getVariable('y');
    MonomeSimple& m = *new MonomeSimple(v, 5.3, 2);
    CPPUNIT_ASSERT(*m.primitive(v) == *new MonomeSimple(v, 5.3/3, 3));
    CPPUNIT_ASSERT(*m.primitive(w) == m);
}

void TestMonomeSimple::clone()
{
    Variable* v = Variable::getVariable('x');
    MonomeSimple& m = *new MonomeSimple(v, 5.3, 2);
    CPPUNIT_ASSERT(*m.clone() == m);
}

void TestMonomeSimple::afficher()
{
    std::ostringstream oss;
    Variable* v = Variable::getVariable('x');
    MonomeSimple& m = *new MonomeSimple(v, 5.3, 2);
    m.afficher(oss);
    CPPUNIT_ASSERT(oss.str() == "5.3x^2");
}
