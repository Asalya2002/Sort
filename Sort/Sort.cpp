// Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNING
#include <cstdlib>
#include <iostream>
#include <random>
#include <fstream>
#include <string>
using namespace std;
//Создаёт файл со случайной последовательностью чисел размера numbersCount,и диапозоном от 0 до maxNumberValue
bool createFileWithRandomNumbers(const string &fileF, const int numbersCount, const int maxNumberValue)
{
    fstream F(fileF, ios_base::in | ios_base::out);
    if (!F.is_open()) { // Проверка на открытие файла
        return false;
    }
    int numbers = rand() % maxNumberValue;
    for (int k = 0; k < maxNumberValue; k++)
    {
        // Записать всю последовательность в файл
        F << numbers << ' ';
        numbers = numbers + rand() % maxNumberValue;
    }
    
    
    F.close(); // закрыть файл
        return true;
}
bool Razbienie(const string &fileF,const int numbersCount)
{
    ifstream F(fileF);
    fstream fa("FA.txt");
    fstream fb("FB.txt");
    if (!F.is_open() || !fa.is_open() || !fb.is_open()) { // Проверка на открытие файла
        return false;
    }
    /*bool R = true;*/
    int n;
    int k = 6;
    int nb, nc; //счетчики элементов в формируемых группах 
    int p; //р=1-признак достижения конца исходного файла
    nb = 0; nc = 0; p = 0;
    while (F)
    {
        if (!F.eof())
        {
            p = 1;
            break;
        }
        else
        {
            if (nb < n)
            {
                fa << numbersCount << endl;
                k++;
                nb++;
                continue;
            }
            else
            {
                fb << numbersCount << endl;
                k++;
                nb = 0;
                nc++;
                break;
            }
        }
    }
    F.close();
    fa.close();
    fb.close();
    return true;
}
int Merge(const string& fileF, const string& fileFa, const string& fileFb, int n,const int numbersCount)
{
    fstream F(fileF);
    ifstream fa(fileFa);
    ifstream fb(fileFb);
    fstream fc("FC.txt");
    fstream fd("FD.txt");
    if (!F.is_open() || !fa.is_open() || !fb.is_open() || !fc.is_open() || !fd.is_open() ) { // Проверка на открытие файла
        return -1;
    }
    int mid = n / 2;
    if (n % 2 == 1)
      mid++;
   
    int h = 1; // шаг
    int step;
    while (h < n)
    {
        step = h;
    int i=0;  // индекс первого пути
    int j = i - 1; // индекс второго пути
    int k = 0;   // индекс элемента в результирующей последовательности
        while (step <= mid)
        {

            while ((i < step) && (j < n) && (j < (mid + step)))
            { // пока не дошли до конца пути
              // заполняем следующий элемент формируемой последовательности
              // меньшим из двух просматриваемых
               
                if (i < j)
                {
                    k = i;
                    i++; k++;
                }
                else {
                   
                    k = j;
                    j++; k++;
                }

            }
            fc.open("FC.txt");
            while (i < step)
            { // переписываем оставшиеся элементы первого пути (если второй кончился раньше)
                k = i;
                i++; k++;
            }
            fd.open("FD.txt");
            while ((j < (mid + step)) && (j < n))
            {  // переписываем оставшиеся элементы второго пути (если первый кончился раньше)
                k = j;
                j++; k++;
            }
            step = step + h; // переходим к следующему этапу
        }
        h = h * 2;
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный файл
        F.open("F.txt");
        
        for (i = 0; i < n; i++)
        { 
            F << numbersCount << endl;
        }
    }
    F.close();
    fa.close();
    fb.close();
    fc.close();
    fd.close();
    return 0;
}
bool isFileContainsSortedArray(const string &fileF,const string &fileFa,const string &fileFb,const int numbersCount,const int maxNumberValue) //Проверяет массив в файле на упорядоченность
{
    if(!createFileWithRandomNumbers(fileF, numbersCount,maxNumberValue))
    {
        -1;
    }
    Merge(fileF,fileFa,fileFb,5, numbersCount);
    if (!isFileContainsSortedArray(fileF,fileFa,fileFb,numbersCount, maxNumberValue))
    {
        -2;
    }
    return 1;
}
int createAndSortFile(const string& f,const string& fileFa,const string &fileFb, const int numbersCount, const int maxNumberValue) //Проверяет работает ли сортировка
{
    if (!createFileWithRandomNumbers(f, numbersCount, maxNumberValue)) {
        return -1;
    }
    Razbienie(f,numbersCount);
    Merge(f,fileFa,fileFb,maxNumberValue,numbersCount); //Вызов вашей функции сортировки

    if (!isFileContainsSortedArray(f,fileFa,fileFb,numbersCount,maxNumberValue)) {
        return -2;
    }
    return 1;
}


int main()
{  
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    string fileF = "F.txt";
    string fileFa = "Fa.txt";
    string fileFb = "Fb.txt";
    string fileFc = "Fc.txt";
    string fileFd = "Fd.txt";
    ifstream F(fileF);
    ifstream fa(fileFa);
    ifstream fb(fileFb);
    ifstream fc(fileFc);
    ifstream fd(fileFd);
    if (!F.is_open() || !fa.is_open() || !fb.is_open() || !fc.is_open() || !fd.is_open()) {  return -1; }
    
    int n=0;
    createFileWithRandomNumbers(fileF,100,100);
    Razbienie(fileF,n);
    Merge(fileF,fileFa,fileFb,n,100);
    isFileContainsSortedArray(fileF,fileFa,fileFb,10,10);
    createAndSortFile(fileF,fileFa,fileFb,10,10);
    switch (isFileContainsSortedArray(fileF,fileFa,fileFb,100,100)) 
    {
        case 1:
            cout << "Test passed." << endl;
            break;

        case -1:
            cout << "Test failed: can't create file." << endl;
            break;

        case -2:
            cout << "Test failed: file isn't sorted." << endl;
            break;
    }
     
    //закрыть все открытые файлы
    F.close();
    fa.close();
    fb.close();
    fc.close();
    fd.close();
    system("pause");
    return 0;
}




