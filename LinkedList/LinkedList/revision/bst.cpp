#include <iostream>
#include <queue>
using namespace std;


struct Node{
    Node* left;
    int data;
    Node* right;

    Node(int value) : left(nullptr), data(value), right(nullptr) {}
};

class BST{
    private:
        Node* buildTree(Node* node, int value){
            if(node == nullptr)
                return new Node(value);
            
            Node* parent = new Node(value);

            if(node->data > value)
                node->left = parent;
            else:
                node->right = parent;

            return parent;
        }
    public:
        Node* root;

        BST() : root(nullptr) {}

        void insert(){
            int input;
            cin >> input;

            while(input != -1){
                root = buildTree(root, input);
                cin >> input;
            }
        }

};


int main(){



    return 0;
}