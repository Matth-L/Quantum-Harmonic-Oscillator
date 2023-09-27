/**
 * @file hermite.cxx
 * @brief implementation of hermite.h
 * @author Lapu Matthias
 */

#include "../headers/hermite.h"

/**
 * @brief Construct a new Hermite:: Hermite object
 *
 * @param nInput (int)
 * @param zInput (arma::vec)
 */
Hermite::Hermite(unsigned int nInput, arma::vec zInput) {
  n = nInput;
  z = zInput;
};

int Hermite::getN() { return n; };

arma::vec Hermite::getZ() { return z; };

void Hermite::setZ(arma::vec zInput) { z = zInput; };

/**
 * @brief get the matrix of the hermite's polynome
 *
 * @return arma::mat
 */
arma::mat Hermite::getPolynomeMat() { return polynomeMat; };

/**
 * @brief compute the value of the hermite's polynome
 *
 * /!\ accessing values in a matrix => (row,column)
 */
void Hermite::fillPolynomeHermite() {
  for (int n = 0; n <= getN(); n++) {
    if (n == 0) {
      polynomeMat.insert_cols(n, ones(size(z)));
    } else if (n == 1) {
      polynomeMat.insert_cols(n, 2 * z);
    } else {
      // using the reccurence formula to get the next value
      // we compute column by column
      polynomeMat.insert_cols(n, 2 * z % polynomeMat.col(n - 1) -
                                     2 * (n - 1) * polynomeMat.col(n - 2));
    }
  }
};
