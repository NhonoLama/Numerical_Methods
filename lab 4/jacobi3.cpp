//jacobi method for linear qequation with three variables.

#include <iostream>
#include <cmath>
#define ROW 3
#define COL 3

using namespace std;

void jacobi(float *x, int a[][COL] , int b[], int iter){

    float x1[ROW] ;
    static int i = 0;

    while(i < iter){

        for(int i = 0; i < ROW; i++){
            float exp = 0;
            for(int j= 0; j < COL;j++ ){
                if(i != j){
                    exp += a[i][j] * x[j];
                }
            } 
            x1[i]= (b[i] - exp)/a[i][i];
        }

        for(int i = 0; i < ROW; i++){
            x[i] = x1[i];
        }
        i++;
    }

}

void swap(int (*a)[COL], int *b, int row, int xrow){
    int temp;
    for(int i = 0; i < COL; i++){
        temp = a[row][i];
        a[row][i] = a[xrow][i];
        a[xrow][i] = temp;
    }
    temp = b[row];
    b[row] = b[xrow];
    b[xrow] = temp;
}

void makeDiagonal(int (*a)[COL], int *b){
    for(int i = 0; i < COL; i++){
        for(int j = i + 1; j < COL; j++){
            if(a[i][i] < a[j][i]){
                swap(&a[0], b, i, j);
            }
        }
    }
}

int main(){
    //should make a diagonally dominent
    int a[COL][COL], b[COL], iter;
    float x[COL] = {0};


    //take the inputs from the user
    cout << "Enter the coef matrix: \n";
    for(int i = 0; i < COL; i++){
        for(int j = 0; j < COL; j++){
            cin >> a[i][j] ;
        }
    }

    //take the constants
    cout << "\nEnter the constants: \n";
    for(int i = 0; i < COL; i++){
        cin >> b[i];
    }

    cout << "\nEnter the number of iterations: ";
    cin >> iter;


    makeDiagonal(&a[0], b);
    jacobi(x, a, b, 4 );

    for(int i = 0; i < ROW; i++)
    cout << round(x[i]) <<"\t";
}
