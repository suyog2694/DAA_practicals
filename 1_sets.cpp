#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int> arr, int index, vector<int> current){
    if (index == arr.size()){
        cout << "{ ";

        for (int i = 0; i < current.size(); i++){
            cout << current[i] << " ";
        }

        cout << "}" << endl;
        return;
    }

    current.push_back(arr[index]);
    generateSubsets(arr, index + 1, current);

    current.pop_back();
    generateSubsets(arr, index + 1, current);
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

    vector<int> current;

    cout << "\nAll subsets are:\n";
    generateSubsets(arr, 0, current);

    return 0;
}