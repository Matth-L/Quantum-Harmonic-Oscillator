#include "../headers/hermite.h"
#include"../headers/solutions.h"

int main()
{
  arma::mat sol = Solutions::solutions(2,-1,1,10);
  sol.print("result");

  // arma::vec input = {2, 3, 4, 5, 6, 7};
  // Hermite test = Hermite(7, input);
  // test.fillPolynomeHermite();

  // arma::mat Result = test.getPolynomeMat();
  // Result.print("result");
  return 0;
}
