#include "Hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hashval = 0;

Hash *newHash(unsigned int size)
{
  Hash *ht = (Hash *)malloc(sizeof(*ht));
  ht->size = size;
  ht->data = (char **)malloc(sizeof(char *) * size);
  ht->insert = insert;
  ht->remove = remove;
  ht->find = find;
  ht->print = print;
  ht->hasher = hasher;
  ht->delete = delete;
  return ht;
}

int insert(Hash *ht, char *data)
{
  if (ht == NULL || data == NULL)
  {
    return 0;
  }
  int hash = hasher(ht, data);
  ht->data[hash] = data;
  return 1;
}

// Removes the entry from the hash
int remove(Hash *ht, char *data)
{
  ht->data = removeSubstring(ht->data[18], data);
  return 1;
}

// Returns the correct value based on the value parameter and if the value is not found, returns an empty string
char *find(Hash *ht, char *str)
{

  if (ht == NULL || str == NULL)
  {
    return NULL;
  }
  for (; *str != '\0'; str++)
  {
    if (strstr(ht->data[18], str) != NULL)
    {
      return str;
    }
    else
    {
      return NULL;
    }
  }
  return str;
}

// Prints out the index and value of each element in the hash
void print(Hash *ht)
{
  printf("%s\n ", ht->data[18]);
}

// Hash function that determines an index based on the key parameter
int hasher(Hash *ht, char *str)
{
  for (; *str != '\0'; str++)
  {
    hashval = *str + (hashval << 5) - hashval;
  }
  return hashval % ht->size;
}

// Function to cleanup hash memory
void delete (Hash *ht)
{
}

char *removeSubstring(char *src, char *key)
{
  while (*src)
  {
    char *k = key, *s = src;
    while (*k && *k == *s)
    {
      ++k;
      ++s;
    }
    if (!*k)
    {
      while (*s)
      {
        *src++ = *s++;
      }
      *src = 0;
      return 1;
    }
    ++src;
  }
  return *src;
}