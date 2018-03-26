#include "vector.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void insertVector(Vector * array, int index, Data value){
    if(array->max_size <= index){
        array->max_size=index*2+1;
        Data * new_array= malloc(sizeof(Data)*array->max_size);
        memset(new_array,-1,sizeof(Data) * array->max_size);
        memcpy(new_array, array->data, sizeof(Data)*array->current_size);
        free(array->data);
        array->data=NULL;
        array->data=new_array;
    }
    array->data[index]=value;
    if(index >= array->current_size)
        array->current_size=index+1;
}



Data * readVector(Vector *array, int index){
    if(index<array->current_size && index >=0)
        return (array->data)+index;
    else
        return NULL;
    
}


void removeVector(Vector * array, int index){
    Data * new_arr=NULL;
    if(index < array->current_size){
        new_arr = malloc(sizeof(Data)*array->max_size);
        memcpy(new_arr,array->data,sizeof(Data)*index);
        memcpy(new_arr+index,array->data+index+1,sizeof(Data)*(array->current_size-index));
        free(array->data);
        array->data=NULL;
        array->data=new_arr;
        array->current_size = array->current_size - 1;
    }
 
}

void deleteVector(Vector * array){
    free(array->data);
    array->data=NULL;
    free(array);
    array=NULL;
}


Vector * newVector()
{
    Vector * new = malloc(sizeof(Vector));
    new->current_size=0;
    new->max_size=0;
    new->data=NULL;
    new->insert=insertVector;
    new->read=readVector;
    new->remove=removeVector;
    new->delete=deleteVector;
    return new;
}





//void insertIncrementalVector(Vector * array, int index, Data value){
//    if(array->max_size <= index){
//        array->max_size=index+1;
  //      Data * new_array= malloc(sizeof(Data)*array->max_size);
    //    memset(new_array,-1,sizeof(Data) * array->max_size);
      //  memcpy(new_array, array->data, sizeof(Data)*array->current_size);
        //free(array->data);
    //    array->data=NULL;
      //  array->data=new_array;
    //}
 //   array->data[index]=value;
   // if(index >= array->current_size)
     //   array->current_size=index+1;
//}

//void insertMineVector(Vector * array, int index, Data value){
//    if(array->max_size <= index){
  //      array->max_size=index*3+1;
    //    Data * new_array= malloc(sizeof(Data)*array->max_size);
      //  memset(new_array,-1,sizeof(Data) * array->max_size);
//        memcpy(new_array, array->data, sizeof(Data)*array->current_size);
  //      free(array->data);
    //    array->data=NULL;
      //  array->data=new_array;
    //}
//    array->data[index]=value;
  //  if(index >= array->current_size)
  //      array->current_size=index+1;
//}



