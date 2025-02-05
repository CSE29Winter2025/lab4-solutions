#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NOTE: This is only one of many possible solutions.
char *getQueries(char *url) {
    // Don't allocate space for the entire lowercased URL here

    // search for ?
    char *ptr = url;
    while (*ptr != '?' && *ptr != 0) {
        ptr++;
    }
    // Skip the ? if found
    if (*ptr == '?') {
        ptr++;
    }
    // Now, ptr should point right after the ? or to '\0'

    // make our lowercase *query* string
    char *query = malloc(strlen(ptr) + 1);
    for (int i = 0; i < strlen(ptr); i++) {
        query[i] = tolower(ptr[i]);
    }
    query[strlen(url)] = '\0';

    // return the query string instead of the entire string
    return query;
}

int main(int argc, char *argv[]) {
    char s[] = "https://example.com/over/there?Name=Ferret";

    char *queries = getQueries(s);
    printf("%s\n", queries);

    // getQueries must return something on the heap that is "alive" after it returns, so
    // main has to free it
    free(queries);

    return 0;
}
