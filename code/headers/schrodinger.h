/**
 * @file schrodinger.h
 * @author Matthias Lapu , Roméo Louati
 * @brief Resulting 1D-HO Schrödinger equation
 * @warning depends on solutions.h because we are using psi
 */

#ifndef SCHRODINGER_H
#define SCHRODINGER_H
#include <armadillo>
using namespace arma;

/**
 * @brief Class handling the computation of the Schrödinger equation, and the energy level according to the formula
 * 
 */
class Schrodinger
{
public:
    /**
     * @brief Construct a new Schrodinger object
     *
     */
    Schrodinger();

    /**
     * @brief Get the Snd Derivative object
     *
     * @return mat
     */
    mat getSndDerivative();

    /**
     * @brief Compute a matrix of second derivative,
     *
     */
    mat sndDerivative;

    /**
     * @brief Compute a matrix of second derivative,
     * using psi and second's derivate approximation
     *
     * @return mat
     */
    mat secondDerivative(mat);

    /**
     * @brief Compute the energy levels using the formula :
     * E_n = hBar * omega * (n + 1/2)
     *
     * @return double
     */
    double energyLevels(double, double, double);

    /**
     * @brief Compute the position operator squared applied to psi
     * @warning we must use solution.h
     *
     * @return mat
     */
    mat psiZ_Squared(mat);

    /**
     * @brief  Compute the Schrödinger equation (the left part)
     *
     * @return mat
     */
    mat schrodinger1DEquation(mat, double, double, double);
};

#endif // SCHRODINGER_H