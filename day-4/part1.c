#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int isRangeFullyContained(int start1, int end1, int start2, int end2) {
	return (start1 <= start2 && end1 >= end2) || (start2 <= start1 && end2 >= end1);
}

int main() {
	FILE *file;
	char line[MAX_LINE_LENGTH];

	file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("Failed to open the file.\n");
		return 1;	
	}

	int count = 0;

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
		int start1, end1, start2, end2;

		sscanf(line, "%d-%d,%d-%d", &start1, &end1, &start2, &end2);

		if (isRangeFullyContained(start1, end1, start2, end2) || 
				isRangeFullyContained(start2, end2, start1, end1))	{
				count++;	
		}
	}

	fclose(file);

	printf("%d\n", count);

	return 0;
}
