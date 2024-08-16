#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    n = 5; // Number of processes
    m = 3; // Number of resources
    int alloc[5][3] = { { 0, 1, 0 }, // P0 // Allocation Matrix
                        { 2, 0, 0 }, // P1
                        { 3, 0, 2 }, // P2
                        { 2, 1, 1 }, // P3
                        { 0, 0, 2 } }; // P4
    
    int max[5][3] = { { 7, 5, 3 }, // P0 // MAX Matrix
                    { 3, 2, 2 }, // P1
                    { 9, 0, 2 }, // P2
                    { 2, 2, 2 }, // P3
                    { 4, 3, 3 } }; // P4
    
    int avail[3] = { 3, 3, 2 }; // Available Resources

    vector<int> ans;
    vector<int> com(n,0);

    int need[n][m] = {0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(int k=0; k<5;k++){
        for(int i=0;i<n;i++){

            if(com[i] == 0){
                int flag = 0;
                for(int j=0;j<m;j++){
                    if(need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
            
                if(flag == 0){
                    ans.push_back(i);
                    com[i] = 1;
                    for(int s=0;s<m;s++){
                        avail[s] += alloc[i][s];
                    }
                }
            }            
        }
    }


    int flag = 0;
    for(int i=0;i<n;i++){
        if(com[i] == 0){
            flag = 1;
            break;
        }
    }

    if(flag == 1) cout << "NO SAFE SEUQ";
    else{
        cout << "SAFE SEQ AVIALABLE" <<endl;
        for(auto it: ans) cout << it << " ";
        cout << endl;
    }


    return 0;
}