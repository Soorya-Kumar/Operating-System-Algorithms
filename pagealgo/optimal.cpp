#include <bits/stdc++.h>
using namespace std;

int predict(vector<int> pg, vector<int> farr, int n, int index){

    int res = 0;
    int farthest = index;

    for(int i= 0;i<farr.size();i++){
        int j;
        for(j=index;j<n;j++){

            if(pg[j] == farr[i]){
                if( j > farthest){
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        if(j == n) return i;
    }

    return res;
}

int optimal(vector<int> pg, int fn, int n){

    int pagefaults = 0;
    vector<int> farr;

    for(int i=0;i<n;i++){

        int flag = 0;
        for(int k=0;k<farr.size();k++){
            if(pg[i] == farr[k]){
                flag = 1;
            }
        }

        if(flag == 0){
            if(farr.size() < fn){
                pagefaults++;
                farr.push_back(pg[i]);
            }

            else{
                int select = predict(pg, farr, n, i+1);
                farr[select] = pg[i];
                pagefaults++;
            }
        }
    }

    return pagefaults;
}



int main(){
    vector<int> pg= {2,3,6,4,1,4,2,2,2,6,2,4,3};
    int n = pg.size();
    int fn = 4;
    int ans = optimal(pg, fn, n);
    cout << ans << endl;
    return 0;
}