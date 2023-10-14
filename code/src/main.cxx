#include "../headers/hermite.h"
#include "../headers/solutions.h"
#include "../headers/schrodinger.h"
#include <iostream>
#include <armadillo>
using namespace arma;

int main()
{
    Solutions sol = Solutions();
    mat res = sol.solutions(3, -10, 10, 6);
    cout << "solutions" << endl;
    cout << res << endl;

    Schrodinger x = Schrodinger();
    mat snd = x.secondDerivative(res);
    cout << "snd" << endl;
    cout << snd << endl;

    mat psiSquared = x.psiZ_Squared(res);
    cout << "psi squared" << endl;
    cout << psiSquared << endl;

    mat schrodingerEquation = x.schrodinger1DEquation(res, 1, 1, 1);
    cout << "schrodinger equation" << endl;
    cout << schrodingerEquation << endl;

    cout << "energy levels" << endl;
    cout << x.energyLevels(1, 1, 2) << endl;

    // we have a system : A = lambda * X , lambda is unknown
    // we want to find the eigenvalues and eigenvectors of A

    // A = Schrodinger equation
    // lambda = energy levels
    // X = psi

    res.shed_row(0);
    res.shed_col(0);
    res.shed_col(res.n_cols - 1);
    mat energie = schrodingerEquation * inv(res);

    res.save("../bin/test.csv", csv_ascii);
    return 0;
}
