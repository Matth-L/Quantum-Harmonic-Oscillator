#include "../headers/hermite.h"

Hermite::Hermite(unsigned int nInput, float zInput) {
  n = nInput;
  z = zInput;
};

float Hermite::polynomeHermite(unsigned int n, float z) {
  if (n >= 1) {
    return 2 * z * polynomeHermite(n - 1, z) -
           2 * (n - 1) * polynomeHermite(n - 2, z);
  } else if (n == 1) {
    return 2 * z;
  } else {
    return 1;
  }
};

/**
 * @brief
 */
arma::vec zValue(unsigned int n, arma::vec vectorZ) {
  // append is really slow doing this is more efficient
  if (n >= 1) {
  } else if (n == 1) {
  } else {
  }
};
