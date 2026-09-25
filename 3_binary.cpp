#include<iostream>
using namespace std;

int main(){
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if(n <= 0){
        cout << "Invalid input!";
        return 0;
    }

    int power = 1;

    while(power * 2 <= n){
        power = power * 2;
    }

    int l = n - power;

    int survivor = 2 * l + 1;

    cout << "Step count (k) = 2" << endl;
    cout << "Last element: " << survivor << endl;

    return 0;
}