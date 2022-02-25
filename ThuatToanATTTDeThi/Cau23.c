#include <stdio.h>
#include <conio.h>

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

int tongSNT(int sang[], int min, int max){
    int total = 0;
    for(int i = min; i <= max; i++) {
        if(i >= 2 && sang[i] == 1) total += i;
    }
    return total;
}

int main(){
    int A, B;
    printf("Nhap A: ");
    scanf("%d", &A);
    do{
        printf("Nhap B: ");
        scanf("%d", &B);
    }while(B <= A);
    int sang[B+1];
    sangNguyenThuy(sang, B);
    int total = tongSNT(sang, A, B);
    printf("\nKQ: Tong = %d", total);
    if(isSNT(total) == 1) printf("\nKQ: YES");
    else printf("\nKQ: NO");

    getch();
    return 0;
}
