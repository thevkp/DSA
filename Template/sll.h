#ifndef sll_h
#define sll_h

template<typename T>

struct Node{
    T data;
    Node* next;

    Node(T val);
};

template <typename T>
class SLL {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        SLL();
        ~SLL();
        
        void append(T value);
        void print();
        void clear();

        Node<T>* getHead();
        void setHead(Node<T>* newHead);
        void setTail(Node<T>* newTail);
};


#endif