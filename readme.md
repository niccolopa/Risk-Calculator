# Portfolio Risk Calculator

A small command-line C++ program that calculates basic risk statistics from historical returns for two assets.

## Features

- Expected return (arithmetic mean)
- Sample variance
- Standard deviation
- Covariance between Asset A and Asset B
- Correlation coefficient between Asset A and Asset B
- Historical 95% Value at Risk (VaR)

The calculations use the C++ standard library only. The sample variance and covariance use `n - 1` in the denominator because the return data is treated as a sample of a larger set of possible returns.

## Requirements

- A C++ compiler such as GCC/MinGW, Clang, or MSVC
- A terminal or an IDE such as Visual Studio Code

## Compile and run

Open a terminal in the project directory and compile the program:

```powershell
g++ risk_calc.cpp -o risk_calc.exe
```

Run it on Windows with PowerShell:

```powershell
.\risk_calc.exe
```

On macOS or Linux, use:

```bash
g++ risk_calc.cpp -o risk_calc
./risk_calc
```

## Example output

```text
Expected Return (Asset A): 0.00300000
Expected Return (Asset B): 0.00240000
Variance (Asset A): 0.00009850
Variance (Asset B): 0.00007830
Standard Deviation (Asset A): 0.00992472
Standard Deviation (Asset B): 0.00884873
Covariance: 0.00008075
Correlation Coefficient: 0.91948264
95% Value at Risk (VaR) (Asset A): -0.01100000
95% Value at Risk (VaR) (Asset B): -0.00800000
```

The return values are decimal returns, so `0.00300000` represents a daily return of `0.3%`.

## Customizing the data

Edit the `asset_a` and `asset_b` vectors in `risk_calc.cpp`. Both vectors must contain the same number of observations, and they should represent matching dates or periods so that covariance and correlation are meaningful.


