#include "../headers/solutions.h"
#include "../headers/hermite.h"
using namespace arma;

// The particle's mass
float m = 1; //[MeV/c^2]

// hbar
float hbar = 1;

// omega
float omega = 1;
/********************************************************
 * @brief Calcutate the solutions of the 1D quantum harmonic oscillator for 1 to n
 * Outputs a [n+1,number of z] matrix like the following:
 * [
 *  [z1, z2, ..., zp]
 *  [ψ0(z0), ψ0​(z2),...,ψ0(zp)] n=0
 *  [ψ1(z0), ψ1​(z2),...,ψ1(zp)] n=1
 *  ...
 *  [ψn(z0), ψn​(z2),...,ψn(zp)] n=n
 * ]
 * @return mat
 *******************************************************/
mat Solutions::solutions(unsigned int n, float start, float end, unsigned int increment)
{
    mat z = linspace(start, end, increment); // creates all the values for z
    float cons = sqrt((m * omega) / hbar);
    Hermite hermiteMat = Hermite(n, cons * z); // creates the value of the Hermite polynomial
    hermiteMat.fillPolynomeHermite();

    z = z.t();
    mat z2 = pow(z, 2);           // z to the power of 2
    mat A = mat(n + 1, z.n_cols); // A is the first part of the equation without Hn
    for (unsigned int i = 0; i < n + 1; i++)
    {
        A.row(i) = (1 / (sqrt(pow(2, i) * tgamma(i + 1)))) * pow((m * omega) / (M_PI * hbar), 0.25) * exp(-((m * omega * z2) / (2 * hbar))); // filling up the matrix
    }

    mat sol = A % hermiteMat.getPolynomeMat().t(); // calculates the actual solution
    sol.insert_rows(0, z);                         // adding the z values to the solution
    return sol;
}