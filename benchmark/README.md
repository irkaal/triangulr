# Benchmarks for Functions for the Triangular Distribution in R

**NOTE**: Functions from [distr6](https://alan-turing-institute.github.io/distr6/) and [tfprobability](https://rstudio.github.io/tfprobability/) packages will not be included as they do not work without requiring a distribution object.

## Methodology

I used [bench](https://bench.r-lib.org/) for speed and memory benchmarking. The bench package is preferred as it provides a number of advantages over other alternatives, such as tracking of memory allocation and number of garbage collections. More info: [bench.r-lib.org](https://bench.r-lib.org/)

## Environment

R 4.0.2

| Package                                                     | Version    |
| ----------------------------------------------------------- | ---------- |
| [EnvStats](https://www.probstatinfo.com/)                   | 2.4.0      |
| [extraDistr](https://github.com/twolodzko/extraDistr)       | 1.9.1      |
| [fitODBOD](https://amalan-constat.github.io/R-fitODBOD/)    | 1.4.1.1    |
| [jmuOutlier](https://CRAN.R-project.org/package=jmuOutlier) | 2.2        |
| [mc2d](https://cran.r-project.org/package=mc2d)             | 0.1.18     |
| [metRology](https://cran.r-project.org/package=metRology)   | 0.9.28.1   |
| [OOmisc](https://cran.r-project.org/package=OOmisc)         | 1.2        |
| [propagate](https://cran.r-project.org/package=propagate)   | 1.0.6      |
| [Runuran](https://statmath.wu.ac.at/unuran/)                | 0.33       |
| [triangle](https://bertcarnell.github.io/triangle/)         | 0.12       |
| [triangulr](https://irkaal.github.io/triangulr/)            | 1.0.0.9000 |
| [VaRES](https://cran.r-project.org/package=VaRES)           | 1.0        |
| [VGAM](https://www.stat.auckland.ac.nz/~yee/VGAM/)          | 1.1.4      |

| Component | Value                        |
| --------- | ---------------------------- |
| CPU Model | Intel Core i7-8700K @ 3.7GHz |
| CPU Cores | 6                            |
| RAM Model | DIMM Synchronous 2667 MHz    |
| RAM GB    | 32                           |

## Density Functions

### 10M Quantiles

![](plot/dbench_8.png)

### Median Time

![](plot/dbench_time.png)

### Memory

![](plot/dbench_mem.png)

## Distribution Functions

### 10M Quantiles

![](plot/pbench_8.png)

### Median Time

![](plot/pbench_time.png)

### Memory Allocation

![](plot/pbench_mem.png)

## Quantile Functions

### 10M Probabilities

![](plot/qbench_7.png)

### Median Time

![](plot/qbench_time.png)

### Memory Allocation

![](plot/qbench_mem.png)

## Random Variate Generator Functions

### 10M Random Variates

![](plot/rbench_8.png)

### Median Time

![](plot/rbench_time.png)

### Memory Allocation

![](plot/rbench_mem.png)

## Expected Shortfall Functions

### 100K Probabilities

![](plot/esbench_6.png)

### Median Time

![](plot/esbench_time.png)

### Memory Allocation

![](plot/esbench_mem.png)
