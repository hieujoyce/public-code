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

int main(){
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);
    int sang[N+3];
    sangNguyenThuy(sang, N+2);
    printf("\nKQ: Nhung cap so NT sinh doi la:\n");
    for(int i = 2; i <= N; i++){
        if(sang[i] == 1 && sang[i+2] == 1) printf("(%d, %d),  ", i, i + 2);
    }
    getch();
    return 0;
}
