// Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <random>
#include <fstream>

using namespace std;
bool CreateFILE()
{
    //создаем файлы
    fstream F("C:\\F.txt");
    fstream FA("C:\\FA.txt");
    fstream FB("C:\\FB.txt");
    fstream FC("C:\\FC.txt");
    fstream FD("C:\\FD.txt");
    if (!F.is_open() || !FA.is_open() || !FB.is_open() || !FC.is_open() || !FD.is_open())
        return false;
}
    bool createFileWithRandomNumbers(int n, int* A, fstream &F)
    {
    if (F.is_open() == NULL)
    {
        puts("Не удалось открыть файл");
        return true;
    }
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        A[i++] = rand() % 100 - 50;
        F<<A<<"";
    }
    
    return true;
    }
bool isFileContainsSortedArray(int* A, int n, fstream &F)
{
    int i;
    if (F.is_open() == NULL)
    {
        puts("Не удалось открыть файл");
        return true;
    }
    F >> A[i]; // Пробуем прочитать с начала
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] > A[i + 1])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return isFileContainsSortedArray;
}
int Razbienie(fstream &F, fstream &FA, fstream &FB, int* A, int n)
{
    int i = 0;
    if (i % 2 == 0)
    {
    }
    else
    {
    }
    F.open("C:\\F.txt");
    while (!F.eof()) // Проверяем, прочитали ли
    {
        F >> A[i]; // Пробуем прочитать дальше
    }
    A[i];
    A[i - 1];
    FA.open("C:\\FA.txt");
    FA << A[i] << "";
    FB.open("C:\\FB.txt");
    FB << A[i - 1] << "";
    return 0;
}
void SortFile(int* A, int n,fstream &F, fstream &FA, fstream &FB,fstream &FC, fstream &FD)
{
    int mid = n / 2;
    if (n % 2 == 1)
        mid++;
    
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
                if (A[i] < A[j])
                {
                    c[k] = A[i];
                    i++; k++;
                }
                else {
                    c[k] = A[j];
                    j++; k++;
                }

            }
             FC.open("C:\\FC.txt");
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                c[k] = A[i];
                i++; k++;
                FC << A[i] << "";
            }
             FD.open("C:\\FD.txt");
            while ((j < (mid + step)) && (j < n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                c[k] = A[j];
                j++; k++;
                FD << A[j] << "";
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходную последовательность
        for (i = 0; i < n; i++)
            A[i] = c[i];
         F.open("C:\\F.txt");
        F << c[i] << "";
    }
    

}
int main(int* A, int n, fstream& F, fstream& FA, fstream& FB, fstream& FC, fstream& FD)
{
    bool CreateFILE();
    bool createFileWithRandomNumbers(int n, int* A);
     int Razbienie();
    void SortFile();
   bool isFileContainsSortedArray(int* A, int n);
 return 0;
}




