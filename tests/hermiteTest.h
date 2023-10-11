/**
 * @file hermiteTest.h
 * @author Lapu Matthias
 * @brief the test class for hermite
 */
#ifndef HERMITETEST_H
#define HERMITETEST_H
#include "hermite.h"
#include <cxxtest/TestSuite.h>
using namespace arma;

/**
 * Method to test
 * - the constructor (2 of them)
 * - the setZ method
 * - the getPolynomeMat method
 * - the fillPolynomeHermite method
 */

class HermiteTest : public CxxTest::TestSuite
{
public:
    vec input = {2, 3, 4, 5, 6, 7};

    // those 2 Hermite's object are supposed to be the same
    Hermite test = Hermite(7, input);
    Hermite test2 = Hermite(7, 2, 7, 6);

    void testConstructor(void)
    {
        TS_TRACE("Starting constructor test");

        // test N
        TS_TRACE("Starting N test");
        TS_ASSERT_EQUALS(test.getN(), 7);
        TS_ASSERT_EQUALS(test2.getN(), 7);
        TS_ASSERT_EQUALS(test.getN(), test2.getN());
        TS_TRACE("Test N is DONE");

        // test Z
        TS_TRACE("Starting Z test");
        vec emptyTest = {};

        // empty test
        TS_TRACE("Starting vacuity test");
        TS_ASSERT(size(test.getZ()) != size(emptyTest));
        TS_ASSERT(size(test2.getZ()) != size(emptyTest));
        TS_TRACE("Vacuity test is DONE");

        // size of elements
        TS_TRACE("Starting size test");
        TS_ASSERT((size(test.getZ()) == size(test2.getZ())));
        TS_TRACE("Size test is DONE");

        // test to see if test1 = test 2
        TS_TRACE("Starting equality test");
        TS_ASSERT(arma::all(test.getZ() == test2.getZ()));
        TS_TRACE("Equality test is DONE");

        TS_TRACE("Z test is DONE");

        TS_TRACE("Finishing constructor test");
    };

    void testFill(void)
    {
        TS_TRACE("Starting fill");
        test.fillPolynomeHermite();
        test2.fillPolynomeHermite();
        TS_TRACE("filling DONE with test1 and test2");

        // testing if the first values is a col of 1 for test1 and test 2
        // this test is now useless, because we test all the value in the next test
        TS_TRACE("Starting first column test");
        TS_ASSERT(arma::all(test.getPolynomeMat().col(0) == 1));
        TS_ASSERT(arma::all(test2.getPolynomeMat().col(0) == 1));
        TS_ASSERT(arma::all(test.getPolynomeMat().col(0) == test2.getPolynomeMat().col(0)));
        TS_TRACE("first column test DONE");

        // testing if all the values are the same for test1 and test 2, due to floating point error, we use a tolerance
        TS_TRACE("Starting comparison test");
        const double tolerance = 1e-6;
        for (int i = 0; i < test.getN(); i++)
        {
            TS_ASSERT(arma::approx_equal(test.getPolynomeMat().col(i), test2.getPolynomeMat().col(i), "absdiff", tolerance));
        }
        TS_TRACE("Comparison test DONE");
    };
};

#endif
