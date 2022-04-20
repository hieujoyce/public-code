#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

//-------------------------Bengin Handle encode and decode-------------------------

int checkNegativeNumber(int n){
    if(n < 0) return n + 26;
}

int inverse(int n){
    for(int i = 0; i < 26; i++){
        if((n * i) % 26 == 1) return i;
    }
    return -1;
}

int isSNTLe(int n){
    if(n < 3) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int gcd(int a, int b){
    int A = a, B = b;
    while(B > 0){
        int R = A % B;
        A = B;
        B = R;
    }
    return A;
}

void defineLockUp(char lock[], int k[]) {
    for(int i = 0; i < strlen(lock); i++){
        k[i] = (int)lock[i] - 97;
    }
}

int euclideMoRongKhongHienThi(int a, int b){
    int x2 = 1, x1 = 0, y2 = 0, y1 = 1, B = b;
    int q, r, x, y, d;
    while(b > 0){
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        //
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    d = a;
    if(d != 1) return -1;
    x2 = x2 < 0 ? x2 + B : x2;
    return x2;
}

int nhanBinhPhuongCoLapKhongHienThi(int a, int k, int n){
    if(k == 1) {
        return a % n;
    }
    long long b = 1;
    if(k == 0) {
        return (int)b;
    }
    long long A = a;
    int t = k % 2;
    k = k / 2;
    if(t == 1){
        b = a;
    }
    for(int i = k; k > 0; k = k / 2){
        A = (A * A) % n;
        t = k % 2;
        if(t == 1){
            b = (A * b) % n;
        }
    }
    return (int)b;
}

int TinhJacobiKhongHienThi(int a, int b, int dau) {
    if(a == 1) {
        return 1 * dau;
    } else if(a == 2) {
        if(b % 8 == 1 || b % 8 == 7) {
            return 1 * dau;
        } else if(b % 8 == 3 || b % 8 == 5) {
            return -1 * dau;
        }
    } else if(a % 2 == 1 && b % 2 == 1 && a < b) {
        if(a % 4 == 3 && b % 4 == 3) {
            int tmp = a;
            a = b;
            b = tmp;
            TinhJacobiKhongHienThi(a, b, -dau);
        } else {
            int tmp = a;
            a = b;
            b = tmp;
            TinhJacobiKhongHienThi(a, b, dau);
        }
    } else if(a % 2 == 1 && b % 2 == 1 && a > b) {
        a = a % b;
        TinhJacobiKhongHienThi(a, b, dau);
    } else if(b % 2 == 1 && a % 2 == 0 && a < b) {
        int A = a;
        int dem, coso[20], somu[20], j = 0;
        for(int i = 2; i <= A; i++){
            dem = 0;
            while(A % i == 0){
                ++dem;
                A /= i;
            }
            if(dem){
                coso[j]=i;
                somu[j]=dem;
                j++;
            }
        }
        int result = 1;
        for(int i = 0; i < j; i++) {
            for(int k = 0; k < somu[i]; k++) {
                result *= TinhJacobiKhongHienThi(coso[i], b, 1);
            }
        }
        return result * dau;
    } else {
        return 0;
    }
}

int handleTinhPhiKhongHienThi(int n) {
    int dem, coso[20], somu[20], j = 0, N = n;
    for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem){
            coso[j]=i;
            somu[j]=dem;
            j++;
        }
    }
    if(j == 1 && somu[0] == 1) {
        return N - 1;
    }
    int phin = N;
    for(int i = 0; i < j; i++) {
        phin = phin * (coso[i] - 1) / coso[i];
    }
    return phin;
}

//---------------------

char* encodeByAffine(char str[], int k[]){
    int a = k[0], b = k[1];
    char *y = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        int x = (int)str[i] - 97;
        y[i] = (char)((a * x + b) % 26 + 97);
    }
    y[strlen(str)] = '\0';
    return y;
}

char* decodeByAffine(char str[], int k[]){
    int a = k[0], b = k[1];
    int inverseToA = inverse(a);
    char *x = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        int y = (int)str[i] - 97;
        int tmp = checkNegativeNumber((inverseToA * (y - b)) % 26);
        int ascii = tmp + 97;
        x[i] = (char)(ascii);
    }
    x[strlen(str)] = '\0';
    return x;
}

void nhapKhoaAffine(int k[]) {
    printf("\nNhap khoa k[1] (a): ");
    scanf("%d", &k[0]);
    printf("\nNhap khoa k[2] (b): ");
    scanf("%d", &k[1]);
}

