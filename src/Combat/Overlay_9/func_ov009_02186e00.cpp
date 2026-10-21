#include "Input/Input.h"

#if defined(jpn)
#include <globaldefs.h>
#include <std_library_functions.h>
#include "Resource/CharacterCreationUI.h"

struct Obj0205eaa0;
struct PartyMemberData { char unknown[0x3c]; char name[1]; };
extern "C" void CharacterCreationUI_SetupSlotNavigation(CharacterCreationUI*);
extern "C" void CharacterCreationUI_LoadSlotLayout(void*);
extern "C" void CharacterCreationUI_MoveCursorToSlot(CharacterCreationUI*, int);
extern "C" int func_ov009_02185c58(void*);
extern "C" int CharacterCreationUI_HandleInput(CharacterCreationUI*);
extern "C" void func_ov009_0218ad0c(void*);
extern "C" void func_ov009_021867bc(unsigned char*, int);
extern "C" void func_0205eaa0(Struct_02108760*, int, int);
extern char data_ov009_0218bc59[];
extern const char data_020ef078[];
extern Struct_02108760 data_02108760;

extern "C" ARM void func_ov009_02186e00(Struct_ov009_021842a0* arg0)
{
    if (self->step == 0) {
        self->keyboardChoice = 0;
        CharacterCreationUI_SetupSlotNavigation(self);
        CharacterCreationUI_LoadSlotLayout(self);
        CharacterCreationUI_MoveCursorToSlot(self, self->keyboardChoice);
        self->flags |= 1;
        self->keyboardPage = self->previousKeyboardPage = 0;
        self->flags &= ~0x800;
        if (self->nameFlags[self->sex] != 0 && self->names[self->sex][8] == 0) {
            for (int character = 1; character < 5; character++) {
                if (self->names[self->sex][character * 2] == 0) {
                    for (int fill = character; fill < 5; fill++)
                        memcpy(&self->names[self->sex][fill * 2], data_ov009_0218bc59, 2);
                }
            }
            arg0->unknown_d9c_ |= 0x8000;
        }
        arg0->unknown_c59_++;
    } else if (arg0->unknown_c59_ == 1) {
        if (arg0->unknown_d9c_ & 0x80)
            return;
        if (!func_ov009_02185c58(arg0->unknown_dc_))
            return;
        int result = CharacterCreationUI_HandleInput(self);
        if (result == -2) {
            func_ov009_0218ad0c(self);
        } else if (result == -3) {
            func_ov009_021867bc((unsigned char*)self, 7);
        } else if (result >= 101 && result <= 108) {
            result -= 100;
            if (result <= self->furthestState[self->sex] && result != self->state)
                func_ov009_021867bc((unsigned char*)self, (unsigned char)result);
        }
        if (arg0->unknown_d9c_ & 0x400000) {
            arg0->unknown_d9c_ |= 0x2000;
            arg0->unknown_c59_++;
        }
        if (arg0->unknown_d9c_ & 0x800) {
            if (var2 == -2)
                arg0->unknown_d9c_ |= 0x1000000;
            Struct_ov005_0215840c_2* var3 = (Struct_ov005_0215840c_2*)arg0->unknown_d88_;
            sprintf(var3->unknown_3c_, data_020ef078, arg0->unknown_d74_[arg0->unknown_da3_]);
            func_ov009_021867bc((unsigned char*)arg0, 9);
        }
    } else if (arg0->unknown_c59_ == 2) {
        if (g_keyManager.TestKeysPressed(0x401) || g_touchInput.pressed_ != 0) {
            func_0205eaa0(&data_02108760, 1, 0);
            arg0->unknown_d9c_ = (arg0->unknown_d9c_ & ~0x400000) | 0x2000;
            arg0->unknown_c59_ = 1;
        } else if (g_keyManager.TestKeysPressed(2)) {
            arg0->unknown_d9c_ = (arg0->unknown_d9c_ & ~0x400000) | 0x2000;
            arg0->unknown_c59_ = 1;
        }
    }
}

