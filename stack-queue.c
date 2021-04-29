#include <stdio.h>
#include <stdlib.h>


typedef struct list* p_list;
typedef struct list_node* p_list_node;
typedef char itemType;

struct list_node{
    itemType item;
    p_list_node next;
    p_list_node prev;
};

struct list{
    p_list_node head;
    p_list_node tail;
};

p_list init(){
    p_list x = malloc(sizeof(*x));
    if(x==NULL){
        printf("Allocation error");
        exit(1);
    }
    x->head=NULL; x->tail=NULL;
    return x;
}

p_list_node NEW(itemType item){
    p_list_node x = malloc(sizeof(*x));
    if(x==NULL){
        printf("Allocation error");
        exit(1);
    }
    x->item=item;
    x->next=NULL;
    x->prev=NULL;
}


int isEmpty(p_list x){
    return ((x->head==NULL) && (x->tail==NULL));
}


void insertFirst(p_list x, itemType item){
    if(isEmpty(x)){
        x->head = (x->tail=NEW(item));
    }
    else{
        x->head->prev = NEW(item);
        x->head->prev->next = x->head;
        x->head = x->head->prev;
    }
}

void insertLast(p_list x, itemType item){
    if(isEmpty(x)){
        x->head = (x->tail=NEW(item));
    }
    else{
        x->tail->next = NEW(item);
        x->tail->next->prev = x->tail;
        x->tail = x->tail->next;
    }
}

itemType removeFirst(p_list x){
    if(isEmpty(x)){
        printf("List is empty \n");
        return '\0';
    }
    else if(x->tail==x->head){
        itemType item = x->head->item;
        free(x->head);
        x->head = (x->tail = NULL);
        return item;
    }
    else{
        itemType item = x->head->item;
        p_list_node tmp = x->head->next;
        free(x->head);
        x->head = tmp;
        x->head->prev=NULL;
        return item;
    }
    return '\0';
}

itemType removeLast(p_list x){
    if(isEmpty(x)){
        printf("List is empty \n");
        return '\0';
    }
    else if(x->tail==x->head){
        itemType item = x->tail->item;
        free(x->tail);
        x->head = (x->tail = NULL);
        return item;
    }
    else{
        itemType item = x->tail->item;
        p_list_node tmp = x->tail->prev;
        free(x->tail);
        x->tail = tmp;
        x->tail->next = NULL;
        return item;
    }
    return '\0';
}


void clear(p_list x){
    while(x->head != NULL){
        p_list_node tmp = x->head->next;
        free(x->head);
        x->head = tmp;
    }
    x->tail = x->head;
}

void destroy(p_list x){
    clear(x);
    free(x);
}

int count(p_list x){
    if(isEmpty(x)){
        return 0;
    }
    else{
        int i=1;
        p_list_node tmp = x->head;
        while(tmp->next != NULL){
            tmp = tmp->next;
            i++;
        }
        return i;
    }
    return 0;
}




int main(void){

    //This is only an example on how to use it, can be changed.
    p_list list=init();
    char ch;

    printf("Is empty? %d \n", isEmpty(list));

    insertFirst(list,'A');
    insertLast(list,'B');

    printf("Count? %d \n", count(list));

    printf("%c \n", removeFirst(list));
    printf("%c \n", removeFirst(list));

    printf("Count? %d \n", count(list));

    printf("Is empty? %d \n", isEmpty(list));

    insertFirst(list,'A');

    printf("Count? %d \n", count(list));

    printf("%c \n", removeLast(list));

    insertLast(list,'B');
    printf("Is empty? %d \n", isEmpty(list));
    clear(list);


    for(ch='A'; ch <= 'H'; ch++){
        printf("Putting first %c \n", ch);
        insertFirst(list, ch);
    }
    for(ch='I'; ch <= 'P'; ch++){
        printf("Putting last %c \n", ch);
        insertLast(list, ch);
    }

    printf("Count? %d \n", count(list));

    for(int i=0; i<8; i++){
        printf("Getting first: %c \n", removeFirst(list));
    }
    for(int i=0; i<8; i++){
        printf("Getting last %c \n", removeLast(list));
    }

    printf("Is empty? %d \n", isEmpty(list));
    destroy(list);
    return 0;
}