void handleEncodeAffine() {
    printf("---------------Encode(Ma hoa Affine)---------------\n");
    char str[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    int k[2];
    nhapKhoaAffine(k);
    char* strEncode = encodeByAffine(str, k);
    printf("\nEncode: %s", strEncode);
}

void handleDecodeAffine() {
    printf("---------------Decode(Giai ma Affine)---------------\n");
    char str[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    int k[2];
    nhapKhoaAffine(k);
    char* strDecode = decodeByAffine(str, k);
    printf("\nDecode: %s", strDecode);
}

//------------------------

char* encodeByHill(char str[], int k[2][2]){
    char *y = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i += 2){
        int x1 = (int)str[i] - 97;
        int x2 = i + 1 == strlen(str) ? 0 : (int)str[i+1] - 97;
        y[i] = (char)((x1 * k[0][0] + x2 * k[0][1]) % 26 + 97);
        y[i+1] = (char)((x1 * k[1][0] + x2 * k[1][1]) % 26 + 97);
    }
    y[strlen(str)] = '\0';
    return y;
}

char* decodeByHill(char str[], int k[2][2]){
    char *x = malloc((strlen(str) + 1) * sizeof(char));
    int detk = checkNegativeNumber((k[0][0] * k[1][1] - k[0][1] * k[1][0]) % 26);
    int inverseToDetK = inverse(detk);
    int inverseToK[2][2], q[2][2];
    q[0][0] = k[1][1];
    q[0][1] = checkNegativeNumber(-k[0][1]);
    q[1][0] = checkNegativeNumber(-k[1][0]);
    q[1][1] = k[0][0];
    inverseToK[0][0] = (inverseToDetK * q[0][0]) % 26;
    inverseToK[0][1] = (inverseToDetK * q[0][1]) % 26;
    inverseToK[1][0] = (inverseToDetK * q[1][0]) % 26;
    inverseToK[1][1] = (inverseToDetK * q[1][1]) % 26;
    for(int i = 0; i < strlen(str); i += 2){
        int y1 = (int)str[i] - 97;
        int y2 = i + 1 == strlen(str) ? 0 : (int)str[i+1] - 97;
        x[i] = (char)((y1 * inverseToK[0][0] + y2 * inverseToK[0][1]) % 26 + 97);
        x[i+1] = (char)((y1 * inverseToK[1][0] + y2 * inverseToK[1][1]) % 26 + 97);
    }
    x[strlen(str)] = '\0';
    return x;
}

void nhapKhoaHill(int k[2][2]) {
    printf("--> Dang khoa:");
    printf("\n _                   _");
    printf("\n|                     |");
    printf("\n| k[0][0]    k[1][0]  |");
    printf("\n| k[0][1]    k[1][1]  |");
    printf("\n|_                   _|");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("\nNhap khoa k[%d][%d]: ", i, j);
            scanf("%d", &k[i][j]);
        }
    }
}

void handleEncodeHill() {
    printf("---------------Encode(Ma hoa Hill)---------------\n");
    char str[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    int k[2][2];
    nhapKhoaHill(k);
    char* strEncode = encodeByHill(str, k);
    printf("\n--> Encode: %s", strEncode);
}

void handleDecodeHill() {
    printf("---------------Decode(Giai ma Hill)---------------\n");
    char str[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    int k[2][2];
    nhapKhoaHill(k);
    char* strDecode = decodeByHill(str, k);
    printf("\n--> Decode: %s", strDecode);
}

//-------------------------

char* encodeByShiftCipher(char str[], int k) {
    char *y = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        int x = (int)str[i] - 97;
        y[i] = (char)((x + k) % 26 + 97);
    }
    y[strlen(str)] = '\0';
    return y;
}

char* decodeByShiftCipher(char str[], int k) {
    char *x = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        int y = (int)str[i] - 97;
        int tmp = checkNegativeNumber((y - k) % 26);
        x[i] = (char)(tmp + 97);
    }
    x[strlen(str)] = '\0';
    return x;
}

