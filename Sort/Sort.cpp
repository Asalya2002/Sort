// Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNING

#include <cstdlib>
#include <iostream>
#include <random>
#include <fstream>
using namespace std;

bool createFileWithRandomNumbers(fstream &f, const int numbersCount, const int maxNumberValue)//Создаёт файл со случайной последовательностью чисел
{
    for (int i = 0; i < 3; i++) { // i - индекс потока
        if (!f.is_open()) // Если файл не открыт
            continue; // Пропускаем итерацию
        int numbersCount = rand() % maxNumberValue;
        for (int k = 0; k < maxNumberValue; k++) {
            f << numbersCount << ' ';
            numbersCount = numbersCount + rand() % maxNumberValue;
        }
    }
    f.close();
        return true;
}
void Razbienie(fstream &f,const int numbersCount)
{
    fstream fa("FA.txt");
    fstream fb("FB.txt");
    /*bool R = true;*/
    int n;
    int k = 6;
    int nb, nc; //счетчики элементов в формируемых группах 
    int p; //р=1-признак достижения конца исходного файла
    nb = 0; nc = 0; p = 0;
    while (f)
    {
        if (!f.eof())
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
    f.close();
    fa.close();
    fb.close();

}
int Merge(fstream& f, fstream& fa, fstream& fb, int n,const int numbersCount)
{
    fstream fc("FC.txt");
    fstream fd("FD.txt");
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
        // Переносим упорядоченную последовательность (промежуточный вариант) в исходный массив
        f.open("F.txt");
        for (i = 0; i < n; i++)
            f << numbersCount << endl;
        return 0;
    }
    f.close();
    fa.close();
    fb.close();
    fc.close();
    fd.close();
}
bool isFileContainsSortedArray(fstream &f,fstream &fa,fstream &fb,const int numbersCount,const int maxNumberValue) //Проверяет массив в файле на упорядоченность
{
    if(!createFileWithRandomNumbers(f, numbersCount,maxNumberValue))
    {
        -1;
    }
    Merge(f,fa,fb,5, numbersCount);
    if (!isFileContainsSortedArray(f,fa,fb,numbersCount, maxNumberValue))
    {
        -2;
    }
    return 1;
    f.close();
}
int createAndSortFile(fstream& f,fstream& fa,fstream &fb, const int numbersCount, const int maxNumberValue) //Проверяет работает ли сортировка
{
    if (!createFileWithRandomNumbers(f, numbersCount, maxNumberValue)) {
        return -1;
    }
    Razbienie(f,numbersCount);
    Merge(f,fa,fb,maxNumberValue,numbersCount); //Вызов вашей функции сортировки

    if (!isFileContainsSortedArray(f,fa,fb,numbersCount,maxNumberValue)) {
        return -2;
    }

    return 1;
}


int main()
{  
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    fstream f("F.txt", ios_base::app | ios_base::in);
        if (!f) { cout << "Ошибка открытия файла" << endl; return 1; }
    fstream fa("FA.txt", ios_base::app | ios_base::in);
        if (!fa) { cout << "Ошибка открытия файла" << endl; return 1; }
    fstream fb("FB.txt", ios_base::app | ios_base::in);
    if (!fb) { cout << "Ошибка открытия файла" << endl; return 1; }
    fstream fc("FC.txt", ios_base::app | ios_base::in);
    if (!fc) { cout << "Ошибка открытия файла" << endl; return 1; }
    fstream fd("FD.txt", ios_base::app | ios_base::in);
    if (!fd) { cout << "Ошибка открытия файла" << endl; return 1; }
    int n=0;
    int x;
    createFileWithRandomNumbers(f,10,10);
    Razbienie(f,n);
    Merge(f,fa,fb,n,x);
    isFileContainsSortedArray(f,fa,fb,10,10);
    createAndSortFile(f,fa,fb,10,10);
    for (int i = 0; i < 10; i++) {
        switch (isFileContainsSortedArray(f,fa,fb,10,10)) {
        case 1:
            std::cout << "Test passed." << std::endl;
            break;

        case -1:
            std::cout << "Test failed: can't create file." << std::endl;
            break;

        case -2:
            std::cout << "Test failed: file isn't sorted." << std::endl;
            break;
        }
    }
    //закрыть все открытые файлы
    f.close();
    fa.close();
    fb.close();
    fc.close();
    fd.close();
    system("pause");
    return 0;
}




