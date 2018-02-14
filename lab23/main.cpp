#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <stdio.h>
#define Etype int
using namespace std;
int             GE(Etype a, Etype b)
{
    return a >= b;
}
int             LT(Etype a, Etype b)
{
    return a < b;
}
void            QSORTB(Etype * A, int l, int r)
{
    int             loc;

    if (l < r) {
        int             i = l,
                        j = r;
        Etype           tmp,
                        pivot = A[l];
        /* Divide piles into partitions */
        for (;;) {
            while ((GE(A[j], pivot)) && (j > l))
                j--;
            while ((LT(A[i], pivot)) && (i < r))
                i++;
            if (i < j) {
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            } else {
                loc = j;
                break;
            }
        }
        /* Recurse */
        QSORTB(A, l, loc);
        QSORTB(A, loc + 1, r);
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "russian");
            const int k=480000;
            int A[k];
        for (int i=0;i<k;i++)
            A[i]=1+rand()%1000;
         cout << "Первые 10 элементов:" << endl;
        for (int i=0;i<10;i++)
           cout << A[i] << "  ";
            cout << endl;
        cout << "Последние 10 элементов:" << endl;
        for (int i=479990;i<480000;i++)
           cout << A[i] << "  ";
            cout << endl;
            clock_t start = clock();
            QSORTB(A,0,k);
           clock_t end = clock();
              double seconds = (double)(end - start) / CLOCKS_PER_SEC;
              printf("The time: %f seconds\n", seconds);
         cout << "Отсортированные первые 10 элементов:" << endl;
            for (int i=0;i<10;i++)
            cout << A[i] << "  ";
            cout << endl;
            cout << "Отсортированные последние 10 элементов:" << endl;
        for (int i=479990;i<480000;i++)
           cout << A[i] << "  ";
            cout << endl;
            system("pause");
    return a.exec();
}