void handleEncodeShiftCipher() {
    printf("---------------Encode(Ma hoa ShiftCipher)---------------\n");
    char str[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    int k;
    printf("\nNhap khoa: ");
    scanf("%d", &k);
    char* strEncode = encodeByShiftCipher(str, k);
    printf("\n--> Encode: %s", strEncode);
}

void handleDecodeShiftCipher() {
    printf("---------------Decode(Giai ma ShiftCipher)---------------\n");
    char str[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    int k;
    printf("\nNhap khoa: ");
    scanf("%d", &k);
    char* strDecode = decodeByShiftCipher(str, k);
    printf("\n--> Decode: %s", strDecode);
}

//-------------------------

char* encodeByVigenere(char str[], char lock[]){
    int index, k[strlen(lock)];
    defineLockUp(lock, k);
    char *y = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        index = i % strlen(lock);
        int x = (int)str[i] - 97;
        y[i] = (char)((x + k[index]) % 26 + 97);
    }
    y[strlen(str)] = '\0';
    return y;
}

char* decodeByVigenere(char str[], char lock[]){
    int index, k[strlen(lock)];
    defineLockUp(lock, k);
    char *x = malloc((strlen(str) + 1) * sizeof(char));
    for(int i = 0; i < strlen(str); i++){
        index = i % strlen(lock);
        int y = (int)str[i] - 97;
        int tmp = checkNegativeNumber((y - k[index]) % 26);
        int ascii = tmp + 97;
        x[i] = (char)(ascii);
    }
    x[strlen(str)] = '\0';
    return x;
}

void handleEncodeVigenere() {
    printf("---------------Encode(Ma hoa Vigenere)---------------\n");
    char str[100], lock[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    printf("Enter lock string: ");
    fflush(stdin);
    gets(lock);
    char* strEncode = encodeByVigenere(str, lock);
    printf("\n--> Encode: %s", strEncode);
}

void handleDecodeVigenere() {
    printf("---------------Decode(Giai ma Vigenere)---------------\n");
    char str[100], lock[100];
    printf("Enter string: ");
    fflush(stdin);
    gets(str);
    printf("Enter lock string: ");
    fflush(stdin);
    gets(lock);
    char* strDecode = decodeByVigenere(str, lock);
    printf("\n--> Decode: %s", strDecode);
}

//-------------------------End Handle encode and decode-------------------------

//-------------------------Nhan binh phuong co lap------------------------------

void showHandleNBPCL(int leng, int k[], long long A[], long long b[]) {
    printf(" ");
    for(int i = 0; i < (leng + 1) * 8 - 1; i++){
        printf("_");
    }
    printf("\n");
    printf("|   i   |");
    for(int i = 0; i < leng; i++) {
        printf("%5d  |", i);
    }
    printf("\n");
    printf("|");
    for(int i = 0; i < (leng + 1) * 8 - 1; i++){
        printf("-");
    }
    printf("|\n");
    printf("|   k   |");
    for(int i = 0; i < leng; i++) {
        printf("%5d  |", k[i]);
    }
    printf("\n");
    printf("|");
    for(int i = 0; i < (leng + 1) * 8 - 1; i++){
        printf("-");
    }
    printf("|\n");
    printf("|   A   |");
    for(int i = 0; i < leng; i++) {
        printf("%5lld  |", A[i]);
    }
    printf("\n");
    printf("|");
    for(int i = 0; i < (leng + 1) * 8 - 1; i++){
        printf("-");
    }
    printf("|\n");
    printf("|   b   |");
    for(int i = 0; i < leng; i++) {
        printf("%5lld  |", b[i]);
    }
    printf("\n");
    printf("|");
    for(int i = 0; i < (leng + 1) * 8 - 1; i++){
        printf("_");
    }
    printf("|\n");
}

void nhanBinhPhuongCoLap(int a, int k, int n){
    long long arrayA[20], arrayb[20];
    int leng = 0, arrayk[20], K = k;
    long long b = 1;
    if(k == 0) {
        printf("\n--> KQ: %d ^ %d mod %d = %lld", a, K, n, b);
        return;
    }
    long long A = a;
    arrayA[leng] = A;
    int t = k % 2;
    arrayk[leng] = t;
    k = k / 2;
    if(t == 1){
        b = a;
    }
    arrayb[leng] = b;
    for(int i = k; k > 0; k = k / 2){
        leng++;
        A = (A * A) % n;
        t = k % 2;
        if(t == 1){
            b = (A * b) % n;
        }
        arrayA[leng] = A;
        arrayk[leng] = t;
        arrayb[leng] = b;
    }
    leng++;
    showHandleNBPCL(leng, arrayk, arrayA, arrayb);
    printf("\n--> KQ: %d ^ %d mod %d = %lld", a, K, n, b);
    return;
}

void handleNhanBinhPhuongCoLap() {
    printf("---------------Nhan binh phuong co lap---------------\n");
    printf("--> a ^ k mod n = ?");
    int a, k, n;
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("Nhap k: ");
    scanf("%d", &k);
    printf("Nhap n: ");
    scanf("%d", &n);
    nhanBinhPhuongCoLap(a, k, n);
}

//------------------------------Euclide mo rong---------------------------------

void euclideMoRong(int a, int b){
    int x2 = 1, x1 = 0, y2 = 0, y1 = 1, A = a, B = b;
    int q, r, x, y, d;
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
        printf("\nd = %d;     x = %d;     y = %d;", d, x, y);
        printf("\n--> %d ^ -1 mod %d = %d", B, A, y2);
        printf("\n--> %d ^ -1 mod %d = %d", A, B, x2);
        return;
    }
    printf(" _________________________________________________________________________________________ \n");
    printf("|    q   |    r   |    x   |    y   |    a   |    b   |    x2  |    x1  |    y2  |    y1  |\n");
    printf("|    -   |    -   |    -   |    -   |%6d  |%6d  |%6d  |%6d  |%6d  |%6d  |\n", a, b, x2, x1, y2, y1);
    while(b > 0){
        q = a / b;
        r = a - q * b;
        x = x2 - q * x1;
        y = y2 - q * y1;
        a = b;
        b = r;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
        printf("|%6d  |%6d  |%6d  |%6d  |%6d  |%6d  |%6d  |%6d  |%6d  |%6d  |\n", q, r, x, y, a, b, x2, x1, y2, y1);
    }
    printf("|________|________|________|________|________|________|________|________|________|________|\n");
    d = a;
    x = x2;
    y = y2;
    printf("\nd = %d;     x = %d;     y = %d;", d, x, y);
    y2 = y2 < 0 ? y2 + A : y2;
    x2 = x2 < 0 ? x2 + B : x2;
    if(d != 1) {
        printf("\n--> Vi d khac 1 nen khong co nghich dao :((");
    } else {
        printf("\n--> %d ^ -1 mod %d = %d", B, A, y2);
        printf("\n--> %d ^ -1 mod %d = %d", A, B, x2);
    }
}

void handleEuclideMoRong() {
    printf("---------------Euclide mo rong---------------\n");
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    euclideMoRong(a, b);
}

//------------------------------Euclide mo rong end-----------------------------

//------------------------------Tinh Phi ---------------------------------------

void handleTinhPhi() {
    printf("-----------------Tinh phi-----------------\n");
    int n;
    printf("\nNhap n = ");
    scanf("%d", &n);
    int dem, coso[100], somu[100], j = 0, N = n;

    for(int i = 2; i <= n; i++){
        dem = 0;
        while(n % i == 0){
            ++dem;
            n /= i;
        }
        if(dem){
            coso[j]=i;
            somu[j]=dem;
            j++;
        }
    }
    if(j == 1 && somu[0] == 1) {
        printf("\n--> %d la SNT", N);
        printf("\n--> phi(%d) = %d", N, N - 1);
        return;
    }
    printf("\n--> %d = ", N);
    for(int i = 0; i < j; i++){
        if(i == 0 && somu[i] != 1) {
            printf("%d ^ %d", coso[i], somu[i]);
        } else if(i == 0 && somu[i] == 1) {
            printf("%d", coso[i]);
        } else if(i != 0 && somu[i] != 1) {
            printf(" * %d ^ %d", coso[i], somu[i]);
        } else if(i != 0 && somu[i] == 1) {
            printf(" * %d", coso[i]);
        }
    }
    int phin = N;
    for(int i = 0; i < j; i++) {
        phin = phin * (coso[i] - 1) / coso[i];
    }
    printf("\n--> phi(%d) = %d", N, phin);
}

//------------------------------Tinh Phi end -----------------------------------

//------------------------------Tinh Jacobi-------------------------------------

int TinhJacobi(int a, int b, int dau, int vitri) {
    printf("\n");
    for(int i = 0; i < vitri; i++) {
        printf("    ");
    }
    if(dau < 0) {
        printf("-");
    }
    printf("(%d/%d)", a, b);
    if(a == 1) {
        printf("  --> %d", 1 * dau);
        return 1 * dau;
    } else if(a == 2) {
        if(b % 8 == 1 || b % 8 == 7) {
            printf("  --> %d", 1 * dau);
            return 1 * dau;
        } else if(b % 8 == 3 || b % 8 == 5) {
            printf("  --> %d", -1 * dau);
            return -1 * dau;
        }
    } else if(a % 2 == 1 && b % 2 == 1 && a < b) {
        if(a % 4 == 3 && b % 4 == 3) {
            int tmp = a;
            a = b;
            b = tmp;
            TinhJacobi(a, b, -dau, vitri);
        } else {
            int tmp = a;
            a = b;
            b = tmp;
            TinhJacobi(a, b, dau, vitri);
        }
    } else if(a % 2 == 1 && b % 2 == 1 && a > b) {
        a = a % b;
        TinhJacobi(a, b, dau, vitri);
    } else if(b % 2 == 1 && a % 2 == 0 && a < b) {
        int A = a;
        int dem, coso[20], somu[20], j = 0;
        //
        for(int i = 2; i <= A; i++){
            dem = 0;
            while(A % i == 0){
                ++dem;
                A /= i;
            }
            if(dem){
                coso[j]=i;
                somu[j]=dem;
                j++;
            }
        }
        vitri++;
        int result = 1;
        for(int i = 0; i < j; i++) {
            for(int k = 0; k < somu[i]; k++) {
                printf("\n");
                for(int i = 0; i < vitri; i++) {
                    printf("    ");
                }
                printf("----------------------------");
                result *= TinhJacobi(coso[i], b, 1, vitri);
            }
        }
        printf("\n");
        for(int i = 0; i < vitri - 1; i++) {
            printf("    ");
        }
        printf("--> ");
        if(dau < 0) {
            printf("-");
        }
        printf("(%d/%d) = %d", a, b, result * dau);
        printf("\n");
        for(int i = 0; i < vitri - 1; i++) {
            printf("    ");
        }
        printf("----------------------------");
        //
        return result * dau;
    } else {
        return 0;
    }
}

void handleTinhJacobi() {
    printf("---------------Encode(Ma hoa Affine)---------------\n");
    printf("Tinh Jacobi (a/b)\n");
    int a, b;
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("\n-->");
    int result = TinhJacobi(a, b, 1, 1);
    printf("\n--> KQ: %d", result);
}

//------------------------------Tinh Jacobi end---------------------------------

//----------------------------Tinh Can Bac 2------------------------------------

void handleTinhCanBac2TT4() {
    printf("---------------Tinh can bac 2 theo tt4---------------\n");
    printf("--> Tinh can bac 2 cua a mod p (p la SNT le)\n");
    int a, p, b, s, t, aNghichDao, c = 0, r = 0;
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("\nNhap p: ");
    scanf("%d", &p);
    while(isSNTLe(p) != 1) {
        printf("Thuat toan 1 yeu cau p la SNT le");
        printf("\nNhap lai p: ");
        scanf("%d", &p);
    }
    int res = TinhJacobiKhongHienThi(a, p, 1);
    printf("\n(a/p) = (%d/%d) = %d", a, p, res);
    if(res == -1 || res == 0) {
        printf("\n--> Khong co can bac 2");
        return;
    }

    for(int i = 1; i < p; i++) {
        if(TinhJacobiKhongHienThi(i, p, 1) == -1) {
            b = i;
            break;
        }
    }
    printf("\n\nChon b = %d vi (b/p) = (%d/%d) = -1\n", b, b, p);
    t = p - 1, s = 0;
    while(t % 2 == 0){
        s++;
        t = t / 2;
    }
    printf("\np - 1 = (2 ^ s) * t = (2 ^ %d) * %d", s, t);
    printf("\n->s = %d", s);
    printf("\n->t = %d", t);
    aNghichDao = euclideMoRongKhongHienThi(a, p);
    if(aNghichDao == -1) {
        printf("\n\n--> Khong co nghich dao cua a mod p");
        return;
    }
    printf("\n\na ^ -1 mod p = %d\n", aNghichDao);
    c = nhanBinhPhuongCoLapKhongHienThi(b, t, p);
    printf("\nc = b ^ t mod p = %d ^ %d mod %d = %d", b, t, p, c);
    r = nhanBinhPhuongCoLapKhongHienThi(a, ((t + 1) / 2), p);
    printf("\nr = a ^ ((t + 1) / 2) mod p = %d ^ %d mod %d = %d\n", a, ((t + 1) / 2), p, r);
    for(int i = 1; i < s; i++) {
        printf("\nVoi i = %d: ", i);
        int d = nhanBinhPhuongCoLapKhongHienThi(r * r * aNghichDao, (int)pow(2, s - i - 1), p);
        printf("\nd = (r ^ 2 * a ^ -1) ^ (2 ^ (s - i - 1)) mod p = %d ^ %d mod %d = %d", r * r * aNghichDao, (int)pow(2, s - i - 1), p, d);
        if(d == p - 1) {
            printf("\nd = -1 mod p");
            printf("\nr = r*c mod p = %d * %d mod %d = %d", r, c, p, (r * c) % p );
            r = (r * c) % p;
        }
        printf("\nc = c^2 mod p = %d^2 mod %d = %d\n", c, p, (c * c) % p);
        c = (c * c) % p;
    }

    printf("\n\n--> KQ: (%d, %d) la can bac 2 cua %d mod %d\n", r, p - r, a, p);

    return;
}

void handleTinhCanBac2TT3() {
    printf("---------------Tinh can bac 2 theo tt3---------------\n");
    printf("--> Tinh can bac 2 cua c mod n (n = p * q; p = q = 3 mod 4)\n");
    int a, b, c, n, p, q;
    printf("\nNhap c: ");
    scanf("%d", &c);
    printf("\nNhap p: ");
    scanf("%d", &p);
    while(p % 4 != 3 && isSNTLe(p) == 1 ) {
        printf("TT3 yeu cau p = 3 mod 4 va p la SNT");
        printf("\nNhap lai p: ");
        scanf("%d", &p);
    }
    printf("\nNhap q: ");
    scanf("%d", &q);
    while(q % 4 != 3 && isSNTLe(q) == 1 ) {
        printf("TT3 yeu cau q = 3 mod 4 va q la SNT");
        printf("\nNhap lai q: ");
        scanf("%d", &q);
    }

    n = p * q;
    printf("\nn = p * q = %d", n);
    //
    int x2 = 1, x1 = 0, y2 = 0, y1 = 1, a1 = p, b1 = q;
    int q1, r1, x, y, d;
    while(b1 > 0){
        q1 = a1 / b1;
        r1 = a1 - q1 * b1;
        x = x2 - q1 * x1;
        y = y2 - q1 * y1;
        //
        a1 = b1;
        b1 = r1;
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    a = x2;
    b = y2;
    //
    printf("\nCo ap + bq = 1");
    printf("\n-->a = %d;  b = %d\n", a, b);
    int r = nhanBinhPhuongCoLapKhongHienThi(c, ((p + 1) / 4), p);
    printf("\nr = c ^ ((p + 1) / 4) mod p = %d ^ %d mod %d = %d", c, ((p + 1) / 4), p, r);
    int s = nhanBinhPhuongCoLapKhongHienThi(c, ((q + 1) / 4), q);
    printf("\ns = c ^ ((q + 1) / 4) mod q = %d ^ %d mod %d = %d", c, ((q + 1) / 4), q, s);
    int resx = (a * p * s + b * q * r) % n;
    if(resx < 0) {
        resx = resx + n;
    }
    printf("\nx = (aps + bqr) mod n = %d", resx);
    int resy = (a * p * s - b * q * r) % n;
    if(resy < 0) {
        resy = resy + n;
    }
    printf("\ny = (aps + bqr) mod n = %d", resy);
    printf("\n\n--> KQ: (%d, %d, %d, %d) la can bac 2 cua %d mod %d", resx, n - resx, resy, n - resy, c, n);
    return;
}

void handleTinhCanBac2TT2() {
    printf("---------------Tinh can bac 2 theo tt2---------------\n");
    printf("--> Tinh can bac 2 cua a mod p (p = 5 mod 8)\n");
    int a, p, r;
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("\nNhap p: ");
    scanf("%d", &p);
    while(p % 8 != 5) {
        printf("Thuat toan 2 yeu cau p = 5 mod 8");
        printf("\nNhap lai p: ");
        scanf("%d", &p);
    }
    int res = TinhJacobiKhongHienThi(a, p, 1);
    printf("\n(a/p) = (%d/%d) = %d", a, p, res);
    if(res == -1 || res == 0) {
        printf("\n--> Khong co can bac 2");
        return;
    }
    int d = nhanBinhPhuongCoLapKhongHienThi(a, ((p - 1) / 4), p);
    printf("\nd = a ^ ((p - 1) / 4) mod p = %d ^ %d mod %d = %d", a, ((p + 1) / 4), p, d);
    if(d == 1) {
        printf("\n\n-->d = 1\n");
        r = nhanBinhPhuongCoLapKhongHienThi(a, ((p + 3) / 8), p);
        printf("\nr = a ^ ((p + 3) / 8) mod p = %d ^ %d mod %d = %d", a, ((p + 3) / 8), p, r);
    } else if(d == p - 1) {
        printf("\n\n-->d = p - 1\n");
        r = (2 * a * nhanBinhPhuongCoLapKhongHienThi(4 * a, ((p - 5) / 8), p)) % p;
        printf("\nr = (2 * a) * (4 * a) ^ ((p + 3) / 8) mod p = %d * %d ^ %d mod %d = %d", 2 * a, 4 * a, ((p - 3) / 8), p, r);
    }
    printf("\n-r = p - r = %d - %d = %d", p, r, p - r);
    printf("\n\n--> KQ: (%d, %d) la can bac 2 cua %d mod %d", r, p - r, a, p);
    return;
}

void handleTinhCanBac2TT1() {
    printf("---------------Tinh can bac 2 theo tt1---------------\n");
    printf("--> Tinh can bac 2 cua a mod p (p = 3 mod 4)\n");
    int a, p;
    printf("\nNhap a: ");
    scanf("%d", &a);
    printf("\nNhap p: ");
    scanf("%d", &p);
    while(p % 4 != 3) {
        printf("Thuat toan 1 yeu cau p = 3 mod 4");
        printf("\nNhap lai p: ");
        scanf("%d", &p);
    }
    int res = TinhJacobiKhongHienThi(a, p, 1);
    printf("\n(a/p) = (%d/%d) = %d", a, p, res);
    if(res == -1 || res == 0) {
        printf("\n--> Khong co can bac 2");
        return;
    }
    int r = nhanBinhPhuongCoLapKhongHienThi(a, ((p + 1) / 4), p);
    printf("\nr = a ^ ((p + 1) / 4) mod p = %d ^ %d mod %d = %d", a, ((p + 1) / 4), p, r);
    printf("\n-r = p - r = %d - %d = %d", p, r, p - r);
    printf("\n\n--> KQ: (%d, %d) la can bac 2 cua %d mod %d", r, p - r, a, p);
    return;
}

void showMenuTinhCanBac2() {
    system("cls");
    printf(" ___________________________________________________\n");
    printf("|             Menu Tinh Can Bac 2                   |\n");
    printf("| 1. Thuat toan 1 (p = 3 mod 4)                     |\n");
    printf("| 2. Thuat toan 2 (p = 5 mod 8)                     |\n");
    printf("| 3. Thuat toan 3 (n = p * q; p = q = 3 mod 4)      |\n");
    printf("| 4. Thuat toan 4 (p la SNT le)                     |\n");
    printf("| 0. Back                                           |\n");
    printf("|___________________________________________________|\n");
}

void mainMenuTinhCanBac2() {
    int select = -1;
    while(select != 0) {
        showMenuTinhCanBac2();
        printf("\n--> Enter your select: ");
        scanf("%d", &select);
        switch(select) {
            case 0:
                break;
            case 1:
                system("cls");
                handleTinhCanBac2TT1();
                printf("\nPress any key to go back!!");
                getch();
                break;
            case 2:
                system("cls");
                handleTinhCanBac2TT2();
                printf("\nPress any key to go back!!");
                getch();
                break;
            case 3:
                system("cls");
                handleTinhCanBac2TT3();
                printf("\nPress any key to go back!!");
                getch();
                break;
            case 4:
                system("cls");
                handleTinhCanBac2TT4();
                printf("\nPress any key to go back!!");
                getch();
                break;
            default:
                system("cls");
                printf("Please enter your correct choice!");
                printf("\nPress any key to go back!!");
                getch();
        }
    }
}

//----------------------------Tinh Can Bac 2 End--------------------------------

//----------------------------He Mat RSA ---------------------------------------

void handleHeMatRSA(int select) {
    printf("---------------He Mat RSA---------------\n");
    int p, q, e, n, phin;
    printf("\nNhap p: ");
    scanf("%d", &p);
    while(isSNTLe(p) != 1) {
        printf("Yeu cau nhap p la SNT");
        printf("\nNhap lai p: ");
        scanf("%d", &p);
    }
    printf("Nhap q: ");
    scanf("%d", &q);
    while(isSNTLe(q) != 1) {
        printf("Yeu cau nhap q la SNT");
        printf("\nNhap lai q: ");
        scanf("%d", &q);
    }
    n = p * q;
    printf("\nn = p * q = %d * %d = %d", p, q, n);
    phin = (p - 1) * (q - 1);
    printf("\nphi(n) = (p - 1) * (q - 1) = %d * %d = %d", p - 1, q - 1, phin);
    printf("\nNhap e: ");
    scanf("%d", &e);
    while(gcd(e, phin) != 1) {
        printf("Yeu cau nhap e sao cho gcd(e, phi(n)) = 1");
        printf("\nNhap lai e: ");
        scanf("%d", &e);
    }
    int d = euclideMoRongKhongHienThi(e, phin);
    printf("d = e ^ -1 mod phi(n) = %d ^ -1 mod %d = %d\n", e, phin, d);
    if(select == 1) {
        printf("\n-----Ma Hoa-----\n");
        int x;
        printf("\nNhap ban ro: ");
        scanf("%d", &x);
        int y = nhanBinhPhuongCoLapKhongHienThi(x, e, n);
        printf("\n--> Ban ma thu duoc: y = x ^ e mod n = %d ^ %d mod %d = %d\n", x, e, n, y);
    } else if(select == 2) {
        printf("\n-----Giai Ma-----\n");
        int y;
        printf("\nNhap ban ma: ");
        scanf("%d", &y);
        int x = nhanBinhPhuongCoLapKhongHienThi(y, d, n);
        printf("\n--> Ban ro thu duoc: x = y ^ d mod n = %d ^ %d mod %d = %d\n", y, d, n, x);
    }

}

//----------------------------He Mat RSA End------------------------------------

//----------------------------Thuat toan buoc nho buoc lon----------------------

void handleBuocNhoBuocLon() {
    printf("-----------------Buoc nho buoc lon-----------------\n");
    int a, b, n, phin, m;
    printf("\nTinh loga(b) tren Z(n) (Yeu cau a la phan tu sinh cua Z(n))\n\n");
    printf("Nhap a: ");
    scanf("%d", &a);
    printf("Nhap b: ");
    scanf("%d", &b);
    printf("Nhap n: ");
    scanf("%d", &n);
    phin = handleTinhPhiKhongHienThi(n);
    printf("\nphi(n) = phi(%d) = %d", n, phin);
    m = ceil(sqrt(phin));
    printf("\nm = %d\n", m);
    int bang1[m], bang2[m];
    //
    printf(" ________________________");
    for(int i = 0; i < m; i++) {
        printf("________");
    }
    printf("\n|         j              |");
    for(int i = 0; i < m; i++) {
        printf("%5d  |", i);
    }
    printf("\n| %3d ^ j mod %3d        |", a, n);
    for(int i = 0; i < m; i++) {
        int tmp1 = nhanBinhPhuongCoLapKhongHienThi(a, i, n);
        bang1[i] = tmp1;
        printf("%5d  |", tmp1);
    }
    printf("\n|________________________|");
    for(int i = 0; i < m; i++) {
        printf("_______|");
    }
    //
    int aND = euclideMoRongKhongHienThi(a, n);
    int aMuTruM = nhanBinhPhuongCoLapKhongHienThi(aND, m, n);
    printf("\na ^ (-m) mod n = %d\n", aMuTruM);
    printf(" ________________________");
    for(int i = 0; i < m; i++) {
        printf("________");
    }
    printf("\n|         i              |");
    for(int i = 0; i < m; i++) {
        printf("%5d  |", i);
    }
    printf("\n| %3d * %3d ^ j mod %3d  |", b, aMuTruM, n);
    for(int i = 0; i < m; i++) {
        int tmp1 = nhanBinhPhuongCoLapKhongHienThi(aMuTruM, i, n);
        int tmp2 = (b * tmp1) % n;
        bang2[i] = tmp2;
        printf("%5d  |", tmp2);
    }
    printf("\n|________________________|");
    for(int i = 0; i < m; i++) {
        printf("_______|");
    }

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < m; i++) {
            if(bang1[j] == bang2[i]) {
                printf("\n\n--> log%d(%d) = mi + j = %d * %d + %d = %d\n", a, b, m, i, j, m * i + j);
                break;
            }
        }
    }
    return;
}

