#if defined(jpn)
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02072a68_2;
struct Struct_0205c508;
struct Struct_020465c0;
struct Struct_ov012_02189af4 {
    int unknown_0_;
    int unknown_4_;
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
};

struct Struct_ov012_02189af4_2 {
    unsigned char unknown_0_[0x54];
    Struct_ov012_02189af4 unknown_54_;
    Struct_ov012_02189af4* inline_ov012_02189af4_3() { return &unknown_54_; }
};

void Text_AppendFrameTag(char*, int, int, int, int, int);
int Text_AppendCursorTag(char*, int);
void* MessageSystem_GetInstance();
void ComputeProductSums0205c508(UnkStruct0205c508*, int*, int*);
int Text_Append(char*, const char*);
const char* FindEntryByKey_02072a68(TableA68*, int);
int Text_AppendNTag(char*, int, const char*);
int AppendXTag_02041a28(char*, int);
extern "C" void func_02046380(void*);
extern "C" void func_020465c0(Struct_020465c0*, int, int);
extern "C" void func_020465f0(unsigned char*, int, unsigned char);
extern "C" void func_020465d8(unsigned char*, int, unsigned char);
extern "C" void func_02042428(char*, int);
extern "C" void func_0202ae18();

struct Struct_ov012_021884f4 {
    unsigned short unknown_0_0_ : 5;
    unsigned short unknown_0_5_ : 11;
};

extern "C" ARM void func_ov012_02189dfc(char* editor, char* text, int hidden) {
    if (!text) return;
    int selection = *(int*)(editor + 0x143c) % 9;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    void* messages = MessageSystem_GetInstance();
    int i;
    ProfileNavigation* navigation = ((ProfileWindowNavigation*)(editor + 0x90))->GetNavigation();
    int page = navigation->page;
    int pages = navigation->pages;
    int first, last;
    ComputeProductSums0205c508((UnkStruct0205c508*)navigation, &first, &last);
    for (i = first; i < last; ++i) {
        if (i != first)
            Text_Append(text, *(const char**)(editor + 0x1348));
        const char* name = FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), (short)((*(signed char**)(editor + 0x1418))[i] + 10000));
        Text_AppendNTag(text, i % 9, name);
    }
    if (((ProfileListCounts*)(editor + 0x141c))->available > 9) {
        func_02046380(messages);
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 0, page + 1);
        StoreInArray0x8b0_020465c0((StoreStruct*)messages, 1, pages);
        SetByteInRange_020465f0((unsigned char*)messages, 0, 2);
        SetByteInRange_020465f0((unsigned char*)messages, 1, 2);
        SetByteAtIndex_020465d8((unsigned char*)messages, 0, 1);
        SetByteAtIndex_020465d8((unsigned char*)messages, 1, 0);
        func_02042428(text, 8);
        Text_Append(text, FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), 0x6b));
    }
}

#else
#include <globaldefs.h>

struct Struct_0205c508;
struct Struct_02072a68_2;

struct Struct_ov012_02189dfc
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_[6];
};

struct Struct_01ff91ac_15
{
    char unknown_0_[0x54];
    Struct_ov012_02189dfc unknown_54_;
    char unknown_74_[0x133c - 0xac - 0x74];

    Struct_ov012_02189dfc* inline_ov012_02189dfc() { return &unknown_54_; }
};

struct Struct_ov012_02189dfc_2
{
    char unknown_0_[0xac];
    Struct_01ff91ac_15 unknown_ac_;
    char unknown_133c_[0x1378 - 0x133c];
    const char* unknown_1378_;
    char unknown_137c_[0x13c0 - 0x137c];
    signed char* unknown_13c0_;
    unsigned short unknown_13c4_0_ : 5;
    unsigned short unknown_13c4_5_ : 11;
    char unknown_13c6_[0x13d8 - 0x13c6];
    int unknown_13d8_[6];

    Struct_01ff91ac_15* inline_ov012_02189dfc_2() { return &unknown_ac_; }
};

void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
void Text_AppendCursorTag(char* text, int a);
void* MessageSystem_GetInstance();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
void Text_Append(char* text, const char* append);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void Text_AppendNTag(char* text, int item, const char* itemText);
void AppendXYTag_02041a90(char* text, int x, int y);
extern "C" void func_ov012_021842a0(ProfileEditor02189dfc* self, int canvas, int color, int shadow);

extern "C" const char data_ov012_0218b310[];

// USA: func_ov012_02189dfc
extern "C" ARM void func_ov012_02189dfc(Struct_ov012_02189dfc_2* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    int selection = self->selections_[3] % 9;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    MessageSystem_GetInstance();
    int i;
    Cursor02189dfc* cursor = self->GetWindow()->GetCursor();
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    ComputeProductSums0205c508((UnkStruct0205c508*)cursor, &first, &last);
    for (i = first; i < last; i++)
    {
        if (i != first)
            Text_Append(text, self->unk_1378);
        Text_AppendNTag(text, i % 9, FindEntryByKey_02072a68((TableA68*)self->strings_, (short)(self->unk_13c0[i] + 10000)));
    }
    if (arg0->unknown_13c4_0_ > 9)
    {
        func_ov012_021842a0(self, 5, shadow, color);
        AppendXYTag_02041a90(text, 0x2a, 0x94);
        Text_Append(text, data_ov012_0218b310);
    }
}

#endif