#else
#include <globaldefs.h>
#include <std_library_functions.h>
#include "GameState/GameState.h"

struct Struct_ov003_0215f4e4_2 {
    short unknown_0_;
    short unknown_2_;
    const char* unknown_4_;
    const char* unknown_8_;
    unsigned char unknown_c_;
    unsigned char unknown_d_;
    unsigned char unknown_e_;
    unsigned char unknown_f_;
    char unknown_10_[4];
};

struct Struct_ov003_0215f4e4 {
    Struct_ov003_0215f4e4_2* unknown_0_;
    void* unknown_4_;
    char* unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    int unknown_18_;
    short unknown_1c_;
    unsigned char unknown_1e_;
    unsigned char unknown_1f_;
    unsigned char unknown_20_;
    unsigned char unknown_21_;
    unsigned char unknown_22_;
    unsigned char unknown_23_;
    unsigned char unknown_24_;
    char unknown_25_[3];

    void inline_ov009_02186e00(char* arg0, int arg1)
    {
        unknown_8_ = arg0;
        unknown_10_ = arg1;
    }
};

struct Struct_ov009_02186e00 {
    const char* unknown_0_;
    signed char unknown_4_;
};

struct Struct_ov009_02186e00_2 {
    char unknown_0_[4];
    int unknown_4_;
    char unknown_8_[0x38];
};

struct Struct_ov005_0215840c_2 {
    char unknown_0_[0x3c];
    char unknown_3c_[1];
};

struct Struct_02108760;
struct Struct_0205bef8;
struct Struct_0205ba68;
struct Struct_0205bacc;

extern "C" void func_ov003_0215f41c(Keyboard* keyboard, const char* text);
CharacterInfo* FindEntryByKey0204254c(int character, int mode);
extern "C" int func_ov003_0215f000(Keyboard* keyboard, int ticks);
extern "C" int CharacterCreationUI_HandleInput(void* self);
extern "C" void func_ov009_02189a4c(void* self);
void SetStatValue021855dc(unsigned char* self, int state);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0* sound, int effect, int a);
void BuildFieldTag_021d9e60(char* self);
extern "C" KeyboardKey* func_ov003_0215f4a4(Keyboard* keyboard, int a);
void ResetEntrySkill0218a8b8(void* self);
void Init0205bef8(Struct_0205bef8* cursor);
void SetupPointerTable0205ba68(Struct_0205ba68* cursor, int columns, int rows, int a);
void SetField0AndPropagate0205bacc(Node0205bacc* cursor, int count);
extern "C" void func_0205bb04(WindowCursor* cursor, int a);
void StoreResultIfNonZero_0215f4e4(Keyboard* keyboard, int id);
extern "C" void func_ov003_0215ec68(int size, short* width, short* height);

extern char data_ov009_0218ad26[];
extern char data_ov009_0218ad2a[];
extern char data_02108760[];
extern const char data_020ef078[];

struct Struct_ov009_021842a0_2 {
    char unknown_0_[0xbc];
    Struct_ov003_0215f4e4_2* unknown_bc_;
    Struct_ov003_0215f4e4* unknown_c0_;
    char unknown_c4_[0xbec - 0xc4];
    Struct_ov009_02186e00_2 unknown_bec_;
    char unknown_c2c_[0xc4c - 0xc2c];
    short unknown_c4c_;
    short unknown_c4e_;
    short unknown_c50_;
    short unknown_c52_;
    short unknown_c54_;
    short unknown_c56_;
    signed char unknown_c58_;
    unsigned char unknown_c59_;
    char unknown_c5a_[0xd88 - 0xc5a];
    Struct_ov005_0215840c_2* unknown_d88_;
    char unknown_d8c_[0xd9c - 0xd8c];
    unsigned int unknown_d9c_;
    signed char unknown_da0_[2];
    unsigned char unknown_da2_;
    unsigned char unknown_da3_;
    char unknown_da4_[0xdb0 - 0xda4];
    char** unknown_db0_;
    unsigned char unknown_db4_;
    unsigned char unknown_db5_;
};

