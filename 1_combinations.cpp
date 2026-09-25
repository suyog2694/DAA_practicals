#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int> arr, int index){
    if (index == arr.size()){
        for (int i = 0; i < arr.size(); i++){
            cout << arr[i] << " ";
        }

        cout << endl;
        return;
    }

    for (int i = index; i < arr.size(); i++){
        swap(arr[index], arr[i]);

        generatePermutations(arr, index + 1);

        swap(arr[index], arr[i]);
    }
}


int main(){
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "\nAll permutations are:\n";
    generatePermutations(arr, 0);

    return 0;
}