#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
sem_t canWrite;

int n = 2;
int reader = 0;

void* writerfun(void *arg){
    sem_wait(&canWrite);
    pthread_mutex_lock(&m);
    cout << "writer got access" << endl;
    n += 2;
    cout << "new write value : " << n << endl;
    cout << endl;
    pthread_mutex_unlock(&m);
    sem_post(&canWrite);
    pthread_exit(NULL);
}

void* readerfun(void *arg){
    
    pthread_mutex_lock(&m);
    reader++;
    if(reader == 1) sem_wait(&canWrite);
    pthread_mutex_unlock(&m);
    
    cout << "Reader reading value : " << n << endl;
    cout << endl;
    
    pthread_mutex_lock(&m);
    reader--;
    if(reader == 0) sem_post(&canWrite);
    pthread_mutex_unlock(&m);
    
    pthread_exit(NULL);
}


int main(){
    pthread_t reader[10], writer[5];
    sem_init(&canWrite, 0, 1);
    
    for(int i=0;i<5;i++){
        pthread_create(&writer[i], NULL, writerfun ,NULL);
    }
    for(int i=0;i<10;i++){
        pthread_create(&reader[i], NULL, readerfun ,NULL);
        sleep(0.5);
    }
    
    for(int i=0;i<5;i++){
        pthread_join(writer[i], NULL);
    }
    for(int i=0;i<10;i++){
        pthread_join(reader[i], NULL);
    }
    
    sem_destroy(&canWrite);
    cout << "completed";
    return 0;
}