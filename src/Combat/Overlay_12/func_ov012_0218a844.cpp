#if defined(jpn)
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif
#include <globaldefs.h>

struct Struct_0205c508;
struct Container020e0310;

struct Struct_ov012_0218a844
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct Struct_0201099c_22
{
    char unk_0[0x54];
    Struct_ov012_0218a844 cursor_;
    char unknown_74_[LOW_REGION(0x128c, 0x1298) - 0x74];

    Struct_ov012_0218a844* inline_ov012_0218a844() { return &cursor_; }
};

struct Struct_ov012_0218a844_2
{
    char unk_0[LOW_REGION(0x90, 0xac)];
    Struct_0201099c_22 window_;
    char texts_[LOW_REGION(0x1348, 0x1378) - LOW_REGION(0x131c, 0x1344)];
    const char* unk_1378;
    char unknown_137c_[LOW_REGION(0x1420, 0x13c8) - LOW_REGION(0x134c, 0x137c)];
    short* unk_13c8;
    char unknown_13cc_[LOW_REGION(0x1448, 0x13f0) - LOW_REGION(0x1424, 0x13cc)];
    int unknown_13f0_;

    Struct_0201099c_22* GetWindow() { return &window_; }
};

extern "C" void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
extern "C" void Text_AppendCursorTag(char* text, int a);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_0205c508(Struct_0205c508* cursor, int* first, int* last);
extern "C" void Text_Append(char* text, const char* append);
extern "C" void func_02041a28(char* text, int x);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" void Text_AppendNTag(char* text, int item, const char* itemText);
extern "C" void func_02041a90(char* text, int x, int y);
#if !defined(jpn)
extern "C" void func_ov012_021842a0(Struct_ov012_0218a844_2* self, int canvas, int color, int arg3);

extern "C" const char data_ov012_0218b310[];
#endif

#if defined(jpn)
struct StoreStruct;
struct TableA68;
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
extern "C" const char* func_02072a68(TableA68*, int);
#endif

// USA: func_ov012_0218a844
extern "C" ARM void func_ov012_0218a844(Struct_ov012_0218a844_2* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->unknown_13f0_ & 0xf;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
#if defined(jpn)
    void* messages = MessageSystem_GetInstance();
#else
    MessageSystem_GetInstance();
#endif
    int i;
    Struct_ov012_0218a844* cursor = self->GetWindow()->inline_ov012_0218a844();
    int var4 = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    func_0205c508((Struct_0205c508*)cursor, &first, &last);
    for (i = first; i < last; i++)
    {
        if (i % 2 == 0)
        {
            if (i != first)
                Text_Append(text, self->unk_1378);
        }
        else
        {
            func_02041a28(text, LOW_REGION(0x7c, 0x88));
        }
        Text_AppendNTag(text, i & 0xf, KeyTable_Get((Container020e0310*)self->texts_, self->unk_13c8[i]));
    }
    if (color > 1)
    {
#if defined(jpn)
        func_02046380(messages);
        func_020465c0((StoreStruct*)messages, 0, var4 + 1);
        func_020465c0((StoreStruct*)messages, 1, color);
        func_020465f0((unsigned char*)messages, 0, 2);
        func_020465f0((unsigned char*)messages, 1, 2);
        func_020465d8((unsigned char*)messages, 0, 1);
        func_020465d8((unsigned char*)messages, 1, 0);
        func_02042428(text, 8);
        Text_Append(text, func_02072a68((TableA68*)((char*)self + 0x1314), 0x7a));
#else
        func_ov012_021842a0(self, 12, var4, color);
        func_02041a90(text, 0x56, 0x94);
        Text_Append(text, data_ov012_0218b310);
#endif
    }
}
