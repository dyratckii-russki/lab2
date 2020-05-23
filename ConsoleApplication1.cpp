#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <ctime> 

using namespace std;

void rezultat(int** n, int* n1, int a, int b);
void pobeda(int* n, int a);

int main()

{
    setlocale(LC_ALL, "russian");
    int n, m;
    cout << "vvedite kol-vo strelkov-";
    cin >> n;
    cout << "vvedite kol-vo vistrelov-";
    cin >> m;
    while (n == 0 || m == 0 || n == 1 || m == 1);
    int** a;
    a = new int* [n];
    for (int i = 0; i < n; i++)
        a[i] = new int[m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = rand() % 11;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%5d", a[i][j]);
        }
        cout << endl;
    }
    int* result;
    result = new int[n];
    rezultat(a, result, n, m);
    pobeda(result, n);
    return 0;
}
void rezultat(int** n, int* n1, int a, int b)
{
    int s;
    for (int i = 0; i < a; i++)
    {
        s = 0;
        for (int j = 0; j < b; j++)
            s += n[i][j];
        n1[i] = s;
    }
    cout << "rezul'tat: " << endl;
    for (int i = 0; i < a; i++)
        cout << n1[i] << endl;
}
void pobeda(int* n, int a)
{
    int max;
    max = n[0];
    for (int i = 0; i < a; i++)
    {
        if (n[i] > max)
            max = n[i];
    }
    cout << "max result = " << max << endl;
    for (int i = 0; i < a; i++)
    {
        if (n[i] == max)
        {
            cout << "pobejdaet № " << i + 1 << endl;
        }
    }
}

