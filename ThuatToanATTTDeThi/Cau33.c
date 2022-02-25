#include<stdio.h>
#include<conio.h>
#include<math.h>

void hienThiDaThuc(int a[], int t){
    int check = 0;
    for(int i = t; i >= 0; i--){
        if(a[i] == 1 && i != 0 && check == 0){
            printf("x^%d  ", i);
            check = 1;
        } else if(a[i] == 1 && i != 0 && check == 1){
            printf("+  x^%d  ", i);
        } else if(a[i] == 1 && i == 0 && check == 0){
            printf("1", i);
        } else if(a[i] == 1 && i == 0 && check == 1){
            printf("+  1", i);
        }
    }
}

void ganBangDaThuc(int a[], int b[], int t){
    for(int i = 0; i <= t; i++){
        a[i] = b[i];
    }
}

void ganBang1DaThuc(int a[], int t){
    for(int i = 0; i <= t; i++){
        a[i] = 0;
    }
    a[0] = 1;
}

void ganBang0DaThuc(int a[], int t){
    for(int i = 0; i <= t; i++){
        a[i] = 0;
    }
}

int soSanhBang1(int a[], int t){
    for(int i = 1; i <= t; i++){
        if(a[i] != 0){
            return 0;
        }
    }
    if(a[0] == 1) return 1;
    else return 0;
}

int congHoacTru(int a, int b){
    return a + b == 2 ? 0 : a + b;
}

void congHoacTruDaThuc(int a[], int b[], int c[], int t){
    for(int i = 0; i <= t; i++){
        c[i] = congHoacTru(a[i], b[i]);
    }
}

void nhanDaThuc(int a[], int b[], int c[], int g[], int t){
    int tmp[t * t + 1];
    ganBang0DaThuc(tmp, t * t);
    for(int i = 0; i <= t; i++){
        if(a[i] == 1){
            int tmp1[t * t + 1];
            ganBang0DaThuc(tmp1, t * t);
            for(int j = 0; j <= t; j++){
                if(b[j] == 1){
                    tmp1[i + j] = 1;
                }
            }
            congHoacTruDaThuc(tmp, tmp1, tmp, t * t);
        }
    }
    int tmp2[t * t + 1];
    ganBangDaThuc(tmp2, tmp, t * t);
    while(1){
        int lengtmp2 = -1;
        for(int j = t * t; j >= 0; j--){
            if(tmp2[j] == 1){
                lengtmp2 = j;
                break;
            }
        }
        if(lengtmp2 - t < 0){
            break;
        }
        if(tmp2[lengtmp2] == 1 && lengtmp2 - t >= 0){
            int tmp3[t * t + 1];
            ganBang0DaThuc(tmp3, t * t);
            for(int j = 0; j <= t; j++){
                if(g[j] == 1) tmp3[j + (lengtmp2 - t)] = 1;
            }
            congHoacTruDaThuc(tmp2, tmp3, tmp2, t * t);
        }
    }

    for(int i = 0; i <= t; i++){
        c[i] = tmp2[i];
    }
}

void chiaDaThuc(int a[], int b[], int c[], int t){
    int tmp2[t + 1];
    ganBangDaThuc(tmp2, a, t);
    int lengb;
    for(int i = t; i >= 0; i--){
        if(b[i] == 1){
            lengb = i;
            break;
        }
    }
    while(1){
        int lengtmp2 = -1;
        for(int j = t; j >= 0; j--){
            if(tmp2[j] == 1){
                lengtmp2 = j;
                break;
            }
        }
        if(lengtmp2 - lengb < 0){
            break;
        }
        if(tmp2[lengtmp2] == 1 && lengtmp2 - lengb >= 0){
            c[lengtmp2 - lengb] = 1;
            int tmp3[t + 1];
            ganBang0DaThuc(tmp3, t);
            for(int j = 0; j <= t; j++){
                if(b[j] == 1) tmp3[j + (lengtmp2 - lengb)] = 1;
            }
            congHoacTruDaThuc(tmp2, tmp3, tmp2, t);
        }
    }
}

void nghicdao(int a[], int p[], int t){
    int u[t + 1], v[t + 1], x1[t + 1], x2[t + 1], q[t + 1], r[t + 1], x[t + 1], tmp1[t + 1], tmp2[t + 1];
    for(int i = 0; i <= t; i++){
        u[i] = v[i] = x1[i] = x2[i] = q[i] = r[i] = x[i] = tmp1[i] = tmp2[i] = 0;
    }
    ganBangDaThuc(u, a, t);
    ganBangDaThuc(v, p, t);
    ganBang1DaThuc(x1, t);
    ganBang0DaThuc(x2, t);
    while(soSanhBang1(u, t) != 1){
        chiaDaThuc(v, u, q, t);
        ganBang0DaThuc(tmp1, t);
        nhanDaThuc(q, u, tmp1, p, t);
        congHoacTruDaThuc(v, tmp1, r, t);
        ganBang0DaThuc(tmp2, t);
        nhanDaThuc(q, x1, tmp2, p, t);
        congHoacTruDaThuc(x2, tmp2, x, t);
        ganBangDaThuc(v, u, t);
        ganBangDaThuc(u, r, t);
        ganBangDaThuc(x2, x1, t);
        ganBangDaThuc(x1, x, t);
    }
    printf("\n\na(x) ^ -1 mod g(x) = ");
    hienThiDaThuc(x1, t);
}

int main(){
    int a[4], g[4], t = 3;
    for(int i = t; i >= 0; i--){
        printf("Nhap he so a ^ %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("\na(x) = ");
    hienThiDaThuc(a, t);
    printf("\n\n");
    for(int i = t; i >= 0; i--){
        printf("Nhap he so g ^ %d: ", i);
        scanf("%d", &g[i]);
    }
    printf("\ng(x) = ");
    hienThiDaThuc(g, t);
    nghicdao(a, g, t);
    //Không ra kết quả chứng tỏ nó không có nghịch đảo còn vd như đề bài thì có kq thì tức có nghịch đảo
    getch();
    return 0;
}
