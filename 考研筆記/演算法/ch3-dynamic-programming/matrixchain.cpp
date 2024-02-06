#include <stdio.h> 
#include<iostream>
using namespace std;
#define n 3
int s[n+1][n+1] = {0};
int c[n][n+1] = {0};


void MatrixChain(int p[4]){
    for(int i=0; i<4; i++){
        cout << i << endl;
    }
    for(int i= 1; i<= n; i++){
        s[i][i] = 0;
    }
    for(int l=2; l<= n; l++){   //控制一次要處理幾個矩陣
        for(int i = 1; i<= n-l+1; i++){ 
            int j = i+l-1;
            cout << i << ", " << j << endl;
            s[i][j] = s[i][i]+s[i+1][j]+p[i-1]*p[i]*p[j];
            for(int k=i; k<= j; k++){ 
                int r = s[i][k]+s[k+1][j]+p[i-1]*p[k]*p[j];
                if(r < s[i][j]) 
                    s[i][j] = r;
                    c[i][j] = k;
            }
        }
    }
}
void PrintParens(int c[3][4],int i,int j){
    if(i == j){
        printf("A");
    }
    else {
        printf("(");
        PrintParens(c, i, c[i][j]);
        PrintParens(c, c[i][j]+1, j);
        printf(")");
    }
    return;
}
int main(){
    int p[4] = {3, 3, 3, 1};
    MatrixChain(p);
    cout << "ans: " << s[1][n] << endl;
    PrintParens(c, 1, 3);
    return 0;
}