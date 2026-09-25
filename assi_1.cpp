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


void generateCombinations(vector<int> arr, int start, int r, vector<int> current){
    if (current.size() == r){
        cout << "{ ";

        for (int i = 0; i < current.size(); i++){
            cout << current[i] << " ";
        }

        cout << "}" << endl;
        return;
    }

    for (int i = start; i < arr.size(); i++){
        current.push_back(arr[i]);
        generateCombinations(arr, i + 1, r, current);
        current.pop_back();
    }
}


int main(){
    int choice;

    do{
        cout << "\n Enumaration of Combinatorial Objects: ";
        cout << "\n1. Generate Subsets";
        cout << "\n2. Generate Permutations";
        cout << "\n3. Generate Combinations";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
            {
                int n;

                cout << "\nEnter number of elements: ";
                cin >> n;

                vector<int> arr(n);

                cout << "Enter the elements: ";
                for (int i = 0; i < n; i++){
                    cin >> arr[i];
                }

                vector<int> current;

                cout << "\nAll subsets are:\n";
                generateSubsets(arr, 0, current);

                break;
            }

            case 2:
            {
                int n;

                cout << "\nEnter number of elements: ";
                cin >> n;

                vector<int> arr(n);

                cout << "Enter the elements: ";
                for (int i = 0; i < n; i++){
                    cin >> arr[i];
                }

                cout << "\nAll permutations are:\n";
                generatePermutations(arr, 0);

                break;
            }

            case 3:
            {
                int n, r;

                cout << "\nEnter number of elements: ";
                cin >> n;

                vector<int> arr(n);

                cout << "Enter the elements: ";
                for (int i = 0; i < n; i++){
                    cin >> arr[i];
                }

                cout << "Enter value of r: ";
                cin >> r;

                if (r > n || r < 0){
                    cout << "\nInvalid value of r!";
                }
                else{
                    vector<int> current;
                    cout << "\nAll combinations of size " << r << " are:\n";
                    generateCombinations(arr, 0, r, current);
                }

                break;
            }

            case 4:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice! Please try again.";
        }

    } while (choice != 4);

    return 0;
}