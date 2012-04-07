#ifndef __TESTCONSTANTE_HPP__
#define __TESTCONSTANTE_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestConstante : public CppUnit::TestFixture
{
	CPPUNIT_TEST_SUITE(TestConstante);
	CPPUNIT_TEST(constructeurValeur);
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
	void derivee();
	void primitive();
    void clone();
	void afficher();
};

#endif // __TESTCONSTANTE_HPP__

