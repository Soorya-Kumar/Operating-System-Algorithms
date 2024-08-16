#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

using namespace std;

pthread_mutex_t mutex;
sem_t fullSlots;
sem_t emptySlots;
 
int produced = 0;
int consumed = 0;

void* producerfun(void *arg){
    
        for(int i=1;i<=5;i++){
            sem_wait(&emptySlots);
            pthread_mutex_lock(&mutex);
            produced++;
            cout << "Produced " << produced << endl;
            pthread_mutex_unlock(&mutex);
            sem_post(&fullSlots);
            sleep(3);
        }

    pthread_exit(NULL);
}

void* consumerfun(void *arg){
    
    while(consumed != 5){
        sem_wait(&fullSlots);
        pthread_mutex_lock(&mutex);
        consumed++;
        cout << "consumed " << consumed << endl;
        pthread_mutex_unlock(&mutex);
        sem_post(&emptySlots);
        sleep(5);
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t consumer, producer;
    int n = 5;
    
    
    sem_init(&fullSlots, 0, 0);
    sem_init(&emptySlots, 0, n);
    
    
    pthread_create(&producer, NULL, producerfun, NULL);
    pthread_create(&consumer, NULL, consumerfun, NULL);
    
    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    
    sem_destroy(&emptySlots);
    sem_destroy(&fullSlots);
    
    cout << "completed" << endl;
    return 0;
}