// Shortest remaining time first with time slicing(time quant)

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n = 5;
    int at[] = {0 ,2 ,2 ,2 ,4}; 
    int bt[] = {3 ,6 ,1 ,2 ,4};
    int rt[] = {3 ,6 ,1 ,2 ,4};
    //int pt[] = {3 ,10 ,9 ,7 ,8};

    int completed_processes = 0;
    int quant = 2;

    vector<int> ct(n);
    vector<int> wt(n);
    vector<int> tat(n);

    float avgwt = 0;
    float avgtat = 0;
    
    int shortest;
    int clock = 0;
    bool check = false;
    int mini = INT_MAX;

    while(completed_processes < n){
         
        for(int i=0;i<n;i++){
            if(at[i] <= clock && rt[i] < mini && rt[i] > 0){
                shortest = i;
                mini = rt[i];
                check = true;
            }
        }

        if(check == false){
            clock++;
            continue;
        }

        if(rt[shortest] == quant){
            completed_processes ++;
            rt[shortest] -= quant;
            mini = INT_MAX;
            check = false;
            clock += quant;
            ct[shortest] = clock;
            wt[shortest] = ct[shortest] - at[shortest] -bt[shortest];
            tat[shortest] = ct[shortest] - at[shortest];
            avgwt += wt[shortest];
            avgtat += tat[shortest];
        }

        else if(rt[shortest] < quant){
            completed_processes ++; 
            rt[shortest] = 0;
            mini = INT_MAX;
            check = false;
            clock += rt[shortest];
            ct[shortest] = clock;
            wt[shortest] = ct[shortest] - at[shortest] -bt[shortest];
            tat[shortest] = ct[shortest] - at[shortest];
            avgwt += wt[shortest];
            avgtat += tat[shortest];
        }

        else{
            rt[shortest]-= quant;
            mini = rt[shortest];
            clock += quant;
        }
    }


    cout << "PID \t" << "AT \t" << "BT \t" << "CT \t" << "WT \t" << "TAT \t" << endl;

    for(int i=0;i<n;i++){
        cout << i+1 << "\t" << at[i] << "\t" << bt[i] << "\t" << ct[i] << "\t" << wt[i] << "\t"  << tat[i] <<endl;  
    }
    return 0;
}