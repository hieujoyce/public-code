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

int tongSNT(int sang[], int n){
    int total = 0;
    for(int i = 2; i <= n; i++) {
        if(sang[i] == 1) total += i;
    }
    return total;
}

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int sang[N+1];
    sangNguyenThuy(sang, N);
    int total = tongSNT(sang, N);
    printf("\nKQ: Tong = %d", total);
    getch();
    return 0;
}
