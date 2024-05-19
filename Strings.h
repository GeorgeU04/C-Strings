#ifndef STRINGS_STRINGS_H
#define STRINGS_STRINGS_H

#include <stdbool.h>
#include <stdlib.h>

char *init_string(char *str);

bool is_empty(char *str);

void clear(char *str);

void popback(char *str);

void string_cpy(char *dest, const char *str);

void string_cat(char *dest, const char *str);

int32_t length(const char *str);

char at(const char *str, int32_t index);

void append(char *str1, const char *str2);

bool compare(const char *str1, const char *str2);

char *substr(const char *str, int32_t begin, int32_t end);

int32_t find(char *str, const char *substr);

void replace(char *str1, const char *str2, int32_t index);

void insert(char *str1, const char *str2, int32_t index);

void erase(char *str1, int32_t begin, int32_t end);

void reverse(char *str);

#endif // STRINGS_STRINGS_H
