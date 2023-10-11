/**
 * @file hermite.cxx
 * @author Matthias Lapu
 * @brief implementation of the hermite's polynome
 */
#include "../headers/hermite.h"
using namespace arma;

/**
 * @brief Construct a new Hermite:: Hermite object
 *
 * @param nInput
 * @param zInput
 */
Hermite::Hermite(unsigned int nInput, vec zInput)
{
  n = nInput;
  z = zInput;
};

/**
 * @brief Construct a new Hermite:: Hermite object
 *
 * @param nInput
 * @param lowestValue
 * @param highestValue
 * @param nbValue
 */
Hermite::Hermite(unsigned int nInput, float lowestValue, float highestValue, float nbValue)
{
  n = nInput;

  // linspace allows us to create a vector of float
  z = linspace(lowestValue, highestValue, nbValue);
};

/**
 * @brief get the value of n
 *
 * @return unsigned int
 */
unsigned int Hermite::getN() { return n; };

/**
 * @brief get the vector of z
 *
 * @return arma::vec
 */
vec Hermite::getZ() { return z; };

/**
 * @brief set the vector of z
 *
 */
void Hermite::setZ(vec zInput) { z = zInput; };

/**
 * @brief get the matrix of the hermite's polynome
 *
 * @return arma::mat
 */
mat Hermite::getPolynomeMat() { return polynomeMat; };

/**
 * @brief compute the value of the hermite's polynome
 */
void Hermite::fillPolynomeHermite()
{
  for (unsigned int n = 0; n <= getN(); n++)
  {
    if (n == 0)
    {
      // n=0 => H0 = 1
      polynomeMat.insert_cols(n, ones(size(z)));
    }
    else if (n == 1)
    {
      // n=1 => H1 = 2z
      polynomeMat.insert_cols(n, 2 * z);
    }
    else
    {
      // n => Hn = 2zHn-1 - 2(n-1)Hn-2
      polynomeMat.insert_cols(n, 2 * z % polynomeMat.col(n - 1) -
                                     2 * (n - 1) * polynomeMat.col(n - 2));
    }
  }
};
