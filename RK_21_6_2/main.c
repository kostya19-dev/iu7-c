#include <stdio.h>


// Ввод длины массива
int input_array_size(void)
{
    int inputCheck, arrayLength;
    printf("Введите длину массива: ");
    inputCheck = scanf("%d", &arrayLength);

    if (inputCheck != 1)
        return -1;

    if (arrayLength <= 0 || arrayLength > 10)
        return -2;

    return arrayLength;
}



// Ввод элементов массива
int input_array(int arr[], size_t n)
{
    int inputCHECK;

    printf("Введите массив: ");
    for (size_t i = 0; i < n; i++)
    {
        inputCHECK = scanf("%d", &arr[i]);
        if (inputCHECK != 1)
            return -2;
    }

    return 0;
}

//заменяем циферки в массиве
void modifyArray(int arr[], size_t n)
{
    int prev = 0; 
    int tmp; 

    for (int i = 0; i < n - 1; i++)
    {
        tmp = arr[i]; 
        arr[i] = prev + arr[i + 1]; 
        prev = tmp; 
    }

    arr[n - 1] = prev; 
}


// Вывод измененного массива
void printArray(int arr[], size_t n)
{
    printf("Измененный массив:\n");
    for (size_t i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(void)
{
    int n = input_array_size();
    if (n == -1)
    {
        printf("Ошибка: некорректный ввод длины массива.\n");
        return 1;
    }
    else if (n == -2)
    {
        printf("Ошибка: длина массива должна быть от 1 до 10.\n");
        return 2;
    }

    int arr[n];
    int result = input_array(arr, n);
    if (result == -3)
    {
        printf("Ошибка: некорректный ввод элемента массива.\n");
        return 3;
    }

    modifyArray(arr, n);
    printArray(arr, n);

    return 0;
}
