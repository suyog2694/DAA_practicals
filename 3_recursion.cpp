#include<iostream>
using namespace std;

int josephus(int n, int k){
    if(n == 1){
        return 0;
    }

    return (josephus(n - 1, k) + k) % n;
}


int main(){
    int n;
    int k;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the step count (k): ";
    cin >> k;

    if(n <= 0 || k <= 0){
        cout << "Invalid input!";
    }
    else{
        int survivor = josephus(n, k);

        cout << "Last element: " << survivor + 1 << endl;
    }

    return 0;
}