//----------------------------Thuat toan buoc nho buoc lon End------------------

//----------------------------Phan tu sinh--------------------------------------

void showMenuPtuSinh() {
    system("cls");
    printf(" ___________________________________________________\n");
    printf("|                       Menu                        |\n");
    printf("| 1. Kiem tra phan tu va cap trong nhom nhan        |\n");
    printf("| 2. Tim tat ca phan tu sinh                        |\n");
    printf("| 0. Back                                           |\n");
    printf("|___________________________________________________|\n");
}

int kiemTraPtuTrongNhomNhan(int a, int n, int phin) {
    if(gcd(a, n) != 1) {
        return -1;
    }
    for(int i = 1;i <= phin; i++) {
        if(phin % i == 0) {
            int tmp = nhanBinhPhuongCoLapKhongHienThi(a, i, n);
            if(tmp == 1) {
                if(i == phin) {
                    return 0;
                }
                return i;
            }
        }
    }
}

void handleKtraPtuVaCap() {
    printf("---------------Kiem tra phan tu va cap trong nhom nhan Z(n)---------------\n");
    int n, phin, a;
    printf("\nNhap n (Z(n)): ");
    scanf("%d", &n);
    printf("Nhap a(Phan tu can kiem tra): ");
    scanf("%d", &a);
    phin = handleTinhPhiKhongHienThi(n);
    int res = kiemTraPtuTrongNhomNhan(a, n, phin);
    if(res == -1) {
        printf("\n--> %d khong thuoc nhom nhan Z(%d)", a, n);
    } else if(res == 0) {
        printf("\n--> %d thuoc nhom nhan Z(%d)", a, n);
        printf("\n--> Cap = %d", phin);
        printf("\n--> Vi Cap = phin = %d --> %d la phan tu sinh", phin, a);
    } else {
        printf("\n--> %d thuoc nhom nhan Z(%d)", a, n);
        printf("\n--> Cap = %d", res);
        printf("\n--> Vi Cap != phin --> %d khong phai la phan tu sinh", a);
    }
}

