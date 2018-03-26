#ifndef BST_H
#define BST_H

typedef struct hash
{
    char ** data;
    unsigned int size;
    int (*insert)(struct Hash *, char *);
    int (*remove)(struct Hash *, char *);
    char * (*find)(struct Hash *, char *);
    void (*print)(struct Hash *);
    int (*hasher)(struct Hash *, char *);
    void (*delete)(struct Hash *);
}Hash;

Hash * newHash(unsigned int size);
int insert(Hash *, char *);
int remove(Hash *, char *);
char * find(Hash *, char *);
void print(Hash *);
int hasher(Hash *, char *);
void delete(Hash *);
char * removeSubstring(char *src,char *key);

#endif