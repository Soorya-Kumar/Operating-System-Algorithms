#include <bits/stdc++.h>
using namespace std;

void scan(vector<int> &arr, int n, int head){

    vector<int> R;
    vector<int> L;
    vector<int> ans;
    int seek = 0; 

    for(int i=0;i<n;i++){
        if(arr[i] >= head) R.push_back(arr[i]);
        else L.push_back(arr[i]);
    }

    R.push_back(199);
    R.push_back(50);

    sort(R.begin(), R.end());
    sort(L.begin(), L.end());

    for(int i=0;i<R.size();i++){
        ans.push_back(R[i]);
        seek += abs(head - R[i]);
        head = R[i];
    }
    
    for(int i=L.size() - 1;i>=0;i--){
        ans.push_back(L[i]);
        seek += abs(head - L[i]);
        head = L[i];
    }

    cout << seek << endl;
    for(auto it: ans) cout << it << " ";
    return ;
}


int main(){
    
    vector<int> arr = { 176, 79, 34, 60, 92, 11, 41, 114 };
    //vector<int> arr = {82,170,43,140,24,16,190};
    int n = arr.size();
    int head = 10;
    scan(arr, n, head);

    return 0;
}