void handleFindAllPtuSinh() {
    printf("---------------Tim tat ca phan tu sinh trong nhom nhan Z(n)---------------\n");
    int n, phin, count = 0;
    printf("\nNhap n (Z(n)): ");
    scanf("%d", &n);
    phin = handleTinhPhiKhongHienThi(n);
    printf("\n--> Cac phan tu sinh trong Z(%d) la: ", n);
    for(int i = 2; i < n; i++) {
        if(kiemTraPtuTrongNhomNhan(i, n, phin) == 0) {
            printf("%4d,", i);
            count++;
        }
    }
    printf("\n--> Tong phan tu sinh trong Z(%d) la: %d", n, count);
}

void handleMenuPtuSinh() {
    int select = -1;
    while(select != 0) {
        showMenuPtuSinh();
        printf("\n--> Enter your select: ");
        scanf("%d", &select);
        switch(select) {
            case 0:
                break;
            case 1:
                system("cls");
                handleKtraPtuVaCap();
                printf("\nPress any key to go back!!");
                getch();
                break;
            case 2:
                system("cls");
                handleFindAllPtuSinh();
                printf("\nPress any key to go back!!");
                getch();
                break;
            default:
                system("cls");
                printf("Please enter your correct choice!");
                printf("\nPress any key to go back!!");
                getch();
        }
    }
}

