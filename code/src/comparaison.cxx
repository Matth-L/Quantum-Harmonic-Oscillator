/**
 * @file comparaison.cxx
 * @author Matthias Lapu
 * @brief Fichier de comparaison de la fonction pow et de la multiplication
 */
#include <iostream>
#include <cmath>
#include <chrono>

/**
 * @brief this function compares the pow function and the multiplication
 *
 * @test compare the pow function and the multiplication using the same base and exponent
 * we can see that pow is slower than the multiplication
 * @return int
 */
int main()
{
    double base = 2.0;
    double exponent = 9.0;
    double result = 1.0; // Résultat de la multiplication

    // Mesure du temps pour la fonction pow
    auto start_pow = std::chrono::high_resolution_clock::now();
    result = std::pow(base, exponent);
    auto end_pow = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_pow = end_pow - start_pow;

    // Mesure du temps pour la multiplication
    auto start_mul = std::chrono::high_resolution_clock::now();
    result = 1.0;
    for (int j = 0; j < exponent; j++)
    {
        result *= base;
    }
    auto end_mul = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_mul = end_mul - start_mul;

    // Affichage des résultats
    std::cout << "Résultat : " << result << std::endl;
    std::cout << "Temps (pow) : " << time_pow.count() << " secondes" << std::endl;
    std::cout << "Temps (multiplication) : " << time_mul.count() << " secondes" << std::endl;

    return 0;
}
