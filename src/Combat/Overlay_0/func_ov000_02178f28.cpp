#include <globaldefs.h>

struct Struct_0205c508;
extern "C" void func_0205c508(struct Struct_0205c508* s, int* out1, int* out2);

extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" int func_ov000_02171674(void* obj, int index);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
struct Container020e0310;
extern "C" int KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int Text_Append(char* dst, const char* src);

struct Struct_ov000_02178f28 {
    char pad[0x20];
    signed char cursor;
};

// USA: func_ov000_02178f28
extern "C" ARM void func_ov000_02178f28(char* obj, struct Struct_ov000_02178f28* entry, char* dst) {
    if (entry != NULL && dst != NULL) {
        int a, b;
        func_0205c508((struct Struct_0205c508*)(obj + 0x1dc), &a, &b);
        signed char first = a;
        signed char last = b;
        signed char cursor = entry->cursor;
        if (func_ov000_0217542c(obj)) {
            Text_AppendFrameTag(dst, cursor - first, 8, 5, 5, 5);
        }
        Text_AppendCursorTag(dst, cursor - first);
        for (signed char i = first; i < last; i++) {
            const char** name = (const char**)func_ov000_02171674(entry, i);
            if (name == NULL) continue;
            Text_AppendNTag(dst, i - first, *name);
            if (i == last - 1) continue;
            Text_Append(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
        }
    }
}
