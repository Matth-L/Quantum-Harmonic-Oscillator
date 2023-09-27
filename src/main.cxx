#include "../headers/hermite.h"

int main() {
  arma::vec input = {2, 3, 4, 5};
  Hermite test = Hermite(2, input);
  test.fillPolynomeHermite(2, input);

  arma::mat Result = test.getPolynomeMat();
  Result.print("result");
  return 0;
}
