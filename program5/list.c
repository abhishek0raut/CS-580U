#include "vector.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>


 Node * createNode(Data value) {
    
     Node * listNode = malloc(sizeof(Node));
    
    if(listNode==NULL) {
        
        printf("Not enough space in Memory\n");
        exit(-1);
    }
    
    listNode->next=NULL;
    listNode->prev=NULL;
    listNode->data=value;
    return listNode;
}


void insertData(List * list, int index, Data value) {
    
    int initial_index=1;
    Node * listNode=createNode(value);
    
    if(list->head == NULL) {
        
        list->head=listNode;
        list->tail=listNode;
        
    } else {
        
        if(index == 0) {
            listNode->next=list->head;
            list->head->prev=listNode;
            list->head=listNode;
            return;
            
        } else {
            
             Node * current=list->head;
            
            while(current->next != NULL && initial_index!=index) {
                
                current=current->next;
                initial_index++;
            }
            
            if(current->next==NULL) {
                current->next=listNode;
                listNode->prev=current;
                list->tail=listNode;
               
                
            } else {
                listNode->next = current->next;
                current->next->prev=listNode;
                listNode->prev = current;
                current->next = listNode;		
                current=listNode;

            }
        }
    }
}

 Data * readData(List * list, int index) {
    
     Node * current;
    int read_index=0;
    
    if(list->head==NULL) {
        
        fprintf(stderr,"The list is empty !!\n");
        return NULL;
    }
    
    current=list->head;
    if(current->next == NULL)
        return &(current->data);
    else {
        if(index == 0)
            return &(current->data);
        else {
            while(current->next != NULL && read_index!=index) {
                
                current=current->next;
                read_index++;
            }
            if(read_index < index)
                return NULL;
            return &(current->data);
        }
    }
}



void removeData(List * list, int index) {
   
     Node * deleteNode;
     Node * current;
    int deleteIndex=1,returnValue=-1;
    
    if(list->head == NULL) {
        
        fprintf(stderr,"Cannot delete. List is empty !!\n");
       
    }
    
    if(list->head->next == NULL) {
        
        deleteNode=list->head;
        returnValue=list->head->data.value;
        list->head=NULL;
        list->tail=NULL;
        free(deleteNode);
        deleteNode=NULL;
        
        
    } else {
        
        if(index == 0) {
            deleteNode=list->head;
            list->head=list->head->next;
            returnValue=deleteNode->data.value;
            list->head->prev=NULL;
            free(deleteNode);
            deleteNode=NULL;
           
            
        } else {
            
            current=list->head;
            
            while(current->next->next!=NULL && deleteIndex!=index) {
                current=current->next;
                deleteIndex++;
                
            }
            
            if(current->next == NULL){
                printf("Cannot delete value as Index is Out of Bounds\n");
               
            }
            
            if(current->next->next == NULL){
                deleteNode=current->next;
                returnValue = deleteNode->data.value;
                current->next=NULL;
                list->tail=current;
                free(deleteNode);
                deleteNode=NULL;
            }
            else{			
                deleteNode=current->next;
                returnValue = deleteNode->data.value;
                current->next=deleteNode->next;
                deleteNode->next->prev = current;
                free(deleteNode);
                deleteNode=NULL;
            }
        }
       
    }
}

void deleteList(List * list) {
    free(list);
    list = NULL;
}




List * newList() {
    
     List * newList = malloc(sizeof(List));
    
    if(newList == NULL){
        printf("Not enough space in Memory\n");
        exit(-1);
    }	
    
    newList->head = NULL;
    newList->tail = NULL;
    newList->insert=insertData;
    newList->remove=removeData;
    newList->read=readData;
    newList->delete=deleteList;
    return newList;
}

