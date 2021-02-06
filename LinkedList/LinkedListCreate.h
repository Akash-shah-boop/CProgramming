#include <stdio.h>
#include <stdlib.h>




//creating a structure for LInked list node


struct node
{
    int data;
    struct node* next;
};


struct node* createList(int data[], int length)
{
    if(length <= 0)
    {
    return NULL;
    }
    struct node* head;
    struct node* movinghead;
    for(int i = 0 ; i < length; i++)
    {
     struct node* headtemp = (struct node*)malloc(sizeof(struct node));
     headtemp->data = data[i];
     headtemp->next = NULL;

     if(i == 0)
     {
        head = headtemp;
        movinghead = headtemp;
     }
     else
     {
         movinghead->next = headtemp;
         movinghead  = movinghead->next;
     }
    }

    return head;


}

void LinkedListTraversal(struct node* n)
{
    while(n!=NULL)
    {
        printf("%d==>", n->data);
        n = n->next;
    }
    printf("NULL\n");
}

int IsEmptyLinkedList(struct node* head)
{
    if(head == NULL)
    return 1;
    else
    return 0;
}

int LinkedListLength(struct node* head)
{
    int a = 0 ;
    while(head != NULL)
    {
        a++;
        head = head->next;
    }
    return a;
}

int FindLengthRecursive(struct node* head)
{
   if(head == NULL)
    return 0;
    else
    return (FindLengthRecursive(head->next)) + 1;
   
}

struct node* InsertionWithReturn(struct node* head, int position, int value)
{
    if(position == 0)
    {
        printf("0 is not a position to insert\n");
        return head;
    }
    if(head == NULL)
    {
        int data[] = {value};
        return createList(data, 1);
    }
    else
    {
        struct node* headreturn = head;
        if(position == 1)
        {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->next = head;
            temp->data = value;
            head = temp;
            return head;
        }
        for(int i = 1; i < position - 1 ; i++)
        {
            if(head == NULL)
            {
                printf("position is greater than length\n");
                return headreturn;
            }
            head = head->next;
            
        }
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->next = head->next;
        temp->data = value;
        head->next = temp;
        return headreturn;

    }
    
}

void InsertionWithoutReturn(struct node** head, int position, int value){


    if(position == 0)
    {
        printf("O is not a valid position\n");
        return;
    }
    if(*head == NULL)
    {
        int data[] = {value};
        struct node* headcreate = createList(data, 1);
        head = &headcreate;
        return;
    }
        struct node* headreturn = *head;
        if(position == 1)
        {
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->next = headreturn;
            temp->data = value;
            *head = temp;
            return;
        }
        for(int i = 1; i < position - 1 ; i++)
        {
            if(headreturn == NULL)
            {
                printf("position is greater than length\n");
                return ;
            }
            headreturn = (headreturn)->next;
            
        }
        struct node* temp = (struct node*)malloc(sizeof(struct node));
        temp->next = (headreturn)->next;
        temp->data = value;
        (headreturn)->next = temp;
        return;
    

}

struct node* DeleteNodeWithReturnAtPosition(struct node* head, int position)
{
    if(position == 0)
    {
        printf("No such position\n");
        return head;
    }
    if(head == NULL)
    {
        printf("Empty LinkedList\n");
        return head;
    }
    if(LinkedListLength(head) < position)
    {
        printf("the position is greater than LL length\n");
        return head;
    }
    if(position == 1)
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else
    {
        struct node* temp = head;
        for(int i = 1 ; i < position - 1; i++)
        {
            if(temp == NULL)
            {
              
                return head;
            }
           temp = temp->next;
        }
         struct node* temp2 = temp->next;
            temp->next = temp->next->next;
            free(temp2);
            return head;
        

    }
}

