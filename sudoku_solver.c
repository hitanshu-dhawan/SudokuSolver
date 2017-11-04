#include <stdio.h>

#define TRUE 1
#define FALSE 0

void solve(int[9][9]);
void solve_helper(int[9][9],int,int);
int is_complete(int[9][9]);
int is_safe(int[9][9],int,int,int);
void print(int[9][9]);

void solve(int sudoku[9][9]) {
    solve_helper(sudoku,0,0);
}

void solve_helper(int sudoku[9][9],int i,int j) {

    if(is_complete(sudoku)) {
        print(sudoku);
        return;
    }

    if(sudoku[i][j]) {
            if(j<8)
                solve_helper(sudoku,i,j+1);
            else
                solve_helper(sudoku,i+1,0);
    }
    else {
        for(int n=1;n<=9;n++) {
            if(is_safe(sudoku,i,j,n)) {
                sudoku[i][j] = n;
                if(j<8)
                    solve_helper(sudoku,i,j+1);
                else
                    solve_helper(sudoku,i+1,0);
                sudoku[i][j] = 0;
            }
        }
    }
}

int is_complete(int sudoku[9][9]) {
    for(int p=0;p<9;p++)
        for(int q=0;q<9;q++)
            if(sudoku[p][q] == 0)
                return FALSE;
    return TRUE;
}

int is_safe(int sudoku[9][9],int i,int j,int n) {
    int a = i/3; a *= 3;
    int b = j/3; b *= 3;

    //square
    for(int p=a;p<a+3;p++) {
        for(int q=b;q<b+3;q++) {
            if(p==i && q==j)
                continue;
            if(sudoku[p][q] == n)
                return FALSE;
        }
    }

    //vertical
    for(int p=0;p<9;p++) {
        if(p==i)
            continue;
        if(sudoku[p][j] == n)
            return FALSE;
    }

    //horizontal
    for(int q=0;q<9;q++) {
        if(q==j)
            continue;
        if(sudoku[i][q] == n)
            return FALSE;
    }

    return TRUE;
}

void print(int sudoku[9][9]) {
    for(int p=0;p<9;p++) {
        for(int q=0;q<9;q++) {
            printf("%d ",sudoku[p][q]);
        }
        printf("\n");
    }
    printf("------------------\n");
}

int main(void) {

    int sudoku[9][9] =
    {{0,7,5,0,9,0,0,0,6},
    {0,2,3,0,8,0,0,4,0},
    {8,0,0,0,0,3,0,0,1},
    {5,0,0,7,0,2,0,0,0},
    {0,4,0,8,0,6,0,2,0},
    {0,0,0,9,0,1,0,0,3},
    {9,0,0,4,0,0,0,0,7},
    {0,6,0,0,7,0,5,8,0},
    {7,0,0,0,1,0,3,9,0}};

    solve(sudoku);

    return 0;
}
