#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void free_list(struct node *first) {
    struct node *it = first;
    while (it != NULL) {
        struct node *to_delete = it;
        // We need to access the data inside this node before freeing it
        it = it->next;
        // Now, we are done with it
        free(to_delete);
    }
}

void print_list(struct node *first) {
    printf("{");
    for (struct node *it = first; it != NULL; it = it->next) {
        if (it != first)
            printf(",");
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
    // Making ourlist NULL does not free what it originally points to
    free_list(ourlist);
}
