#include "../headers/hermite.h"
#include "../headers/solutions.h"
#include "../headers/schrodinger.h"
#include <iostream>
#include <armadillo>

int main()
{
    Solutions sol = Solutions();
    mat res = sol.solutions(4, -10, 10, 6);
    cout << "solutions" << endl;
    cout << sol.solution << endl;

    Schrodinger x = Schrodinger();
    mat s = x.secondDerivative(res);
    cout << "shrodinger" << endl;
    cout << s << endl;

    mat psiSquared = x.psiZ_Squared(sol.solution);
    cout << "psi squared" << endl;
    cout << psiSquared << endl;

    mat schrodingerEquation = x.schrodinger1DEquation(sol.solution, 1, 1, 1);
    cout << "schrodinger equation" << endl;
    cout << schrodingerEquation << endl;

    cout << "energy levels" << endl;
    cout << x.energyLevels(1, 1, 1) << endl;

    cout << "resultat ???" << endl;
    cout << schrodingerEquation * pinv(res) << endl;

    res.save("../bin/test.csv", csv_ascii);
    return 0;
}
