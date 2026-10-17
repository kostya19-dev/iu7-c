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

    double price_limit;
    int result = str_to_double(argv[2], &price_limit);
    if (result != OK)
    {
        return FILE_READ_ERROR;
    }
    if (price_limit <= 0.0)
    {
        return ARG_ERROR;
    }

    int count;
    product *products;
    result = read_product_from_file(argv[1], &products, 15, &count);
    if (result != OK)
    {
        return FILE_READ_ERROR;
    }

    result = show_products(products, count, price_limit);
    if (result != OK)
    {
        fclose(stdout);
        free_products(products, count);
        return FILE_READ_ERROR;
    }
    

    fclose(stdout);
    free_products(products, count);
    return OK;
}