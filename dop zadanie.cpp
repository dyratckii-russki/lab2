#include <iostream>  
#include <fstream>  
#include <conio.h>  
#include <stdlib.h>  
#define SPACE ' ' 

char matrix[3][3] = { /* matrix for tic-tac-toe */
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE}
};

void get_computer_move(void), get_player_move(void);
void disp_matrix(void);
char check(void);
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    char done;
    done = SPACE;
    do {
        disp_matrix();  //game board output  
        get_player_move(); //player walks 
        done = check(); //victory check 
        if (done != SPACE) break; //winner 
        get_computer_move(); //computer is walking 
        done = check(); //victory check 
    } while (done == SPACE);
    if (done == 'X') printf("You won!\n");
    else printf("Computer won!!!!\n");
    disp_matrix(); //display of the resulting position 
    return 0;
}
//player turn input
void get_player_move(void)
{
    int x, y;
    cout << "Enter the coordinates for your X" << endl;
    cout << "Line=";
    cin >> x;
    cout << "Column=";
    cin >> y;
    x--; y--;
    if (x < 0 || y < 0 || x>2 || y>2 || matrix[x][y] != SPACE)
    {
        printf("Wrong move, try again.\n");
        get_player_move();
    }
    else matrix[x][y] = 'X';
}
//computer running
void get_computer_move(void)
{
    register int t;
    char* p;
    p = (char*)matrix;
    for (t = 0; *p != SPACE && t < 9; ++t) p++;
    if (t == 9)
    {
        exit(0); //game over 
    }
    else *p = 'O';
}
//game board display 
void disp_matrix(void)
{
    int t;
    for (t = 0; t < 3; t++)
    {
        printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
        if (t != 2) printf("\n---|---|---\n");
    }
    printf("\n");
}
//victory check 
char check(void)
{
    int t;
    char* p;
    for (t = 0; t < 3; t++) { //string check 
        p = &matrix[t][0];
        if (*p == *(p + 1) && *(p + 1) == *(p + 2)) return *p;
    }
    for (t = 0; t < 3; t++) { //column check 
        p = &matrix[0][t];
        if (*p == *(p + 3) && *(p + 3) == *(p + 6)) return *p;
    }
    //diagonal check 
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
        return matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
        return matrix[0][2];
    return SPACE;
}

