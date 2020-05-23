
#include <locale> 
#include <iostream> 
#include <ctime> 

using namespace std;

const int n = 4;
int i, j, l, k;
double a1, a2;
double a[n][n + 1] =

{ { 1,1,1,1,1}, //coefficient matrix, where the last column is the right side of the system 
{1,2,1,3,0},
{1,1,2,2,3},
{ 1,1,1,3,3} };

int main()

{
    setlocale(LC_ALL, "Russian");
    double* x;
    x = (double*)malloc(n * sizeof(double));
    for (k = 0; k < n; k++) //Finding the maximum item in the first column 
    {
        a1 = abs(a[k][k]);
        i = k;
        for (l = k + 1; l < n; l++)
            if (abs(a[l][k]) > a1)
            {
                i = l;
                a1 = abs(a[l][k]);
            }
        if (a1 == 0) //zero element check 
        {
            cout << "The system has no solutions." << endl;
        }
        if (i != k) // permutation of the i-th row containing the main element of the k-th row 
        {
            for (j = k; j < n + 1; j++)
            {
                a2 = a[k][j];
                a[k][j] = a[i][j];
                a[i][j] = a2;
            }
        }
        a1 = a[k][k];//k-th row conversion (Calculation of scaling factors) 
        a[k][k] = 1;
        for (j = k + 1; j < n + 1; j++)
            a[k][j] = a[k][j] / a1;
        for (i = k + 1; i < n; i++)//string conversion using k-th string 
        {
            a2 = a[i][k];
            a[i][k] = 0;
            if (a2 != 0)
                for (j = k + 1; j < n + 1; j++)
                    a[i][j] = a[i][j] - a2 * a[k][j];
        }
    }
    for (i = n - 1; i >= 0; i--) //Finding SLAU Solutions 
    {
        x[i] = 0;
        a1 = a[i][n];
        for (j = n; j > i; j--)
            a1 = a1 - a[i][j] * x[j];
        x[i] = a1;
    }
    cout << "System solution:" << endl; //conclusion of decisions 
    int t = clock();
    cout << ((float)t) / CLOCKS_PER_SEC << " seconds.n" << endl;
    for (i = 0; i < n; i++)
    {
        cout << "x[" << i + 1 << "]=" << x[i];
        cout << endl;
    }
    system("PAUSE");
    return 0;
}
