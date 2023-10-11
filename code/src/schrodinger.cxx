/**
 *@file schrodinger.cxx
 *@author Matthias Lapu
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

mat Schrodinger::getSndDerivative()
{
    return sndDerivative;
}

// access matrix (row, column)

/**
 * @brief
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
 * @example For each value , starting at 1 we are doing :
 * ψ0​(z0) - 2*ψ0​(z1) + ψ0​(z2) / (ψ0​(z1) - ψ0​(z0))² = ψ0"(z0)
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
    // the pow function is slower than just doing x*x
    // unless we use -ffast-math
    double dxSquared = (psi(0, 1) - psi(0, 0)) * (psi(0, 1) - psi(0, 0));

    // number of iteration
    int n = psi.n_rows;

    // number of value in a Vect
    int value = psi.n_cols;

    cout << n << endl;
    cout << value << endl;
    cout << dxSquared << endl;

    sndDerivative = mat(n, value - 2);

    // for each row , we are going to take 3 value at a time
    // and compute the second derivative
    // using pointers reduce the overall computing time
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 1; j < value - 1; j++)
        {
            sndDerivative(i, count) = (psi(i, j - 1) - 2 * psi(i, j) + psi(i, j + 1)) / dxSquared;
            count++;
        }
    }

    return sndDerivative;
};

/**
 * @brief Compute the energie levels
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

mat Schrodinger::psiZ_Squared(mat x)
{
    int n = x.n_rows;
    // vector only take cols
    vec z = x.row(0).t();

    // square Z
    z = pow(z, 2);

    Solutions sol = Solutions();
    sol.solutions(n - 2, z);

    // fill a matrix with one
    return sol.solution;
};