//----------------------------Phan tu sinh end----------------------------------

//----------------------------Giai hpt dong du----------------------------------

void handleGiaiHPTDongDu() {
    printf("---------------Giai hpt dong du---------------\n");
    printf("Dang phuong trinh: b * x = a mod n");
    int count, tmp = 1, tmp1 = 0, x;
    printf("\nNhap so phuong trinh: ");
    scanf("%d", &count);
    int a[count], b[count], n[count], N[count], M[count];
    for(int i = 0; i < count; i++) {
        printf("\nNhap b[%d]: ", i + 1);
        scanf("%d", &b[i]);
        printf("Nhap a[%d]: ", i + 1);
        scanf("%d", &a[i]);
        printf("Nhap n[%d]: ", i + 1);
        scanf("%d", &n[i]);
    }
    for(int i = 0; i < count; i++) {
        if(b[i] != 1) {
            int tmpb = euclideMoRongKhongHienThi(b[i], n[i]);
            a[i] = (a[i] * tmp) % n[i];
        }
    }
    for(int i = 0; i < count; i++) {
        tmp *= n[i];
    }
    for(int i = 0; i < count; i++) {
        N[i] = tmp / n[i];
        M[i] = euclideMoRongKhongHienThi(N[i], n[i]);
    }
    for(int i = 0; i < count; i++) {
        int tmp2 = a[i] * N[i] * M[i];
        tmp1 += tmp2;
    }
    x = tmp1 % tmp;
    printf("\n--> x = %d", x);
}

