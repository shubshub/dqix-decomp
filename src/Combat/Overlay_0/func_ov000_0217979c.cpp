#include <globaldefs.h>

struct Struct_0205c508;
extern "C" void func_0205c508(struct Struct_0205c508* s, int* out1, int* out2);
struct Container020e0310;
extern "C" char* KeyTable_Get(struct Container020e0310* c, int key);
extern "C" int func_ov000_0217542c(void* obj);
extern "C" int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
extern "C" int Text_AppendCursorTag(char* dst, int cursor);
extern "C" void* func_ov000_02171b9c(void* obj, int idx);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);
extern "C" int Text_Append(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* dst, int w);
#define func_02041acc func_02042158
#else
extern "C" int func_02041acc(char* dst, int w);
#endif
extern "C" void func_0206819c(const char* src, char* dst, int flag);

#if defined(jpn)
#define data_ov000_02184069 data_ov000_021851a9
#endif
extern char data_ov000_02184069[];

struct Struct_ov000_0217979c {
    int field_0x0;
    const char* name;
    unsigned int kind : 4;
};

struct Struct_ov000_0217979c_2 {
    char pad0[0x22];
    signed char cursor;
};

// USA: func_ov000_0217979c
extern "C" ARM void func_ov000_0217979c(char* obj, struct Struct_ov000_0217979c_2* list, char* dst) {
    if (list == NULL || dst == NULL) {
        return;
    }
    int first;
    int last;
    func_0205c508((struct Struct_0205c508*)(obj + 0x1dc), &first, &last);
    signed char start = first;
    signed char end = last;
    signed char cursor = list->cursor;
#if !defined(jpn)
    char* prefix = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x13);
    char* separator = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0);
#endif
    if (func_ov000_0217542c(obj)) {
        Text_AppendFrameTag(dst, cursor - start, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        struct Struct_ov000_0217979c* item = (struct Struct_ov000_0217979c*)func_ov000_02171b9c(list, i);
        if (item == NULL) {
            Text_AppendNTag(dst, i - start, data_ov000_02184069);
            continue;
        }
        char text[0x80];
        __clear(text, 0x80);
        int var10 = item->kind <= 7;
        if (var10) {
#if defined(jpn)
            Text_Append(text, KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x13));
#else
            Text_Append(text, prefix);
            func_02041acc(text, 3);
#endif
        } else {
            func_02041acc(text, 8);
        }
#if defined(jpn)
        Text_Append(text, item->name);
#else
        char name[0x100];
        __clear(name, 0x100);
        func_0206819c(item->name, name, 0);
        Text_Append(text, name);
#endif
        Text_AppendNTag(dst, i - start, text);
        if (i != end - 1) {
#if defined(jpn)
            Text_Append(dst, KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
#else
            Text_Append(dst, separator);
#endif
        }
    }
}
