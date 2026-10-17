#include "associative_array.h"
#include "arr.h"

assoc_array_t assoc_array_create(void)
{
    assoc_array_t arr = malloc(sizeof(struct assoc_array_type));
    if (arr)
    {
        arr->entries = malloc(10 * sizeof(struct entry));
        arr->size = 0;
        arr->capacity = 10;
    }
    return arr;
}

void assoc_array_destroy(assoc_array_t *arr)
{
    if (arr && *arr)
    {
        for (size_t i = 0; i < (*arr)->size; ++i)
        {
            free((*arr)->entries[i].key);
        }
        free((*arr)->entries);
        free(*arr);
        *arr = NULL;
    }
}

assoc_array_error_t assoc_array_insert(assoc_array_t arr, const char *key, int num)
{
    if (!arr || !key || strlen(key) == 0)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    for (size_t i = 0; i < arr->size; ++i)
    {
        if (strcmp(arr->entries[i].key, key) == 0)
        {
            return ASSOC_ARRAY_KEY_EXISTS;
        }
    }
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;
        struct entry *new_entries = realloc(arr->entries, arr->capacity * sizeof(struct entry));
        if (!new_entries)
        {
            return ASSOC_ARRAY_MEM;
        }
        arr->entries = new_entries;
    }
    arr->entries[arr->size].key = malloc(strlen(key) + 1);
    if (!arr->entries[arr->size].key)
    {
        return ASSOC_ARRAY_MEM;
    }
    strcpy(arr->entries[arr->size].key, key);
    arr->entries[arr->size].value = num;
    arr->size++;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_find(const assoc_array_t arr, const char *key, int **num)
{
    if (!arr || !key || strlen(key) == 0 || !num)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    for (size_t i = 0; i < arr->size; ++i)
    {
        if (strcmp(arr->entries[i].key, key) == 0)
        {
            *num = &arr->entries[i].value;
            return ASSOC_ARRAY_OK;
        }
    }
    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_remove(assoc_array_t arr, const char *key)
{
    if (!arr || !key || strlen(key) == 0)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    for (size_t i = 0; i < arr->size; ++i)
    {
        if (strcmp(arr->entries[i].key, key) == 0)
        {
            free(arr->entries[i].key);
            arr->entries[i] = arr->entries[arr->size - 1];
            arr->size--;
            return ASSOC_ARRAY_OK;
        }
    }
    return ASSOC_ARRAY_NOT_FOUND;
}

assoc_array_error_t assoc_array_clear(assoc_array_t arr)
{
    if (!arr)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    for (size_t i = 0; i < arr->size; ++i)
    {
        free(arr->entries[i].key);
    }
    arr->size = 0;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_each(const assoc_array_t arr, void (*action)(const char *key, int *num, void *param), void *param)
{
    if (!arr || !action)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    for (size_t i = 0; i < arr->size; ++i)
    {
        action(arr->entries[i].key, &arr->entries[i].value, param);
    }
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_min(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    if (arr->size == 0)
    {
        return ASSOC_ARRAY_NOT_FOUND;
    }
    size_t min_index = 0;
    for (size_t i = 1; i < arr->size; ++i)
    {
        if (strcmp(arr->entries[i].key, arr->entries[min_index].key) < 0)
        {
            min_index = i;
        }
    }
    *num = &arr->entries[min_index].value;
    return ASSOC_ARRAY_OK;
}

assoc_array_error_t assoc_array_max(const assoc_array_t arr, int **num)
{
    if (!arr || !num)
    {
        return ASSOC_ARRAY_INVALID_PARAM;
    }
    if (arr->size == 0)
    {
        return ASSOC_ARRAY_NOT_FOUND;
    }
    size_t max_index = 0;
    for (size_t i = 1; i < arr->size; ++i)
    {
        if (strcmp(arr->entries[i].key, arr->entries[max_index].key) > 0)
        {
            max_index = i;
        }
    }
    *num = &arr->entries[max_index].value;
    return ASSOC_ARRAY_OK;
}
