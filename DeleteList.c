#include<stdio.h>
#include<stdlib.h>

struct Node{

    int data;
    struct Node* next;
};

void linkListTravers(struct Node *ptr){

    while (ptr != NULL)
    {
        printf("Element : %d \n",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    
}
// Case 1
struct Node *deleteAtFirst(struct Node *head){

    struct Node *ptr = head;
    
    head = head->next;

    free(ptr);

    return head;

}
// Case 2
struct Node  *deleteAtIndex(struct Node *head, int index){
  struct Node *p = head;
  struct Node *q;
  int i=1;
  while (i!= index - 1)
  {
    p = p->next;
    i++;
  }
  q = p->next;
  p->next = q->next;
  free(q);

  return head;
  
}
// Case 3
struct Node  *deleteAtEnd(struct Node *head){
  struct Node *p = head;
  struct Node *q = head->next;
  while (q->next != NULL)
  {
    q = q->next;
    p = p->next;
  }
  p->next = NULL;
  free(q);

  return head;
  
}
// Case 4
struct Node *deleteAtAfterNode(struct Node *head, int value)
{
    struct Node *p= head;
    struct Node *q = head->next; 
    while(p->next != value && q->next != NULL){
      p = p->next;
      q = q->next;
    }
    if(q->data == value){
      p->next = q->next;
      free(q);
    }
    

   

    return head;
}


int main()
{
        

        struct Node * head = (struct Node*)malloc(sizeof(struct Node));
        struct Node * second = (struct Node*)malloc(sizeof(struct Node));
        struct Node * third = (struct Node*)malloc(sizeof(struct Node));
        struct Node * fourth = (struct Node*)malloc(sizeof(struct Node));

        head->data = 11;
        head->next = second;

        second->data = 22;
        second->next = third;
        
        third->data = 33;
        third->next = fourth;

        fourth->data = 44;
        fourth->next = NULL;

        linkListTravers(head);

        //head = deleteAtFirst(head);

       // head = deleteAtIndex(head, 3);

       //head = deleteAtEnd(head);

       head = deleteAtAfterNode(head, 22);

        linkListTravers(head);

        

    return 0;
}