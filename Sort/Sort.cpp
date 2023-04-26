// Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNING

#include <cstdlib>
#include <iostream>
#include <random>
#include <fstream>
using namespace std;

bool createFileWithRandomNumbers(fstream &f)//Создаёт файл со случайной последовательностью чисел
{
    for (int i = 0; i < 3; i++) { // i - индекс потока
        if (!f.is_open()) // Если файл не открыт
            continue; // Пропускаем итерацию
        int x = rand() % 10;
        for (int k = 0; k < 10; k++) {
            f << x << ' ';
            x = x + rand() % 10;
        }
    }
    f.close();
        return true;
}
void Razbienie() 
{
    ifstream f("F.txt");
    fstream fa("FA.txt");
    fstream fb("FB.txt");
    int k = 0;
    int x;
    while (!f.eof()) {
        for (int i = 0; i < k; i++)
        {     
       //запись в файл fa
            f >> x;
                fa << x << "\t";
        }

        for (int i = 0; i < k; i++) {      //запись в файл fb
                f >> x;
            i = i + 1;
            k = 1 - k;
           fb << x << "\t";
        }
    }
    f.close();
    fa.close();
    fb.close();

}
int Merge(fstream &f,int x)
{
    int n;
    fstream fa("FA.txt");
    fstream fb("FB.txt");
    fstream fc("FC.txt");
    fstream fd("FD.txt");
    int mid = n / 2;
    if (n % 2 == 1)
      mid++;
    Razbienie();
    int h = 1; // шаг
    // выделяем память под формируемую последовательность
    int c = (int)/*malloc*/(n * sizeof(int));
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
            x = c;
        return 0;
    }
    f.close();
    fa.close();
    fb.close();
    fc.close();
    fd.close();
}
bool isFileContainsSortedArray(fstream &f)
{
    if(!createFileWithRandomNumbers(f))
    {
        -1;
    }
    Merge(f,5);
    if (!isFileContainsSortedArray(f))
    {
        -2;
    }
    return 1;
    f.close();
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
    int n = 0;
    createFileWithRandomNumbers(f);
    Razbienie();
    Merge(f,10);
    isFileContainsSortedArray(f);
    for (int i = 0; i < 10; i++) {
        switch (isFileContainsSortedArray(f)) {
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




