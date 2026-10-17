#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "product.h"

int read_products_from_file(const char *filename, product *products, int max_count, int *count)
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        return FILE_OPEN_ERROR;
    }

    if (fscanf(file, "%d\n", count) != 1)
    {
        fclose(file);
        return FILE_READ_ERROR;
    }

    if (*count < 0)
    {
        fclose(file);
        return FILE_READ_ERROR; 
    }

    if (*count == 0)
    {
        fclose(file);
        return FILE_READ_ERROR; 
    }

    if (*count > max_count)
    {
        fclose(file);
        return FILE_READ_ERROR;
    }

    int i = 0;
    while (!feof(file))
    {
        if (fgets(products[i].name, sizeof(products[i].name), file) == NULL)
        {
            break;
        }
        int size = strcspn(products[i].name, "\n");
        products[i].name[size] = '\0';
        if (size > 25 || size == 0)
        {
            fclose(file);
            return FILE_READ_ERROR;
        }
        if (fscanf(file, "%d\n", &products[i].price) != 1)
        {
            break;
        }
        if (products[i].price <= 0)
        {
            fclose(file);
            return FILE_READ_ERROR;
        }
        i++;
        if (i > *count)
        {
            fclose(file);
            return FILE_READ_ERROR;
        }
    }

    fclose(file);
    if (i < *count)
    {
        return FILE_READ_ERROR;
    }
    return OK;
}

void print_product(const product *product)
{
    printf("%s\n", product->name);
    printf("%d\n", product->price);
}
