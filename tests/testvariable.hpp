#ifndef __TESTVARIABLE_HPP__
#define __TESTVARIABLE_HPP__

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestVariable : public CppUnit::TestFixture 
{
	CPPUNIT_TEST_SUITE(TestVecteur);
	CPPUNIT_TEST(constructeurDefaut);
	CPPUNIT_TEST(constructeurVector);
	CPPUNIT_TEST(constructeurCopie);
	CPPUNIT_TEST_SUITE_END();

public:
	//~ Call before tests
	void setUp() {}
	//~ Call after tests
	void tearDown() {}

protected:
	void constructeurDefaut();
	void constructeurVector();
	void constructeurCopie();
};

#endif
