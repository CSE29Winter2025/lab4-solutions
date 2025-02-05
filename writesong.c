#include <stdio.h>

int main() {
    FILE *mysong = fopen("mysong.txt", "w");

    // `i` should be initialized here or else it would take on a garbage value to begin with
    for (int i = 0; i < 30; ++i) {
        fprintf(mysong, "%d pointer%s on the -Wall...\n", i, i == 1 ? "" : "s");
    }

    fclose(mysong);
}
