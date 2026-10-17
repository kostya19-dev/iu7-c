#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct
{
    char name[50];
    int price;
} product;

int read_products_from_file(const char *filename, product *products, int max_count, int *count);
void print_product(const product *product);

#endif
