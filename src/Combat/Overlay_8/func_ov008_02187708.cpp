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
    unsigned char female_ : 1;
    unsigned char unknown_16_1_ : 4;
    unsigned char unknown_16_5_ : 3;
    unsigned char unknown_17_;
};

struct TextTable {
    int unknown_0_[0x18 / 4];
};

struct Struct_ov008_02185dc0 {
    int unknown_0_[2];
};


struct TextWindow {
    int unknown_0_[0xbc / 4];
};

struct Canvas {
    int unknown_0_[0xe0 / 4];
};

struct WindowCursor {
    int unknown_0_[0x40 / 4];
};

struct Struct_ov008_021842a0_2 {
    SafeAllocator allocator_;
    SafeAllocator unknown_14_;
    SafeAllocator textAllocator_;
    SafeAllocator spriteAllocator_;
    SafeAllocator iconAllocator_;
    SafeAllocator modelAllocator_;
    SafeAllocator titleAllocator_;
    SafeAllocator unknown_8c_;
    TextTable texts_;
    char* text_;
    char unknown_bc_[0x14];
    BackgroundGraphics backgrounds_[3];
    TextWindow window_;
    Canvas canvases_[6];
    void* pixels_;
    void* renderer_;
    void* sprites_;
    void* animations_;
    void* iconRenderer_;
    void* iconSprite_;
    unsigned char items_[8];
    unsigned char unknown_74c_;
    WindowCursor cursor_;
    Object3D model_;
    char camera_[0x2c8];
    void* titles_;
    void* unknown_b08_;
    void* page_;
    signed char state_;
    unsigned char step_;
    unsigned char unknown_b12_;
    unsigned char unknown_b13_;
    short unknown_b14_;
    short unknown_b16_;
    int flags_;
    int unknown_b1c_;
    int task_;
    int mode_;
    unsigned char kind_;
    unsigned char unknown_b29_;
    unsigned char unknown_b2a_;
    int titleX_;
    const void* unknown_b30_;
    Struct_ov008_02187278* unknown_b34_;
    void* unknown_b38_;
    void* guestTitles_;
    Struct_01ff8b48_26 unknown_b40_[2];
};

struct PartyMemberData {
    char unknown_0_[0x49c];
    unsigned char female_ : 1;
    char unknown_49d_[0x950 - 0x49d];
    int vocation_;
};

struct GameObject {
    char unknown_0_[0x150];
    PartyMemberData* unknown_150_;
};

struct GameState {
    static GameState* GetInstance();
    GameObject* GetProtagonist();
};

struct Struct_ov008_02187708 {
    unsigned int unk_0 : 19;
    int unknown_2_3_ : 11;
    unsigned int unknown_3_6_ : 2;
};

static inline char* inline_ov008_02187708(GameState* gameState)
{
    return (char*)gameState + 0x569c;
}

struct MessageSystem {
    char unknown_0_[0x10];
    void* unk_10;
};

struct Struct_ov008_02187708_2 {
    int unknown_0_[3];
};

struct Struct_020727d8;
struct Container020e0310;
struct TableA68;
struct StreamHeader;
struct Obj02046574;

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];
extern char data_ov008_0218b49b[];
extern char data_ov008_0218b4b0[];
extern char data_ov008_0218b4c1[];

extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void NameText_Clear(void* name);
extern "C" void func_020e4c74(void* name, GameObject* object);
extern "C" void func_020727d8(Struct_020727d8* list);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);
extern "C" const char* func_02072a68(TableA68* texts, int id);
extern "C" void func_02072928(void* list, StreamHeader* file, int size, int id, void* output, unsigned char female);
extern "C" void MessageSystem_SetStringArgument(Obj02046574* messages, int index, char* text);
extern "C" char* func_020d2f88(char* text, char* search);
extern "C" void func_02041a5c(char* text, int y);
extern "C" void Text_Append(char* text, const char* append);

extern "C" {
void __clear(void* buffer, unsigned long size);
int sprintf(char* buffer, const char* format, ...);
void* ExtractFileFromGP2(char* path, char* inner, unsigned int* size);
void func_02046380(MessageSystem* messages);
void Font_DecodeText(const void* codes, char* text, int value);
void func_020e4b34(Struct_ov008_02187708_2* name, char* text, char* text2, int a, int b, int c, int d, int female, int e,
                   int f, int g, int h);
const char* func_020e046c(char* output, void* file, unsigned int size, short id);
void MessageSystem_FormatText(MessageSystem* messages, int value, const char* format, char* output, int size, int a, int b);
int Font_GetTextWidth(const char* text, int large);
}

