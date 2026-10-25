#include <globaldefs.h>

struct UnkStruct0205c508;
void ComputeProductSums0205c508(struct UnkStruct0205c508* s, int* out1, int* out2);
struct Container020e0310;
char* KeyTable_Get(struct Container020e0310* c, int key);
int IsField0x118Equal2_ov000_0217542c(void* obj);
int Text_AppendFrameTag(char* dst, int a1, int a2, int a3, int a4, int a5);
int Text_AppendCursorTag(char* dst, int cursor);
void* GetPointerField_02171b9c_02171b9c(void* obj, int idx);
int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" void __clear(void* buf, int n);
int Text_Append(char* dst, const char* src);
#if defined(jpn)
extern "C" int func_02042158(char* arg0, int arg1);
#define func_02041acc func_02042158
#else
extern "C" int func_02041acc(char* arg0, int arg1);
#endif
extern "C" void func_0206819c(const char* arg0, char* arg1, int arg2);

#if defined(jpn)
#define data_ov000_02184069 data_ov000_021851a9
#endif
extern char data_ov000_02184069[];

struct Struct_ov000_0217979c {
    int unknown_0_;
    const char* unknown_4_;
    unsigned int unknown_8_0_ : 4;
};

struct Struct_ov000_0217979c_2 {
    char unknown_0_[0x22];
    signed char unknown_22_;
};

// USA: func_ov000_0217979c
extern "C" ARM void func_ov000_0217979c(char* arg0, struct Struct_ov000_0217979c_2* arg1, char* arg2) {
    if (arg1 == NULL || arg2 == NULL) {
        return;
    }
    int var0;
    int var1;
    func_0205c508((struct Struct_0205c508*)(arg0 + 0x1dc), &var0, &var1);
    signed char var2 = var0;
    signed char var3 = var1;
    signed char var4 = arg1->unknown_22_;
#if !defined(jpn)
    char* prefix = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x13);
    char* separator = KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0);
#endif
    if (IsField0x118Equal2_ov000_0217542c(obj)) {
        Text_AppendFrameTag(dst, cursor - start, 8, 5, 5, 5);
    }
    Text_AppendCursorTag(dst, cursor - start);
    for (signed char i = start; i < end; i++) {
        struct ListItem0217979c* item = (struct ListItem0217979c*)GetPointerField_02171b9c_02171b9c(list, i);
        if (item == NULL) {
            Text_AppendNTag(dst, i - start, data_ov000_02184069);
            continue;
        }
        char var9[0x80];
        __clear(var9, 0x80);
        int var10 = var8->unknown_8_0_ <= 7;
        if (var10) {
#if defined(jpn)
            Text_Append(text, KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0x13));
#else
            Text_Append(text, prefix);
            AppendWidthTag_02041acc(text, 3);
#endif
        } else {
            func_02041acc(var9, 8);
        }
#if defined(jpn)
        Text_Append(text, item->name);
#else
        char name[0x100];
        __clear(name, 0x100);
        CopyTextAndUppercaseIfFlagged0206819c(item->name, name, 0);
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
