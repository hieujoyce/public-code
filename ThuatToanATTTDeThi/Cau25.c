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

int tongSNT(int sang[], int soLuong){
    int total = 0, check = 0;
    for(int i = 2; ; i++) {
        if(sang[i] == 1){
            total += i;
            check++;
            if(check == soLuong) break;
        }
    }
    return total;
}

int main(){
    int N, M;
    printf("Nhap N: ");
    scanf("%d", &N);
    printf("Nhap M: ");
    scanf("%d", &M);
    int sang[N+1];
    sangNguyenThuy(sang, N);
    int total = tongSNT(sang, M);
    printf("\nTong = %d", total);
    if(total == N){
        printf("\nKQ: Thoa Man\n");
        int check = 0;
        for(int i = 2; ; i++){
            if(sang[i] == 1){
                printf("%d   ", i);
                check++;
                if(check == M) break;
            }
        }
    } else {
        printf("\nKQ: Khong thoa man.");
    }
    getch();
    return 0;
}
