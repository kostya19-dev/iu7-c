#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "product.h"
#include "utils.h"
#include "errors.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return ARG_ERROR;
    }

    const char *filename = argv[1];
    double price_limit = str_to_double(argv[2]);

    if (!(price_limit > 0))
    {
        return ARG_ERROR;
    }

    product products[20];
    int count;
    int status = read_products_from_file(filename, products, 15, &count);
    if (status != OK)
    {
        return FILE_READ_ERROR;
    }

    if (count == -1)
    {
        return FILE_READ_ERROR;
    }

    if (count <= 0)
    {
        return EMPTY_ERROR;
    }
    if (count > 15)
    {
        return EMPTY_ERROR;
    }

    for (int i = 0; i < count; i++)
    {
        if (strlen(products[i].name) == 0)
        {
            return ARG_ERROR;
        }

        if (products[i].price < 0)
        {
            return ARG_ERROR;
        }
        if (products[i].price == 0)
        {
            return ARG_ERROR;
        }

        if (products[i].price < price_limit)
        {
            print_product(&products[i]);
        }
    }

    return OK;
}
