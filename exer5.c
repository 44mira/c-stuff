#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 100
#define EXIT 1
#define CONTINUE 0
#define TRUE 1
#define FALSE 0

void toPigLatin(char *src, char *dest);
int isVowel(char letter);

int main(void) {
  // Create a string buffer for the input
  char buffer[BUFFER_SIZE];

  printf("This program converts a given word into its Pig Latin form\n");

  // Loop until user decides to exit
  int exit_flag;
  do {
    printf("Please type in the word: ");
    scanf("%s", buffer);

    toPigLatin(buffer, buffer);
    printf("Pig Latin form: %s\n", buffer);

    // Check if the user wants to loop again
    while (1) {
      printf("Would you like to try again, yes or no? ");
      scanf("%s", buffer);

      if (strcmp(buffer, "no") == 0) {
        exit_flag = EXIT;
        break;
      } else if (strcmp(buffer, "yes") == 0) {
        exit_flag = CONTINUE;
        break;
      };

      printf("Invalid input, type either yes or no!");
    }

  } while (exit_flag == CONTINUE);

  return 0;
}

int isVowel(char letter) {
  const char VOWELS[] = "aeiou";
  letter = tolower(letter); // normalize input

  for (int i = 0; i < 5; i++) {
    if (letter == VOWELS[i])
      return TRUE;
  }
  return FALSE;
}

void toPigLatin(char *src, char *dest) {
  /**
   * Takes a pointer `source` to a string to be converted to pig Latin, then
   * writes in the destination pointer `dest`.
   */

  // Pig Latin takes the first consonant cluster and puts it at the end of the
  // string
  char consonant_buffer[BUFFER_SIZE];
  int i = 0;

  // Collect first consonant cluster
  while (i < BUFFER_SIZE && !isVowel(*(src + i))) {
    consonant_buffer[i] = *(src + i);
    i++;
  }
  consonant_buffer[i] = '\0';

  // If no consonants are found, append "way" to the word
  if (i == 0) {
    dest = strncpy(dest, src, BUFFER_SIZE);
    strncat(dest, "way", 5);
    return;
  }

  // Move the first consonant cluster to the end of the string, and then append
  // "ay"
  dest = strncpy(dest, src + i, BUFFER_SIZE);
  strncat(dest, consonant_buffer, i);
  strncat(dest, "ay", 5);
}
