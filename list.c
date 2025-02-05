#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void free_list(struct node *first) {
    struct node *it = first;
    while (it != NULL) {
      free(it);
      it = it->next;
    }
}

void print_list(struct node *first) {
    printf("{");
    for (struct node *it = first; it != NULL; it = it->next) {
        if (it != first) printf(",");
        printf("%d", it->data);
    }
    printf("}\n");
}

struct node *create_29_list(void) {
    struct node *first = malloc(sizeof(struct node));
    struct node *second = malloc(sizeof(struct node));

    first->data = 2;
    second->data = 9;
    first->next = second;
    second->next = NULL;

    return first;
}

int main(void) {
    struct node *ourlist = create_29_list();
    print_list(ourlist);
    ourlist = NULL;
}
