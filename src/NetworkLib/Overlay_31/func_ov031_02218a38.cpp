#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_02218a38_2 { char* name; char* value; };
struct Struct_ov031_02218a38 { Struct_ov031_02218a38_2* entries; int capacity; int count; };
typedef char* (*Type_ov031_02218a38)(const char*, unsigned int);
typedef void (*Type_ov031_02218a38_2)(const char*, char*, int);
#if defined(jpn)
#define data_ov031_02249f40 data_ov031_0224ab40
#define data_ov031_02249f60 data_ov031_0224ab60
#define data_ov031_02249f80 data_ov031_0224ab80
#define data_ov031_02249f9c data_ov031_0224ab9c
#endif
extern char data_ov031_02249f40[];
extern char data_ov031_02249f60[];
extern char data_ov031_02249f80[];
extern char data_ov031_02249f9c[];

// USA: func_ov031_02218a38
extern "C" ARM int func_ov031_02218a38(void* allocator, Struct_ov031_02218a38* list, const char* name, const char* value) {
    Type_ov031_02218a38 var0 = *(Type_ov031_02218a38*)((char*)allocator + 0x1010);
    Type_ov031_02218a38_2 var1 = *(Type_ov031_02218a38_2*)((char*)allocator + 0x1014);
    if (list->count > list->capacity) return 0;
    list->entries[list->count].name = var0(data_ov031_02249f40, strlen(name) + 1);
    if (list->entries[list->count].name != NULL) {
        list->entries[list->count].value = var0(data_ov031_02249f60, strlen(value) + 1);
        if (list->entries[list->count].value != NULL) {
            strcpy(list->entries[list->count].name, name);
            strcpy(list->entries[list->count].value, value);
            list->count++;
            return 1;
        }
    }
    if (list->entries[list->count].name != NULL) {
        var1(data_ov031_02249f80, list->entries[list->count].name, 0);
        list->entries[list->count].name = NULL;
    }
    Struct_ov031_02218a38_2* entries = list->entries;
    int count = list->count;
    if (entries[count].value != NULL) {
        var1(data_ov031_02249f9c, entries[count].value, 0);
        list->entries[list->count].value = NULL;
    }
    return 0;
}
