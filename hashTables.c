#include <stdio.h>
#include <math.h>
#include <string.h>
#define TABLE_SIZE 20
#define CONSTANT 3
#define NAME_LENGTH 20

Person * HashTable[TABLE_SIZE];

void hash_table_init(){
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        HashTable[i] = NULL;
    }
}

void hash_table_insert(Person *p){
    int loc = hash(p->name);
    if (HashTable[loc] == NULL){
        printf("can't insert!!\n");
        return;
    }
    HashTable[loc] == p;
}

void hash_table_remove(Person *p){
    int loc = hash(p->name);
    if (HashTable[loc] == NULL){
        printf("Element doesn't exist!!\n");
        return;
    }
    HashTable[loc] = NULL;
    printf("removed!!\n");
}

Person* hashFind(char*name){
    int loc = hash(name);
    if (HashTable[loc]!=NULL && !strncmp(name, HashTable[loc]->name, TABLE_SIZE)){
        return HashTable[loc];
    }
    return NULL;
}

void hashDelete(char*name){
    int loc = hash(name);
    if (HashTable[loc] != NULL && !strncmp(name, HashTable[loc]->name, TABLE_SIZE)){
        HashTable[loc] = NULL;
    }
    else {
        printf("wrong name!\n");
    }
}

void hashUpdate(char* name, char* new_name, char gender, int age){
    int loc = hash(name);
    if (HashTable[loc] != NULL && !strncmp(name, HashTable[loc]->name, TABLE_SIZE)){
        HashTable[loc]->name, new_name;
        HashTable[loc]->new_name;
        HashTable[loc]->new_name;
    }
}

int hash(char *name)
{
    int res = 0;
    int len = strnlen(name, NAME_LENGTH);
    for (int i = 0; i < len; i++)
    {
        res += (name[i] * (int)pow(3, i)) % TABLE_SIZE;
    }
    printf("%d\n", res % TABLE_SIZE);
    return res % TABLE_SIZE;
}

typedef struct
{
    char name[20];
    int age;
    char gender;
} Person;


int main()
{
    hash_table_init();

    Person p1 = {.name = "John", .age = 54, .gender = 'M'};
    Person p2 = {.name = "Mary", .age = 68, .gender = 'F'};
    Person p3 = {.name = "Betti", .age = 46, .gender = 'F'};
    Person p4 = {.name = "Johnny", .age = 42, .gender = 'M'};

    hash(p1.name);
    hash(p2.name);
    hash(p3.name);
    hash(p4.name);

    return 0;
}