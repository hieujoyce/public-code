#include <stdio.h>
#include <conio.h>

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

int main(){
    int L, R;
    printf("Nhap L: ");
    scanf("%d", &L);
    do{
        printf("Nhap R: ");
        scanf("%d", &R);
    }while(R <= L);
    int sang[R+1];
    sangNguyenThuy(sang, R);
    printf("\nKQ: Cac gia tri cua cap F(i) * F(j) la:\n");
    for(int i = L; i < R; i++){
        int fi = sang[i] == 1 ? i : 0;
        for(int j = i + 1; j <= R; j++){
            int fj = sang[j] == 1 ? j : 0;
            printf("F(%d) * F(%d) = %d\n", i, j, fi * fj);
        }
    }
    getch();
    return 0;
}
