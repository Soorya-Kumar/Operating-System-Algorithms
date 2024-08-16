#include <bits/stdc++.h>
using namespace std;

void fcfs(vector<int> &arr, int n, int head){

    int seek  = 0;
    for(int i=0;i<n;i++){
        seek += abs(head - arr[i]);
        head = arr[i];
    }
    cout << seek;
    //same order as array
}


int main(){

    vector<int> arr = { 176, 79, 34, 60, 92, 11, 41, 114 };
    //vector<int> arr = {82,170,43,140,24,16,190};
    int n = arr.size();
    int head = 10;
    fcfs(arr, n, head);

    return 0;
}