#ifndef __TESTMONOMESIMPLE_HPP__
#define __TESTMONOMESIMPLE_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestMonomeSimple : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestMonomeSimple);
	CPPUNIT_TEST(constructeurValeur);
	CPPUNIT_TEST(constructeurCopie);
	CPPUNIT_TEST(derivee);
	CPPUNIT_TEST(primitive);
	CPPUNIT_TEST(clone);
	CPPUNIT_TEST(afficher);
	CPPUNIT_TEST_SUITE_END();

public:
	//~ Call before tests
	void setUp() {}
	//~ Call after tests
	void tearDown() {}

protected:
	void constructeurValeur();
	void constructeurCopie();
	void derivee();
	void primitive();
    void clone();
	void afficher();
};

#endif // __TESTMONOMESIMPLE_HPP__

