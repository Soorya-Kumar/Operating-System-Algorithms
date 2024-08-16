#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <cstdlib> // For rand()

using namespace std;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t barber_ready = PTHREAD_COND_INITIALIZER;

int numchairs = 5;
int numwaiting = 0;
int numcustomers = 0;

void* barberfun(void* arg) {
    cout << "Barber thread started" << endl;
    
    while (1) {
        pthread_mutex_lock(&m);

        if (numwaiting == 0) {
            cout << "Barber is sleeping" << endl;
            pthread_cond_wait(&barber_ready, &m);
        }

        cout << "Barber is cutting hair" << endl;
        numwaiting--;
        numcustomers--;

        pthread_mutex_unlock(&m);

        sleep(2); // Simulate hair cutting time
    }

    return NULL;
}

void* customfun(void* arg) {
    int cid = *((int*)arg);

    pthread_mutex_lock(&m);

    if (numwaiting == numchairs) {
        cout << "Customer " << cid << " cannot find a chair, leaving" << endl;
        pthread_mutex_unlock(&m);
        pthread_exit(NULL);
    }

    numcustomers++;
    numwaiting++;
    cout << "Customer " << cid << " arrived and is waiting" << endl;
    pthread_cond_signal(&barber_ready); // Signal barber that a customer is waiting

    pthread_mutex_unlock(&m);

    sleep(3); // Simulate hair cutting time

    cout << "Hair cut done for Customer " << cid << endl;

    pthread_exit(NULL);
}

int main() {
    pthread_t barber_thread;
    pthread_t customer_threads[7]; // Array to hold customer threads
    int customer_ids[] = {1, 2, 3, 4, 5, 6, 7};

    srand(time(NULL)); // Seed for random number generation

    pthread_create(&barber_thread, NULL, barberfun, NULL);

    for (int i = 0; i < 7; i++) {
        pthread_create(&customer_threads[i], NULL, customfun, (void*)&customer_ids[i]);
        sleep(rand() % 3); // Randomize customer arrival times
    }

    pthread_join(barber_thread, NULL);
    for (int i = 0; i < 7; i++) {
        pthread_join(customer_threads[i], NULL);
    }

    return 0;
}
