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

int demSNT(int sang[], int n){
    int count = 0;
    for(int i = 2; i <= n; i++) {
        if(sang[i] == 1) count++;
    }
    return count;
}

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int sang[N+1];
    sangNguyenThuy(sang, N);
    int count = demSNT(sang, N);
    printf("\nKQ: Co %d SNT", count);
    getch();
    return 0;
}