//----------------------------Giai hpt dong du end------------------------------

//------------------------------------------------------------------------------

void showMenu() {
    system("cls");
    printf(" ____________________________________________________\n");
    printf("|                        Menu                        |\n");
    printf("|  1. Affine                                         |\n");
    printf("|  2. Hill                                           |\n");
    printf("|  3. ShifCipher                                     |\n");
    printf("|  4. Vigenere                                       |\n");
    printf("|  5. Nhan binh phuong co lap                        |\n");
    printf("|  6. Euclide mo rong                                |\n");
    printf("|  7. Tinh phi                                       |\n");
    printf("|  8. Tinh Jacobi                                    |\n");
    printf("|  9. Tinh Can bac 2                                 |\n");
    printf("| 10. He mat RSA                                     |\n");
    printf("| 11. Thuat toan buoc lon buoc nho                   |\n");
    printf("| 12. Phan tu sinh                                   |\n");
    printf("| 13. Giai he phuong trinh dong du                   |\n");
    printf("|  0. Back                                           |\n");
    printf("|____________________________________________________|\n");
}

void showMenuAffine() {
    system("cls");
    printf(" ___________________________________________________\n");
    printf("|                       Menu                        |\n");
    printf("| 1. Encode(Ma hoa)                                 |\n");
    printf("| 2. Decode(Giai ma)                                |\n");
    printf("| 0. Back                                           |\n");
    printf("|___________________________________________________|\n");
}

