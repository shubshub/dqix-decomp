#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

struct FontBankLoader;
extern "C" void* MessageSystem_GetInstance();
struct ListHead02046b60;
extern "C" int func_02046b60(ListHead02046b60*, int);
extern "C" void func_ov016_0218b5c0(int, int);
extern "C" void func_ov017_0218b5f8(int);
extern "C" void func_02046380(void*);
#if defined(jpn)
extern "C" void func_0204500c(void*, void*, int);
#else
extern "C" void func_0204500c(void*, void*, int, int);
#endif
extern "C" void func_02042b3c(void*);
extern "C" void MessageSystem_Reset(char*);
extern char data_020f2348[];

struct Struct_020d7b04_2 {
#if defined(jpn)
    char text[0x4f];
    unsigned char style : 7;
#else
    char text[0x6f];
    unsigned char style : 6;
    unsigned char unknown_6f_6_ : 1;
#endif
    unsigned char unknown_6f_7_ : 1;
};

struct Struct_020d7b04_3 {
    Struct_020d7b04_2 entries[3];
    unsigned char count : 6;
    unsigned char unknown_150_6_ : 1;
    unsigned char unknown_150_7_ : 1;
    unsigned char unknown_151_;
    unsigned short unknown_152_;
};

struct MessageWindowState {
#if defined(jpn)
    char unknown0[0x868];
#else
    char unknown0[0x998];
#endif
    int active;
#if defined(jpn)
    char unknown_86c_[0x17e2 - 0x86c];
#else
    char unknown_99c_[0x19b2 - 0x99c];
#endif
    unsigned char state;
#if defined(jpn)
    char unknown_17e3_[0x17ff - 0x17e3];
    unsigned char unknown_17ff_0_ : 2;
    unsigned char blocked : 1;
    unsigned char unknown_17ff_3_ : 5;
#else
    char unknown_19b3_[0x19d0 - 0x19b3];
    unsigned char blocked;
#endif
};

extern "C" ARM void func_020d7b04(Struct_020d7b04_3* queue) {
    char formattedText[0xc8];
    GameState* game = GameState::GetInstance();
    FontBankLoader* fonts = FontBankLoader_GetInstance();
    MessageWindowState* window = static_cast<MessageWindowState*>(MessageSystem_GetInstance());
    if (queue->unknown_150_7_ && !func_02094b4c(fonts)) return;

    void* requests = GetGameResources()->fieldTaskQueue_;
    if (func_02046b60((ListHead02046b60*)requests, 0x25)) return;
    if (func_02046b60((ListHead02046b60*)requests, 0x26)) return;

    unsigned short elapsed = game->GetEffectiveDeltaTime();
    if (queue->unknown_152_ != 0) {
        if (elapsed < queue->unknown_152_) {
            queue->unknown_152_ -= elapsed;
            return;
        }
        if (window->blocked) return;
        queue->unknown_152_ = 0;
        if (queue->count == 0) return;
        memcpy(&queue->entries[0], &queue->entries[1], sizeof(Struct_020d7b04_2));
        memcpy(&queue->entries[1], &queue->entries[2], sizeof(Struct_020d7b04_2));
        queue->count--;
        if (queue->count == 0) {
            func_ov016_0218b5c0(1, -1);
            func_ov017_0218b5f8(-1);
        }
        return;
    }

    if (window->blocked) return;
    if (queue->count != 0) {
        if (queue->entries[0].style != 0) {
            int var6 = 1;
            if (queue->entries[0].unknown_6f_7_) {
                var6 = !func_02046b60((ListHead02046b60*)requests, 0xc);
            }
            if (var6) {
                func_02094b3c(fonts, 10);
                func_02094b30(fonts, 505, 0);
                queue->entries[0].style = 0;
                queue->unknown_150_7_ = 1;
                return;
            }
        }
        sprintf(formattedText, data_020f2348, queue->entries[0].text);
        if (queue->count > 1) {
            queue->unknown_152_ = 1000;
        } else {
            queue->unknown_152_ = 3000;
        }
        if (queue->entries[0].text[0] != 0) {
#if defined(jpn)
            func_0204500c(window, formattedText, 0);
#else
            func_02046380(window);
            if (queue->entries[0].unknown_6f_6_) {
                func_0204500c(window, formattedText, 0, 0xe3);
            } else {
                func_0204500c(window, formattedText, 0, 0x100);
            }
#endif
            func_02042b3c(window);
            window->active = 1;
            window->state = 1;
            queue->unknown_150_6_ = 1;
            return;
        }
        queue->unknown_150_6_ = 0;
        queue->unknown_152_ = 0;
        queue->count = 0;
        return;
    } else {
        if (queue->unknown_150_7_) {
            FontBankLoader_CancelLoads(fonts);
            queue->unknown_150_7_ = 0;
        }
        if (queue->unknown_150_6_) {
            MessageSystem_Reset(static_cast<char*>(MessageSystem_GetInstance()));
            queue->unknown_150_6_ = 0;
        }
    }
    queue->unknown_152_ = 0;
    queue->count = 0;
}
