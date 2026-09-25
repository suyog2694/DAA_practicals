#include<iostream>
#include<vector>
using namespace std;

int josephusVector(int n, int k, vector<int> arr){
    int i = 0;
    int count = 0;
    int flag = n;

    while(flag >= 1){
        if(arr[i] != 0 && flag == 1){
            return arr[i];
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

    return -1;
}



struct Node{
    int data;
    Node* next;
};

int josephusLinkedList(int n, int k, vector<int> arr){
    Node* head = NULL;
    Node* last = NULL;

    for(int i = 0; i < n; i++){
        Node* newNode = new Node();

        newNode->data = arr[i];
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            last = newNode;
        }
        else{
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = head;

    Node* current = head;
    Node* previous = last;

    int flag = n;

    while(flag > 1){

        for(int i = 1; i < k; i++){
            previous = current;
            current = current->next;
        }

        cout << "Eliminated: " << current->data << endl;
        previous->next = current->next;
        Node* temp = current;
        current = current->next;
        delete temp;
        flag--;
    }

    int survivor = current->data;
    delete current;
    return survivor;
}



int josephusRecursion(int n, int k){
    if(n == 1){
        return 0;
    }

    return (josephusRecursion(n - 1, k) + k) % n;
}



int josephusBinary(int n){
    int power = 1;

    while(power * 2 <= n){
        power = power * 2;
    }

    int l = n - power;
    return 2 * l + 1;
}



int main(){
    int choice;

    do{
        cout << "\nJOSEPHUS PROBLEM : ";
        cout << "\n1. Using Vector";
        cout << "\n2. Using Linked List";
        cout << "\n3. Using Recurrence Relation";
        cout << "\n4. Using Binary Representation";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
            {
                int n;
                int k;

                cout << "\nEnter the number of elements: ";
                cin >> n;

                cout << "Enter the step count (k): ";
                cin >> k;

                if(n <= 0 || k <= 0){
                    cout << "\nInvalid input!";
                    break;
                }

                vector<int> arr(n);

                cout << "Enter the positive elements: ";
                for(int i = 0; i < n; i++){
                    cin >> arr[i];
                }

                int survivor = josephusVector(n, k, arr);
                cout << "Last element: " << survivor << endl;
                break;
            }


            case 2:
            {
                int n;
                int k;

                cout << "\nEnter the number of elements: ";
                cin >> n;

                cout << "Enter the step count (k): ";
                cin >> k;

                if(n <= 0 || k <= 0){
                    cout << "\nInvalid input!";
                    break;
                }

                vector<int> arr(n);

                cout << "Enter the positive elements: ";
                for(int i = 0; i < n; i++){
                    cin >> arr[i];
                }

                int survivor = josephusLinkedList(n, k, arr);
                cout << "Last element: " << survivor << endl;
                break;
            }


            case 3:
            {
                int n;
                int k;

                cout << "\nEnter the number of elements: ";
                cin >> n;

                cout << "Enter the step count (k): ";
                cin >> k;

                if(n <= 0 || k <= 0){
                    cout << "\nInvalid input!";
                    break;
                }

                int survivor = josephusRecursion(n, k);
                cout << "Last element: " << survivor + 1 << endl;
                break;
            }


            case 4:
            {
                int n;
                cout << "\nEnter the number of elements: ";
                cin >> n;

                if(n <= 0){
                    cout << "\nInvalid input!";
                    break;
                }

                int survivor = josephusBinary(n);
                cout << "\nStep count (k) = 2";
                cout << "\nLast element: " << survivor << endl;
                break;
            }

            case 5:
                cout << "\nExiting program...";
                break;

            default:
                cout << "\nInvalid choice! Please try again.";
        }

    }while(choice != 5);
    return 0;
}