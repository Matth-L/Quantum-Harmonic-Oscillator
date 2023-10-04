#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <armadillo>
#include <iostream>
#include <cmath>

class Solutions
{

public:
    /*******************************************************
     * @brief Calcutate the solutions of the 1D quantum harmonic oscillator for 1 to
     * Outputs a [n+1,number of z] matrix like the following:
     * [
     *  [z1, z2, ..., zp]
     *  [ψ0(z0), ψ0​(z2),...,ψ0(zp)] n=0
     *  [ψ1(z0), ψ1​(z2),...,ψ1(zp)] n=1
     *  ...
     *  [ψn(z0), ψn​(z2),...,ψn(zp)] n=n
     * ]
     *
     * @param int n
     * @param float start
     * @param float end
     * @param int number of values
     * @return arma::mat
     *******************************************************/
    static arma::mat solutions(unsigned int, float, float, unsigned int);
};

#endif // SOLUTIONS_H