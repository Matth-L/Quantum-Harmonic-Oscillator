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

/**
 * @brief this class tests the Schrodinger equation
 *
 */
class SchrodingerTest : public CxxTest::TestSuite
{

public:
    /**
     * @test This function tests the energy levels
     * of the Schrodinger equation
     * using the formula : E_n = hbar * omega * (n + 1/2)
     * The test is done with different values of hbar and omega (1 and random)
     * and with different values of n
     */
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

    /**
     * @test this function tests the second derivative matrix
     * The test is done by comparing the result of the function
     * with 2 values that were calculated by hand.
     * @warning the tolerance is set to 1e-2
     */
    void testSecondDerivative(void)
    {
        const double tolerance = 1e-2;

        //--------------------------------------------
        TS_TRACE("Starting second derivative test");

        // testing for n=1 , interval = [-1, 1], nodes = 3
        TS_TRACE("Starting n=1 , interval = [-1, 1], nodes = 3 test");

        vec test = {-0.591, 0};
        Schrodinger x = Schrodinger();
        Solutions sol = Solutions();
        mat psi = sol.solutions(1, -1, 1, 3);
        mat snd = x.secondDerivative(psi);

        // testing with approximation for all the nodes
        for (int i = 0; i < snd.n_rows - 1; i++)
        {
            TS_ASSERT_DELTA(snd(i, 0), test(i, 0), tolerance);
        }
        TS_TRACE("Test n=1 , interval = [-1, 1], nodes = 3 is DONE");

        //--------------------------------------------

        TS_TRACE("Starting dx test");

        // testing if dx squared is correct
        double dx = 1;
        double dxToTest = psi(0, 1) - psi(0, 0);
        TS_ASSERT_DELTA(dx, dxToTest * dxToTest, tolerance);

        TS_TRACE("Test dx is DONE");

        //--------------------------------------------

        // testing for n=2 , interval = [-1, 1], nodes = 3
        TS_TRACE("Starting n=2 , interval = [-1, 1], nodes = 3 test");

        vec test2 = {-0.591, 0, 1.7064};

        snd = x.secondDerivative(sol.solutions(2, -1, 1, 3));

        for (int i = 0; i < snd.n_rows - 1; i++)
        {
            TS_ASSERT_DELTA(snd(i, 0), test2(i, 0), tolerance);
        }
        TS_TRACE("Test n=2 , interval = [-1, 1], nodes = 3 is DONE");

        //--------------------------------------------

        TS_TRACE("Second derivative is DONE");
    }

    /**
     * @test this function tests the left part of the Schrodinger equation
     * with the right part of the Schrodinger equation
     * It means that it test if the left part of the equation is equal to the right part.
     */
    void testLeftPartVSRightPart(void)
    {
    }
};

#endif // SCHRODINGERTEST_H