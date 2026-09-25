#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    int k;
    int i = 0;
    int count = 0;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the step count (k): ";
    cin >> k;

    vector<int> arr(n);

    cout << "Enter the positive elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int flag = n;

    while(flag >= 1){
        if(arr[i] != 0 && flag == 1){
            cout << "Last element: " << arr[i] << endl;
            break;
        }

        if(arr[i] != 0){
            count++;
        }

        if(count == k){
            cout << "Eliminated: " << arr[i] << endl;

            arr[i] = 0;

            count = 0;
            flag--;
        }

        i = (i + 1) % n;
    }

    return 0;
}