#include <stdio.h>
#include <conio.h>

int gcd(int a, int b){
    int A = a, B = b;
    while(B > 0){
        int R = A % B;
        A = B;
        B = R;
    }
    return A;
}

int main(){
    int M, N, D;
    do{
        printf("Nhap M: ");
        scanf("%d", &M);
    }while(M < 0 || M > 1000);
    do{
        printf("Nhap N: ");
        scanf("%d", &N);
    }while((N < 0 || N > 1000) || N <= M);
    do{
        printf("Nhap D: ");
        scanf("%d", &D);
    }while(D < 0 || D > 1000);
    printf("\nKQ: Cac cap so (A, B) la:\n");
    for(int i = M; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(gcd(i, j) == D) printf("(%d, %d),  ", i, j);
        }
    }
    getch();
    return 0;
}
