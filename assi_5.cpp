#include<iostream>
#include<vector>
using namespace std;

struct Node{
    char data;
    int frequency;
    Node* left;
    Node* right;
};


Node* createNode(char data, int frequency){
    Node* newNode = new Node();

    newNode->data = data;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


int findMinimum(vector<Node*> nodes){
    int minimum = 0;

    for(int i = 1; i < nodes.size(); i++){
        if(nodes[i]->frequency < nodes[minimum]->frequency){
            minimum = i;
        }
    }
    return minimum;
}


Node* buildHuffmanTree(vector<char> characters, vector<int> frequencies){
    vector<Node*> nodes;

    for(int i = 0; i < characters.size(); i++){
        nodes.push_back(createNode(characters[i], frequencies[i]));
    }

    while(nodes.size() > 1){
        int first = findMinimum(nodes);
        Node* left = nodes[first];
        nodes.erase(nodes.begin() + first);

        int second = findMinimum(nodes);
        Node* right = nodes[second];
        nodes.erase(nodes.begin() + second);

        Node* newNode = createNode('$',left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        nodes.push_back(newNode);
    }
    return nodes[0];
}


void generateCodes(Node* root, string code){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        cout << root->data << " : " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}


int main(){
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> characters(n);
    vector<int> frequencies(n);

    cout << "\nEnter characters and their frequencies:\n";

    for(int i = 0; i < n; i++){
        cout << "Character " << i + 1 << ": ";
        cin >> characters[i];

        cout << "Frequency: ";
        cin >> frequencies[i];
    }

    Node* root = buildHuffmanTree(characters, frequencies);
    cout << "\nHuffman Codes:\n";
    generateCodes(root, "");

    return 0;
}