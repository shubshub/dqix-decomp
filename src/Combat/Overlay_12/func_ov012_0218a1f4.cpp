#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218a1f4 func_ov012_0218ae20
#endif

struct Struct_02072a68 {
    short unknown_0_;
    void* unknown_4_;
};

struct Struct_02072a68_2 {
    struct Struct_02072a68* unknown_0_;
    short unknown_4_;
};

struct Struct_020465c0 {
    char unknown_0_[0x8b0];
    int unknown_8b0_[0x10];
};

int MessageSystem_GetInstance();
void StoreInArray0x8b0_020465c0(struct StoreStruct* base, int index, int value);
void SetByteInRange_020465f0(unsigned char* base, int index, unsigned char value);
void SetByteAtIndex_020465d8(unsigned char* base, int index, unsigned char value);
int AppendSizeTag_02041d9c(char* dst, int size);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Font_GetTextWidth(char* str, int id);
int AppendXYTag_02041a90(char* dst, int x, int y);
int Text_Append(char* dst, const char* src);
#if defined(jpn)
extern "C" void func_02042428(char* arg0, int arg1);
#endif

// USA: func_ov012_0218a1f4
extern "C" ARM void func_ov012_0218a1f4(unsigned char* arg0, char* arg1) {
    if (arg1 == 0) return;

    struct StoreStruct* base = (struct StoreStruct*)MessageSystem_GetInstance();
#if defined(jpn)
    StoreInArray0x8b0_020465c0(base, 0, self[0x1457]);
    SetByteInRange_020465f0((unsigned char*)base, 0, 2);
    SetByteAtIndex_020465d8((unsigned char*)base, 0, 1);
    func_02042428(dst, 0xc);
    if (self[0x1341] == 9) {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x69);
        Text_AppendNTag(dst, 0, (const char*)name);
    } else {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x66);
        Text_AppendNTag(dst, 0, (const char*)name);
    }
#else
    func_020465c0(var0, 0, *(unsigned short*)(arg0 + 0x13fc));
    func_020465f0((unsigned char*)var0, 0, 4);
    func_020465d8((unsigned char*)var0, 0, 1);

    func_02041d9c(arg1, 0xc);

    int key = 0x64;
    if (self[0x1371] == 7) key = 0x67;
    void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), key);
    Text_AppendNTag(dst, 0, (const char*)name);

    void* str = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), 0x2a);
    int len = Font_GetTextWidth((char*)str, 0);
    AppendXYTag_02041a90(dst, (0x60 - len) >> 1, 1);
    Text_Append(dst, (const char*)str);
#endif
}
