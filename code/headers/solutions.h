#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <armadillo>
#include <cmath>
#include <iostream>

/**
 * @brief Class handling the math behind the solution and the verification for the orthonormality
 *
 */
class Solutions
{

public:
    /**
    *@brief The particle's mass [MeV/c^2]
    */
    float m;
    /**
     * @brief value for hbar [MeV.fs]
     *
     */
    float hbar;
    /**
     * @brief value for omega
     *
     */
    float omega;

    /**
     * @brief get the particle's mass
     *
     * @return float mass
     */
    float getM();

    /**
     * @brief get hbar
     *
     * @return float hbar
     */
    float getHbar();

    /**
     * @brief get omega
     *
     * @return float omega
     */
    float getOmega();
    /**
     * @brief Construct a new Solutions::solutions object
     *
     */
    Solutions(float, float, float);

    /**
     * @brief Construct a new Solutions::solutions object
     */
    Solutions();

    /**
     * @brief Calcutate the solutions of the 1D quantum harmonic oscillator for 1 to n.
     * The method calculates the z values maching the parameters
     * Outputs a [n+1,number of z] matrix like the following:
     * [
     *  [z1, z2, ..., zp]
     *  [ψ0(z0), ψ0​(z2),...,ψ0(zp)] n=0
     *  [ψ1(z0), ψ1​(z2),...,ψ1(zp)] n=1
     *  ...
     *  [ψn(z0), ψn​(z2),...,ψn(zp)] n=n
     * @return mat
     */
    arma::mat solutions(unsigned int, float, float, unsigned int);

    /**
     * @brief Calcutate the solutions of the 1D quantum harmonic oscillator for 1 to n
     * using the given z values
     * Outputs a [n+1,number of z] matrix like the following:
     * @return mat
     */
    arma::mat solutions(unsigned int, arma::mat);

    /**
     * @brief Verifies the orthogonality for the two given value for n
     *
     * @return float
     */
    float verifOrthonormality(unsigned int, unsigned int);
};

#endif // SOLUTIONS_H