#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <stdio.h>
#define Etype int
using namespace std;
int  GT(Etype a, Etype b)
{
    return a > b;
}

void            LINEARINSERTION(Etype a[], unsigned long n)
{
    unsigned long   i,
                    j;
    Etype           tmp;

    for (i = 1; i < n; i++)     /* look for insertion point. */
        for (j = i; j > 0 && GT(a[j - 1], a[j]); j--) {
            /* Move the others down and insert it. */
            tmp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = tmp;
        }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "russian");
            const int k=50000;
            int A[k];
        for (int i=0;i<k;i++)
            A[i]=1+rand()%100;
         cout << "Первые 10 элементов:" << endl;
        for (int i=0;i<10;i++)
           cout << A[i] << "  ";
            cout << endl;
        cout << "Последние 10 элементов:" << endl;
        for (int i=49990;i<50000;i++)
           cout << A[i] << "  ";
            cout << endl;
            clock_t start = clock();
            LINEARINSERTION(A,k);
           clock_t end = clock();
              double seconds = (double)(end - start) / CLOCKS_PER_SEC;
              printf("The time: %f seconds\n", seconds);
         cout << "Отсортированные первые 10 элементов:" << endl;
            for (int i=0;i<10;i++)
            cout << A[i] << "  ";
            cout << endl;
            cout << "Отсортированные последние 10 элементов:" << endl;
        for (int i=49990;i<50000;i++)
           cout << A[i] << "  ";
            cout << endl;
            system("pause");
    return a.exec();
}
