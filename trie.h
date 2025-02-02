/*------------------ Trie Data Structure ----------------------------------*/
/*------------- Implemented for search a word in dictionary ---------------*/
/*----- character - 97 used for get the character from the ASCII value -----*/
// https://github.com/TheAlgorithms/C/

// needed for strnlen
#define _POSIX_C_SOURCE 200809L

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

/*--Node in the Trie--*/
struct trie {
  struct trie *children[ALPHABET_SIZE];
  bool end_of_word;
};

/*--Create new trie node--*/
int trie_new(struct trie **trie);
/*--Insert new word to Trie--*/
int trie_insert(struct trie *trie, char *word, unsigned word_len);
/*--Search a word in the Trie--*/
int trie_search(struct trie *trie, char *word, unsigned word_len, struct trie **result);
/*---Return all the related words------*/
void trie_print(struct trie *trie, char prefix[], unsigned prefix_len);
