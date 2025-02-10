#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* pNext;
};
struct Node* head=NULL;
void addNewElement(int data){
    //queue
    /*
    if(head==NULL){
        head = (struct Node*) malloc(sizeof(struct Node));
        head->data = data;
        head->pNext = NULL;
    }else{
        struct Node* temp = head;
        while(temp->pNext!=NULL){
            temp = temp->pNext;
        }
        temp->pNext = (struct Node*)malloc(sizeof(struct Node));
        temp->pNext->data =data;
        temp->pNext->pNext=NULL;
    }*/
    //stack
    if(head==NULL){
        head = (struct Node*) malloc(sizeof(struct Node));
        head->data = data;
        head->pNext = NULL;
    }else{
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->pNext = head;
        temp->data = data;
        head = temp;


    }
}
void printList(){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->pNext;

    }
}
int main(){
    addNewElement(5);
    addNewElement(6);
    addNewElement(745);
    printList();
    return 0;
}
