# Introduction

This project is a class assignment for the HPC course at ENSIIE. Our goal is to implement the quantum harmonic oscillator in C++ and plot the values in Python.

## Table of Contents

- [Introduction](#introduction)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)

## Introduction

The quantum harmonic oscillator is used in the world of physics to describe the behavior of a system that experiences a restoring force proportional to the displacement from equilibrium position.
This is an important model in quantum mechanics, therefore we will implement it in C++ and plot the values in Python. 

## Requirements

This project uses the following libraries:
- C++11
- armadillo (C++ library)
- cxxtest (C++ library)
- Python 3
- matplotlib (Python library)
- astyle (code formatter)

for Debian distributions, you can install the libraries using the following command:

```bash
sudo apt-get install libarmadillo-dev cxxtest python3-matplotlib build-essential astyle
```

## Installation

To install this project on your computer, you can clone the repository using the following command:

```bash
git clone https://gitlab.pedago.ensiie.fr/romeo.louati/quantum-harmonic-oscillator.git 
```

## Usage

The result will be either computed using the C++ code or the Python code. The C++ code will be used to compute the values of the quantum harmonic oscillator and the Python code will be used to plot the values.

## Commands

There is different option that can be done using makefile : 

If you wish to compile the entire project, including doxygen documentation, run the following command:
```bash
make 
```

If you wish to compile the code only, run the following command:

```bash
make code
```

If you wish to compile the documentation only, run the following command:
```bash
make doc
```

The documentation will be generated in the doc folder. You can open the index.html file to see the documentation. Our class being in French, the documentation is written in French. e.g : 
```bash 
firefox doc/html/index.html
```

If you intend to clean the project, run the following command:
```bash
make clean
```
the makefile are recursive, so you can run the same command inside the different folders to clean the specific folder.

Before any commit, we ask that you run the following command to check if there is any error in the code:
```bash
make test
```

And also please , format your code using the following command :

```bash
make style 
```
We use astyle to format our code, you can find the configuration file in the root folder.