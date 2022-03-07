#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

sem_t bus, wheel, nonWheel;
pthread_mutex_t mutex;
char nonWheelArr[4] = {'_', '_', '_', '_'};
char wheelArr[6] = {'_', '_', '_', '_', '_', '_'};
int nonWheelCount = 0;
int wheelCount = 0;
int busCount = 0;

void show() {
    printf(" XeBus: [");
    for(int i = 0; i < 4; i++) {
        if(i != 3) printf("%c, ", nonWheelArr[i]);
        else printf("%c]", nonWheelArr[i]);
    }
    printf(" [");
    for(int i = 0; i < 6; i++) {
        if(i != 5) printf("%c, ", wheelArr[i]);
        else printf("%c]", wheelArr[i]);
    }
}

void showHangDoi() {
    printf("Hang doi: [%d, %d]", nonWheelCount, wheelCount);
}

void reset() {
    for(int i = 0; i < 4; i++) {
        nonWheelArr[i] = '_';
    }
    for(int i = 0; i < 6; i++) {
        wheelArr[i] = '_';
    }
}

void *getPassenger(void* arg) {
    sem_wait(&bus);
    reset();
    printf("\n===========Xe Bus thu %d===============\n\n", busCount + 1);
    for(int i = 0; i < 4; i++) {
        sem_wait(&nonWheel);
        pthread_mutex_lock(&mutex);
        nonWheelCount--;
        showHangDoi();
        nonWheelArr[i] = 'x';
        printf(" Dua 1 khach xe lan vao cho -> ");
        show();
        printf("\n");
        pthread_mutex_unlock(&mutex);
    }
    for(int i = 0; i < 6; i++) {
        sem_wait(&wheel);
        pthread_mutex_lock(&mutex);
        wheelCount--;
        showHangDoi();
        wheelArr[i] = 'x';
        printf(" Dua 1 khach binh thuong vao cho -> ");
        show();
        printf("\n");
        pthread_mutex_unlock(&mutex);
    }
    busCount++;
    sem_post(&bus);
    pthread_exit(NULL);
}

void *wheelPassenger(void* arg) {
    pthread_mutex_lock(&mutex);
    wheelCount++;
    showHangDoi();
    printf(" Khach binh thuong toi.");
    printf("\n");
    pthread_mutex_unlock(&mutex);
    sem_post(&wheel);
    pthread_exit(NULL);
}

void *nonWheelPassenger(void* arg) {
    pthread_mutex_lock(&mutex);
    nonWheelCount++;
    showHangDoi();
    printf(" Khach xe lan toi.");
    printf("\n");
    pthread_mutex_unlock(&mutex);
    sem_post(&nonWheel);
    pthread_exit(NULL);
}


int main(){
    int a = 2;
    int b = 4 * a;
    int c = 6 * a;
    pthread_t xebus[a], hanhKhachBinhThuong[b], hanhKhachXeLan[c];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&bus, 0, 1);
    sem_init(&wheel, 0, 0);
    sem_init(&nonWheel, 0, 0);
    for(int i = 0; i < a; i++) {
        pthread_create(&xebus[i], NULL, getPassenger, NULL);
    }
    for(int i = 0; i < b; i++) {
        pthread_create(&hanhKhachXeLan[i], NULL, nonWheelPassenger, NULL);
    }
    for(int i = 0; i < c; i++) {
        pthread_create(&hanhKhachBinhThuong[i], NULL, wheelPassenger, NULL);
    }

    for(int i = 0; i < a; i++) {
        pthread_join(xebus[i], NULL);
    }
    for(int i = 0; i < b; i++) {
        pthread_join(hanhKhachXeLan[i], NULL);
    }
    for(int i = 0; i < c; i++) {
        pthread_join(hanhKhachBinhThuong[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&bus);
    sem_destroy(&wheel);
    sem_destroy(&nonWheel);

    return 0;
}
