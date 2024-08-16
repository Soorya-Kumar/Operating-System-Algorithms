#include <bits/stdc++.h>
using namespace std;

int fifo(vector<int> pg, int fn, int n){

    unordered_set<int> s;
    queue<int> q;

    int pagefault = 0;

    for(int i=0;i<n;i++){

        if(s.size() < fn){
            if(s.find(pg[i]) == s.end()){
                pagefault++;
                s.insert(pg[i]);
                q.push(pg[i]);
            }
        }

        else{
            if(s.find(pg[i]) == s.end()){
                pagefault++;
                int rem = q.front();
                q.pop();
                s.erase(rem);
                s.insert(pg[i]);
                q.push(pg[i]);
            }
        }
    }

    return pagefault;
}


int main(){
    vector<int> pg = {2,3,6,4,1,4,2,2,2,6,2,4,3}; 
    int n = pg.size(); 
    int fn = 4; 
    cout << fifo(pg, fn, n); 
    return 0; 
}