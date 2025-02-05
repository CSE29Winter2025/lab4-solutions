#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getQueries(char *url) {
  char *query = malloc(sizeof(char) * (strlen(url) + 1));

  // make our lowercase string
  for (int i = 0; i < strlen(url); i++) {
    query[i] = tolower(url[i]);
  }
  query[strlen(url)] = '\0';

  // search for ?
  char *ptr = query;
  while (*ptr != '?' && *ptr != 0) {
    ptr++;
  }
  if (*ptr == '?') {
    return ptr + 1;
  }
  return ptr;
}

int main(int argc, char *argv[]) {
  char s[] = "https://example.com/over/there?name=ferret";

  char *queries = getQueries(s);
  printf("%s\n", queries);

  return 0;
}
