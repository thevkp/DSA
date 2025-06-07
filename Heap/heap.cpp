#include <iostream>
#include <queue>
using namespace std;

class Heap{
    private:
        struct Node{
            int data;
            Node* left;
            Node* right;

            Node(int value) : data(value), left(nullptr), right(nullptr) {}
        };

        Node* root;

        Node* buildHeap(Node* node){
            int input;
            cin >> input;

           if(input == -1)
                return nullptr;
            
            Node* parent = new Node(input);

            // parent->left = buildHeap(parent->left);
            if(!parent->left){
                parent->left = buildHeap(parent->left);
            }
            else
                parent->right = buildHeap(parent->right);
            
            return parent;
        }

        void inorderTraversal(Node* node){
            if(!node)
                return;

            inorderTraversal(node->left);
            cout << node->data << " ";
            inorderTraversal(node->right);
        }

        void deleteHeap(Node* node){
            if(!node)
                return;

            deleteHeap(node->left);
            deleteHeap(node->right);
            delete node;
        }

        void levelOrder(){
            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                int levelSize = q.size();
                for(int i = 0; i < levelSize; i++){
                    Node* curr = q.front();
                    q.pop();

                    cout << curr->data << " ";
                    if(curr->left) q.push(curr->left);
                    if(curr->right) q.push(curr->right);
                }
                cout << endl;
            }
        }

    public:
        Heap(){
            root = nullptr;
        }

        ~Heap(){
            deleteHeap(root);
            root = nullptr;
        }

        void build(){
            root = buildHeap(root);
        }

        void inorder(){
            inorderTraversal(root);
        }

        void bfs(){
            levelOrder();
        }
};


int main(){
    system("cls");

    Heap h;

    h.build();

    h.inorder();
    cout << endl;
    h.bfs();



    return 0;
}