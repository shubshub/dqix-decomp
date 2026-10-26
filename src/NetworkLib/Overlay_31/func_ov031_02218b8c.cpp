#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Memory.h"

struct Struct_ov031_02218b8c { char* name; char* value; };
struct Struct_ov031_02218b8c_2 { Struct_ov031_02218b8c* entries; int capacity; int count; };
extern char data_ov031_02249df8[];
extern char data_ov031_02249fb8[];
extern char data_ov031_02249fbc[];
extern char data_ov031_02249fc8[];
extern char data_ov031_02249e28[];
extern char data_ov031_02249fcc[];
extern char data_ov031_02249fd0[];
extern char data_ov031_02249fd4[];
extern "C" int func_ov031_02218a38(void* allocator, Struct_ov031_02218b8c_2* list, const char* name, const char* value);

// USA: func_ov031_02218b8c
extern "C" ARM int func_ov031_02218b8c(void* self, int mode) {
    Struct_ov031_02218b8c_2 list;
    char* text;
    char* body;
    char* end;
    char* status;
    char var5;
    char var6;
    char* var7;
    char var8;
    char* line;
    char* var10;
    char* var11;
    char* param;
    char var13;
    char* var14;
    char* var15;
    char* var16;
    int length;
    list.entries = (Struct_ov031_02218b8c*)((char*)self + 0x1000 + 0xa38);
    list.capacity = 0x20;
    list.count = 0;
    VectorizedMemset(list.entries, 0, 0x100);
    text = *(char**)((char*)self + 0x1000 + 0xa08);
    body = strstr(text, data_ov031_02249df8);
    if (body == NULL) return 0;
    end = body + 4 + strlen(body + 4);
    status = strstr(text, data_ov031_02249fb8);
    if (status == NULL) return 0;
    var5 = status[4];
    status[4] = 0;
    if (func_ov031_02218a38(self, &list, data_ov031_02249fbc, status + 1) != 1) {
        status[4] = var5;
        return 0;
    }
    status[4] = var5;
    if (mode == 1 || strncmp(status + 1, data_ov031_02249fc8, 3) != 0) return 1;
    line = strstr(status + 5, data_ov031_02249e28);
    if (line == NULL) return 0;
    line += 2;
    while (line[0] != '\r' && line[1] != '\n') {
        var15 = strstr(line, data_ov031_02249fcc);
        if (var15 == NULL) break;
        var6 = *var15;
        var10 = var15 + 2;
        *var15 = 0;
        var16 = strstr(var10, data_ov031_02249e28);
        if (var16 == NULL) {
            *var15 = var6;
            break;
        }
        var8 = *var16;
        *var16 = 0;
        if (func_ov031_02218a38(self, &list, line, var10) != 1) {
            *var15 = var6;
            *var16 = var8;
            return 0;
        }
        length = strlen(var10);
        *var15 = var6;
        *var16 = var8;
        line = var10 + length + 2;
    }
    param = body + 4;
    if (param < end) do {
        var7 = strstr(param, data_ov031_02249fd0);
        if (var7 == NULL) break;
        var13 = *var7;
        var11 = var7 + 1;
        *var7 = 0;
        var14 = strstr(var11, data_ov031_02249fd4);
        if (var14 == NULL) var14 = strstr(var11, data_ov031_02249e28);
        if (var14 != NULL) {
            var8 = *var14;
            *var14 = 0;
        }
        if (func_ov031_02218a38(self, &list, param, var11) != 1) {
            *var7 = var13;
            if (var14 != NULL) *var14 = var8;
            return 0;
        }
        length = strlen(var11);
        *var7 = var13;
        if (var14 != NULL) *var14 = var8;
        param = var11 + length + 1;
    } while (param < end);
    return 1;
}
