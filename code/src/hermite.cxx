/*******************************************************
 * @file hermite.cxx
 * @author Matthias Lapu
 * @brief implementation of the hermite's polynome
 *******************************************************/
#include "../headers/hermite.h"

/*******************************************************
 * @brief Construct a new Hermite:: Hermite object
 *
 * @param nInput
 * @param zInput
 *******************************************************/
Hermite::Hermite(unsigned int nInput, arma::vec zInput)
{
  n = nInput;
  z = zInput;
};

/*******************************************************
 * @brief Construct a new Hermite:: Hermite object
 *
 * @param nInput
 * @param lowestValue
 * @param highestValue
 * @param increment
 *******************************************************/
Hermite::Hermite(unsigned int nInput, float lowestValue, float highestValue, float increment)
{
  n = nInput;

  // linspace allows us to create a vector of float
  z = arma::linspace(lowestValue, highestValue, increment);
};

/*******************************************************
 * @brief get the value of n
 *
 * @return unsigned int
 *******************************************************/
unsigned int Hermite::getN() { return n; };

/*******************************************************
 * @brief get the vector of z
 *
 * @return arma::vec
 *******************************************************/
arma::vec Hermite::getZ() { return z; };

/*******************************************************
 * @brief set the vector of z
 *
 * @param zInput
 *******************************************************/
void Hermite::setZ(arma::vec zInput) { z = zInput; };

/*******************************************************
 * @brief get the matrix of the hermite's polynome
 *
 * @return arma::mat
 *******************************************************/
arma::mat Hermite::getPolynomeMat() { return polynomeMat; };

/*******************************************************
 * @brief compute the value of the hermite's polynome
 *******************************************************/
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
