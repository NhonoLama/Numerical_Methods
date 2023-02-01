//echeloen form
#include <iostream>
#include <cmath>
#define COL 3

using namespace std;

void xchange(float (*a)[COL], float *b, int row){
    float temp;
    for(int i = 0 ; i < COL; i++){
        temp = a[row][i];
        a[row][i] = a[row + 1][i];
        a[row + 1][i] = temp;
    }
    temp = b[row];
    b[row] = b[row + 1];
    b[row + 1] = temp; 
    
}

void gauss(float (*a)[COL], float *b){

    for(int i = 0; i < COL; i++){
        for(int j = i + 1 ; j < COL; j++){
            //check if pivot is zero.
            //if zero and row ahead has non-zero then interchange .......To be added.

            if(a[i][i] == 0){//exchange rows.
                if(a[i + 1][i] != 0){
                    xchange(&a[0], b, i);
                }
                else{
                    return;
                }

            }
            
            float factor = a[j][i] / a[i][i];
            for(int k = i; k < COL; k++){
                a[j][k] = a[j][k] - factor * a[i][k] ;
                // cout << a[j][k] << "\t" << factor <<"\n";
            } 
            b[j] = b[j] - factor * b[i];
            // cout <<"\n";
        }
    }

}

int main(){

    float a[][COL] = {{20, 15, 10}, {-3, -2.249, 7}, {5, 1, 3}}, b[COL] = {45, 1.751, 9}, x[COL] = {0};

    gauss(&a[0], b);

//find the x using elemination method
    for(int i = COL - 1; i >= 0; i--){

        float coe = 0;
        for(int j = i; j < COL; j++){
            coe += a[i][j] * x[j];
        }
        x[i] = round((b[i] - coe)/a[i][i]);
    }

    for(int i = 0; i < COL; i++){
        cout << x[i] << "\n";
    }

    return 0;
}                 
