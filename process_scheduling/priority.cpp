#include<bits/stdc++.h>
using namespace std;

struct process{
    int at; 
    int bt; 
    int pt;
    int pid;
};

bool cmp(process a, process b){
    if(a.pt == b.pt)
    return (a.at <b.at);
    return (a.pt < b.pt);
}

void pfifo(vector<process> &arr, int n){

    int clock = 0;
    clock = arr[0].at;
    vector<int> wt(n);
    vector<int> tat(n);
    vector<int> ct(n);

    wt[0] = 0;
    ct[0] = clock + arr[0].bt;
    tat[0] = ct[0] - arr[0].at;


    double avgwt = wt[0];
    double avgtat = tat[0];
    clock += arr[0].bt; 

    for(int i=1;i<n;i++){
        wt[i] =  clock - arr[i].at;
        tat[i] = arr[i].bt + wt[i];
        ct[i] = arr[i].at + tat[i]; 
        avgwt += wt[i];
        avgtat += tat[i];
        clock = ct[i];
    }

    cout<<  "pid"<<"\t\t"<< "AT"<<"\t\t"    <<"BT"<<"\t\t"<<    "WT"<<"\t\t"<<  "CT"<<"\t\t"<<  "TAT"<<endl;
    for(int i=0;i<n;i++) 
    {         
        cout<<  arr[i].pid<<"\t\t"<<  arr[i].at <<"\t\t"<<  arr[i].bt<<"\t\t"<<  wt[i]<<"\t\t"<< ct[i]<<"\t\t"<< tat[i]<<endl;
    } 
    
    cout<<"Average waiting time is : "; 
    cout<<avgwt/(float)n<<endl; 
    cout<<"average turnaround time : "; 
    cout<<avgtat/(float)n<<endl; 
  
} 

int main(){

    int n = 5;
    int at[] = {0 ,1 ,3 ,2 ,4};
    int bt[] = {3 ,6 ,1 ,2 ,4};
    int pt[] = {3 ,4 ,9 ,7 ,8};

    vector<process> arr(n);

    for(int i=0;i<n;i++){   
        arr[i].at= at[i];
        arr[i].bt= bt[i];
        arr[i].pt= pt[i];
        arr[i].pid= i+1;
    }

    sort(arr.begin(), arr.end(),cmp);
    pfifo(arr,n);
    return 0;
}
