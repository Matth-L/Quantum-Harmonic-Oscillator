#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#include <armadillo>

class Solutions
{

public:
    Solutions();
    /**
     * @brief Calcutate the solutions of the 1D quantum harmonic oscillator
     * 
     * @param int n
     * @param float start
     * @param float end
     * @param int increment
     * @return arma::mat 
     */
    arma::mat solutions(unsigned int,float,float,unsigned int);
};

#endif SOLUTIONS_H