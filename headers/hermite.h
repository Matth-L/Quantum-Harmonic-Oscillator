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
   * the n & z value given by the user
   */
  int n;
  float z;

  /**
   * @brief this class contains the initial value of N and Z
   */
  Hermite(unsigned int, float);

  /**
   * @brief compute the value of the hermite's polynome
   *
   * @param n
   * @param z
   */
  float polynomeHermite(unsigned int, float);
};

#endif // HERMITE_H
