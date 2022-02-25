#include <stdio.h>
#include <conio.h>
#include <math.h>

void sangNguyenThuy(int sang[], int n) {
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

void inSoManhMe(int sang[], int n){
    for(int i = 2; i * i <= n; i++) {
        if(sang[i] == 1) {
            int j = i * i;
            if(j <= n){
                printf("\nSo manh me voi %d la: ", i);
            }
            for(int k = 1; j * k <= n; k++){
                printf("%d,  ", j * k);
            }
        }
    }
}

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int sang[N+1];
    sangNguyenThuy(sang, N);
    inSoManhMe(sang, N);
    getch();
    return 0;
}
