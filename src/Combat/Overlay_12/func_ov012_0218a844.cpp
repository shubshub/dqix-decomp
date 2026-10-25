#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205c508;
struct Struct_0201099c_3;

struct Struct_ov012_0218a844
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_[6];
};

struct Struct_0201099c_22
{
    char unknown_0_[0x54];
    Struct_ov012_0218a844 unknown_54_;
    char unknown_74_[LOW_REGION(0x128c, 0x1298) - 0x74];

    Struct_ov012_0218a844* inline_ov012_0218a844() { return &unknown_54_; }
};

struct Struct_ov012_0218a844_2
{
    char unknown_0_[LOW_REGION(0x90, 0xac)];
    Struct_0201099c_22 unknown_ac_;
    char unknown_1344_[LOW_REGION(0x1348, 0x1378) - LOW_REGION(0x131c, 0x1344)];
    const char* unknown_1378_;
    char unknown_137c_[LOW_REGION(0x1420, 0x13c8) - LOW_REGION(0x134c, 0x137c)];
    short* unknown_13c8_;
    char unknown_13cc_[LOW_REGION(0x1448, 0x13f0) - LOW_REGION(0x1424, 0x13cc)];
    int unknown_13f0_;

    Struct_0201099c_22* inline_ov012_0218a844_2() { return &unknown_ac_; }
};

void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
void Text_AppendCursorTag(char* text, int a);
void* MessageSystem_GetInstance();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
void Text_Append(char* text, const char* append);
void AppendXTag_02041a28(char* text, int x);
const char* KeyTable_Get(Container020e0310* texts, int id);
void Text_AppendNTag(char* text, int item, const char* itemText);
void AppendXYTag_02041a90(char* text, int x, int y);
#if !defined(jpn)
extern "C" void func_ov012_021842a0(Struct_ov012_0218a844_2* arg0, int arg1, int arg2, int arg3);

extern "C" const char data_ov012_0218b310[];
#endif

#if defined(jpn)
struct Struct_020465c0;
struct Struct_02072a68_2;
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
extern "C" const char* func_02072a68(Struct_02072a68_2*, int);
#endif

// USA: func_ov012_0218a844
extern "C" ARM void func_ov012_0218a844(Struct_ov012_0218a844_2* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    int selection = self->unk_13f0 & 0xf;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
#if defined(jpn)
    void* messages = MessageSystem_GetInstance();
#else
    MessageSystem_GetInstance();
#endif
    int var2;
    Struct_ov012_0218a844* var3 = arg0->inline_ov012_0218a844_2()->inline_ov012_0218a844();
    int var4 = var3->unknown_8_[3];
    int var5 = var3->unknown_4_;
    int var6;
    int var7;
    func_0205c508((Struct_0205c508*)var3, &var6, &var7);
    for (var2 = var6; var2 < var7; var2++)
    {
        if (var2 % 2 == 0)
        {
            if (i != first)
                Text_Append(text, self->unk_1378);
        }
        else
        {
            func_02041a28(arg1, LOW_REGION(0x7c, 0x88));
        }
        Text_AppendNTag(text, i & 0xf, KeyTable_Get((Container020e0310*)self->texts_, self->unk_13c8[i]));
    }
    if (var5 > 1)
    {
#if defined(jpn)
        func_02046380(messages);
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, shadow + 1);
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, color);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
        SetByteInRange_020465f0((unsigned char*)messages, 1, 2);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteAtIndex_020465d8((unsigned char*)messages, 1, 0);
        func_02042428(text, 8);
        Text_Append(text, FindEntryByKey_02072a68((TableA68*)((char*)self + 0x1314), 0x7a));
#else
        func_ov012_021842a0(self, 12, shadow, color);
        AppendXYTag_02041a90(text, 0x56, 0x94);
        Text_Append(text, data_ov012_0218b310);
#endif
    }
}
