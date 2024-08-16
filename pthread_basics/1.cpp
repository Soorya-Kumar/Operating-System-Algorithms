#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

void *fun( void *param){
    int* n ;
    n = (int*) param;
    cout << "hello world" << n << endl;
    pthread_exit(NULL);
}

int main(){
    pthread_t p1, p2;
    int r1, r2;
    
    r1 = pthread_create(&p1, NULL, fun, (void *)3); 
    r2 = pthread_create(&p2, NULL, fun, (void *)4);
    
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    
    printf("Thread 1 returns: %d\n",r1);
    printf("Thread 2 returns: %d\n",r2);
    
    return 0;
}