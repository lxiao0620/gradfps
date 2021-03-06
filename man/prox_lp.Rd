% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{prox_lp}
\alias{prox_lp}
\alias{prox_lp_mat}
\title{Proximal operator of squared Lp norm}
\usage{
prox_lp(v, p, alpha, eps = 1e-06, maxiter = 100L, verbose = 0L)

prox_lp_mat(V, p, alpha, eps = 1e-06, maxiter = 100L, verbose = 0L)
}
\arguments{
\item{v}{A numeric vector.}

\item{p}{Norm parameter.}

\item{alpha}{Proximal parameter.}

\item{eps}{Precision of the result.}

\item{maxiter}{Maximum number of iterations.}

\item{verbose}{Level of verbosity.}

\item{V}{A symmetric matrix.}
}
\description{
This function solves the optimization problem
\deqn{\min\quad\frac{1}{2}||x||_p^2 + \frac{1}{2\alpha}||x - v||^2}{min  0.5 * ||x||_p^2 + (0.5 / \alpha) * ||x - v||^2}
}
