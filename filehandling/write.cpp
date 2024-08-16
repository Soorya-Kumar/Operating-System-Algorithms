#include <bits/stdc++.h>
using namespace std;

int main(){

    ofstream outputfile("data.txt");

    if( outputfile.is_open() == false){
        cout << " FILE NOT FOUND ERROR WHILE FETCING";
        return 1;
    }

    string line = "ELLEO SEFSDF\nsdflksdl\nasdlklsdf\nss\nsSSSdf";
    outputfile << line << endl;
    outputfile.close();
    return 0;

}   