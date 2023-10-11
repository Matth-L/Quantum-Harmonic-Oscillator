/**
 * @file hermite.h
 * @author Lapu Matthias
 */

#ifndef HERMITE_H
#define HERMITE_H
#include <armadillo>
#include <iostream>

/**
 * @brief Hermite's object containing :
 * - the value of n (int)
 * - a vector Z with all the values to be computed
 * - an array of all the formulas pre-computed (armadillo matrix)
 */
class Hermite
{
public:
    /**
     * @brief N variable of Hermite's Polynome
     *
     */
    unsigned int n;

    /**
     * @brief getter
     *
     * @return unsigned int
     */
    unsigned int getN();

    /**
     * @brief vecteur Z
     *
     */
    arma::vec z;

    /**
     * this matrix contains
     * [
     * [z0_computed z1_computed z2_computed z3_computed] n=0
     * [z0_computed z1_computed z2_computed z3_computed] n=1
     * [z0_computed z1_computed z2_computed z3_computed] n=2
     * ]
     * it will contains the value of the hermite's polynome for each z
     */
    arma::mat polynomeMat;

    /**
     * @brief get the vector of z
     *
     * @return arma::vec
     */
    arma::vec getZ();

    /**
     * @brief set the vector of z
     *
     */
    void setZ(arma::vec);

    /**
     * @brief get the matrix of the hermite's polynome
     *
     * @return arma::mat
     */
    arma::mat getPolynomeMat();

    /**
     * @brief this class contains the initial value of N and the vector Z
     *
     */
    Hermite(unsigned int, arma::vec);

    /**
     * @brief Construct a new Hermite object
     *
     */
    Hermite(unsigned int, float, float, float);

    /**
     * @brief compute the value of the hermite's polynome
     */
    void fillPolynomeHermite();
};

#endif // HERMITE_H
