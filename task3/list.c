#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


void init_list(StringList *list) {
    list->capacity = 10;
    list->size = 0;
    list->items = malloc(list->capacity * sizeof(char *));
}


void add_to_list(StringList *list, const char *str) {
    if (list->size >= list->capacity) {
        list->capacity *= 2;
        char **new_items = realloc(list->items, list->capacity * sizeof(char *));
        list->items = new_items;
    }
    

    list->items[list->size] = malloc(strlen(str) + 1);
    strcpy(list->items[list->size], str);
    list->size++;
}


void sort_list(StringList *list) {
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            if (strcmp(list->items[j], list->items[j + 1]) > 0) {
                char *temp = list->items[j];
                list->items[j] = list->items[j + 1];
                list->items[j + 1] = temp;
            }
        }
    }
}

void reverse_list(StringList *list){
    int left = 0;
    int right = list->size-1;
    while (left < right){
        char *temp = list->items[left];
        list->items[left] = list->items[right];
        list->items[right] = temp;
        left++;
        right --;
    }
}


void print_list(const StringList *list) {
    printf("Длина списка: %d\n Элементы: ", list->size);
    for (int i = 0; i < list->size; i++) {
        printf("%s ", list->items[i]);
    }
    printf("\n");
}


void free_list(StringList *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    free(list->items);
    list->items = NULL;
    list->size = 0;
    list->capacity = 0;
}