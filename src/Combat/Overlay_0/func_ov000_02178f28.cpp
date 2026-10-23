#include <globaldefs.h>

struct Struct_0205c508;
extern "C" void func_0205c508(struct Struct_0205c508* arg0, int* arg1, int* arg2);

int IsField0x118Equal2_ov000_0217542c(void* obj);
int AppendFrameTag02041c08(char* dst, int a1, int a2, int a3, int a4, int a5);
int AppendCursorTag_02041ea4(char* dst, int cursor);
int GetBoundedField156_02171674(void* obj, int index);
int AppendNameTag_02041b70(char* dst, int n, const char* name);
struct Container020e0310;
int KeyTable_Get(struct Container020e0310* c, int key);
int AppendString02042058(char* dst, const char* src);

struct Struct_ov000_02178f28 {
    char unknown_0_[0x20];
    signed char unknown_20_;
};

// USA: func_ov000_02178f28
extern "C" ARM void func_ov000_02178f28(char* arg0, struct Struct_ov000_02178f28* arg1, char* arg2) {
    if (arg1 != NULL && arg2 != NULL) {
        int var0, var1;
        func_0205c508((struct Struct_0205c508*)(arg0 + 0x1dc), &var0, &var1);
        signed char var2 = var0;
        signed char var3 = var1;
        signed char var4 = arg1->unknown_20_;
        if (func_ov000_0217542c(arg0)) {
            func_02041c08(arg2, var4 - var2, 8, 5, 5, 5);
        }
        AppendCursorTag_02041ea4(dst, cursor - first);
        for (signed char i = first; i < last; i++) {
            const char** name = (const char**)GetBoundedField156_02171674(entry, i);
            if (name == NULL) continue;
            AppendNameTag_02041b70(dst, i - first, *name);
            if (i == last - 1) continue;
            AppendString02042058(dst, (const char*)KeyTable_Get((struct Container020e0310*)(obj + 0xb8), 0));
        }
    }
}
