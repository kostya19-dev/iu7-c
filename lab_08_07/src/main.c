#include "main.h"
#include "matrix.h"
#include "matrix_alloc.h"
#include <stdio.h>
#include "errors.h"

int main()
{
    int64_t **a, **b;
    int64_t m, n, p, q;

    int read_result = read_matrix(&a, &n, &m);
    if (read_result != OK)
    {
        return read_result;
    }

    read_result = read_matrix(&b, &p, &q);
    if (read_result != OK)
    {
        free_matrix(a, n);
        return read_result;
    }

    int64_t k = (m < n) ? m : n;
    int64_t s = (p < q) ? p : q;

    if (n > m)
    {
        while (n > k)
        {
            remove_min_rows(&a, &n, m);
        }
    }
    else
    {
        while (m > k)
        {
            remove_min_cols(&a, n, &m);
        }
    }

    if (p > q)
    {
        while (p > s)
        {
            remove_min_rows(&b, &p, q);
        }
    }
    else
    {
        while (q > s)
        {
            remove_min_cols(&b, p, &q);
        }
    }

    int64_t z = (k > s) ? k : s;
    int expand_result = expand_matrix(&a, &n, &m, z);
    if (expand_result != OK)
    {
        free_matrix(a, n);
        free_matrix(b, q);
        return ARG_ERROR;
    }
    expand_result = expand_matrix(&b, &p, &q, z);
    if (expand_result != OK)
    {
        free_matrix(a, n);
        free_matrix(b, q);
        return ARG_ERROR;
    }

    int64_t rho, gamma;
    if (scanf("%ld%ld", &rho, &gamma) != 2)
    {
        free_matrix(a, n);
        free_matrix(b, q);
        return ARG_ERROR;
    }

    if (rho < 0 || gamma < 0)
    {
        free_matrix(a, n);
        free_matrix(b, q);
        return ARG_ERROR;
    }

    int64_t **a_pow = matrix_power(a, z, rho);
    int64_t **b_pow = matrix_power(b, z, gamma);

    if (!a_pow || !b_pow)
    {
        free_matrix(a, n);
        free_matrix(b, q);
        if (a_pow)
        {
            free_matrix(a_pow, n);
        }
        if (b_pow)
        {
            free_matrix(b_pow, q);
        }
        return ALLOC_ERROR;
    }

    int64_t **result_matrix = allocate_matrix(z, z);
    if (!result_matrix)
    {
        free_matrix(a, n);
        free_matrix(b, q);
        free_matrix(a_pow, n);
        free_matrix(b_pow, q);
        return ALLOC_ERROR;
    }

    for (int64_t i = 0; i < z; i++)
    {
        for (int64_t j = 0; j < z; j++)
        {
            result_matrix[i][j] = 0;
            for (int64_t k_temp = 0; k_temp < z; k_temp++)
            {
                result_matrix[i][j] += a_pow[i][k_temp] * b_pow[k_temp][j];
            }
        }
    }

    print_matrix(result_matrix, z, z);

    free_matrix(a, n);
    free_matrix(b, q);
    free_matrix(a_pow, z);
    free_matrix(b_pow, z);
    free_matrix(result_matrix, z);

    return 0;
}
