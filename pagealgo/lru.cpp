#include <bits/stdc++.h>
using namespace std;

int lru(vector<int> pg, int fn, int n){

    vector<pair<int, int>> farr;
    int pagefaults = 0;

    for(int i=0;i<n;i++){

        if(farr.size() < fn){
            int flag = 0;
            for(int j=0;j<farr.size();j++){
                if(pg[i] == farr[j].second){
                    flag = 1;
                    farr[j].first = i;
                }
            }

            if(flag == 0){
                farr.push_back({i,pg[i]});
                pagefaults++;
            }
        }


        else{
            int flag = 0;
            for(int j=0;j<farr.size();j++){
                if(pg[i] == farr[j].second){
                    flag = 1;
                    farr[j].first = i;
                }
            }

            if(flag == 0){
                int mini = INT_MAX;
                int min_index = -1;

                for(int j=0;j<farr.size();j++){
                    if(mini > farr[j].first){
                        mini = farr[j].first;
                        min_index = j;
                    }
                }
                    
                farr[min_index].first = i;
                farr[min_index].second = pg[i];
                pagefaults++;
            }
        }

    }

    return pagefaults;
}


int main() 
{ 
    vector<int> pages = {2,3,6,4,1,4,2,2,2,6,2,4,3}; 
    int n = pages.size(); 
    int fn = 4; 
    cout << lru(pages, fn, n); 
    return 0; 
} 