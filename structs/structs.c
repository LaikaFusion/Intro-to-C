#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int string_length(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; ++i);
    return i;
}
/* 
    Define the Person struct by specifying the fields that make up the
    Person type. Don't forget to specify the type of each field. A 
    Person should have the fields `name`, `age`, `height`, and `weight`.
*/
typedef struct Person {
    char *name;
    int age;
    int height;
    int weight;
} Person;

/*
    Creates an instance of the Person struct that receives all the relevant
    pieces of data associated with a Person instance.
    Allocates the appropriate amount of memory to hold an instance of the 
    Person struct, and then sets the struct's fields with the input data.
    When setting the `name` field, use your previously-built string_dup
    function, which handles the allocation of memory for the new string.
*/
 Person *createPerson(char *name, int age, int height, int weight)
{
    printf("%s \n", "test");

    struct Person *a_person = malloc(sizeof( Person));

    a_person->name = malloc(string_length(name));
    a_person->name = strdup( name);

    a_person->age =  age;

    a_person->height=  height;

    a_person->weight = weight;
    
    return a_person;
}

/*
    Given a pointer to a Person struct, frees up the memory that holds the
    Person's name as well as the memory that holds the Person instance.
*/
void destroyPerson(Person *who)
{
        if (who->name != NULL) {
            free(who->name);
        }

        if (who != NULL) {
            free(who);
        }
}

#ifndef TESTING
int main(void)
{
    Person *tony = createPerson("Tony Stark", 32, 64, 140);

    printf("  Name: %s\n", tony->name);
    printf("   Age: %d\n", tony->age);
    printf("Height: %d\n", tony->height);
    printf("Weight: %d\n", tony->weight);

    destroyPerson(tony);

    return 0;
}
#endif