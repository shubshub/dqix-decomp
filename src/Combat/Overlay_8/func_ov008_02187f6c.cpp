#include <globaldefs.h>

#if defined(jpn)
#define func_ov008_02187f6c func_ov008_02188ccc
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif
#include <std_library_functions.h>
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"


struct Container020e0310;
struct MessageSystem;

extern "C" void __clear(void* buffer, unsigned long size);
extern "C" void* ExtractFileFromGP2(const char* gp2, const char* inner, unsigned int* size);
extern "C" const char* func_020e046c(char* output, void* file, unsigned int size, short id);
extern "C" int Font_GetTextWidth(const char* text, int large);
extern "C" char* Scenario_GetInstance();

struct TextWindow;
#if defined(jpn)
extern "C" void Window_OpenPane(TextWindow* window, char* text, int, int, int, int, int);
extern "C" void func_020e2168(char*, const char*, unsigned int, unsigned char, int);
extern "C" void func_02041f50(char*, char*);
extern "C" int STD_GetStringLength(const char*);
extern char data_ov008_0218c0d5[];
#else
extern "C" void Window_OpenPane(TextWindow* window, char* text, int, int, int, int, int, int);
#endif

extern "C" MessageSystem* MessageSystem_GetInstance();
extern "C" void func_02041a90(char* text, int x, int y);
extern "C" void Text_Append(char* text, const char* append);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" const char* KeyTable_Get(Container020e0310* texts, int id);

extern char data_ov008_0218b465[];
extern char data_ov008_0218b47c[];

struct TextWindow
{
    char unk_0[0xa0];
    short width_;
    short height_;
    short unknown_a4_;
    short unknown_a6_;
    short unknown_a8_;
    short unknown_aa_;
    short unk_ac;
    short unknown_ae_;
    unsigned char unk_b0;
    unsigned char unknown_b1_;
    unsigned char unknown_b2_;
    unsigned char unknown_b3_;
    unsigned char unknown_b4_;
    unsigned char unknown_b5_;
    unsigned char unknown_b6_;
    unsigned char unknown_b7_;
    unsigned char unk_b8;
    unsigned char unknown_b9_;
    unsigned char unknown_ba_;
    unsigned char unknown_bb_;
};

struct Struct_ov008_021843f8_2
{
    char unk_0[0x10];
    unsigned int unknown_10_0_ : 9;
    unsigned int unknown_11_1_ : 14;
    unsigned int unknown_12_7_ : 9;
};

struct Struct_ov008_02187f6c
{
    unsigned char female_ : 1;
};

struct Struct_ov008_02187f6c_2
{
    char unk_0[0x49c];
    Struct_ov008_02187f6c appearance_;
};

struct Struct_ov008_02187f6c_3
{
    char unk_0[LOW_REGION(0x144,0x150)];
    Struct_ov008_02187f6c_2* unknown_150_;
};

struct Struct_ov008_021842a0_2
{
    char unk_0[0xa0];
    char texts_[0x18];
    char* text_;
    char unk_bc[0x130 - 0xbc];
    TextWindow window_;
};

extern "C" void func_ov008_02188408(Struct_ov008_021842a0_2* self, char* text, int kind, Struct_ov008_021843f8_2* records);

// USA: func_ov008_02187f6c
extern "C" ARM void func_ov008_02187f6c(Struct_ov008_021842a0_2* self, Struct_ov008_021843f8_2* records)
{
    if (records != NULL)
    {
        self->window_.width_ = LOW_REGION(0x10,0x14);
        self->window_.height_ = 3;
        self->window_.unknown_a4_ = LOW_REGION(8,6);
        self->window_.unknown_a6_ = 0x11;
        self->window_.unknown_a8_ = 0;
        self->window_.unknown_aa_ = LOW_REGION(5,6);
        self->window_.unk_ac = 0xc;
        self->window_.unknown_ae_ = 0xe;
        self->window_.unknown_b7_ = 0xc;
        self->window_.unknown_b1_ = 4;
        self->window_.unknown_b5_ = 1;
        self->window_.unknown_b6_ = 1;
        memset(self->text_, 0, LOW_REGION(0x800,0x960));
        char* text = self->text_;
        if (text != NULL)
        {
            MessageSystem_GetInstance();
            if (records != NULL)
            {
    #if defined(jpn)
            Struct_ov008_02187f6c_3* hero = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
            char* name = self->text_ + 0x780;
            func_020e2168(name, data_ov008_0218c0d5, records->unknown_12_7_, hero->unknown_150_->appearance_.female_, 1);
            char plainName[0x80];
            __clear(plainName, sizeof(plainName));
            func_02041f50(name, plainName);
            int length = STD_GetStringLength(plainName);
            int y;
            int x = (0x80 - (length / 2) * 12) / 2;
            y = 6;
            if (length != STD_GetStringLength(name)) y = 8;
            func_02041a90(text, x, y);
            Text_Append(text, name);
#else
            Struct_ov008_02187f6c_3* hero = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
                char* name = self->text_ + 0x8e0;
                BackgroundLoader::AddLockGlobal();
                unsigned int size = 0;
                char inner[0x20];
                char gp2[0x40];
                __clear(gp2, sizeof(gp2));
                __clear(inner, sizeof(inner));
                sprintf(gp2, data_ov008_0218b465, hero->unknown_150_->appearance_.female_);
                sprintf(inner, data_ov008_0218b47c, hero->unknown_150_->appearance_.female_);
                void* file = ExtractFileFromGP2(gp2, inner, &size);
                if (file != NULL)
                    func_020e046c(name, file, size, (short)records->unknown_12_7_);
                BackgroundLoader::RemoveLockGlobal();
                int x = (0xa0 - Font_GetTextWidth(name, 1)) / 2;
                if (x < 0)
                    x = 0;
                func_02041a90(text, x, 6);
                if (name != NULL)
                    Text_Append(text, name);
#endif
            }
            else
            {
                int i;
                int count = 3;
                char* store = Scenario_GetInstance();
                if (Scenario_TestFlag((int)store, (unsigned char*)store + 0x8c, 0x1198))
                    count = 4;
                for (i = 0; i < count; i++)
                {
                    func_02041a90(text, 4, i * 15 + 4);
                    Text_Append(text, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x82)));
                }
            }
        }
        #if defined(jpn)
    Window_OpenPane(&self->window_, self->text_, 0, 0, 0, 0, 0);
