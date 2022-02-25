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
    int N, soUoc = 0, soUocNgTo = 0;
    printf("Nhap N: ");
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        if(N % i == 0){
            soUoc++;
            if(isSNT(i) == 1){
                soUocNgTo++;
            }
        }
    }
    printf("\nKQ: Co %d uoc va %d uoc nguyen to", soUoc, soUocNgTo);
    getch();
    return 0;
}