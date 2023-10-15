/**
 * @file schrodingerTest.h
 * @author Matthias Lapu
 * @brief Test class for Schrodinger
 */

#ifndef SCHRODINGERTEST_H
#define SCHRODINGERTEST_H

#include "schrodinger.h"
#include "solutions.h"
#include <cxxtest/TestSuite.h>

class SchrodingerTest : public CxxTest::TestSuite
{

public:
    void testEnergyLevels(void)
    {
        TS_TRACE("Starting energy level test");

        // the energy formula is :
        // E_n = hbar * omega * (n + 1/2)

        // testing for hbar = 1, omega = 1
        TS_TRACE("Starting hbar = 1, omega = 1 test");
        for (int i = 0; i < 25; i++)
        {
            Schrodinger x = Schrodinger();
            TS_ASSERT(x.energyLevels(1, 1, i) == 1 * 1 * (i + 0.5));
        }
        TS_TRACE("Test hbar = 1, omega = 1 is DONE");

        // testing for hbar = random number, omega = random number

        TS_TRACE("Starting hbar = random, omega = random test");
        int hbar = rand() % 100;
        int omega = rand() % 100;

        TS_TRACE("hbar = " + std::to_string(hbar));
        TS_TRACE("omega = " + std::to_string(omega));

        for (int i = 0; i < 25; i++)
        {
            Schrodinger x = Schrodinger();
            TS_ASSERT(x.energyLevels(hbar, omega, i) == hbar * omega * (i + 0.5));
        }

        TS_TRACE("Test hbar = random, omega = random is DONE");
        TS_TRACE("Test is DONE");
    }

    // void testSecondDerivative(void)
    // {
    //     // testing if dx squared is correct
    //     // testing if the matrix is correct
    //     TS_TRACE("Starting second derivative test");
    //     TS_TRACE("Second derivative is DONE");
    // }
};

#endif // SCHRODINGERTEST_H