/*******************************************************
 * @file hermiteTest.h
 * @author Lapu Matthias
 * @brief the test class for hermite
 *******************************************************/
#include "hermite.h"
#include <cxxtest/TestSuite.h>
using namespace arma;

/*******************************************************
 * Method to test
 * - the constructor (2 of them)
 * - the setZ method
 * - the getPolynomeMat method
 * - the fillPolynomeHermite method
 *******************************************************/

class HermiteTest : public CxxTest::TestSuite
{
public:
    vec input = {2, 3, 4, 5, 6, 7};
    Hermite test = Hermite(7, input);
    Hermite test2 = Hermite(7, 2, 7, 1);

    void testConstructor(void)
    {
        TS_TRACE("Starting constructor test");

        // test N
        TS_ASSERT_EQUALS(test.getN(), 7);
        TS_ASSERT_EQUALS(test2.getN(), 7);
        TS_ASSERT_EQUALS(test.getN(), test2.getN());

        // test Z , armadillo's operator is element wise

        TS_TRACE("Finishing constructor test");
    };

    void testFill(void)
    {
        // testing if the first values is a col of 1

        // testing if the second value is 2z
    }
};