#include <iostream> 
//#include <string> 
#include <time.h> 
#include <stdlib.h> 
#include <iomanip> 

using namespace std;

int main()

{

    setlocale(LC_ALL, "russian");
    int** a, h, k;//h should be equal k 
    cout << "vvedite kol-vo strok-"; cin >> h;
    cout << "vvedite kol-vo stolbov"; cin >> k;
    a = new int* [h];
    for (int i = 0; i < h; i++)
        a[i] = new int[k];
    int maxNeg = -100, minPos = 100, iN, jN, iP, jP;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            if ((i >= j) && (j <= k - i - 1))//Red area 
            {
                a[i][j] = rand() % 201 - 100;
                cout << setw(4) << a[i][j];
                if (a[i][j] > 0)
                    if (minPos > a[i][j])
                    {
                        minPos = a[i][j];
                        iP = i;
                        jP = j;
                    }
            }
            else if ((i <= j) && (j >= k - i - 1))//Green area 
            {
                a[i][j] = rand() % 201 - 100;
                cout << setw(4) << a[i][j];
                if (a[i][j] < 0)
                    if (maxNeg < a[i][j])
                    {
                        maxNeg = a[i][j];
                        iN = i;
                        jN = j;
                    }
            }
            else {
                a[i][j] = rand() % 201 - 100;
                cout << setw(4) << " ";
            }
        }
        cout << endl;
    }
    cout << endl << "maximum negative element in the green area " << maxNeg
        << "  Position: " << iN << "," << jN << endl;
    cout << "minimum positive in the red area " << minPos
        << "  Position: " << iP << "," << jP << endl << endl;
    swap(a[iP][jP], a[iN][jN]);//Replace Items 
    for (int i = 0; i < h; ++i)//Output a new array 
    {
        for (int j = 0; j < k; ++j)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
