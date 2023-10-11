#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <armadillo>
#include <iostream>
#include <cmath>

class Solutions
{

public:
// The particle's mass
float m; //[MeV/c^2]
// hbar
float hbar;
// omega
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
     * @param float m
     * @param float hbar
     * @param float omega
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
     * 
     * @param unsigned int n 
     * @param float start 
     * @param float end 
     * @param unsigned int increment 
     * @return mat 
     */
    arma::mat solutions(unsigned int, float, float, unsigned int);

    /**
     * @brief Calcutate the solutions of the 1D quantum harmonic oscillator for 1 to n
     * using the given z values
     * Outputs a [n+1,number of z] matrix like the following:
     * @param unsigned int n 
     * @param mat z all the values for z
     * @return mat 
     */
    arma::mat solutions(unsigned int, arma::mat);
};

#endif // SOLUTIONS_H