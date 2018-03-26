#ifndef LIST_H
#define LIST_H


typedef struct node {
    
     Data data;
    struct node * next;
    struct node * prev;
}Node;

typedef struct list {
    
     Node * head;
     Node * tail;
void (*insert)(struct List *, int,Data Data);
void (*remove)(struct List *, int);
Data * (*read)(struct List *, int);
void (*delete)(struct List *);

}List;


List * newList();
void insertData(List * l, int i, Data d);
void removeData(List * l, int i);
Data * readData(List * l, int i);
void deleteList(List * l);

#endif

