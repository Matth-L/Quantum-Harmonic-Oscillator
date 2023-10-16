\mainpage

##Introduction
Ce projet consiste à calculer les solutions de l'oscillateur harmonique quantique à une dimension, et à vérifier certaines de leur propriété.

##Contexte physique
###Forme des solutions
Partons de l'équation de Schrödinger, à une dimension indépendante du temps:

\f$\hat{H}_{(z)} \psi_{n}(z) = E_{n} \psi_{n}(z)\f$

avec \f$\hat{H}_{(z)} \equiv \frac{\hat{p}_{(z)}^{2}}{2m} + \frac{1}{2}mw^{2}\hat{z}^{2}\f$

et \f$\hat{p}_{(z)}^{2} \equiv -i\hbar \frac{\partial}{\partial z}\f$


La forme analytique des solutions est la suivante:
\f$ \psi_{n}(z) = \frac{1}{\sqrt{2^{n}n!}}(\frac{mw}{\pi\hbar})^{\frac{1}{4}}e^{-\frac{mwz^{2}}{2\hbar}}H_{n}(\sqrt{\frac{mw}{\hbar}}.z)\f$

avec \f$H_{n}\f$ qui représente les polynômes d'Hermite

###Polynômes d'Hermite

Ici, nous utilisons la définition par réccurence de ces polynômes:

\f$
\begin{aligned}
H_{0}(z) &= 1 \\

H_{1}(z) &= 2z \\

\forall n \ge 1,H_{n+1}(z) &= 2zH_{n}(z) - 2nH_{n-1}(z)
\end{aligned}
\f$ 

##Calcul de la solution

Tout d'abord, il faut calculer les polynôme d'Hermite pour un ordre \f$n\f$ donné, voir hermite.h. Le résultat est stocké sous forme de tableau
dans lequel chaque ordre inférieur ou égal à celui demandé est présent, avec des valeurs choisies, donc fixes, pour z.

Ensuite, dans le fichier solution.h, on peut donc utiliser ce tableau et renvoyer une matrice avec en première ligne, les valeurs de z, puis
sur les lignes d'après: \f$\psi_{0}(z), \psi_{1}(z), \dots, \psi_{n}(z)\f$.

Finalement, il ne reste plus qu'à exporter ces données pour les tracer !

##Orthogonalité

Les solutions de cette équation sont orthonormales entre elles, c'est à dire:

\f$\forall (m,n), \int \psi^*_m(z)\psi_n(z) dz = \delta_{mn}\f$

On peut approximer cette intégrale en utilisant les règles de quadrature de Gauss:

\f$\int_{a}^b \omega(x)g(x) dx \simeq \sum_{i=0}^{n-1}w^\omega_ig(x^\omega_i)\f$

Plus précisément, on utilise ici les règles de quadrature de Gauss-Hermite car:

\f$\omega(x)\f$ est de la forme \f$\omega(x)=e^{-x^2}\f$, \f$a=-\infty\f$ et \f$b=+\infty\f$

##Calcul de l'énergie

Maintenant qu'on dispose des solutions, on peut calculer le membre de gauche de l'équation de Schrödinger:

\f$-\frac{\hbar}{2m}\frac{d\Psi^{2}}{dx^{2}} + \frac{1}{2}mw^{2}Z^2\Psi\f$

à l'aide de l'approximation de la dérivée seconde via la méthode des différences finies. Ici, \f$\Psi\f$ est la matrice venant de solution.h,
\f$Z\f$ est le vecteur qui contient toutes les abscisses \f$z_0,z_1, \dots, z_n\f$. 

Ce qui nous donne une matrice \f$A\f$, la matrice hamiltonienne liée à ce système.

On a donc \f$A = E\Psi\f$, avec \f$E\f$ qui est un vecteur qui possède \f$E_0,E_1,\dots, E_n\f$, les inconnues du système.
On utilise alors pinv sur la matrice de \f$\Psi\f$, car cette matrice n'est pas forcément carrée,ce qui donne:
\f$E \simeq A\Psi^{-1}\f$

Il faut sommer les lignes de \f$E\f$ ce qui donne les \f$E_0,E_1,\dots, E_n\f$