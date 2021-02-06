#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "LinkedListCreate.h"





// 1->2->3->4->NULL

int main(){

    int a[] = {4,2,3,5,1,2,6,4,10,7,8,9,7,8,9,6,4,7};
    struct node* head1 = createList(a,sizeof(a)/sizeof(a[0]));
    
    LinkedListTraversal(head1);
    head1 = RemoveDuplicateSorted(MergeSortLinkedList(head1));
    LinkedListTraversal(head1);
        
    return 0;
}