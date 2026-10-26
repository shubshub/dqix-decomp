#include <globaldefs.h>

struct Struct_ov023_021db314_2 {
    char pad0[2];
    short limit;
    void* head;
};

struct Struct_ov023_021db314 {
    char pad0[1];
    unsigned char flag1;
    char pad2[2];
    void* target;
};

extern "C" int func_02005a94(signed char* s);
extern "C" int func_ov023_021db564(char* str);

// USA: func_ov023_021db314
extern "C" ARM void func_ov023_021db314(void* obj, short* out, short* outCount) {
    struct Struct_ov023_021db314_2* list = *(struct Struct_ov023_021db314_2**)((char*)obj + 0x8);
    struct Struct_ov023_021db314* entry = (struct Struct_ov023_021db314*)list->head;
    short count = 0;
    short limit = list->limit;

    int i;
    for (i = 0; i < limit; i++, entry = (struct Struct_ov023_021db314*)((char*)entry + 8)) {
        if (entry->flag1 != 0 && entry->target != NULL) {
            signed char* ptr = (signed char*)entry->target;

            if (*ptr == 'f') {
                out[count] = (short)func_02005a94(ptr + 5);
                count++;
            } else if (*ptr >= 'A' && *ptr <= 'Z') {
                unsigned short v = (unsigned short)func_ov023_021db564((char*)ptr);
                if (v != 0) {
                    out[count] = v;
                    count++;
                }
            }
        }
    }

    *outCount = count;
}
