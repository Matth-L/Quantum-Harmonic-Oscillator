/**
 * @file hermite.h
 */

#ifndef HERMITE_H
#define HERMITE_H
#include <armadillo>
#include <iostream>

/**
 * @brief Hermite's object containing :
 * - the value of n (int)
 * - an array of all the formulas pre-computed (armadillo matrix)
 */
class Hermite {
public:
  /**
   * the n value given by the user
   */
  int n;

  int getN();
  /*
   * all the z values (they will be computed at the same time)
   */
  arma::vec z;

  arma::vec getZ();
  /*
   * this matrix contains
   * [
   * [z0_computed z1_computed z2_computed z3_computed] n=0
   * [z0_computed z1_computed z2_computed z3_computed] n=1
   * [z0_computed z1_computed z2_computed z3_computed] n=2
   * ]
   *
   */
  arma::mat polynomeMat;

  arma::mat getPolynomeMat();

  /**
   * @brief this class contains the initial value of N and Z
   */
  Hermite(unsigned int, arma::vec);

  /**
   * @brief compute the value of the hermite's polynome
   *
   * @param n
   * @param z
   */
  void fillPolynomeHermite(unsigned int, arma::vec);

  arma::vec vectorOfZComputed();
};

#endif // HERMITE_H
