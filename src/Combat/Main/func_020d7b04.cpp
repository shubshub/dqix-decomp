#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct FontBankLoader;
void* MessageSystem_GetInstance();
struct ListHead02046b60;
int ListContainsId(ListHead02046b60*, int);
extern "C" void func_ov016_0218b5c0(int, int);
extern "C" void func_ov017_0218b5f8(int);
extern "C" void func_02046380(void*);
#if defined(jpn)
extern "C" void func_0204500c(void*, void*, int);
#else
extern "C" void func_0204500c(void*, void*, int, int);
#endif
void InitFields02042b3c(void*);
void MessageSystem_Reset(char*);
extern char data_020f2348[];

struct Struct_020d7b04_2 {
#if defined(jpn)
    char unknown_0_[0x4f];
    unsigned char unknown_6f_0_ : 7;
#else
    char unknown_0_[0x6f];
    unsigned char unknown_6f_0_ : 6;
    unsigned char unknown_6f_6_ : 1;
#endif
    unsigned char unknown_6f_7_ : 1;
};

struct Struct_020d7b04_3 {
    Struct_020d7b04_2 unknown_0_[3];
    unsigned char unknown_150_0_ : 6;
    unsigned char unknown_150_6_ : 1;
    unsigned char unknown_150_7_ : 1;
    unsigned char unknown_151_;
    unsigned short unknown_152_;
};

struct Struct_020d7b04 {
#if defined(jpn)
    char unknown_0_[0x868];
#else
    char unknown1_0_[0x998];
#endif
    int unknown_998_;
#if defined(jpn)
    char unknown_86c_[0x17e2 - 0x86c];
#else
    char unknown_99c_[0x19b2 - 0x99c];
#endif
    unsigned char unknown_19b2_;
#if defined(jpn)
    char unknown_17e3_[0x17ff - 0x17e3];
    unsigned char unknown_17ff_0_ : 2;
    unsigned char unknown_19d0_ : 1;
    unsigned char unknown_17ff_3_ : 5;
#else
    char unknown_19b3_[0x19d0 - 0x19b3];
    unsigned char unknown_19d0_;
#endif
};

extern "C" ARM void func_020d7b04(TextMessageQueue* queue) {
    char formattedText[0xc8];
    GameState* game = GameState::GetInstance();
    FontBankLoader* fonts = FontBankLoader_GetInstance();
    MessageWindowState* window = static_cast<MessageWindowState*>(MessageSystem_GetInstance());
    if (queue->fontRequested && !AlwaysTrue02094b4c(fonts)) return;

    void* requests = GetGameResources()->fieldTaskQueue_;
    if (ListContainsId((ListHead02046b60*)requests, 0x25)) return;
    if (ListContainsId((ListHead02046b60*)requests, 0x26)) return;

    unsigned short var5 = var1->GetEffectiveDeltaTime();
    if (arg0->unknown_152_ != 0) {
        if (var5 < arg0->unknown_152_) {
            arg0->unknown_152_ -= var5;
            return;
        }
        if (var3->unknown_19d0_) return;
        arg0->unknown_152_ = 0;
        if (arg0->unknown_150_0_ == 0) return;
        memcpy(&arg0->unknown_0_[0], &arg0->unknown_0_[1], sizeof(Struct_020d7b04_2));
        memcpy(&arg0->unknown_0_[1], &arg0->unknown_0_[2], sizeof(Struct_020d7b04_2));
        arg0->unknown_150_0_--;
        if (arg0->unknown_150_0_ == 0) {
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
        }
        return;
    }

    if (var3->unknown_19d0_) return;
    if (arg0->unknown_150_0_ != 0) {
        if (arg0->unknown_0_[0].unknown_6f_0_ != 0) {
            int var6 = 1;
            if (arg0->unknown_0_[0].unknown_6f_7_) {
                var6 = !func_02046b60((Struct_02038598_5*)var4, 0xc);
            }
            if (var6) {
                func_02094b3c(var2, 10);
                func_02094b30(var2, 505, 0);
                arg0->unknown_0_[0].unknown_6f_0_ = 0;
                arg0->unknown_150_7_ = 1;
                return;
            }
        }
        sprintf(var0, data_020f2348, arg0->unknown_0_[0].unknown_0_);
        if (arg0->unknown_150_0_ > 1) {
            arg0->unknown_152_ = 1000;
        } else {
            arg0->unknown_152_ = 3000;
        }
        if (arg0->unknown_0_[0].unknown_0_[0] != 0) {
#if defined(jpn)
            func_0204500c(var3, var0, 0);
#else
            func_02046380(var3);
            if (arg0->unknown_0_[0].unknown_6f_6_) {
                func_0204500c(var3, var0, 0, 0xe3);
            } else {
                func_0204500c(var3, var0, 0, 0x100);
            }
#endif
            func_02042b3c(var3);
            var3->unknown_998_ = 1;
            var3->unknown_19b2_ = 1;
            arg0->unknown_150_6_ = 1;
            return;
        }
        arg0->unknown_150_6_ = 0;
        arg0->unknown_152_ = 0;
        arg0->unknown_150_0_ = 0;
        return;
    } else {
        if (queue->fontRequested) {
            FontBankLoader_CancelLoads(fonts);
            queue->fontRequested = 0;
        }
        if (queue->windowActive) {
            MessageSystem_Reset(static_cast<char*>(MessageSystem_GetInstance()));
            queue->windowActive = 0;
        }
    }
    arg0->unknown_152_ = 0;
    arg0->unknown_150_0_ = 0;
}
