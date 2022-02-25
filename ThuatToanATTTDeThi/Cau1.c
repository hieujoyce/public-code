#include <stdio.h>
#include <conio.h>
#include <math.h>

int isQprime(int n){
    int soUoc = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            soUoc++;
            if(soUoc > 4) return 0;
        }
    }
    if(soUoc == 4) return 1;
    else return 0;
}

void inSoQprime(int n){
    printf("\nKQ: ");
    for(int i = 2; i <= n; i++){
        if(isQprime(i) == 1) printf("%d   ", i);
    }
}

int main(){
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    inSoQprime(n);
    getch();
    return 0;
}
