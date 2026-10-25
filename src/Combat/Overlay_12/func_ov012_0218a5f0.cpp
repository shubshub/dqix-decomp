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

extern "C" ARM void func_ov012_0218a5f0(char* editor, char* text, int hidden) {
    if (!text) return;
    int selection = *(int*)(editor + 0x1444) % 10;
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
    func_0202ae18();
    GameState::GetInstance();
    for (i = first; i < last; ++i) {
        if (i != first)
            Text_Append(text, *(const char**)(editor + 0x1348));
        if (i == 0) {
            const char* name = FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), 0x50dc);
            Text_AppendNTag(text, i % 10, name);
        } else {
            const char* name = FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), (short)(0x5140 + i - 1));
            Text_AppendNTag(text, i % 10, name);
        }
    }
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

#else
#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c508;
struct Struct_02072a68_2;

struct Struct_ov012_0218a5f0
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_[6];
};

struct Struct_01ff91ac_16
{
    char unknown_0_[0x54];
    Struct_ov012_0218a5f0 unknown_54_;
    char unknown_74_[0x1290 - 0x74];

    Struct_ov012_0218a5f0* inline_ov012_0218a5f0() { return &unknown_54_; }
};

struct Struct_ov012_0218a5f0_2
{
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
};

struct Struct_ov012_0218a5f0_3
{
    char unknown_0_[0x150];
    Struct_ov012_0218a5f0_2* unknown_150_;
};

struct Struct_ov012_0218a5f0_4
{
    char unknown_0_[0xac];
    Struct_01ff91ac_16 unknown_ac_;
    char unknown_133c_[0x1378 - 0x133c];
    const char* unknown_1378_;
    char unknown_137c_[0x13d8 - 0x137c];
    int unknown_13d8_[6];

    Struct_01ff91ac_16* inline_ov012_0218a5f0_2() { return &unknown_ac_; }
};

void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
void Text_AppendCursorTag(char* text, int a);
void* MessageSystem_GetInstance();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
extern "C" void func_0202ae18();
void Text_Append(char* text, const char* append);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void Text_AppendNTag(char* text, int item, const char* itemText);
extern "C" void __clear(void* buffer, unsigned long size);
void CopyTextAndUppercaseIfFlagged0206819c(const char* text, char* output, int a);
extern "C" void func_ov012_021842a0(ProfileEditor0218a5f0* self, int canvas, int color, int shadow);

// USA: func_ov012_0218a5f0
extern "C" ARM void func_ov012_0218a5f0(Struct_ov012_0218a5f0_4* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    int selection = self->selections_[5] % 10;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    MessageSystem_GetInstance();
    Protagonist0218a5f0* protagonist;
    int i;
    Cursor0218a5f0* cursor = self->GetWindow()->GetCursor();
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    ComputeProductSums0205c508((UnkStruct0205c508*)cursor, &first, &last);
    func_0202ae18();
    var11 = (Struct_ov012_0218a5f0_3*)GameState::GetInstance()->GetProtagonist();
    int var18 = 0x50dc;
    for (var12 = var16; var12 < var17; var12++)
    {
        if (i != first)
            Text_Append(text, self->unk_1378);
        if (i == 0)
        {
            int id = base;
            if (protagonist->partyData_->female_ == 1)
                id = 0x510e;
            const char* name = FindEntryByKey_02072a68((TableA68*)self->strings_, (short)id);
            Text_AppendNTag(text, i % 10, name);
        }
        else
        {
            int id = 0x5140;
            if (protagonist->partyData_->female_ == 1)
                id = 0x51a4;
            const char* name = FindEntryByKey_02072a68((TableA68*)self->strings_, (short)(id + i - 1));
            char converted[0x80];
            __clear(converted, sizeof(converted));
            CopyTextAndUppercaseIfFlagged0206819c(name, converted, 0);
            Text_AppendNTag(text, i % 10, converted);
        }
    }
    func_ov012_021842a0(arg0, 11, var14, var15);
}

#endif
