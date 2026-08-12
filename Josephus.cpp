#include<iostream>
#include<vector>
using namespace std;

int arrays(vector<int> arr, int n, int k) {
    int i = 0;
    int count = 0;
    int flag = n;

    while (flag >= 1) {
        if (arr[i] != 0 && flag == 1) {
            return arr[i];
        }
        if (arr[i] != 0) {
            count++;
        }
        if (count == k) {
            cout << "Eliminated: " << arr[i] << endl;
            arr[i] = 0;
            count = 0;
            flag--;
        }
        i = (i + 1) % n;
    }
    return -1;
}

int main(){
    int choice ;
    int n ;
    int k ;

    do {
        cout << "\n Josephus Problem using methods : " << endl ;
        cout << "1. Using Arrays/Vectors" << endl ;
        cout << "2. Using Linked Lists" << endl ;
        cout << "3. Using Recursion" << endl ;
        cout << "4. Using Binary Bits" << endl ;
        cout << "5. Exit" << endl ;

        cout << "Enter your choice : " ;
        cin >> choice ;

        if (choice == 5) {
            cout << "Exiting the program." << endl;
            break;
        }

        cout << "Enter the number of people (n) : " ;
        cin >> n ;
        cout << "Enter the step count (k) : " ;
        cin >> k ;

        switch(choice){
            case 1: {
                vector<int> arr(n) ;
                cout << "enter the elements of the array : " << endl ;
                for (int i = 0; i < n; i++) {
                    cin >> arr[i] ;
                }
                int last = arrays(arr, n, k);
                cout << "Last element: " << last << endl;
                break;
            }

            case 2:
                // Call the function for Linked Lists method
                break;
            case 3:
                // Call the function for Recursion method
                break;
            case 4:
                // Call the function for Binary Bits method
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        } 
    } while (choice != 5);

    return 0 ;
}