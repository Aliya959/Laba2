#include <QCoreApplication>
#include <iostream>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <stdio.h>
using namespace std;
int             GT(int a, int b)
{
    return a > b;
}
void            SWAP( int * a, int * b)
{
    int           tmp = *a;
    *a = *b;
    *b = tmp;
}
int             LT(int a, int b)
{
    return a < b;
}
void INSERTTWO(int array[])
{
    if (GT(array[0], array[1]))
        SWAP(&array[0], &array[1]);
    return;
}
void            INSERTTHREE(int array[])
{
    if (LT(array[0], array[1])) {
        if (LT(array[1], array[2]))
            return;
        else if (LT(array[0], array[2]))
            SWAP(&array[1], &array[2]);
        else {
            int           Tmp = array[0];
            array[0] = array[2];
            array[2] = array[1];
            array[1] = Tmp;
        }
    } else {
        if (LT(array[0], array[2]))
            SWAP(&array[0], &array[1]);
        else if (LT(array[1], array[2])) {
            int           Tmp = array[0];
            array[0] = array[1];
            array[1] = array[2];
            array[2] = Tmp;
        } else
            SWAP(&array[0], &array[2]);
    }
    return;
}
void            INSERTFOUR(int array[])
{
    int           temp;
    if (GT(array[0], array[1])) {
        temp = array[0];
        array[0] = array[1];
        array[1] = temp;
    }
    if (GT(array[2], array[3])) {
        temp = array[2];
        array[2] = array[3];
        array[3] = temp;
    }
    if (GT(array[1], array[2])) {
        if (GT(array[0], array[3])) {
            temp = array[0];
            array[0] = array[2];
            array[2] = temp;
            temp = array[1];
            array[1] = array[3];
            array[3] = temp;
        } else {
            temp = array[1];
            array[1] = array[2];
            array[2] = temp;
            if (GT(array[0], array[1])) {
                temp = array[0];
                array[0] = array[1];
                array[1] = temp;
            }
            if (GT(array[2], array[3])) {
                temp = array[2];
                array[2] = array[3];
                array[3] = temp;
            }
        }
    }
}
void  SHELLSORT(int array[], int count)
{
    int          i,inc,j;
    int           tmp;

    switch (count) {
    case 0:
    case 1:
        return;
    case 2:
        INSERTTWO(array);
        return;
    case 3:
        INSERTTHREE(array);
        return;
    case 4:
        INSERTFOUR(array);
        return;
#ifdef MY_CACHE_IS_ENORMOUS
    case 5:
        InsertFive(array);
        return;
#endif

    default:

        for (inc = count; inc > 0;) {
            for (i = inc; i < count; i++) {
                j = i;
                tmp = array[i];
                while (j >= inc && (LT(tmp, array[j - inc]))) {
                    array[j] = array[j - inc];
                    j -= inc;
                }
                array[j] = tmp;
            }                   /* Calculate the next h-increment */
            inc = (size_t) ((inc > 1) && (inc < 5)) ? 1 : 5 * inc / 11;
        }
    }
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    setlocale(LC_ALL, "russian");
            const int k=480000;
            int A[k];
        for (int i=0;i<k;i++)
            A[i]=1+rand()%100;
         cout << "Первые 10 элементов:" << endl;
        for (int i=0;i<10;i++)
           cout << A[i] << "  ";
            cout << endl;
        cout << "Последние 10 элементов:" << endl;
        for (int i=479990;i<480000;i++)
           cout << A[i] << "  ";
            cout << endl;
            clock_t start = clock();
            SHELLSORT(A,k);
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
