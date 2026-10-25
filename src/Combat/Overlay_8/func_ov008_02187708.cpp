#include <globaldefs.h>
#include "Graphics/Background.h"
#include <Memory/SafeAllocator.h>
#include <World/Object3D.h>
#include <Filesystem/BackgroundLoader.h>

struct Struct_01ff8b48_26 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov008_021843f8_2;

struct Struct_ov008_02187278 {
    unsigned int unknown_0_0_ : 14;
    unsigned int unknown_1_6_ : 17;
    unsigned int unknown_3_7_ : 1;
    unsigned int unknown_4_0_ : 14;
    unsigned int unknown_5_6_ : 17;
    unsigned int unknown_7_7_ : 1;
    unsigned int unknown_8_0_ : 7;
    unsigned int unknown_8_7_ : 7;
    unsigned int unknown_9_6_ : 7;
    unsigned int unknown_a_5_ : 7;
    unsigned int unknown_b_4_ : 4;
    unsigned int unknown_c_0_ : 10;
    unsigned int unknown_d_2_ : 14;
    unsigned int unknown_f_0_ : 7;
    unsigned int unknown_f_7_ : 1;
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 7;
    unsigned int unknown_13_6_ : 2;
    short unknown_14_;
    unsigned char unknown_16_0_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct Struct_01ff8b48_13 {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov008_02185dc0 {
    int unknown_0_[2];
};


struct Struct_02081870_2 {
    int unknown_0_[0xbc / 4];
};

struct Struct_ov006_02158478 {
    int unknown_0_[0xe0 / 4];
};

struct Struct_ov009_02186e00_2 {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator unknown_0_;
    SafeAllocator unknown_14_;
    SafeAllocator unknown_28_;
    SafeAllocator unknown_3c_;
    SafeAllocator unknown_50_;
    SafeAllocator unknown_64_;
    SafeAllocator unknown_78_;
    SafeAllocator unknown_8c_;
    Struct_01ff8b48_13 unknown_a0_;
    char* unknown_b8_;
    char unknown_bc_[0x14];
    Struct_ov003_021594c4 unknown_d0_[3];
    Struct_02081870_2 unknown_130_;
    Struct_ov006_02158478 unknown_1ec_[6];
    void* unknown_72c_;
    void* unknown_730_;
    void* unknown_734_;
    void* unknown_738_;
    void* unknown_73c_;
    void* unknown_740_;
    unsigned char unknown_744_[8];
    unsigned char unknown_74c_;
    Struct_ov009_02186e00_2 unknown_750_;
    Object3D unknown_790_;
    char unknown_83c_[0x2c8];
    void* unknown_b04_;
    void* unknown_b08_;
    void* unknown_b0c_;
    signed char unknown_b10_;
    unsigned char unknown_b11_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int unknown_b18_;
    int unknown_b1c_;
    int unknown_b20_;
    int unknown_b24_;
    unsigned char unknown_b28_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int unknown_b2c_;
    const void* unknown_b30_;
    Struct_ov008_02187278* unknown_b34_;
    void* unknown_b38_;
    void* unknown_b3c_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x49c];
    unsigned char unknown_49c_0_ : 1;
    char unknown_49d_[0x950 - 0x49d];
    int unknown_950_;
};

struct GameObject {
    char unknown_0_[0x150];
    Struct_ov005_0215840c_2* unknown_150_;
};

struct GameState {
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct Struct_ov008_02187708 {
    unsigned int unknown_0_0_ : 19;
    int unknown_2_3_ : 11;
    unsigned int unknown_3_6_ : 2;
};

static inline char* inline_ov008_02187708(GameState* arg0)
{
    return (char*)arg0 + 0x569c;
}

struct Struct_02021b84 {
    char unknown_0_[0x10];
    void* unknown_10_;
};

struct Struct_ov008_02187708_2 {
    int unknown_0_[3];
};

struct Struct_020727d8;
struct Struct_0201099c_3;
struct Struct_02072a68_2;
struct Struct_02013fb4;
struct Struct_02046574_2;

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];
extern char data_ov008_0218b49b[];
extern char data_ov008_0218b4b0[];
extern char data_ov008_0218b4c1[];

MessageSystem* MessageSystem_GetInstance();
void Clear12Bytes020e46c4(void* name);
void InitObjFromCombatant020e4c74(void* name, GameObject* object);
void ResetListHeader020727d8(List020727d8* list);
const char* KeyTable_Get(Container020e0310* texts, int id);
const char* FindEntryByKey_02072a68(TableA68* texts, int id);
void SubmitAndRunScript02072928(void* list, StreamHeader* file, int size, int id, void* output, unsigned char female);
void MessageSystem_SetStringArgument(Obj02046574* messages, int index, char* text);
char* FindSubstring_020d2f88(char* text, char* search);
void AppendYTag_02041a5c(char* text, int y);
void Text_Append(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
int sprintf(char* buffer, const char* format, ...);
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_02046380(MessageSystem* messages);
void Font_DecodeText(const void* codes, char* text, int value);
void func_020e4b34(MessageName* name, char* text, char* text2, int a, int b, int c, int d, int female, int e,
                   int f, int g, int h);
const char* func_020e046c(char* output, void* file, unsigned int size, short id);
void MessageSystem_FormatText(MessageSystem* messages, int value, const char* format, char* output, int size, int a, int b);
int Font_GetTextWidth(const char* text, int large);
}

// USA: func_ov008_02187708
extern "C" ARM void func_ov008_02187708(Struct_ov008_021842a0_2* arg0, char* arg1, Struct_ov008_021843f8_2* arg2)
{
    if (arg1 == NULL)
        return;
    GameState* var0 = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    MessageSystem* messages = MessageSystem_GetInstance();
    char name[0x30];
    __clear(name, sizeof(name));
    short title = 0;
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    unsigned int female = 0;
    func_02046380(messages);
    MessageName heroName;
    MessageName guestName;
    const void* codes = self->guest_;
    if (codes == NULL)
    {
        char* var9 = inline_ov008_02187708(var0);
        var3 = ((Struct_ov008_02187708*)(var9 + 4))->unknown_2_3_;
        GameObject* var10 = var0->GetProtagonist();
        if (var10 != NULL)
        {
            if (var3 <= 0)
            {
                Struct_ov005_0215840c_2* var11 = var10->unknown_150_;
                int var12 = 0x50dc;
                if (var11->unknown_49c_0_ == 1)
                    var12 = 0x510e;
                var3 = var12 - 20000 + var11->unknown_950_;
            }
            var5 = var10->unknown_150_->unknown_49c_0_;
            func_020e46c4(&var6);
            func_020e4c74(&var6, var10);
            var1->unknown_10_ = &var6;
        }
    }
    else
    {
        GuestRecords* guest = self->guestRecords_;
        if (guest != NULL)
            title = guest->title_;
        female = guest->female_;
        Font_DecodeText(codes, name, 1);
        Clear12Bytes020e46c4(&guestName);
        func_020e4b34(&guestName, name, name, 0, 0, 0, 0, female, 0, 1, 0, 1);
        messages->unk_10 = &guestName;
    }
    if (var3 > 0)
    {
        Struct_ov008_02185dc0 var14;
        func_020727d8((Struct_020727d8*)&var14);
        const char* var15 = NULL;
        unsigned int var16 = 0;
        if (var3 < 700)
        {
            if (arg0->unknown_b3c_ != NULL)
            {
                titleText = KeyTable_Get((Container020e0310*)self->guestTitles_, title);
            }
            else
            {
                BackgroundLoader::AddLockGlobal();
                unsigned int var17 = 0;
                char var18[0x40];
                char var19[0x20];
                __clear(var18, sizeof(var18));
                __clear(var19, sizeof(var19));
                sprintf(var18, data_ov008_0218b465, var5);
                sprintf(var19, data_ov008_0218b47c, var5);
                void* var20 = ExtractFileFromGP2(var18, var19, &var17);
                if (var20 != NULL)
                    var15 = func_020e046c(var4, var20, var17, var3);
                BackgroundLoader::RemoveLockGlobal();
            }
        }
        else
        {
            if (arg0->unknown_b38_ != NULL)
            {
                var15 = func_02072a68((Struct_02072a68_2*)arg0->unknown_b38_, (short)(var3 + 20000));
            }
            else
            {
                BackgroundLoader::AddLockGlobal();
                void* var21 = ExtractFileFromGP2(data_ov008_0218b49b, data_ov008_0218b4b0, &var16);
                if (var21 != NULL)
                {
                    func_02072928(&var14, (Struct_02013fb4*)var21, var16, (short)(var3 + 20000), var4, 0);
                    var15 = var4;
                }
                BackgroundLoader::RemoveLockGlobal();
            }
        }
        MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)titleText);
    }
    char* var22 = arg0->unknown_b8_;
    int var23 = 100;
    int var24 = 0xee;
    if (arg2 != NULL)
    {
        var23 = 101;
        var24 = 0xdf;
    }
    MessageSystem_FormatText(messages, 10, KeyTable_Get((Container020e0310*)&self->texts_, format), output + 0x760, width, 1, 0);
    int color = 7;
    if (FindSubstring_020d2f88(output + 0x760, data_ov008_0218b4c1) != NULL)
        color = 2;
    if (records != NULL)
    {
        self->titleX_ = (Font_GetTextWidth(output + 0x760, 0) + 0x10) << 12;
        if (color == 2)
            self->titleX_ = 0xe0000;
    }
    AppendYTag_02041a5c(text, color);
    Text_Append(text, output + 0x760);
}
