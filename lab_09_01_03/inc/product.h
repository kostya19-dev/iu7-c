#ifndef PRODUCT_H
#define PRODUCT_H

typedef struct 
{
    char *name;
    int price;
} product;

int read_product_from_file(const char *filename, product **products, int max_count, int *count);
void free_products(product *products, int count);
int show_products(product *products, int count, double price_limit);
void print_product(const product *product);
#endif