struct node* DeleteNodeWithReturnAtKey(struct node* head, int key)
{
    if(head == NULL)
    {
        printf("LL empty\n");
        return head;
    }
    struct node* head1 = head;
    struct node* headmove = head;
    int position = 0;
    while(head1->data != key)
    {
        head1 = head1->next;
        if(position > 0)
        {
            headmove = headmove->next;
            
        }
        else
        position = 1;
        if(head1 == NULL)
        {
            printf("Key not present\n");
            return head;
        }

    }
    printf("%d %d\n", headmove->data, head1->data);
    if(headmove == head1)
    {
        head1 = head1->next;
        free(headmove);
        printf("hre");
        return head1;
        
    }
    headmove->next = head1->next;
    free(head1);
    return head;
    

    
}

void DeleteLinkedList(struct node** head)
{
    if(*head == NULL)
    {
        printf("LinkedliSt already empty\n");
        return;
    }
    while((*head) != NULL)
    {
        struct node* headtemp = *head;
        *head = (*head)->next;
        free(headtemp);
        
    }
    return;
}

int SearchAKey(struct node* head, int value, int position)
{
    
    if(head == NULL)
    return 0;
    if(head->data == value)
    return position;
    else
    return SearchAKey(head->next, value, position + 1);
}

int GetNthNode(struct node* head, int position)
{
    int number = 0;
    if(head == NULL)
    {
        printf("LinkedList is empty \n");
        return -1;
    }
    struct node* moveslow = head;
    struct node* movefast = head;
    while(movefast->next != NULL)
    {
        if(movefast->next->next == NULL)
       { movefast = movefast->next;
       number = number + 1;}
        else
        {movefast = movefast->next->next;
        moveslow = moveslow->next;
        number = number + 2;}    
    }
    if( (number + 1)/2 > number - position + 1 )
    {
        moveslow = head;
        
          for(int i = 0; i < number-position + 1; i++)
        {
            moveslow = moveslow->next;
        }  
        return moveslow->data;
    }
    else if((number + 1)/2 < number - position + 1)
    {
        for(int i = (number)/2; i < number-position + 1; i++)
        {
            moveslow = moveslow->next;
        }
        return moveslow->data;
    }else if((number + 1)/2 == number - position + 1)
    {
        return moveslow->data;
    }
    return -1;
}

int Middleelement(struct node* head)
{
    if(IsEmptyLinkedList(head))
    return -1;
    struct node* headslow = head;
    while(head->next!=NULL)
    {
        if(head->next->next == NULL)
        {
            head = head->next;
        }
        else
        {
            head= head->next->next;
            headslow = headslow->next;
        }

    }
    return headslow->data;


}

struct node* MiddleelementNode(struct node* head)
{
    if(IsEmptyLinkedList(head))
    return head;
    struct node* headslow = head;
    while(head->next!=NULL)
    {
        if(head->next->next == NULL)
        {
            head = head->next;
        }
        else
        {
            head= head->next->next;
            headslow = headslow->next;
        }

    }
    return headslow;


}

int CountIntegerLinkedList(struct node* head, int number)
{
    if(IsEmptyLinkedList(head))
    return 0;
    int count = 0;
    while(head != NULL)
    {
        if(head->data == number)
        count++;
        head = head->next;
    }
    return count;


}

int CountIntRecursive(struct node* head, int number, int count)
{
    if(head == NULL)
    return count;

    if(head->data == number)
    return CountIntRecursive(head->next, number, ++count);
    else 
    return CountIntRecursive(head->next, number, count);

}


int isLoop(struct node* head)
{
   struct node* head2 = head;
   if(head == NULL)
   return 0;
   while(head2->next != NULL)
   {
       if(head2->next->next != NULL)
       {
           head2 = head2->next->next;
           head = head->next;
           if(head == head2)
           return 1;
       }
       else
       return 0;
   }
   
   return 0;
   
   
}

int countNodesinLoop(struct node* head)
{
    
    if(head == NULL)
    return 0;
    
    
    struct node* head2 = head;
    struct node* headstatic = head;
    while(head2->next != NULL)
    {
        
        if(head2->next->next != NULL)
        {
            head2 = head2->next->next;
            head = head->next;
            
            if(head2 == head)
            {
                head = headstatic;
                while(head != head2)
                {
                    head = head->next;
                    head2 = head2->next;
                    
                }
                int number = 1;
                head2 = head2->next;
                
                while(head != head2)
                {
                    number++;
                    head2 = head2->next;
                }
                return number;
            }
        }   
        else
        {
            return 0;
        }
        
    
    }

    return 0;
}

