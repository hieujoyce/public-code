#include <stdio.h>
#include <conio.h>
#include <math.h>

int isSNT(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

void sangNguyenThuy(int sang[], int n){
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

int kiemTraDieuKien(int n){
    for(int i = 1; i * i <= n; i++){
        int j = n - i * i;
        int k = 0, check = 0;
        while(k * k <= j){
            if(k * k == j) return 1;
            k++;
        }
    }
    return 0;
}

int main(){
    int A, B;
    printf("Nhap A: ");
    scanf("%d", &A);
    do{
        printf("Nhap B: ");
        scanf("%d", &B);
    }while(B <= A);
    int sang[B + 1];
    sangNguyenThuy(sang, B);
    int count = 0;
    for(int i = A; i <= B; i++){
        if(sang[i] == 1 && kiemTraDieuKien(i) == 1){
            printf("%d   ", i);
            count++;
        }
    }
    printf("\nKQ: %d", count);

    getch();
    return 0;
}
