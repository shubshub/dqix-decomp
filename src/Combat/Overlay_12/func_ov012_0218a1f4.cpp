#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218a1f4 func_ov012_0218ae20
#endif

struct Struct_02072a68 {
    short key;
    void* value;
};

struct TableA68 {
    struct Struct_02072a68* entries;
    short count;
};

struct StoreStruct {
    char pad[0x8b0];
    int arr[0x10];
};

extern "C" int MessageSystem_GetInstance();
extern "C" void func_020465c0(struct StoreStruct* base, int index, int value);
extern "C" void func_020465f0(unsigned char* base, int index, unsigned char value);
extern "C" void func_020465d8(unsigned char* base, int index, unsigned char value);
extern "C" int func_02041d9c(char* dst, int size);
extern "C" void* func_02072a68(struct TableA68* table, int key);
extern "C" int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Font_GetTextWidth(char* str, int id);
extern "C" int func_02041a90(char* dst, int x, int y);
extern "C" int Text_Append(char* dst, const char* src);
#if defined(jpn)
extern "C" void func_02042428(char* dst, int size);
#endif

// USA: func_ov012_0218a1f4
extern "C" ARM void func_ov012_0218a1f4(unsigned char* self, char* dst) {
    if (dst == 0) return;

    struct StoreStruct* base = (struct StoreStruct*)MessageSystem_GetInstance();
#if defined(jpn)
    func_020465c0(base, 0, self[0x1457]);
    func_020465f0((unsigned char*)base, 0, 2);
    func_020465d8((unsigned char*)base, 0, 1);
    func_02042428(dst, 0xc);
    if (self[0x1341] == 9) {
        void* name = func_02072a68((struct TableA68*)(self + 0x1314), 0x69);
        Text_AppendNTag(dst, 0, (const char*)name);
    } else {
        void* name = func_02072a68((struct TableA68*)(self + 0x1314), 0x66);
        Text_AppendNTag(dst, 0, (const char*)name);
    }
#else
    func_020465c0(base, 0, *(unsigned short*)(self + 0x13fc));
    func_020465f0((unsigned char*)base, 0, 4);
    func_020465d8((unsigned char*)base, 0, 1);

    func_02041d9c(dst, 0xc);

    int key = 0x64;
    if (self[0x1371] == 7) key = 0x67;
    void* name = func_02072a68((struct TableA68*)(self + 0x133c), key);
    Text_AppendNTag(dst, 0, (const char*)name);

    void* str = func_02072a68((struct TableA68*)(self + 0x133c), 0x2a);
    int len = Font_GetTextWidth((char*)str, 0);
    func_02041a90(dst, (0x60 - len) >> 1, 1);
    Text_Append(dst, (const char*)str);
#endif
}
