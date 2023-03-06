// Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <random>
#include <fstream>

using namespace std;
bool createFileWithRandomNumbers(int n, int* mass)
{
    FILE* fileF, * fileFA, * fileFB, * fileFC, * fileFD;
    fileFA = fopen("FA.txt", "w");
    fileFB = fopen("FB.txt", "w");
    fileFC = fopen("FC.txt", "w");
    fileFD = fopen("FC.txt", "w");
    if (!fileFA || !fileFB || !fileFC || !fileFD)
        return false;
    if ((fileF = fopen("F.txt", "w+")) == NULL)
    {
        puts("Не удалось открыть файл");
        return true;
    }
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        mass[i++] = rand() % 100 - 50;
        fwrite(&mass, sizeof(int), 1, fileF);
    }
    fcloseall();//закрыть все открытые файлы
    return true;
}
bool isFileContainsSortedArray(int* mass, int n)
{
    int i;
    FILE* fileF = fopen("F.txt", "rt");
    fscanf(fileF, "%d", &n); // Пробуем прочитать с начала
    for (int i = 0; i < n - 1; i++)
    {
        if (mass[i] > mass[i + 1])
        {
            cout << "Array is not ordered" << endl;
            return false;
        }
        else
        {
            cout << "Array is ordered" << endl;
        }
    }
    fclose(fileF);
    return true;
}
void SortFile(int* mass, int n)
{
    int i;
    if (i % 2 == 0)
    {
    }
    else
    {
    }
    FILE* fileF = fopen("F", "rt");
    fscanf(fileF, "%d", &mass); // Пробуем прочитать с начала
    while (!feof(fileF) && !ferror(fileF)) // Проверяем, прочитали ли
    {
        fscanf(fileF, "%d", &mass); // Пробуем прочитать дальше
    }
    mass[i];
    mass[i - 1];
    int mid = mass[i++] / 2;
    if (n % 2 == 1)
        mid++;
    FILE* fileFA = fopen("FA", "w");
    fprintf(fileFA, "%d ", mass[i]);
    FILE* fileFB = fopen("FB", "w");
    fprintf(fileFB, "%d ", mass[i - 1]);
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int* c = (int*)malloc(n * sizeof(int));
    int step;
    while (h < n)
    {
        step = h;
        int i;  // индекс первого пути
        int j = i - 1; // индекс второго пути
        int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {

            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
                FILE* fileFC = fopen("FC", "w");
                if (mass[i] < mass[j])
                {
                    c[k] = mass[i];
                    i++; k++;
                }
                else {
                    FILE* fileFD = fopen("FD", "w");
                    c[k] = mass[j];
                    j++; k++;
                }

            }
            FILE* fileFA = fopen("FA", "w");
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = mass[i];
                i++; k++;
            }
            FILE* fileFB = fopen("FB", "w");
            while ((j < (mid + step)) && (j < n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = mass[j];
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        FILE* fileF = fopen("F", "w");
        for (i = 0; i < n; i++)
            mass[i] = c[i];
    }
    fcloseall();//закрыть все открытые файлы

}
int main()
{
    FILE* fileF, * fileFA, * fileFB, * fileFC, * fileFD;
    bool createFileWithRandomNumbers(int n, int* mass);
    bool isFileContainsSortedArray(int* mass, int n);
    void SortFile();
    fcloseall();//закрыть все открытые файлы
    return 0;
}


