//
// Created by gjumb on 3/3/2024.
//
#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

// returns length of string
int32_t length(const char *str) {
    int32_t size = 0;
    for (size_t i = 0; str[i] != '\0'; ++i) {
        size++;
    }
    return size;
}

// appends one string to another string
void string_cat(char *dest, const char *str) {
    size_t i;
    size_t dest_len = length(dest);
    size_t j = 0;
    for (i = dest_len; str[j] != '\0'; ++i) {
        dest[i] = str[j++];
    }
    dest[i] = '\0';
}


// copies one string to another string
void string_cpy(char *dest, const char *str) {
    size_t i;
    for (i = 0; str[i] != '\0'; ++i) {
        dest[i] = str[i];
    }
    dest[i] = '\0';
}

// initialize the string
char *init_string(char *str) {
    char *s = (char *) malloc(sizeof(char) * (length(str) + 1));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    string_cpy(s, str);
    return s;
}

// returns a character in the string at a given index
char at(const char *str, int32_t index) {
    if (length(str) <= index || (index < 0 && length(str) < abs(index))) {
        printf("Index out of range");
        exit(EXIT_FAILURE);
    }
    if (index < 0)
        return str[length(str) + index];
    return str[index];
}

// appends one string to another
void append(char *str1, const char *str2) {
    int32_t len1 = length(str1);
    int32_t len2 = length(str2);
    char *temp = (char *) realloc(str1, sizeof(char) * (len1 + len2 + 1));
    if (!temp) {
        printf("Memory allocation failed :(\n");
        free(str1);
        exit(EXIT_FAILURE);
    }
    str1 = temp;
    string_cat(str1 + len1, str2); // Starting from the end of str1
}


// compares two strings and checks if they are the same
bool compare(const char *str1, const char *str2) {
    if (length(str1) != length(str2))
        return false;
    for (size_t i = 0; i < length(str1); ++i) {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

// returns a substring of the original
char *substr(const char *str, int32_t begin, int32_t end) {
    if (begin < 0 || end <= 0) {
        printf("Out of Bounds\n");
        exit(EXIT_FAILURE);
    }
    if (end > length(str)) {
        printf("Out of Bounds\n");
        exit(EXIT_FAILURE);
    }
    char *s = (char *) malloc(sizeof(char) * (end - begin + 2));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    size_t j = 0;
    for (size_t i = begin; i < end; ++i) {
        s[j++] = str[i];
    }
    s[j] = '\0';
    return s;
}

// will find first occurrence of substring in the main string and return -1 if it does not exist
int32_t find(char *str, const char *substr) {
    int32_t str_len = length(str);
    int32_t subLen = length(substr);
    for (size_t i = 0; i <= str_len - subLen; ++i) {
        size_t j;
        for (j = 0; j < subLen; j++) {
            if (str[i + j] != substr[j])
                break;
        }
        if (j == subLen)
            return (int32_t) i;
    }
    return -1;
}

// replaces a given amount of characters in a string with the characters in a provided substring
void replace(char *str1, const char *str2, int32_t index) {
    int32_t len1 = length(str1);
    int32_t len2 = length(str2);
    if (index < 0 || index + len2 > len1) {
        printf("Out of Bounds\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < length(str2); ++i) {
        str1[i + index] = str2[i];
    }
}

// inserts a string into the index of another string
void insert(char *str1, const char *str2, int32_t index) {
    int32_t len = length(str1);
    int32_t len2 = length(str2);
    char *temp = (char *) realloc(str1, sizeof(char) * (length(str1) + length(str2) + 1));
    if (!temp) {
        printf("Memory allocation failed :(\n");
        free(str1);
        exit(EXIT_FAILURE);
    }
    for (size_t i = len; i >= index; --i) {
        str1[i + len2] = str1[i];
    }

    for (size_t i = 0; i < len2; ++i) {
        str1[index + i] = str2[i];
    }
}

// removes a given amount of characters from the string indicated by the beginning and end parameters
void erase(char *str1, int32_t begin, int32_t end) {
    int32_t len1 = length(str1);
    if (begin < 0 || begin >= len1 || end < 0 || begin + end > len1) {
        printf("Out of Bounds\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = begin; i < len1 - end + 1; ++i) {
        str1[i] = str1[i + end];
    }

    str1[len1 - end ] = '\0';
}

// reverses a given string
void reverse(char* str){
    int32_t len = length(str);
    char swap;
    for(size_t i = 0; i < len/2; ++i){
        swap = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = swap;
    }
}
