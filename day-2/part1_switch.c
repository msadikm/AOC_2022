// Using switch statements 

#include <stdio.h>

int main() {
    FILE *file;
    int chosen = 0;
    int win = 0;
    char char1, char2;
    int total = 0;

    file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    while (fscanf(file, " %c %c", &char1, &char2) == 2) {
        switch (char2) {
            case 'X':
                chosen += 1;
                break;
            case 'Y':
                chosen += 2;
                break;
            default:
                chosen += 3;
                break;
        }

        switch (char1) {
            case 'A':
                switch (char2) {
                    case 'X':
                        win += 3;
                        break;
                    case 'Z':
                        win += 0;
                        break;
                    default:
                        win += 6;
                        break;
                }
                break;
            case 'B':
                switch (char2) {
                    case 'Y':
                        win += 3;
                        break;
                    case 'X':
                        win += 0;
                        break;
                    default:
                        win += 6;
                        break;
                }
                break;
            case 'C':
                switch (char2) {
                    case 'Z':
                        win += 3;
                        break;
                    case 'Y':
                        win += 0;
                        break;
                    default:
                        win += 6;
                        break;
                }
                break;
        }
    }

    total = chosen + win;
    printf("%d\n", total);

    fclose(file);

    return 0;
}

