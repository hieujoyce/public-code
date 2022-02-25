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

int main(){
    int N, k = 0, q = 0, p = 0, s = 0;
    printf("Nhap N: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        if(N % i == 0){
            p += i;
            s++;
            if(isSNT(i) == 1){
                q += i;
                k++;
            }
        }
    }
    int result = N + p + s - q - k;
    printf("\nKQ: %d", result);
    getch();
    return 0;
}
