#include <bits/stdc++.h>
using namespace std;

int main(){

    int clock = 0;
    int n = 5;
    int at[] = {0 ,2 ,2 ,2 ,4}; //sort based on arrival time
    int bt[] = {3 ,6 ,1 ,2 ,4};
    int temp[] = {3 ,6 ,1 ,2 ,4};
    //int pt[] = {3 ,10 ,9 ,7 ,8};

    queue<int> q;
    int N = n;
    int quant = 2;
    float avgtat=0;
    float avgwt=0;

    vector<int> ct(n);
    vector<int> wt(n);
    vector<int> tat(n);

    int count = 0;
    clock += at[0];
    int max_index = 0;
    q.push(0);
    int i = q.front();

    while( N != 0 ){
        
        q.pop();
        if(temp[i] <= quant && temp[i] > 0){
            clock += temp[i];
            temp[i] = 0;
            count = 1;
        }

        else if (temp[i] > 0){
            clock += quant;
            temp[i] -= quant;
        }

        if(count == 1 && temp[i] == 0 ){
            N--;
            ct[i] = clock;
            wt[i] = clock - at[i] - bt[i];
            tat[i] = clock - at[i];
            avgtat += tat[i];
            avgwt += wt[i];
            count = 0;
        }

        for(int j=max_index+1;j<n;j++){
            if(clock >= at[j] && temp[j]>0){
                q.push(j);
                max_index = max(max_index, j);
            }
            else{
                break;
            }
        }

        if(temp[i] > 0)
        q.push(i);
    
        if(q.empty() && N != 0){
            for(int j=0;j<n;j++){
                if(temp[j] > 0){
                    clock = at[j];
                    q.push(j);
                    break;
                }
            }
        }

        if(!q.empty()) i = q.front();
        else continue;
    }

    cout << "PID \t" << "AT \t" << "BT \t" << "CT \t" << "WT \t" << "TAT \t" << endl;

    for(int i=0;i<n;i++){
        cout << i+1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t"  << tat[i] <<endl;  
    }

    return 0;   
}