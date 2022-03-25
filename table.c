#include <stdio.h>
#include <stdlib.h>

typedef struct hashTable {
  int array[13];
  int hashMod;
} hasht;

typedef struct hashEntry {
  int key;
} entry;

int main(int argc, char *argv[]) {

  hasht *me;
  me->hashMod = 7;

  entry **e;
  e[0]->key = 13;

  printf("%d\n", e[0]->key);

  return 0;
}