// USA: func_ov009_02186e00
extern "C" ARM void func_ov009_02186e00(Struct_ov009_021842a0_2* arg0)
{
    if (arg0->unknown_c59_ == 0)
    {
        arg0->unknown_c0_->inline_ov009_02186e00(arg0->unknown_db0_[arg0->unknown_da3_], 0x48);
        arg0->unknown_c0_->unknown_14_ = 8;
        arg0->unknown_c0_->unknown_1f_ = 0;
        arg0->unknown_c0_->unknown_21_ = 0;
        arg0->unknown_c0_->unknown_24_ = 1;
        func_ov003_0215f41c(arg0->unknown_c0_, data_ov009_0218ad26);
        arg0->unknown_bc_ = arg0->unknown_c0_->unknown_0_;
        if (arg0->unknown_bc_ != NULL)
            arg0->unknown_c0_->unknown_0_ = arg0->unknown_bc_;
        arg0->unknown_bc_ = NULL;
        Struct_ov009_02186e00* var4 = func_0204254c((int)data_ov009_0218ad2a, 0);
        if (var4 != NULL)
            arg0->unknown_c0_->unknown_c_ = var4->unknown_4_ * 8 + 7;
        arg0->unknown_c59_++;
    }
    else if (arg0->unknown_c59_ == 1)
    {
        arg0->unknown_c0_->unknown_18_ = 0;
        arg0->unknown_c0_->unknown_1c_ = 0;
        arg0->unknown_d9c_ |= 1;
        arg0->unknown_d9c_ &= ~0x800;
        arg0->unknown_d9c_ |= 0x8100;
        arg0->unknown_c59_++;
    }
    else if (arg0->unknown_c59_ == 2)
    {
        if (arg0->unknown_d9c_ & 0x80)
            return;
        self->keyboardResult_ = func_ov003_0215f000(self->keyboard_, GameState::GetInstance()->GetTickCount());
        int result = CharacterCreationUI_HandleInput(self);
        if (self->keyboardResult_ != 0)
            result = -1;
        int checked = 0;
        if (result == -2)
        {
            var6 = 1;
            func_ov009_02189a4c(arg0);
        }
        else if (var5 == -3)
        {
            func_ov009_021855dc((unsigned char*)arg0, 7);
            return;
        }
        else if (var5 >= 101 && var5 <= 108)
        {
            var5 -= 100;
            if (var5 <= arg0->unknown_da0_[arg0->unknown_da3_] && var5 != arg0->unknown_c58_)
            {
                func_ov009_021855dc((unsigned char*)arg0, (unsigned char)var5);
                return;
            }
        }

        arg0->unknown_d9c_ |= 0x2000;
        switch (arg0->unknown_db5_)
        {
        case 1:
            func_0205eaa0((Struct_02108760*)data_02108760, 2, 0);
            break;
        case 9:
            if (!g_keyManager.TestKeysPressed(1) && g_touchInput.pressed_ == 0)
                func_ov009_021855dc((unsigned char*)arg0, 7);
            else
                func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            arg0->unknown_d9c_ |= 0x8100;
            break;
        case 2:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 11:
            if (!g_keyManager.TestKeysPressed(2))
                func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            arg0->unknown_d9c_ |= 0x8100;
            break;
        case 3:
            func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            arg0->unknown_d9c_ |= 0x8100;
            func_ov023_021d9e60((char*)arg0);
            if (g_keyManager.TestKeysPressed(1))
            {
                Struct_ov003_0215f4e4_2* var7 = func_ov003_0215f4a4(arg0->unknown_c0_, 6);
                if (var7 != NULL)
                    arg0->unknown_c0_->unknown_0_ = var7;
            }
            break;
        case 10:
            if (*arg0->unknown_db0_[arg0->unknown_da3_] == 0)
                func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            if (var6 == 0)
            {
                var6 = 1;
                func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
                func_ov009_02189a4c(arg0);
            }
            break;
        case 13:
            func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            break;
        case 12:
            func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            func_ov009_0218a8b8(arg0);
            arg0->unknown_d9c_ |= 0x8100;
            return;
        default:
            arg0->unknown_d9c_ &= ~0x2000;
            if (g_keyManager.TestKeysPressed(4) && var5 != -2)
            {
                if (arg0->unknown_c0_->unknown_0_ != NULL)
                {
                    func_ov009_0218a8b8(arg0);
                    arg0->unknown_d9c_ |= 0x8100;
                    return;
                }
            }
            else if (g_keyManager.TestKeysPressed(0xc0))
            {
                arg0->unknown_d9c_ |= 0x2000;
            }
            break;
        }

        if (arg0->unknown_db5_ != 0 && arg0->unknown_db5_ != 8)
        {
            Struct_ov009_02186e00_2* var8 = &arg0->unknown_bec_;
            func_0205bef8((Struct_0205bef8*)var8);
            func_0205ba68((Struct_0205ba68*)var8, 11, 6, 1);
            func_0205bacc((Struct_0205bacc*)var8, 0x42);
            var8->unknown_4_ = 1;
            func_0205bb04(var8, 0);
        }
        if (g_keyManager.TestKeysPressed(8) && !(arg0->unknown_d9c_ & 0x8100) &&
            arg0->unknown_c0_->unknown_0_ != NULL && var6 == 0)
            func_ov009_02189a4c(arg0);
        if (arg0->unknown_d9c_ & 0x400000)
        {
            arg0->unknown_d9c_ |= 0x2000 | 0x1000000;
            arg0->unknown_c59_++;
        }
        if (arg0->unknown_d9c_ & 0x800)
        {
            Struct_ov009_02186e00_2* var9 = &arg0->unknown_bec_;
            func_0205bef8((Struct_0205bef8*)var9);
            func_0205ba68((Struct_0205ba68*)var9, 11, 6, 1);
            func_0205bacc((Struct_0205bacc*)var9, 0x42);
            var9->unknown_4_ = 1;
            func_0205bb04(var9, 0);
            func_ov003_0215f4e4(arg0->unknown_c0_, 6);
            arg0->unknown_d9c_ |= 0x1000000;
            sprintf(arg0->unknown_d88_->unknown_3c_, data_020ef078, arg0->unknown_db0_[arg0->unknown_da3_]);
            func_ov009_021855dc((unsigned char*)arg0, 9);
        }
    }
    else if (arg0->unknown_c59_ == 3)
    {
        if (g_keyManager.TestKeysPressed(0x401) || g_touchInput.pressed_ != 0)
        {
            func_0205eaa0((Struct_02108760*)data_02108760, 1, 0);
            arg0->unknown_d9c_ = (arg0->unknown_d9c_ & ~0x1400000) | 0x2000;
            arg0->unknown_c59_ = 2;
        }
        else if (g_keyManager.TestKeysPressed(2))
        {
            arg0->unknown_d9c_ = (arg0->unknown_d9c_ & ~0x1400000) | 0x2000;
            arg0->unknown_c59_ = 2;
        }
    }

    Struct_ov003_0215f4e4_2* var10 = arg0->unknown_c0_->unknown_0_;
    if (var10 != NULL)
    {
        short var11;
        short var12;
        func_ov003_0215ec68(var10->unknown_e_, &var11, &var12);
        arg0->unknown_c4c_ = var10->unknown_0_;
        arg0->unknown_c4e_ = var10->unknown_2_;
        arg0->unknown_c50_ = var11;
        arg0->unknown_c52_ = var12;
    }
}

#endif
