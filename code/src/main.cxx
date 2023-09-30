#include "../headers/hermite.h"

int main()
{
  arma::vec input = {2, 3, 4, 5, 6, 7};
  Hermite test = Hermite(7, input);
  test.fillPolynomeHermite();

  arma::mat Result = test.getPolynomeMat();
  Result.print("result");
  return 0;
}
