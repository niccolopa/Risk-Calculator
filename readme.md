# Portfolio Risk Calculator (my first C++ project)

A command-line tool built in C++ to calculate foundational quantitative finance and risk metrics. This project computes core descriptive statistics from historical asset returns using only the C++ Standard Template Library.

## Overview
This engine processes arrays of daily financial returns to evaluate asset performance and volatility. It's designed to demonstrate memory-efficient calculations and standard C++ practices without relying on external data science libraries.

## Features
* **Expected return:** calculates the average historical return.
* **Sample variance:** measures the dispersion of the returns.
* **Standard deviation:** evaluate baseline asset volatility.

## Getting started

### Prerequisites
* A C++ compiler (GCC/MinGW, Clang or MSVC);
* Visual Studio Code or your preferred IDE.

### Compilation
Open your terminal in the root directory of the project and compile the code:

'''bash
g++ main.cpp -o risk_calc