struct node* ReverseLinkedList(struct node* head)
{
    
    if(head == NULL)
    return head;

    struct node* head2 = head->next;
    struct node* X = NULL;
    head->next = X;
    while(head2 != NULL)
    {
        X = head2;
        head2 = head2->next;
        X->next = head;
        head = X;
        X = head2;
    }

    return head;


}

int CompareTwoLinkedList(struct node* head, struct node* head2)
{
    if(head == NULL && head2 == NULL)
    return 1;
    else if(head2 == NULL || head == NULL)
    return 0;

    while(1)
    {
        if(head->data == head2->data)
        {
            head = head->next;
            head2 = head2->next;

        }
        else
        {
            return 0;
        }
        if(head == NULL || head2 == NULL)
        {
            if(head == NULL && head2 == NULL)
            return 1;
            else
            return -1;
        }
    }
}

int isPalidrome(struct node* head)
{
    if(head == NULL)
    return 0;
    struct node* headstatic = head;
    struct node* head2 = head;
    while(head->next!= NULL)
    {
        if(head->next->next != NULL)
        {
            head = head->next->next;
            head2 = head2->next;
        }
        else
        {
            head= head->next;
        }
        


    }
    // till here we have found the last element that is head and middle element that is head2
        struct node* headmiddlenext = head2->next;
        head2->next = NULL;
        headmiddlenext = ReverseLinkedList(headmiddlenext);
    // checking if both linkedlist is same
        int returnval;
        if(CompareTwoLinkedList(headmiddlenext, headstatic) == 1 || CompareTwoLinkedList(headmiddlenext, headstatic) == -1)
        {returnval = 1;}
        else
        {returnval = 0;}
        //merging the two linkedlist into one
        headmiddlenext = ReverseLinkedList(headmiddlenext);
        head2->next = headmiddlenext;
        return returnval;


}

struct node* RemoveDuplicateSorted(struct node* head){

    if(head == NULL)
    return head;

    struct node* headstatic = head;

    struct node* head2 = head;
    head2 = head2->next;
    while(head != NULL && head2 != NULL)
    {
        if(head->data == head2->data)
        {

            struct node* headfree = head2;
            head2 = head2->next;
            head->next = head2;
            free(headfree);
        }
        else
        {
            head2 = head2->next;
            head = head->next;
        }
    }
    return headstatic;
}

struct node* Merge(struct node* head1, struct node* head2)
{
    if(head1 == NULL && head2 == NULL)
    return NULL;
    if(head1 == NULL)
    return head2;
    if(head2 == NULL)
    return head1;

    struct node* headreturn;
    (head1->data <= head2->data)?(headreturn = head1):(headreturn = head2);
    (head1->data <= head2->data)?(head1 = head1->next):(head2 = head2->next);
    struct node* movehead = headreturn;
    
    headreturn->next = NULL;

    //checking which one is greater
    while(1)
    {
        
        if(head1 == NULL)
        {
            movehead->next = head2;
            return headreturn;
        }
        else if(head2 == NULL)
        {
            movehead->next = head1;
            return headreturn;
        }
        else
        {
            if(head1->data <= head2->data)
            {
                movehead->next = head1;
                head1 = head1->next;
                movehead = movehead->next;
                movehead->next = NULL;
            }
            else
            {
                movehead->next = head2;
                head2 = head2->next;
                movehead = movehead->next;
                movehead->next = NULL;
            }
        }
    }
    
}

struct node* MergeSortLinkedList(struct node* head)
{
    if(head == NULL)
    return head;
    if(head->next == NULL)
    return head;
    struct node* headmiddle = MiddleelementNode(head);
    
    struct node* headmiddle2 = headmiddle->next;
    
    headmiddle->next = NULL;
    head = MergeSortLinkedList(head);
    headmiddle2 = MergeSortLinkedList(headmiddle2);
    return Merge(head, headmiddle2);
}