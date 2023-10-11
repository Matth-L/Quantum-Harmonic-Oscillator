/**
 *@file schrodinger.cxx
 *@author Matthias Lapu
 *@brief calcul de l'énergie en utilisant l'approximation de la dérivée
 *        seconde
 */

#include <cmath>
#include "../headers/solutions.h"
using namespace arma;

double secondeDerivative(double x, double dx, mat phi)
{
  int n = phi.n_rows - 1; // number of values
  // access matrix (row, column)

  // f (x-dx) - 2f(x) + f(x+dx)
  // f(x-dx) correspond à phi(n-1)
  // f(x) correspond à phi(n)
  // f(x+dx) correspond à phi(n+1)

  int aDeterminer = (n - 1) / 2;
  return (phi(n - 1, aDeterminer) - 2 * phi(n, aDeterminer) + phi(n + 1, aDeterminer)) / pow(dx, 2);
};

double energie(double hbar, double m, double omega, double x, double dx, mat phi)
{
  double a = -hbar * hbar / (2 * m);
  double b = secondeDerivative(x, dx, phi);
  double c = omega * omega * 1 / 2 * m * x * x;
  double d = phi(phi.n_rows - 1, (phi.n_rows - 1) / 2);

  return a * b + c * d;
};