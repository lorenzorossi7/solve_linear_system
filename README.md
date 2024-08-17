This repository contains two different ways of implementing a code that solves a system of linear equations: Ax=b, where A is an NXN matrix, b is an N-vector and x is the unknown N-vector that we want to solve for.
One implementation simply consists of hard-coding the previously-computed expression for the solution. It takes longer to compile due to the length of the expressions.
The other implementation employs the so-called LU factorisation algorithm, employed, for example, in LAPACK dgesv function (see [here](https://netlib.org/lapack/explore-html-3.6.1/d7/d3b/group__double_g_esolve_ga5ee879032a8365897c3ba91e3dc8d512.html)).
This implementation was used to remove the need for LAPACK in the GRFolres code. It turns out that this algorithm is faster than LAPACK's one.
