#ifndef VECTOR_H
#define VECTOR_H

typedef struct data{
    int value;
    
}Data;

typedef struct vector{
    Data * data;
    int current_size;
    int max_size;
void (*insert)(struct Vector *, int, Data);
Data * (*read)(struct Vector *, int);
void (*remove)(struct Vector * array, int index);
void (*delete)(struct Vector * array);

}Vector;

Vector * newVector();
void insertVector(Vector * v, int i, Data d);
Data * readVector(Vector *array, int index);
void removeVector(Vector * array, int index);
void deleteVector(Vector * array);

#endif


