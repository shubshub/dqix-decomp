#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct StateBits5ccc_1155c;
void GameState_ClearErrorScreenRequest(struct StateBits5ccc_1155c* state);
int IsFunc020d0840NonZero_02075ca0();
void NotifyU16AndSetFlag02075cb8();

extern "C" int func_02075910(int arg0, void* arg1, unsigned int arg2, int arg3);
extern "C" int func_02075acc(int arg0, void* arg1, unsigned int arg2, int arg3);
extern "C" int func_01ff85b8(void* arg0, int arg1);
extern "C" int strcmp(const char* arg0, const char* arg1);

struct Struct_020a94f8_2 {
    int unknown_0_;
    char unknown_4_[0x10];
};
extern "C" int func_020a94f8(struct Struct_020a94f8_2* arg0, int arg1);

struct Struct_020ab7a8_2 {
    int unknown_0_;
    unsigned char unknown_4_[4];
    char unknown_8_[12];
};

struct Struct_020ab7a8_3 {
    int unknown_0_;
    char unknown_4_[0x5c];
};

struct Struct_020ab7a8_4 {
    int unknown_0_;
    char unknown_4_[0x6f5c];
};

struct Struct_020ab7a8_5 {
    struct Struct_020ab7a8_2 unknown_0_;
    struct Struct_020ab7a8_3 unknown_14_;
    struct Struct_020ab7a8_4 unknown_74_;
};

struct Struct_020ab7a8 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_[2];
    struct Struct_020ab7a8_5* unknown_4_;
};

extern "C" char g_fileLoadBuffer[];
extern "C" char data_020f1be8;

// USA: func_020ab7a8
extern "C" ARM int func_020ab7a8(void* arg0, int arg1) {
    struct Struct_020ab7a8* var0 = (struct Struct_020ab7a8*)arg0;
    char var1;
    char var2;
    struct Struct_020a94f8_2 var3;

    if (task->state == 0) {
        GameState_ClearErrorScreenRequest((struct StateBits5ccc_1155c*)GameState::GetInstance());
        if (func_02075910(0, &local0, 1, 0) == 0) {
            return 1;
        }
        BackgroundLoader::FreeAllocationsGlobal();
        task->buf = (struct SaveBuf020ab7a8*)((unsigned char*)&g_fileLoadBuffer[0] + 0x2901c);
        if (func_02075910(flag ? 0x8010 : 0x10, task->buf, 0x6fe4, 1) == 0) {
            return 1;
        }
        var0->unknown_1_ = 1;
    } else if (var0->unknown_1_ == 1) {
        if (func_02075ca0() == 0) {
            return 0;
        }
        func_02075cb8();
        if (func_02075910(0, &var2, 1, 0) == 0) {
            return 2;
        }
        if (func_01ff85b8(&var0->unknown_4_->unknown_0_.unknown_4_[0], 0x10) != var0->unknown_4_->unknown_0_.unknown_0_) {
            return 3;
        }
        if (var0->unknown_4_->unknown_0_.unknown_4_[1] == 0) {
            return 3;
        }
        if (strcmp(var0->unknown_4_->unknown_0_.unknown_8_, &data_020f1be8) == 0) {
            return 3;
        }
        struct Struct_020ab7a8_5* var4 = var0->unknown_4_;
        if (func_01ff85b8(&var4->unknown_14_.unknown_4_[0], 0x5c) != var4->unknown_14_.unknown_0_) {
            return 3;
        }
        struct Struct_020ab7a8_5* var5 = var0->unknown_4_;
        if (func_01ff85b8(&var5->unknown_74_.unknown_4_[0], 0x6f5c) != var5->unknown_74_.unknown_0_) {
            return 3;
        }
        func_02075acc(arg1 ? 0x10 : 0x8010, var0->unknown_4_, 0x6fe4, 1);
        var0->unknown_1_ = 2;
        return 4;
    } else if (var0->unknown_1_ == 2) {
        if (func_02075ca0() == 0) {
            return 4;
        }
        func_02075cb8();
        if (arg1) {
            if (func_020a94f8(&var3, 1) != 0) {
                var3.unknown_4_[0] = 0;
                var3.unknown_0_ = func_01ff85b8((char*)&var3 + 4, 0x10);
                func_02075acc(0x10, &var3, 0x14, 0);
            }
        }
        var0->unknown_1_ = 3;
        return 5;
    } else {
        return 5;
    }
    return 0;
}
