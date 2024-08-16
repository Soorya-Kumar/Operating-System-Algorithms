#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

void *fun(void *param){
    int* n ;
    n = (int*) param;
    
    for(int i=0;i<*n;i++){
        cout << "HELL O WORLD !!";    
    }
    cout << endl;
    pthread_exit(NULL);
}

int main(){
    
    pthread_t p[4];
    
    for(int i = 0; i < 4; i++){
        int *s =(int *)malloc(sizeof(int)) ;
        *s = i+1;
        int r = pthread_create(&p[i], NULL, fun, (void *)s);
        sleep(3); // if we remove sleep random order
    }
    
    // Join threads
    for(int i = 0; i < 4; i++){
        pthread_join(p[i], NULL); // Wait for each thread to finish
    }
    
    
    cout << endl << endl << "EOF" << endl;
    return 0;
}