// USA: func_ov008_02187708
extern "C" ARM void func_ov008_02187708(Struct_ov008_021842a0_2* self, char* text, Struct_ov008_021843f8_2* records)
{
    if (text == NULL)
        return;
    GameState* gameState = GameState::GetInstance();
    BackgroundLoader::GetInstance();
    MessageSystem* messages = MessageSystem_GetInstance();
    char name[0x30];
    __clear(name, sizeof(name));
    short title = 0;
    char buffer[0x40];
    __clear(buffer, sizeof(buffer));
    unsigned int female = 0;
    func_02046380(messages);
    Struct_ov008_02187708_2 heroName;
    Struct_ov008_02187708_2 guestName;
    const void* codes = self->unknown_b30_;
    if (codes == NULL)
    {
        char* var9 = inline_ov008_02187708(gameState);
        title = ((Struct_ov008_02187708*)(var9 + 4))->unknown_2_3_;
        GameObject* hero = gameState->GetProtagonist();
        if (hero != NULL)
        {
            if (title <= 0)
            {
                PartyMemberData* data = hero->unknown_150_;
                int var12 = 0x50dc;
                if (data->female_ == 1)
                    var12 = 0x510e;
                title = var12 - 20000 + data->vocation_;
            }
            female = hero->unknown_150_->female_;
            NameText_Clear(&heroName);
            func_020e4c74(&heroName, hero);
            messages->unk_10 = &heroName;
        }
    }
    else
    {
        Struct_ov008_02187278* var13 = self->unknown_b34_;
        if (var13 != NULL)
            title = var13->unknown_14_;
        female = var13->female_;
        Font_DecodeText(codes, name, 1);
        NameText_Clear(&guestName);
        func_020e4b34(&guestName, name, name, 0, 0, 0, 0, female, 0, 1, 0, 1);
        messages->unk_10 = &guestName;
    }
    if (title > 0)
    {
        Struct_ov008_02185dc0 list;
        func_020727d8((Struct_020727d8*)&list);
        const char* titleText = NULL;
        unsigned int size = 0;
        if (title < 700)
        {
            if (self->guestTitles_ != NULL)
            {
                titleText = KeyTable_Get((Container020e0310*)self->guestTitles_, title);
            }
            else
            {
                BackgroundLoader::AddLockGlobal();
                unsigned int var17 = 0;
                char gp2[0x40];
                char inner[0x20];
                __clear(gp2, sizeof(gp2));
                __clear(inner, sizeof(inner));
                sprintf(gp2, data_ov008_0218b465, female);
                sprintf(inner, data_ov008_0218b47c, female);
                void* file = ExtractFileFromGP2(gp2, inner, &var17);
                if (file != NULL)
                    titleText = func_020e046c(buffer, file, var17, title);
                BackgroundLoader::RemoveLockGlobal();
            }
        }
        else
        {
            if (self->unknown_b38_ != NULL)
            {
                titleText = func_02072a68((TableA68*)self->unknown_b38_, (short)(title + 20000));
            }
            else
            {
                BackgroundLoader::AddLockGlobal();
                void* file = ExtractFileFromGP2(data_ov008_0218b49b, data_ov008_0218b4b0, &size);
                if (file != NULL)
                {
                    func_02072928(&list, (StreamHeader*)file, size, (short)(title + 20000), buffer, 0);
                    titleText = buffer;
                }
                BackgroundLoader::RemoveLockGlobal();
            }
        }
        MessageSystem_SetStringArgument((Obj02046574*)messages, 0, (char*)titleText);
    }
    char* output = self->text_;
    int format = 100;
    int width = 0xee;
    if (records != NULL)
    {
        format = 101;
        width = 0xdf;
    }
    MessageSystem_FormatText(messages, 10, KeyTable_Get((Container020e0310*)&self->texts_, format), output + 0x760, width, 1, 0);
    int color = 7;
    if (func_020d2f88(output + 0x760, data_ov008_0218b4c1) != NULL)
        color = 2;
    if (records != NULL)
    {
        self->titleX_ = (Font_GetTextWidth(output + 0x760, 0) + 0x10) << 12;
        if (color == 2)
            self->titleX_ = 0xe0000;
    }
    func_02041a5c(text, color);
    Text_Append(text, output + 0x760);
}
