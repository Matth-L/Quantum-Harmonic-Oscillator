#include "../headers/hermite.h"
#include "../headers/solutions.h"
#include "../headers/schrodinger.h"
#include <iostream>
#include <armadillo>

int main()
{
    Solutions sol = Solutions();
    mat res = sol.solutions(2, -10, 10, 10);
    cout << "solutions" << endl;
    cout << sol.solution << endl;

    Schrodinger x = Schrodinger();
    mat s = x.secondDerivative(res);
    cout << "shrodinger" << endl;
    cout << s << endl;
    mat psiSquared = x.psiZ_Squared(sol.solution);
    cout << "psi squared" << endl;
    cout << psiSquared << endl;

    res.save("../bin/test.csv", csv_ascii);
    return 0;
}
