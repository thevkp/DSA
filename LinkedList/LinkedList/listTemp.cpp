#include "intersectTwoLinkedLists.cpp";

    LinkedList list1;
    LinkedList list2;

    int input1;
    cin >> input1;
    while(input1 == -1){
        list1.createNode(input1);
        cin >> input1;
    }

    int input2;
    cin >> input2;
    while(input2 == -1){
        list2.createNode(input2);
        cin >> input2;
    }

    list1.printList();
    list2.printList();

