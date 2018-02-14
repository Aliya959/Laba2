#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include <stdio.h>
#define Etype int
using namespace std;
void SWAP(Etype  *a, Etype *b)
{
    Etype tmp = *a;
    *a = *b;
    *b = tmp;
}

int correct( int *arr, int size )
{
    while (--size > 0)
        if (arr[size - 1] > arr[size])
            return 0;
    return 1;
}
void shuffle( int *arr, int size )
{
    int i;
    for (i = 0; i < size; i++)
        SWAP(arr + i, arr + (rand() % size));
}
void bogoSort( int *arr, int size )
{
    while (!correct(arr, size))
        shuffle(arr, size);
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "russian");
            const int k=10;
            int A[k];
        for (int i=0;i<k;i++)
            A[i]=1+rand()%100;
         cout << "Элементы массива::" << endl;
        for (int i=0;i<k;i++)
           cout << A[i] << "  ";
            cout << endl;
            clock_t start = clock();
            bogoSort(A,k);
           clock_t end = clock();
              double seconds = (double)(end - start) / CLOCKS_PER_SEC;
              printf("The time: %f seconds\n", seconds);
               cout << "Отсортированные элементы с помощью сортировки BogoSort:" << endl;
            for (int i=0;i<k;i++)
            cout << A[i] << "  ";
            cout << endl;
            system("pause");
    return a.exec();
}
