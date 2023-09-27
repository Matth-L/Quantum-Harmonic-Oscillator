#include "../headers/hermite.h"

Hermite::Hermite(unsigned int nInput, arma::vec zInput) {
  n = nInput;
  z = zInput;
};

int Hermite::getN() { return n; };

arma::vec Hermite::getZ() { return z; }

arma::mat Hermite::getPolynomeMat() { return polynomeMat; }

/**
 * /!\ accessing values in a matrix (row,column)
 */
void Hermite::fillPolynomeHermite(unsigned int nMax, arma::vec z) {
  for (int n = 0; n <= nMax; n++) {
    if (n == 0) {
      polynomeMat.insert_cols(n, ones(size(z)));
    } else if (n == 1) {
      polynomeMat.insert_cols(n, 2 * z);
    } else {
      // pour chaque Z on va faire , 2 * Z_i * case précédente - 2*(n-1)*(2
      // cases avant)
      arma::vec toInsert(size(z));
      for (arma::uword index = 0; index < z.n_elem; index++) {
        toInsert[index] = 2 * z[index] * polynomeMat(index, n - 1) -
                          2 * (n)*polynomeMat(index, n - 2);
      }
      polynomeMat.insert_cols(n, toInsert);
    }
  }
};
