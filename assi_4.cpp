#include<iostream>
using namespace std;

int tiling(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return tiling(n - 1) + tiling(n - 2);
}


int main(){
    int n;

    cout << "Enter the value of n: ";
    cin >> n;

    if(n < 0){
        cout << "Invalid input!";
    }
    else{
        int ways = tiling(n);
        cout << "Number of ways to tile the 2 x " << n << " board: ";
        cout << ways << endl;
    }

    return 0;
}