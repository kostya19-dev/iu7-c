#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "product.h"

int read_product_from_file(const char *filename, product **products, int max_count, int *count)
{
    FILE* file = fopen(filename, "r");
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
    (*products) = malloc(sizeof(product) * (*count));
    char buffer[512];
    while (!feof(file))
    {
        if (i >= *count)
        {
            for (int j = 0; j < i; j++)
            {
                free((*products)[j].name);
            }
            free((*products));
            fclose(file);
            return FILE_READ_ERROR;
        }
        if (fgets(buffer, sizeof(buffer), file) == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free((*products)[j].name);
            }
            free((*products));
            fclose(file);
            return FILE_OPEN_ERROR;
        }

        int size = strcspn(buffer, "\n");
        buffer[size] = '\0';

        if (size > 25 || size == 0)
        {
            for (int j = 0; j < i; j++)
            {
                free((*products)[j].name);
            }
            free((*products));
            fclose(file);
            return FILE_READ_ERROR;
        }

        if (fscanf(file, "%d\n", &(*products)[i].price) != 1)
        {
            for (int j = 0; j < i; j++)
            {
                free((*products)[j].name);
            }
            free((*products));
            fclose(file);
            return FILE_READ_ERROR;
        }

        if ((*products)[i].price <= 0)
        {
            for (int j = 0; j < i; j++)
            {
                free((*products)[j].name);
            }
            free((*products));
            fclose(file);
            return FILE_READ_ERROR;
        }

        (*products)[i].name = malloc(sizeof(char) * (size + 1));
        strcpy((*products)[i].name, buffer);
        i++;
    }
    if (i < *count)
    {
        for (int j = 0; j < i; j++)
        {
            free((*products)[j].name);
        }
        free((*products));
        fclose(file);
        return FILE_READ_ERROR;
    }

    fclose(file);

    return OK;
}

void free_products(product *products, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(products[i].name);
    }
    free(products);
}

int show_products(product *products, int count, double price_limit)
{
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

void print_product(const product *product)
{
    printf("%s\n%d\n", product->name, product->price);
}
