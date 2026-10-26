#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Filesystem/BackgroundLoader.h"

struct StateBits5ccc_1155c;
extern "C" void GameState_ClearErrorScreenRequest(struct StateBits5ccc_1155c* state);
extern "C" int func_02075ca0();
extern "C" void func_02075cb8();

extern "C" int func_02075910(int a, void* p, unsigned int size, int c);
extern "C" int func_02075acc(int a, void* p, unsigned int size, int c);
extern "C" int func_01ff85b8(void* buf, int size);
extern "C" int strcmp(const char* a, const char* b);

struct Struct_020a94f8_2 {
    int hdr;
    char data[0x10];
};
extern "C" int func_020a94f8(struct Struct_020a94f8_2* buf, int flag);

struct Struct_020ab7a8_2 {
    int hdr;
    unsigned char pad[4];
    char str[12];
};

struct Struct_020ab7a8_3 {
    int hdr;
    char data[0x5c];
};

struct Struct_020ab7a8_4 {
    int hdr;
    char data[0x6f5c];
};

struct SaveBuf020ab7a8 {
    struct Struct_020ab7a8_2 head;
    struct Struct_020ab7a8_3 unknown_14_;
    struct Struct_020ab7a8_4 tail;
};

struct Struct_020ab7a8 {
    unsigned char pad0;
    unsigned char state;
    unsigned char pad2[2];
    struct SaveBuf020ab7a8* buf;
};

extern "C" char g_fileLoadBuffer[];
extern "C" char data_020f1be8;

// USA: func_020ab7a8
extern "C" ARM int func_020ab7a8(void* obj, int flag) {
    struct Struct_020ab7a8* task = (struct Struct_020ab7a8*)obj;
    char local0;
    char local1;
    struct Struct_020a94f8_2 buf;

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
        task->state = 1;
    } else if (task->state == 1) {
        if (func_02075ca0() == 0) {
            return 0;
        }
        func_02075cb8();
        if (func_02075910(0, &local1, 1, 0) == 0) {
            return 2;
        }
        if (func_01ff85b8(&task->buf->head.pad[0], 0x10) != task->buf->head.hdr) {
            return 3;
        }
        if (task->buf->head.pad[1] == 0) {
            return 3;
        }
        if (strcmp(task->buf->head.str, &data_020f1be8) == 0) {
            return 3;
        }
        struct SaveBuf020ab7a8* var4 = task->buf;
        if (func_01ff85b8(&var4->unknown_14_.data[0], 0x5c) != var4->unknown_14_.hdr) {
            return 3;
        }
        struct SaveBuf020ab7a8* tail = task->buf;
        if (func_01ff85b8(&tail->tail.data[0], 0x6f5c) != tail->tail.hdr) {
            return 3;
        }
        func_02075acc(flag ? 0x10 : 0x8010, task->buf, 0x6fe4, 1);
        task->state = 2;
        return 4;
    } else if (task->state == 2) {
        if (func_02075ca0() == 0) {
            return 4;
        }
        func_02075cb8();
        if (flag) {
            if (func_020a94f8(&buf, 1) != 0) {
                buf.data[0] = 0;
                buf.hdr = func_01ff85b8((char*)&buf + 4, 0x10);
                func_02075acc(0x10, &buf, 0x14, 0);
            }
        }
        task->state = 3;
        return 5;
    } else {
        return 5;
    }
    return 0;
}
