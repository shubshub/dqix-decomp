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
extern "C" void LinkSession_GetInstance();

extern "C" ARM void func_ov012_02189af4(char* editor, char* text, int hidden) {
    if (!text) return;
    int selection = *(int*)(editor + 0x1434) & 15;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    void* messages = MessageSystem_GetInstance();
    int i;
    int end;
    int right;
    ProfileNavigation* navigation = ((ProfileWindowNavigation*)(editor + 0x90))->GetNavigation();
    int page = navigation->page;
    int pages = navigation->pages;
    int first, last;
    ComputeProductSums0205c508((UnkStruct0205c508*)navigation, &first, &last);
    end = first + (last + 1 - first) / 2;
    for (i = first; i < end; ++i) {
        if (i != first)
            Text_Append(text, *(const char**)(editor + 0x1348));
        Text_AppendNTag(text, i & 15, FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), (short)(i + 0x2774)));
        right = i + (last + 1 - first) / 2;
        if (right < 47) {
            AppendXTag_02041a28(text, 0x56);
            Text_AppendNTag(text, right & 15, FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), (short)(right + 0x2774)));
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
    Text_Append(text, FindEntryByKey_02072a68((TableA68*)(editor + 0x1314), 0x6a));
}

#else
#include <globaldefs.h>

struct Struct_0205c508;
struct Struct_02072a68_2;

struct Struct_ov012_02189af4_3
{
    int unknown_0_;
    int unknown_4_;
    int unknown_8_[6];
};

struct Struct_01ff91ac_14
{
    char unknown_0_[0x54];
    Struct_ov012_02189af4_3 unknown_54_;
    char unknown_74_[0x1290 - 0x74];

    Struct_ov012_02189af4_3* inline_ov012_02189af4() { return &unknown_54_; }
};

struct Struct_ov012_02189af4_4
{
    char unknown_0_[0xac];
    Struct_01ff91ac_14 unknown_ac_;
    char unknown_133c_[0x1378 - 0x133c];
    const char* unknown_1378_;
    char unknown_137c_[0x13d8 - 0x137c];
    int unknown_13d8_[6];

    Struct_01ff91ac_14* inline_ov012_02189af4_2() { return &unknown_ac_; }
};

void Text_AppendFrameTag(char* text, int a, int b, int c, int d, int e);
void Text_AppendCursorTag(char* text, int a);
void* MessageSystem_GetInstance();
void ComputeProductSums0205c508(UnkStruct0205c508* cursor, int* first, int* last);
void Text_Append(char* text, const char* append);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void Text_AppendNTag(char* text, int item, const char* itemText);
void AppendXTag_02041a28(char* text, int x);
extern "C" void func_ov012_021842a0(ProfileEditor02189af4* self, int canvas, int color, int shadow);

// USA: func_ov012_02189af4
extern "C" ARM void func_ov012_02189af4(Struct_ov012_02189af4_4* arg0, char* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    int selection = self->selections_[1] & 0xf;
    if (hidden)
        Text_AppendFrameTag(text, selection, 8, 5, 5, 5);
    Text_AppendCursorTag(text, selection);
    MessageSystem_GetInstance();
    Cursor02189af4* cursor = self->GetWindow()->GetCursor();
    int shadow = cursor->words_[3];
    int color = cursor->unk_4;
    int first;
    int last;
    ComputeProductSums0205c508((UnkStruct0205c508*)cursor, &first, &last);
    int end = first + (last + 1 - first) / 2;
    for (int i = first; i < end; i++)
    {
        if (i != first)
            Text_Append(text, self->unk_1378);
        Text_AppendNTag(text, i & 0xf, FindEntryByKey_02072a68((TableA68*)self->strings_, (short)(i + 0x2846)));
        int right = i + (last + 1 - first) / 2;
        if (right < 0xc0)
        {
            AppendXTag_02041a28(text, 0x56);
            Text_AppendNTag(text, right & 0xf, FindEntryByKey_02072a68((TableA68*)self->strings_, (short)(right + 0x2846)));
        }
    }
    func_ov012_021842a0(arg0, 3, var12, var13);
}

#endif
