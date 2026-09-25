#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int main(){
    int n;
    int k;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the step count (k): ";
    cin >> k;

    Node* head = NULL;
    Node* last = NULL;

    cout << "Enter the positive elements: ";

    for(int i = 0; i < n; i++){
        int value;
        cin >> value;

        Node* newNode = new Node();

        newNode->data = value;
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

    cout << "Last element: " << current->data << endl;
    delete current;

    return 0;
}