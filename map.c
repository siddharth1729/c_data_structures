#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node
{
    int index;
    char* keys;
    int* values;
};

struct map
{
    int index;
    char** list_keys;
    struct node keys[100];
};


void map_append(struct map* map, char* key, int value)
{
    bool found = false;
    int found_in = 0;

    for(unsigned int i = 0; i<map->index; i++) { if(strcmp(map->list_keys[i], key) == 0) { found=true; found_in=i;} }

    if(!found)
    {
        map->keys[map->index].keys = (char*)malloc(100 * sizeof(char));

        strcpy(map->keys[map->index].keys, key);
        map->keys[map->index].keys[strlen(key)] = '\0';

        strcpy(map->list_keys[map->index], key);

        map->keys[map->index].values = (int*)malloc(100 * sizeof(int));

        map->keys[map->index].values[0] = value;
        map->keys[map->index].index = 1;

        map->index++;
    }
    else
    {
        map->keys[found_in].values[map->keys[found_in].index] = value;
        map->keys[found_in].index++;
    }
    
}
void map_pop()
{

}


char** get_keys(struct map* map)
{
    return map->list_keys;
}

int* get_values(struct map* map, char* key)
{

    for (unsigned int i=0; i<map->index; i++)
    {
        if (!strcmp(map->keys[i].keys, key))
        {
            return map->keys[i].values;
        }
    }
    return NULL;
}

struct map map_initialize()
{
    struct map map = {0};

    map.list_keys = (char**)malloc(100 * sizeof(char*));
    for (int i=0; i<100; i++)
    {
        map.list_keys[i] = (char*)malloc(100 * sizeof(char));
    }
    return map;
}


int main()
{
    struct map map = map_initialize();
    map_append(&map, "test", 1);
    map_append(&map, "test", 2000);
    map_append(&map, "another", 200);
    map_append(&map, "and_another", 100000);

    char** keys = get_keys(&map);
    int* values = get_values(&map, "test");

    
    for (int i=0; i<map.index; i++)
    {
        printf("%s\n", keys[i]);
    }
    
    for (int i=0; i<sizeof(values)/sizeof(values[0])+1; i++)
    {
        printf("%d\n", values[i]);
    }

    return EXIT_SUCCESS;
}