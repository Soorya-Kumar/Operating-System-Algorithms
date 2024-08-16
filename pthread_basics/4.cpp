#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

pthread_mutex_t odd = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t even = PTHREAD_MUTEX_INITIALIZER;

int counter_odd = 1;
int counter_even = 0;

void *oddfun(void *param){
    while (counter_odd <= 10) {
        pthread_mutex_lock(&odd);
        if (counter_odd <= 10) {
            cout << counter_odd << endl;
            counter_odd += 2;
        }
        pthread_mutex_unlock(&even);
    }
    pthread_exit(NULL);
}
    
void *evenfun(void *param){
    while (counter_even <= 10) {
        pthread_mutex_lock(&even);
        if (counter_even <= 10) {
            cout << counter_even << endl;
            counter_even += 2;
        }
        pthread_mutex_unlock(&odd);
    }
    pthread_exit(NULL);
}


int main(){
    
    pthread_t p[10];

    for(int i=0;i<10;i+=2){
        pthread_create(&p[i], NULL, oddfun, NULL);
        pthread_create(&p[i+1], NULL, evenfun, NULL);
    }
    
    for(int i=0;i<10;i++){
        pthread_join(p[i], NULL);
    }
    
    cout << endl << "EOF" << endl;
    return 0;
}