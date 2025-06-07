#include "SLL.h"
#include <iostream>
using namespace std;


int sumNLastNodes(Node* head, int n){
    if(!head) return 0;
    if(!head->next) return head->data;

    Node* ptr1 = head;
    Node* ptr2 = head;

    int sum1 = 0, sum2 = 0;

    for(int i = 0; i < n && ptr1; i++){
        sum1 = sum1 + ptr1->data;
        ptr1 = ptr1->next;
    }

    if(!ptr1) return sum1;

    while(ptr1){
        sum1 += ptr1->data;
        sum2 += ptr2->data;

        ptr1 = ptr2->next;
        ptr2 = ptr2->next;
    }

    return (sum1 - sum2);
}


int main(){
    system("cls");

    SLL list;

    int input;
    cin >> input;
    while(input != -1){
        list.append(input);
        cin >> input;
    }

    list.printList();
    int n;
    cin >> n;
    Node* head = list.getHead();
    int ans = sumNLastNodes(head, n);


    return 0;
}


// $files = "main.cpp", "SLL.cpp"
// g++ $files -o main
// if ($?) {
//     .\main
// }