/**
 *@file schrodinger.cxx
 *@author Matthias Lapu , Roméo Louati 
 *@brief calcul de l'énergie en utilisant
 * l'approximation de la dérivée seconde
 */

#include <cmath>
#include <iostream>
#include "../headers/solutions.h"
#include "../headers/schrodinger.h"
using namespace arma;

/**
 * @brief Construct a new Schrodinger:: Schrodinger object
 *
 */
Schrodinger::Schrodinger() {};

/**
 * @brief Return the matrix of the second derivative
 * 
 * @return mat 
 */
mat Schrodinger::getSndDerivative()
{
    return sndDerivative;
}

/**
 * @brief Compute the energie levels using the formula : 
 * E = hbar * omega * (n + 0.5)
 *
 * @param hbar
 * @param omega
 * @param n
 * @return double
 */
double Schrodinger::energyLevels(double hbar, double omega, double n)
{
    return hbar * omega * (n + 0.5);
};

/**
 * @brief Compute the position operator squared applied to psi
 * 
 * @param psi 
 * @return mat 
 */
mat Schrodinger::psiZ_Squared(mat psi)
{
    rowvec z = pow(psi.row(0), 2);
    psi.shed_row(0);
    for (int i = 0; i < (int)psi.n_rows; i++)
    {
        psi.row(i) = z % psi.row(i);
    }
    return psi;
};

/**
 * @brief Compute the schrodinger equation for 1D (left part of the equation)
 * It uses hbar , omega and m to compute the equation (constants)
 * 
 * @param psi (matrix of psi)
 * @param hbar 
 * @param omega 
 * @param m 
 * @return mat 
 */
mat Schrodinger::schrodinger1DEquation(mat psi, double hbar, double omega, double m)
{
    // get the second derivative
    mat sndDerivative = secondDerivative(psi);

    // get the z_hat
    mat psiSquared = psiZ_Squared(psi);
    psiSquared.shed_col(psiSquared.n_cols -1);
    psiSquared.shed_col(0);

    return -hbar * hbar / (2 * m) * sndDerivative + 0.5 * m * omega * omega * psiSquared;
};

/**
 * @brief Compute the second derivative of psi
 *
 * @details
 *
 * Goal
 *
 * Before :
 *   [z1, z2, ..., zp]
 *   [ψ0(z0), ψ0​(z2),...,ψ0(zp)] n=0
 *   [ψ1(z0), ψ1​(z2),...,ψ1(zp)] n=1
 *   ...
 *   [ψn(z0), ψn​(z2),...,ψn(zp)] n=n
 *
 * After:
 *   [z1, z2, ..., zp]
 *   [ψ0"(z1), ψ0"​(z2),...,ψ0"(zp-1)] n=0
 *   [ψ1"(z1), ψ2"​(z2),...,ψ3"(zp-1)] n=1
 *   ...
 *   [ψn"(z1), ψn"​(z2),...,ψn"(zp-1)] n=n
 *
 *
 * dx is equal to the value between 2 value, all values
 * have the same dx because they are evenly distributed
 *
 * the formula is :
 * F"(x) = ( F(x-dx) - 2F(x) + F(x+dx)) / ( dx^2 )
 *
 * @test For each value , starting at 1 we are doing :
 * ψ0​(z0) - 2*ψ0​(z1) + ψ0​(z2) / ((z1) - ​(z0))² = ψ0"(z0)
 * thus , we are not computing the first and last values
 * because they are used to compute the others
 * then we will put all the values in a matrix
 * for each psi
 *
 * @warning needs at least 3 values in the vector
 * @param psi
 * @return mat
 */
mat Schrodinger::secondDerivative(mat psi)
{
    // Compute the squared step size
    double dxSquared = pow(psi(0, 1) - psi(0, 0), 2);

    // Get the number of rows and columns in the input matrix
    int n = psi.n_rows;
    int value = psi.n_cols;

    // Create a matrix to store the second derivative
    mat sndDerivative(n, value - 2);

    // Compute the second derivative for each row of the input matrix
    for (int i = 0; i < n; i++)
    {
        // Compute the second derivative for the remaining values of the row
        for (int j = 1; j < value - 1; j++)
        {
            sndDerivative(i, j - 1) = (psi(i, j - 1) - 2 * psi(i, j) + psi(i, j + 1)) / dxSquared;
        }
    }

    sndDerivative.shed_row(0);

    // Return the second derivative matrix
    return sndDerivative;
}