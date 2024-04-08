#include <stdio.h>

int main() {
    FILE *file;
		int choosen = 0;
		int win = 0;
		int total = 0;
		char char1, char2, space;
    char line[3];

    file = fopen("input.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Read the file line by line until EOF (End of File)
		while (fscanf(file, " %c %c", &char1, &char2) == 2) {
			if (char2 == 'X') {
				choosen += 1;
			} else if (char2 == 'Y') {
				choosen += 2;	
			} else {
				choosen += 3;	
			}
			
			// A - Rock, B - Paper, C - Scissor
			// X - Rock, Y - Paper, Z - Scissor
			// Rock defeats Scissors, Scissors defeats Paper, Paper defeats Rock
			if ((char1 == 'A' && char2 == 'X') || (char1 == 'B' && char2 == 'Y') || (char1 == 'C' && char2 == 'Z')) {
				win += 3;	
			} else if ((char1 == 'A' && char2 == 'Z') || (char1 == 'B' && char2 == 'X') || (char1 == 'C' && char2 == 'Y')) {
				win += 0;	
			} else {
				win += 6;	
			}
		}

		total += choosen + win;
		printf("%d\n", total);
    fclose(file);

    return 0;
}

