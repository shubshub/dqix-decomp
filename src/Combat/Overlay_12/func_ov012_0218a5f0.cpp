#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct TableA68;
struct Struct_0205c508;
struct StoreStruct;
struct Struct_ov012_02189af4 {
    int count;
    int pages;
    int columns;
    int rows;
    int mode;
    int page;
};

struct Struct_ov012_02189af4_2 {
    unsigned char unknown[0x54];
    Struct_ov012_02189af4 navigation;
    Struct_ov012_02189af4* inline_ov012_02189af4_3() { return &navigation; }
};

extern "C" void Text_AppendFrameTag(char*, int, int, int, int, int);
extern "C" int Text_AppendCursorTag(char*, int);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_0205c508(Struct_0205c508*, int*, int*);
extern "C" int Text_Append(char*, const char*);
extern "C" const char* func_02072a68(TableA68*, int);
extern "C" int Text_AppendNTag(char*, int, const char*);
extern "C" int func_02041a28(char*, int);
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(StoreStruct*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
extern "C" void LinkSession_GetInstance();

extern "C" ARM void func_ov012_0218a5f0(char* editor, char* text, int hidden) {
    if (!text) return;
    int selection = *(int*)(editor + 0x1444) % 10;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    void* messages = MessageSystem_GetInstance();
    int i;
    Struct_ov012_02189af4* navigation = ((Struct_ov012_02189af4_2*)(editor + 0x90))->inline_ov012_02189af4_3();
    int page = navigation->page;
    int pages = navigation->pages;
    int first, last;
    func_0205c508((Struct_0205c508*)navigation, &first, &last);
    LinkSession_GetInstance();
    GameState::GetInstance();
    for (i = first; i < last; ++i) {
        if (i != first)
            Text_Append(text, *(const char**)(editor + 0x1348));
        if (i == 0) {
            const char* name = func_02072a68((TableA68*)(editor + 0x1314), 0x50dc);
            Text_AppendNTag(text, i % 10, name);
        } else {
            const char* name = func_02072a68((TableA68*)(editor + 0x1314), (short)(0x5140 + i - 1));
            Text_AppendNTag(text, i % 10, name);
        }
    }
    func_02046380(messages);
    func_020465c0((StoreStruct*)messages, 0, page + 1);
    func_020465c0((StoreStruct*)messages, 1, pages);
    func_020465f0((unsigned char*)messages, 0, 2);
    func_020465f0((unsigned char*)messages, 1, 2);
    func_020465d8((unsigned char*)messages, 0, 1);
    func_020465d8((unsigned char*)messages, 1, 0);
    func_02042428(text, 8);
    Text_Append(text, func_02072a68((TableA68*)(editor + 0x1314), 0x6b));
}

#else
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c508;
struct TableA68;

struct Struct_ov012_0218a5f0
{
    int unk_0;
    int unk_4;
    int words_[6];
};

struct Struct_01ff91ac_16
{
    char unk_0[0x54];
    Struct_ov012_0218a5f0 cursor_;
    char unknown_74_[0x1290 - 0x74];

    Struct_ov012_0218a5f0* inline_ov012_0218a5f0() { return &cursor_; }
};

struct Struct_ov012_0218a5f0_2
{
    char unk_0[0x49c];
    unsigned char female_ : 1;
};

struct Struct_ov012_0218a5f0_3
{
    char unk_0[0x150];
    Struct_ov012_0218a5f0_2* unknown_150_;
};

struct Struct_ov012_0218a5f0_4
{
    char unk_0[0xac];
    Struct_01ff91ac_16 window_;
    char strings_[0x1378 - 0x133c];
    const char* unk_1378;
    char unknown_137c_[0x13d8 - 0x137c];
    int selections_[6];

    Struct_01ff91ac_16* GetWindow() { return &window_; }
};

extern "C" void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
extern "C" void Text_AppendCursorTag(char* text, int a);
extern "C" void* MessageSystem_GetInstance();
extern "C" void func_0205c508(Struct_0205c508* cursor, int* first, int* last);
extern "C" void LinkSession_GetInstance();
extern "C" void Text_Append(char* text, const char* append);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" void Text_AppendNTag(char* text, int item, const char* itemText);
extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void func_0206819c(const char* text, char* output, int a);
extern "C" void func_ov012_021842a0(Struct_ov012_0218a5f0_4* self, int canvas, int color, int arg3);

// USA: func_ov012_0218a5f0
extern "C" ARM void func_ov012_0218a5f0(Struct_ov012_0218a5f0_4* self, char* text, int hidden)
{
    if (text == 0)
        return;

    int selection = self->selections_[5] % 10;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    MessageSystem_GetInstance();
    Struct_ov012_0218a5f0_3* protagonist;
    int i;
    Struct_ov012_0218a5f0* cursor = self->GetWindow()->inline_ov012_0218a5f0();
    int var14 = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    func_0205c508((Struct_0205c508*)cursor, &first, &last);
    LinkSession_GetInstance();
    protagonist = (Struct_ov012_0218a5f0_3*)GameState::GetInstance()->GetProtagonist();
    int base = 0x50dc;
    for (i = first; i < last; i++)
    {
        if (i != first)
            Text_Append(text, self->unk_1378);
        if (i == 0)
        {
            int id = base;
            if (protagonist->unknown_150_->female_ == 1)
                id = 0x510e;
            const char* name = func_02072a68((TableA68*)self->strings_, (short)id);
            Text_AppendNTag(text, i % 10, name);
        }
        else
        {
            int id = 0x5140;
            if (protagonist->unknown_150_->female_ == 1)
                id = 0x51a4;
            const char* name = func_02072a68((TableA68*)self->strings_, (short)(id + i - 1));
            char converted[0x80];
            __clear(converted, sizeof(converted));
            func_0206819c(name, converted, 0);
            Text_AppendNTag(text, i % 10, converted);
        }
    }
    func_ov012_021842a0(self, 11, var14, color);
}

#endif
