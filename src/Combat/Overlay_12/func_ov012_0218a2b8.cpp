#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218a2b8 func_ov012_0218ad7c
#endif

struct Struct_02072a68 {
    short key;
    void* value;
};

struct TableA68 {
    struct Struct_02072a68* entries;
    short count;
};

extern "C" int MessageSystem_GetInstance();
extern "C" int func_02041dd0(char* buf, int index);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" int func_02041a90(char* dst, int x, int y);
extern "C" int Text_Append(char* dst, const char* src);
#if defined(jpn)
struct StoreStruct;
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" void func_02042428(char* dst, int size);
#endif

// USA: func_ov012_0218a2b8
extern "C" ARM void func_ov012_0218a2b8(unsigned char* self, char* dst) {
    if (dst == 0) return;
#if defined(jpn)
    struct StoreStruct* base = (struct StoreStruct*)MessageSystem_GetInstance();
    func_020465c0(base, 0, self[0x1456]);
    func_020465f0((unsigned char*)base, 0, 2);
    func_020465d8((unsigned char*)base, 0, 1);
    func_02042428(dst, 0xc);
    if (self[0x1341] == 8) {
        void* name = func_02072a68((struct TableA68*)(self + 0x1314), 0x68);
        Text_AppendNTag(dst, 0, (const char*)name);
    } else {
        void* name = func_02072a68((struct TableA68*)(self + 0x1314), 0x65);
        Text_AppendNTag(dst, 0, (const char*)name);
    }
#else
    MessageSystem_GetInstance();

    if (self[0x1371] == 8) {
        func_02041dd0(dst, 4);
    }

    void* name = func_02072a68((struct TableA68*)(self + 0x133c), (short)(self[0x13fe] + 0x13));
    Text_AppendNTag(dst, 0, (const char*)name);

    if (self[0x1371] == 8) {
        func_02041dd0(dst, 0);
    }

    void* str = func_02072a68((struct TableA68*)(self + 0x133c), 0x29);
    int len = Font_GetTextWidth((char*)str, 0);
    func_02041a90(dst, (0x48 - len) >> 1, 1);
    Text_Append(dst, (const char*)str);
#endif
}
