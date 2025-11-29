#ifndef LIST_H
#define LIST_H


typedef struct {
    char **items;     
    int capacity;     
    int size;         
} StringList;


void init_list(StringList *list);
void add_to_list(StringList *list, const char *str);
void sort_list(StringList *list);
void print_list(const StringList *list);
void free_list(StringList *list);
void reverse_list(StringList *list);

#endif