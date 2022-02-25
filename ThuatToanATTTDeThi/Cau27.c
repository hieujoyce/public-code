#include <stdio.h>
#include <conio.h>
#include <math.h>

int gcd(int a, int b){
    int A = a, B = b;
    while(B > 0){
        int R = A % B;
        A = B;
        B = R;
    }
    return A;
}

void sangNguyenThuy(int sang[], int n) {
    sang[0] = 0;
    sang[1] = 0;
    for(int i = 2; i <= n; i++) {
        sang[i] = 1;
    }
    for(int i = 2; i * i <= n; i++) {
         if(sang[i] == 1) {
             for(int j = i + i; j <= n; j += i)
                 sang[j] = 0;
        }
    }
}

int main(){
    int a, b, sang[1000];
    sangNguyenThuy(sang, 1000);
    printf("\nKQ: Cap (a, b) la: \n");
    for(int i = 1; i < 999; i++){
        for(int j = i + 1; j < 1000; j++){
            if(sang[gcd(i, j)] == 1) printf("(%d, %d),   ", i, j);
        }
    }
    getch();
    return 0;
}
