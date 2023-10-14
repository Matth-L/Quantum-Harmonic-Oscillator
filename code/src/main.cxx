#include "../headers/hermite.h"
#include "../headers/solutions.h"
#include "../headers/schrodinger.h"
#include <iostream>
#include <armadillo>
using namespace arma;

int main()
{
  Solutions sol = Solutions();
  int n = 1;
  mat res = sol.solutions(n, -5, 5, 100);
  cout << "solutions" << endl;
  cout << res << endl;

  Schrodinger x = Schrodinger();
  mat snd = x.secondDerivative(res);
  cout << "snd" << endl;
  cout << snd << endl;

  mat psiSquared = x.psiZ_Squared(res);
  cout << "psi squared" << endl;
  cout << psiSquared << endl;

  mat schrodingerEquation = x.schrodinger1DEquation(res, 1, 1, 1);
  cout << "schrodinger equation" << endl;
  cout << schrodingerEquation << endl;

  cout << "energy levels" << endl;
  cout << x.energyLevels(1, 1, n - 1) << endl;

  res.shed_row(0);
  res.shed_col(0);
  res.shed_col(res.n_cols - 1);

  mat energie = schrodingerEquation * pinv(res);
  cout << sum(energie) << endl;

  // res.save("../bin/test.csv", csv_ascii);

  // arma::mat A;
  // A.load("../code/data/nodes_weights", arma::csv_ascii);
  // A.print();

  Solutions sol = Solutions();

  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      float a = sol.verifOrthonormality(i, j);
      printf("%10f", a);
    }
    printf("\n");
  }

  sol.save("./bin/test.csv", csv_ascii);
  return 0;
}
