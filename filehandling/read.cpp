#include <bits/stdc++.h>
using namespace std;

int main(){

    ifstream inputfile("sample.txt");

    if( inputfile.is_open() == false){
        cout << " FILE NOT FOUND ERROR WHILE FETCING";
        return 1;
    }

    string line;

    while( getline(inputfile, line)){
        cout << line << endl;
    }

    inputfile.close();
    return 0;

}