void mainMenuEncodeAndDecode(int algorithm) {
    int select = -1;
    while(select != 0) {
        showMenuAffine();
        printf("\n--> Enter your select: ");
        scanf("%d", &select);
        switch(select) {
            case 0:
                break;
            case 1:
                system("cls");
                if(algorithm == 1){
                    handleEncodeAffine();
                } else if(algorithm == 2) {
                    handleEncodeHill();
                } else if(algorithm == 3) {
                    handleEncodeShiftCipher();
                } else if(algorithm == 4) {
                    handleEncodeVigenere();
                } else if(algorithm == 10) {
                    handleHeMatRSA(1);
                }
                printf("\nPress any key to go back!!");
                getch();
                break;
            case 2:
                system("cls");
                if(algorithm == 1){
                    handleDecodeAffine();
                } else if(algorithm == 2) {
                    handleDecodeHill();
                } else if(algorithm == 3) {
                    handleDecodeShiftCipher();
                } else if(algorithm == 4) {
                    handleDecodeVigenere();
                } else if(algorithm == 10) {
                    handleHeMatRSA(2);
                }
                printf("\nPress any key to go back!!");
                getch();
                break;
            default:
                system("cls");
                printf("Please enter your correct choice!");
                printf("\nPress any key to go back!!");
                getch();
        }
    }
}

void mainMenu() {
    int select = -1;
    while(1) {
        showMenu();
        printf("\n--> Enter your select: ");
        scanf("%d", &select);
        switch(select) {
            case 0:
                system("cls");
                printf("Exited the program!!");
                exit(0);
            case 1:
                system("cls");
                mainMenuEncodeAndDecode(1);
                break;
            case 2:
                system("cls");
                mainMenuEncodeAndDecode(2);
                break;
            case 3:
                system("cls");
                mainMenuEncodeAndDecode(3);
                break;
            case 4:
                system("cls");
                mainMenuEncodeAndDecode(4);
                break;
            case 5:
                system("cls");
                handleNhanBinhPhuongCoLap();
                printf("\n\nPress any key to go back!!");
                getch();
                break;
            case 6:
                system("cls");
                handleEuclideMoRong();
                printf("\n\nPress any key to go back!!");
                getch();
                break;
            case 7:
                system("cls");
                handleTinhPhi();
                printf("\n\nPress any key to go back!!");
                getch();
                break;
            case 8:
                system("cls");
                handleTinhJacobi();
                printf("\n\nPress any key to go back!!");
                getch();
                break;
            case 9:
                system("cls");
                mainMenuTinhCanBac2();
                break;
            case 10:
                system("cls");
                mainMenuEncodeAndDecode(10);
                break;
            case 11:
                system("cls");
                handleBuocNhoBuocLon();
                printf("\n\nPress any key to go back!!");
                getch();
                break;
            case 12:
                system("cls");
                handleMenuPtuSinh();
                break;
            case 13:
                system("cls");
                handleGiaiHPTDongDu();
                printf("\n\nPress any key to go back!!");
                getch();
                break;
            default:
                system("cls");
                printf("Please enter your correct choice!");
                printf("\nPress any key to go back!!");
                getch();
        }
    }
}

int main() {
    mainMenu();
    return 0;
}
