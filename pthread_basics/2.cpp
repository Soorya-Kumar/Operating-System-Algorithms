#include<iostream>
#include<cstdlib>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

struct mat3{
    int m1[2][2];
    int m2[2][2];
    int m3[2][2];
};

void *fun( void *input){
    
    struct mat3* iomat;
    iomat = (struct mat3*) input;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            iomat->m3[i][j] = 0;
 
            for (int k = 0; k < 2; k++) {
                iomat->m3[i][j] += iomat->m1[i][k] * iomat->m2[k][j];
            }
            
        }
        
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t p1, p2;
    int r1, r2;
    
    struct mat3 *M = new mat3;
     
    M->m1[0][0] = 2;
    M->m1[0][1] = 3;
    M->m1[1][0] = 4;
    M->m1[1][1] = 5;

    M->m2[0][0] = 4;
    M->m2[0][1] = 3;
    M->m2[1][0] = 0;
    M->m2[1][1] = 0;

    r1 = pthread_create(&p1, NULL, fun, (void *)M); 
    pthread_join(p1, NULL);
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            
             cout << M->m3[i][j];
        }
    }
    cout << endl;
    
    return 0;
}