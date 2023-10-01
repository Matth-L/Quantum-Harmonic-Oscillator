#include "../headers/solutions.h"
#include "../headers/hermite.h"
using namespace std;

// tgamma = (n-1) ! =>  tgamma(i+1) = i! sounds like overkill but why not might be faster
// tgamma is a built in function
// https://en.wikipedia.org/wiki/Gamma_function

Solutions::Solutions(void){

};
/*******************************************************
 * @brief Calcutate the solutions of the 1D quantum harmonic oscillator for 1 to n
 * Outputs a [n+1,number of z] matrix like the following:
 * [
 *  [z1, z2, ..., zp]
 *  [ψ0(z0), ψ0​(z2),...,ψ0(zp)] n=0
 *  [ψ1(z0), ψ1​(z2),...,ψ1(zp)] n=1
 *  ...
 *  [ψn(z0), ψn​(z2),...,ψn(zp)] n=n
 * ]
 * @return arma::mat
 *******************************************************/
arma::mat Solutions::solutions(unsigned int n, float start, float end, unsigned int increment)
{

    // creates all the values for z
    arma::vec z = arma::linspace(start, end, increment);

    float cons = sqrt((m * omega) / hbar);

    // creates the value of the Hermite polynomial
    Hermite hermiteMat = Hermite(n, cons * z);
    hermiteMat.fillPolynomeHermite();

    // z to the power of 2
    arma::mat z2 = arma::pow(z, 2);

    // A is the first part of the equation without Hn
    arma::mat A = arma::mat(n + 1, z.n_cols);

    // passer this pemet d'avoir accès aux constante du .H
    // &z2 permet d'avoir accès à la valeur de z2 par référence
    // utilisation de each row et d'une lambda function (https://www.cprogramming.com/c++11/c++11-lambda-closures.html)
    int i = 0;
    A.each_row([this, &z2, &i](arma::rowvec &a)
               { a = (1 / (sqrt(pow(2, i) * tgamma(i + 1)))) * pow((m * omega) / (M_PI * hbar), 0.25) * arma::exp(-((m * omega * z2) / (2 * hbar))); i++; });
    arma::mat sol = A % hermiteMat.getPolynomeMat().t(); // calculates the actual solution
    sol.insert_rows(0, z);                               // adding the z values to the solution
    return sol;
}