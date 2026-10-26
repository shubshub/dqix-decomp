#pragma once

#ifdef __cplusplus
extern "C" {
#endif

unsigned int strlen(const char* str);
char* strcpy(char* dst, const char* src);
char* strncpy(char* dst, const char* src, unsigned int count);
int strcmp(const char* lhs, const char* rhs);
int strncmp(const char* lhs, const char* rhs, unsigned int count);
char* strcat(char* dst, const char* src);
char* strchr(const char* str, int ch);

#ifdef __cplusplus
}
#endif
