#include<stdio.h>
#define before 1

typedef struct node Node;
struct node{
    int data;
    Node *next;
};
Node *create_node(int item, Node *next){
    Node *new_node=(Node *) malloc(sizeof(Node));
    if(new_node==NULL){
        printf("Error! Can't create");
        return;
    }
    new_node->data = item;
    new_node->next = next;
    return new_node;
}
Node *node_insertion(int item, Node *head, Node *next){
    if(head == NULL){
        return create_node(item, next);
    }
    else if(head == next){ // insert node at beginning
        head = create_node(item, head);
        return head;
    }
    else if(next == NULL){ // insert node at ending
        Node *new_node = create_node(item, NULL);
        Node *current_node=head;
        while(current_node->next != NULL){
            current_node = current_node->next;
        }
        current_node->next = new_node;
        return head;
    }
    else{ // insert node before a node(next)
        if(before==1){
            Node *new_node = create_node(item, next);
            Node *current_node=head;
            while(current_node->next != next){
                current_node = current_node->next;
            }
            current_node->next = new_node;
            return head;
        }
        else{// insert node after a node(previous)
            Node *previous = next;
            Node *new_node = create_node(item, previous->next);
            previous->next = new_node;
            return head;
        }
    }
}
void main(){
    Node *head=NULL, *next=NULL;
    int i;
    printf("\n\n\tSequence of evens of (10 -> 24)\n");
    for(i=10; i<=24; i+=2){
        if(head == NULL){
            head = node_insertion(i, head, next);
            printf("\t\thead = %d\n", head->data);
        }
        else
        {
            if(i==18){
                head = node_insertion(i, head, head);
                printf("\t\t18 <goes before< head\n");
            }
            else if(i==20){
                Node *current_node=head;
                while(current_node->data != 12){
                    current_node = current_node->next;
                }
                head = node_insertion(i, head, current_node);
                printf("\t\t20 <goes before< 12\n");
            }
            else{
                head = node_insertion(i, head, NULL);
            }
        }
    }

    // node traveling
    printf("\n------------------------After all operation------------------------\n\n");
    Node *current_node = head;
    while(current_node != NULL){
        printf("\t%d", current_node->data);
        current_node = current_node->next;
    }
    printf("\n\n-------------------------------------------------------------------\n");
}
