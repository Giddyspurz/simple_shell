#include "header.h"
/**
 *cmp_char_str - look for a char in a string
 *@_char: char to look for
 *@_str: string
 *Return: 1 if the char is found or 0 on failure
 */
int cmp_char_str(char _char, char *_str)
{
	int i = 0;

	while (_str[i])
	{
		if (_str[i] == _char)
			return (1);
		i++;
	}

	return (0);
}
/**
 *count_words - count the amount of words in a string
 *@str: string
 *@delimiter: delimiter of the strings
 *Return: the amount of the words
 */
int count_words(char *str, char *delimiter)
{
	int i = 0, words = 0;

	while (str[i])
	{
		if (cmp_char_str(str[i], delimiter))
		{
			while (cmp_char_str(str[i], delimiter) && str[i])
				i++;
		}
		else
		{
			while (!cmp_char_str(str[i], delimiter) && str[i])
				i++;
			words++;
		}
	}

	return (words);
}
/**
 *length_word - find the length of word inside a string
 *@str: string
 *@delimiter: delimiter of the words
 *@flag: initial position of the word
 *Return: the length of the word
 */
int length_word(char *str, char *delimiter, int flag)
{
	int i = 0, len = 0;

	while (str[i] && flag >= 0)
	{
		if (cmp_char_str(str[i], delimiter))
		{
			while (cmp_char_str(str[i], delimiter) && str[i])
				i++;
		}
		else
		{
			while (!cmp_char_str(str[i], delimiter) && str[i])
			{
				if (flag == 0)
					len++;
				i++;
			}
			flag--;
		}
	}

	return (len);
}
/**
 *copy_word - copy a word into a new string
 *@str: string with the word
 *@str_tok: new string to save the word
 *@flag: initial position of the word
 *@delimiter: delimiter of the word
 *Return: void
 */
void copy_word(char *str, char *str_tok, int flag, char *delimiter)
{
	int i = 0, j = 0;

	while (str[i] && flag >= 0)
	{
		if (cmp_char_str(str[i], delimiter))
		{
			while (cmp_char_str(str[i], delimiter) && str[i])
				i++;
		}
		else
		{
			while (!cmp_char_str(str[i], delimiter) && str[i])
			{
				if (flag == 0)
					str_tok[j] = str[i], j++;
				i++;
			}
			flag--;
		}
	}
	str_tok[j] = '\0';
}
/**
 *str_tok - split a string into words in an array of string
 *@str: string
 *@delimiter: delimiters of the words
 *Return: An array of string
 */
char **str_tok(char *str, char *delimiter)
{
	int words = 0, i = 0, len = 0, flag = 0;
	char **str_tok = NULL;
	/* 1. count words */
	words = count_words(str, delimiter);
	/* 2. allocate memory for array of strings */
	str_tok = malloc(sizeof(char *) * (words + 1));
	/* 2.1. Check for malloc */
	if (!str_tok)
		return (NULL);
	/* 3. find the every word */
	while (i < words)
	{
		/* 3.1. find the length of the word */
		len = length_word(str, delimiter, flag);
		/* 3.2 Allocate memory for the word */
		str_tok[i] = malloc(sizeof(char) * (len + 1));
		/* 3.3 Check for malloc */
		if (!str_tok[i])
			return (NULL);
		/* 3.4 Copy the word in the allocate memory */
		copy_word(str, str_tok[i], flag, delimiter);
		/* 3.5 Save the position which the new word begins */
		flag++;
		i++;
	}
	str_tok[i] = NULL;

	return (str_tok);
}
