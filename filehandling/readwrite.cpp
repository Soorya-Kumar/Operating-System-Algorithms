#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int n; 
    cout << "ENTER A NUMBER : ";
    cin >> n;

    ifstream inputfile("final.txt");
    ofstream outputfile("final.txt", ios::app);

    outputfile << n << endl;

    string line;
    while(getline(inputfile,line))
    cout << line << endl;

    outputfile << n+1 << endl;

    inputfile.clear(); 
    inputfile.seekg(0);
    string line1;
    while(getline(inputfile,line))
    cout << line1 << endl;

    inputfile.close();
    outputfile.close();
    return 0;
}