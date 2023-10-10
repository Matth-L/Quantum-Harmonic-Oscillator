\mainpage

##Introduction
Ce projet consiste à calculer les solutions de l'oscillateur harmonique quantique à une dimension, et à vérifier certaines de leur propriété.

##Contexte physique
###Forme des solutions
Partons de l'équation de Schrödinger:

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

Ensuite, dans le fichier solution.h, on peut donc utiliser ce tableau et renvoyer un tableau avec en première ligne, les valeurs de z, puis
sur les lignes d'après: \f$\psi_{0}(z), \psi_{1}(z), \dots, \psi_{n}(z)\f$.

Finalement, il ne reste plus qu'à exporter ces données pour les tracer !