#include <stdio.h>

int main() {
  int current_elf_calories = 0;
  int max_calories = 0;
  int calories;

  // Open the file containing data
  FILE *file = fopen("input.txt", "r");

  if (file == NULL) {
    printf("Error opening file.");
    return 1;
  }

  int c;
  while ((c = fgetc(file)) != EOF) {
    if (c == '\n') {
      if ((c = fgetc(file)) == '\n' ||
          c == EOF) { // Check for blank line or end of file
        if (current_elf_calories > max_calories) {
          max_calories = current_elf_calories;
        }
        current_elf_calories = 0;
        if (c == EOF) // Break loop if end of file
          break;
      } else {
        ungetc(c, file); // Put back the character read
        fscanf(file, "%d", &calories);
        current_elf_calories += calories;
      }
    } else {
      ungetc(c, file); // Put back the character read
      fscanf(file, "%d", &calories);
      current_elf_calories += calories;
    }
  }

  fclose(file);

  printf("%d\n", max_calories);

  return 0;
}

