#include <globaldefs.h>

#if defined(jpn)
#define func_ov012_0218a2b8 func_ov012_0218ad7c
#endif

struct Struct_02072a68 {
    short unknown_0_;
    void* unknown_4_;
};

struct Struct_02072a68_2 {
    struct Struct_02072a68* unknown_0_;
    short unknown_4_;
};

int MessageSystem_GetInstance();
int FormatCombatLogSuffix02041dd0(char* buf, int index);
void* FindEntryByKey_02072a68(struct TableA68* table, int key);
int Text_AppendNTag(char* dst, int n, const char* name);
extern "C" int Font_GetTextWidth(char* str, int id);
int AppendXYTag_02041a90(char* dst, int x, int y);
int Text_Append(char* dst, const char* src);
#if defined(jpn)
struct Struct_020465c0;
extern "C" void func_020465c0(struct Struct_020465c0* arg0, int arg1, int arg2);
extern "C" void func_020465f0(unsigned char* arg0, int arg1, unsigned char arg2);
extern "C" void func_020465d8(unsigned char* arg0, int arg1, unsigned char arg2);
extern "C" void func_02042428(char* arg0, int arg1);
#endif

// USA: func_ov012_0218a2b8
extern "C" ARM void func_ov012_0218a2b8(unsigned char* arg0, char* arg1) {
    if (arg1 == 0) return;
#if defined(jpn)
    struct StoreStruct* base = (struct StoreStruct*)MessageSystem_GetInstance();
    StoreInArray0x8b0_020465c0(base, 0, self[0x1456]);
    SetByteInRange_020465f0((unsigned char*)base, 0, 2);
    SetByteAtIndex_020465d8((unsigned char*)base, 0, 1);
    func_02042428(dst, 0xc);
    if (self[0x1341] == 8) {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x68);
        Text_AppendNTag(dst, 0, (const char*)name);
    } else {
        void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x1314), 0x65);
        Text_AppendNTag(dst, 0, (const char*)name);
    }
#else
    MessageSystem_GetInstance();

    if (arg0[0x1371] == 8) {
        func_02041dd0(arg1, 4);
    }

    void* name = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), (short)(self[0x13fe] + 0x13));
    Text_AppendNTag(dst, 0, (const char*)name);

    if (arg0[0x1371] == 8) {
        func_02041dd0(arg1, 0);
    }

    void* str = FindEntryByKey_02072a68((struct TableA68*)(self + 0x133c), 0x29);
    int len = Font_GetTextWidth((char*)str, 0);
    AppendXYTag_02041a90(dst, (0x48 - len) >> 1, 1);
    Text_Append(dst, (const char*)str);
#endif
}
