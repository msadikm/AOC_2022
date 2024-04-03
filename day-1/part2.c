#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 500

// Function to compare integers (required by qsort)
int compare(const void *a, const void *b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	FILE *file;
	char filename[] = "input.txt";
	file = fopen(filename, "r");

	if (file == NULL) {
		perror("Error opening file");
		return 1;
	}

	int values[MAX_VALUES];
	int sum = 0;
	int index = 0;
	char line[100];

	while (fgets(line, sizeof(line), file)) {
		if (line[0] == '\n' || line[0] == '\r') {
			values[index++] = sum;
			sum = 0;
			// Break if we reach the maximum number of rows
			if (index >= MAX_VALUES) {
				break;	
			}	
		} else {
			sum += atoi(line);	
		}	
	}

	fclose(file);

	// Sort using quicksort
	qsort(values, index, sizeof(int), compare);

	// Print the sorted sums
	int top_three_sum = 0;
	for (int i = index - 1; i >= index - 3; i--) {
		if (i >= 0) {
			top_three_sum += values[i];	
		}	
	}
	printf("%d\n", top_three_sum);

	return 0;
}