#else
    Window_OpenPane(&self->window_, self->text_, 0, 0, 0, 0, 0, 1);
#endif
        return;
    }
    self->window_.width_ = LOW_REGION(0x12,0x16);
    self->window_.height_ = 8;
    self->window_.unknown_a4_ = 1;
    self->window_.unknown_a6_ = 0xf;
    self->window_.unknown_a8_ = 4;
    self->window_.unknown_aa_ = 5;
    self->window_.unk_ac = 0xa;
    self->window_.unknown_ae_ = 0xe;
    self->window_.unknown_b7_ = 0xa;
    self->window_.unknown_b1_ = 4;
    self->window_.unknown_b5_ = 1;
    self->window_.unknown_b6_ = 1;
    memset(self->text_, 0, LOW_REGION(0x800,0x960));
    char* labels = self->text_;
    if (labels != NULL)
    {
        MessageSystem_GetInstance();
        if (records != NULL)
        {
#if defined(jpn)
            Struct_ov008_02187f6c_3* hero = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
            char* name = self->text_ + 0x780;
            func_020e2168(name, data_ov008_0218c0d5, records->unknown_12_7_, hero->unknown_150_->appearance_.female_, 1);
            char plainName[0x80];
            __clear(plainName, sizeof(plainName));
            func_02041f50(name, plainName);
            int length = STD_GetStringLength(plainName);
            int y;
            int x = (0x80 - (length / 2) * 12) / 2;
            y = 6;
            if (length != STD_GetStringLength(name)) y = 8;
            func_02041a90(labels, x, y);
            Text_Append(labels, name);
#else
            Struct_ov008_02187f6c_3* hero = (Struct_ov008_02187f6c_3*)GameState::GetInstance()->GetProtagonist();
            char* name = self->text_ + 0x8e0;
            BackgroundLoader::AddLockGlobal();
            unsigned int size = 0;
            char inner[0x20];
            char gp2[0x40];
            __clear(gp2, sizeof(gp2));
            __clear(inner, sizeof(inner));
            sprintf(gp2, data_ov008_0218b465, hero->unknown_150_->appearance_.female_);
            sprintf(inner, data_ov008_0218b47c, hero->unknown_150_->appearance_.female_);
            void* file = ExtractFileFromGP2(gp2, inner, &size);
            if (file != NULL)
                func_020e046c(name, file, size, (short)records->unknown_12_7_);
            BackgroundLoader::RemoveLockGlobal();
            int x = (0xa0 - Font_GetTextWidth(name, 1)) / 2;
            if (x < 0)
                x = 0;
            func_02041a90(labels, x, 6);
            if (name != NULL)
                Text_Append(labels, name);
#endif
        }
        else
        {
            int i;
            int count = 3;
            char* store = Scenario_GetInstance();
            if (Scenario_TestFlag((int)store, (unsigned char*)store + 0x8c, 0x1198))
                count = 4;
            for (i = 0; i < count; i++)
            {
                func_02041a90(labels, 4, i * 15 + 4);
                Text_Append(labels, KeyTable_Get((Container020e0310*)&self->texts_, (short)(i + 0x82)));
            }
        }
    }
    #if defined(jpn)
    Window_OpenPane(&self->window_, self->text_, 0, 0, 0, 0, 0);
#else
    Window_OpenPane(&self->window_, self->text_, 0, 0, 0, 0, 0, 0);
#endif
    self->window_.width_ = LOW_REGION(5,3);
    self->window_.height_ = 8;
    self->window_.unknown_a4_ = LOW_REGION(0x1a,0x1b);
    self->window_.unknown_a6_ = 0xf;
    self->window_.unknown_a8_ = 4;
    self->window_.unknown_aa_ = 5;
    self->window_.unk_ac = 0xa;
    self->window_.unknown_ae_ = 0xe;
    self->window_.unknown_b7_ = 0xa;
    self->window_.unknown_b1_ = 5;
    self->window_.unknown_b5_ = 1;
    self->window_.unknown_b6_ = 1;
    memset(self->text_, 0, LOW_REGION(0x800,0x960));
    func_ov008_02188408(self, self->text_, 1, records);
    #if defined(jpn)
    Window_OpenPane(&self->window_, self->text_, 0, 0, 0, 0, 0);
#else
    Window_OpenPane(&self->window_, self->text_, 0, 0, 0, 0, 0, 0);
#endif
}
