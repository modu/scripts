#include "test.h"

#include <stdio.h>
#include <string>
#include "hashtable.h"
#include "linkedlist.h"

void printList(LinkedList<int, int> *list)
{
    /*for(auto it = list->begin(); it != list->end(); it = it->next)
        printf("%d ", it->value);
    printf("\n");*/
}

bool testLinkedListAdd(LinkedList<int, int> *list)
{
    list->add(1, 1);
    list->add(2, 2);
    list->add(3, 3);
    if(list->size() != 3) return false;
    if(list->find(900) != NULL) return false;
    if(list->find(1)->value != 1) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(1)->value != 1) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(2)->value != 2) return false;
    return true;
}

bool testLinkedListFind(LinkedList<int, int> *list)
{
    list->add(5, 5);
    if(list->size() != 4) return false;
    if(list->find(5)->value != 5) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(1)->value != 1) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(6) != NULL) return false;
    return true; 
}

bool testLinkedListErase(LinkedList<int, int> *list)
{
    list->erase(1);
    printList(list);
    if(list->size() != 3) return false;
    if(list->find(5)->value != 5) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(1) != NULL) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(6) != NULL) return false;
    if(list->find(1) != NULL) return false;
    list->erase(5);
    printList(list);
    if(list->size() != 2) return false;
    if(list->find(5) != NULL) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(1) != NULL) return false;
    if(list->find(3)->value != 3) return false;
    if(list->find(2)->value != 2) return false;
    if(list->find(6) != NULL) return false;
    if(list->find(1) != NULL) return false;
    list->erase(3);
    printList(list);
    if(list->size() != 1) return false;
    if(list->find(3) != NULL) return false;
    if(list->find(2)->value != 2) return false;
    return true; 
}

bool testLinkedListErase2(LinkedList<int, int> *list)
{
    list->erase(2);
    printList(list);
    if(list->size() != 0) return false;
    if(list->find(5) != NULL) return false;
    if(list->find(2) != NULL) return false;
    if(list->find(1) != NULL) return false;
    if(list->find(6) != NULL) return false;
    if(list->find(1) != NULL) return false;
    return true;
}

void printTestRes(bool res, std::string test_name)
{
    printf("Test %s ", test_name.c_str());
    if(res) printf("PASSED\n");
    else printf("FAILED\n");
}

void runAllTests()
{
    LinkedList<int, int> *list = new LinkedList<int, int>();
    printTestRes(testLinkedListAdd(list), "LinkedList add test");
    printTestRes(testLinkedListFind(list), "LinkedList find test");
    printTestRes(testLinkedListErase(list), "LinkedList erase test");
    printTestRes(testLinkedListErase2(list), "LinkedList erase2 test");
    printTestRes(testLinkedListAdd(list), "LinkedList add test");
    printTestRes(testLinkedListFind(list), "LinkedList find test");
    printTestRes(testLinkedListErase(list), "LinkedList erase test");
    printTestRes(testLinkedListErase2(list), "LinkedList erase2 test");
    delete list;
}


