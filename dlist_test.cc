#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <timer.h>

#include "dlist.hh"

//#define DEBUG

void test();

int main(int argc, char* argv[]){

#ifdef DEBUG
    test();
#endif

#ifndef DEBUG

    int n = -1;

    if(argc == 2){
        n = atoi (argv[1]);
        assert(n>0);
    }
    else{
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        fprintf(stderr, "where <n> is the length of the list\n");
        return -1;
    }

    DList dlist;

    for(int i = 1; i <= n; i++){
        dlist.add_to_back(i);
    }

    struct stopwatch_t* timer = stopwatch_create();
    assert(timer);
    srand(time(0));
    int j = (rand() % (n+1)) + 1;
    ListNode* node;
    stopwatch_start(timer);
    node = dlist.search_value(j);
    int k = node->val;
    dlist.remove(node);
    float t = stopwatch_stop(timer);
    dlist.add_to_front(k);
    printf("Time: %f\n", t); 
#endif

    return 0;
}

void test(){
    
    DList dlist;
    
    for(int i = 1; i <= 10; i++){
        dlist.add_to_back(i);
    }

    dlist.printList();

    ListNode* node1;
    ListNode* node2;
    ListNode* node3;
    node1 = dlist.search_value(5);
    node2 = dlist.previous(node1);
    node3 = dlist.next(node1);
    printf("The current node is %d, prev is %d, next is %d\n", node1->val, node2->val, node3->val);
    int j = node1->val;
    dlist.remove(node1);
    dlist.printList();
    dlist.add_to_front(j);
    dlist.printList();
    node1 = dlist.search_value(9);
    printf("The current node is %d\n", node1->val);
    j = node1->val;
    dlist.remove(node1);
    dlist.printList();
    dlist.add_to_back(j);
    dlist.printList();
    dlist.deleteList();
}