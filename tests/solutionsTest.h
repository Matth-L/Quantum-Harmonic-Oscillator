/**
 * @file solutionsTest.h
 * @author Lapu Matthias
 * @brief
 */

#ifndef SOLUTIONSTEST_H
#define SOLUTIONSTEST_H

#include "solutions.h"
#include <cxxtest/TestSuite.h>
using namespace arma;

class SolutionTest : public CxxTest::TestSuite
{
public:
    // parameters are supposed to be 1
    Solutions x1 = Solutions();
    Solutions x2 = Solutions(1, 1, 1);
    Solutions x3 = Solutions(2, 9, 5);

    void testConstructorSolutions(void)
    {
        TS_TRACE("Starting test");

        // test m
        TS_TRACE("Starting M test");
        TS_ASSERT(x1.getM() == 1);
        TS_ASSERT(x2.getM() == 1);
        TS_ASSERT(x2.getM() == x1.getM());
        TS_ASSERT(x2.getM() != x3.getM());
        TS_TRACE("Test M is DONE");

        // test hbar
        TS_TRACE("Starting Hbar test");
        TS_ASSERT(x1.getHbar() == 1);
        TS_ASSERT(x2.getHbar() == 1);
        TS_ASSERT(x2.getHbar() == x1.getHbar());
        TS_ASSERT(x2.getHbar() != x3.getHbar());
        TS_TRACE("Test Hbar is DONE");

        // test omega
        TS_TRACE("Starting Omega test");
        TS_ASSERT(x1.getOmega() == 1);
        TS_ASSERT(x2.getOmega() == 1);
        TS_ASSERT(x2.getOmega() == x1.getOmega());
        TS_ASSERT(x2.getOmega() != x3.getOmega());
        TS_TRACE("Test Omega is DONE");

        TS_TRACE("Test is DONE");
    }

    void testOrthonormality(void)
    {
        TS_TRACE("Starting orthonormality test");

        // if i == j then the result should be 1
        // otherwise it should be 0
        for (int i = 0; i < 25; i++)
        {
            for (int j = 0; j < 24; j++)
            {
                float a = x1.verifOrthonormality(i, j);
                float b = x2.verifOrthonormality(i, j);
                float c = x3.verifOrthonormality(i, j);
                if (i == j)
                {
                    TS_ASSERT_DELTA(a, 1, 0.0001);
                    TS_ASSERT_DELTA(b, 1, 0.0001);
                    TS_ASSERT_DELTA(c, 1, 0.0001);
                }
                else
                {
                    TS_ASSERT_DELTA(a, 0, 0.0001);
                    TS_ASSERT_DELTA(b, 0, 0.0001);
                    TS_ASSERT_DELTA(c, 0, 0.0001);
                }
            }
        }
        TS_TRACE("Orthonormality is DONE");
    }
};

#endif // SOLUTIONSTEST_H