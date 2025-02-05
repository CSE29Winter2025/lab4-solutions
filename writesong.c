#include <stdio.h>

int main() {
    FILE *mysong = fopen("mysong.txt", "w");

    for (int i; i < 30; ++i) {
        fprintf(mysong, "%d pointer%s on the -Wall...\n", i, i == 1 ? "" : "s");
    }

    fclose(mysong);
}
