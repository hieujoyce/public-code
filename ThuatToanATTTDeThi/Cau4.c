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

int demSNT(int sang[], int min, int max){
    int count = 0;
    for(int i = min; i <= max; i++) {
        if(i >= 2 && sang[i] == 1) count++;
    }
    return count;
}

int main(){
    int A, B;
    printf("Nhap A: ");
    scanf("%d", &A);
    do{
        printf("Nhap B: ");
        scanf("%d", &B);
    }while(B <= A);//khi nhập B <= A sẽ bắt nhập lại 
    int sang[B+1];
    sangNguyenThuy(sang, B);
    int count = demSNT(sang, A, B);
    printf("\nKQ: Co %d SNT", count);
    getch();
    return 0;
}
