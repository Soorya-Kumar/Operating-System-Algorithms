#include <bits/stdc++.h>
using namespace std;

void sstf(vector<int> &arr, int n, int head){

    vector<int> vis(n, false);
    vector<int> ans;
    ans.push_back(50);  //head
    int seek = 0;
    
    for(int i= 0;i<n;i++){

        int mini = INT_MAX;
        int index = -1;
        for(int j=0;j<n;j++){
            if(vis[j] == false && abs(head - arr[j]) < mini){
                mini = abs(head - arr[j]);
                index = j;
            }
        }
        ans.push_back(arr[index]);
        seek += abs(head - arr[index]);
        head = arr[index];
        vis[index] = true;
    }

    cout << seek << endl;
    for(auto it: ans) cout << it << " " ;
    return ;
}


int main(){

    vector<int> arr = { 176, 79, 34, 60, 92, 11, 41, 114 };
    //vector<int> arr = {82,170,43,140,24,16,190};
    int n = arr.size();
    int head = 10;
    sstf(arr, n, head);

    return 0;
}