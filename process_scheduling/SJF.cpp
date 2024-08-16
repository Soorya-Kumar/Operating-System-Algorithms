#include<bits/stdc++.h>
using namespace std;


struct process{
    int at;
    int bt;
    int rt;
};


bool cmp(process a, process b){
    return a.at < b.at;
}

int main(){
    int n = 5;
  
    vector<int> at = {0 ,2 ,2 ,2 ,4}; 
    int bt[] = {3 ,6 ,1 ,2 ,4};
    int rt[] = {3 ,6 ,1 ,2 ,4};

    vector<process> arr(n);
    for(int i=0;i<n;i++){
        arr[i].at = at[i]; 
        arr[i].bt = bt[i];
        arr[i].rt = rt[i];
    }

    sort(arr.begin(), arr.end(), cmp);

    /* for(int i=0;i<n;i++){
        cout << arr[i].at << " "<< arr[i].bt << " " << arr[i].rt << endl;     
    }
    */

    vector<int> ct(n);
    vector<int> tat(n);
    vector<int> wt(n);

    int completed = 0;
    int clock = 0;
    
    int shortest = -1;
    

    while(completed < n){   

        int mini = INT_MAX;
        bool check = false;
        for(int i=0;i<n;i++){
            if(arr[i].at <= clock && arr[i].bt < mini && arr[i].bt > 0){
                shortest = i;
                mini = arr[i].bt;
                check = true;  
            }
        }

        if(check == false){
            for(int i=0;i<n;i++){
                if(arr[i].at > clock && arr[i].bt != 0){
                    clock = arr[i].at;
                    break;
                }
            }
            continue;
        }

        clock += arr[shortest].bt;
        arr[shortest].bt = 0;

        if(arr[shortest].bt == 0 ){
            completed++;
            ct[shortest] = clock;
            wt[shortest] = clock - arr[shortest].rt - arr[shortest].at;
            tat[shortest] = clock - arr[shortest].at;
        } 

    }

    cout << "PID \t" << "AT \t" << "BT \t" << "CT \t" << "WT \t" << "TAT \t" << endl;

    for(int i=0;i<n;i++){
        cout << i+1 << "\t" << arr[i].at << "\t" << arr[i].rt << "\t" << ct[i] << "\t" << wt[i] << "\t"  << tat[i] <<endl;  
    }
    return 0;
}