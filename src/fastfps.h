#ifndef FASTFPS_FASTFPS_H
#define FASTFPS_FASTFPS_H

#include "common.h"
#include "sparsemat.h"
#include "symmat.h"
#include "eigenvalue.h"

// Initial guess using partial eigen decomposition
inline void initial_guess(const SymMat& S, int d, SymMat& x)
{
    MatrixXd evecs = eigs_dense_largest_spectra(S, d);
    MatrixXd proj(S.dim(), S.dim());
    proj.noalias() = evecs * evecs.transpose();
    x.swap(proj);
}

// Thresholding of eigenvalues
inline double lambda_max_thresh(double x, double thresh)
{
    return (x > 1.0 + thresh) ?
    (x - thresh) :
    ((x > 1.0) ? 1.0 : x);
}
inline double lambda_min_thresh(double x, double thresh)
{
    return (x > 0.0) ?
    (x) :
    ((x > -thresh) ? 0.0 : (x + thresh));
}

// FPS objective function: -<S, X> + lambda * ||X||_1
// Only the lower triangular part is read
inline double fps_objfn(const SymMat& smat, const SymMat& xmat, double lambda)
{
    const int sn = smat.dim();
    const int smaxn = smat.max_dim();
    const int xn = xmat.dim();
    const int xmaxn = xmat.max_dim();

    if(sn != xn)
        throw std::invalid_argument("matrix sizes do not match");

    const double* x = xmat.data();
    const double* x_col_begin = x;
    const double* x_col_end   = x + xn;

    const double* s = smat.data();
    const double* s_col_begin = s;

    double diag1 = 0.0, diag2 = 0.0;
    double off_diag1 = 0.0, off_diag2 = 0.0;

    for(int j = 0; j < xn; j++)
    {
        x = x_col_begin + j;
        s = s_col_begin + j;

        diag1 += (*s) * (*x);
        diag2 += std::abs(*x);

        x = x + 1;
        s = s + 1;

        for(; x < x_col_end; x++, s++)
        {
            off_diag1 += (*s) * (*x);
            off_diag2 += std::abs(*x);
        }

        x_col_begin += xmaxn;
        x_col_end   += xmaxn;
        s_col_begin += smaxn;
    }

    return -(diag1 + off_diag1 * 2) + lambda * (diag2 + off_diag2 * 2);
}

// Apply a rank-r update on a sparse matrix x.
// Only the lower triangular part is read and written
// x <- xsp + a1 * v1 * v1' + ... + ar * vr * vr'
template <int r>
void rank_r_update_sparse(SymMat& x, const dgCMatrix& xsp, const RefVec& a, const RefMat& v)
{
    const int xn = x.dim();
    if(xn != xsp.rows())
        throw std::invalid_argument("matrix sizes do not match");

    double vj[r];

    for(int j = 0; j < xn; j++)
    {
        for(int k = 0; k < r; k++)
        {
            vj[k] = a[k] * v.coeff(j, k);
        }
        for(int i = j; i < xn; i++)
        {
            double sum = 0.0;
            for(int k = 0; k < r; k++)
            {
                sum += vj[k] * v.coeff(i, k);
            }
            x.ref(i, j) = sum;
        }
    }

    // Add the sparse matrix
    xsp.add_to(x);
}

// x += alpha*x + beta*y + gamma*z
// Only the lower triangular part is read and written
inline void sym_mat_update(
    int p, double* x, const double* y, const double* z,
    double alpha, double beta, double gamma
)
{
    double*       x_col_begin = x;
    const double* x_col_end   = x + p;

    const double* y_col_begin = y;
    const double* y_col_end   = y + p;

    const double* z_col_begin = z;
    const double* z_col_end   = z + p;

    for(int j = 0; j < p; j++)
    {
        x = x_col_begin + j;
        y = y_col_begin + j;
        z = z_col_begin + j;

        for(; x < x_col_end; x++, y++, z++)
            (*x) += alpha * (*x) + beta * (*y) + gamma * (*z);

        x_col_begin += p;
        x_col_end   += p;

        y_col_begin += p;
        y_col_end   += p;

        z_col_begin += p;
        z_col_end   += p;
    }
}

// x += gamma*z
// Only the lower triangular part is read and written
inline void sym_mat_update(
    int p, double* x, const double* z, double gamma
)
{
    double*       x_col_begin = x;
    const double* x_col_end   = x + p;

    const double* z_col_begin = z;
    const double* z_col_end   = z + p;

    for(int j = 0; j < p; j++)
    {
        x = x_col_begin + j;
        z = z_col_begin + j;

        for(; x < x_col_end; x++, z++)
            (*x) += gamma * (*z);

        x_col_begin += p;
        x_col_end   += p;

        z_col_begin += p;
        z_col_end   += p;
    }
}

// Frobenius norm of a symmetric matrix
// Only the lower triangular part is read
inline double sym_mat_norm(int p, const double* x)
{
    const double* col_begin = x;
    const double* col_end   = x + p;
    double diag = 0.0;
    double off_diag = 0.0;

    for(int j = 0; j < p; j++, col_begin += p, col_end += p)
    {
        x = col_begin + j;
        diag += (*x) * (*x);
        x = x + 1;

        for(; x < col_end; x++)
            off_diag += (*x) * (*x);
    }

    return std::sqrt(diag + 2 * off_diag);
}

// FPS objective function: -<S, X> + lambda * ||X||_1
// Only the lower triangular part is read
inline double fps_objfn(int p, const double* x, const double* s, double lambda)
{
    const double* x_col_begin = x;
    const double* x_col_end   = x + p;

    const double* s_col_begin = s;
    const double* s_col_end   = s + p;

    double diag1 = 0.0, diag2 = 0.0;
    double off_diag1 = 0.0, off_diag2 = 0.0;

    for(int j = 0; j < p; j++)
    {
        x = x_col_begin + j;
        s = s_col_begin + j;

        diag1 += (*s) * (*x);
        diag2 += std::abs(*x);

        x = x + 1;
        s = s + 1;

        for(; x < x_col_end; x++, s++)
        {
            off_diag1 += (*s) * (*x);
            off_diag2 += std::abs(*x);
        }

        x_col_begin += p;
        x_col_end   += p;

        s_col_begin += p;
        s_col_end   += p;
    }

    return -(diag1 + off_diag1 * 2) + lambda * (diag2 + off_diag2 * 2);
}


#endif  // FASTFPS_FASTFPS_H
