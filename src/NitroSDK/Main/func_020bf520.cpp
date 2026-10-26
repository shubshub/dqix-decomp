#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"
#include "NitroSDK/ProcessorContext.h"

extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

struct Struct_020bf520 {
    char pad0[0x11c];
    int unknown_11c_;
};

struct Struct_020bf520_2 {
    SignedAllocatorHeader* prev;
    SignedAllocatorHeader* next;
    Struct_020bf520* player;
    int status;
    int unknown_10_;
    void* buffer[6];
    unsigned int unknown_2c_;
};

struct Struct_02110560 {
    char pad0[0x4c0];
    BlockedContextList unknown_4c0_;
    char pad1[0x4e0 - 0x4c8];
    SignedAllocatorList unknown_4e0_;
};

struct Struct_021103b0_5 { int f0; Struct_02110560* unknown_4_; };

extern SignedAllocatorList data_02110a40;
extern Struct_02110560 data_02110560;
extern Struct_021103b0_5 data_021103b0;

extern "C" SignedAllocatorHeader* func_020bf418(void);
extern "C" void func_020bf458(SignedAllocatorHeader* header);

// USA: func_020bf520
extern "C" ARM void func_020bf520(int status, int arg1, void* buffer[], unsigned int len, int format, void* arg) {
    Struct_020bf520* player = (Struct_020bf520*)arg;
    Struct_020bf520_2* command;
    Struct_02110560* var2;
    int ch;

    if (player->unknown_11c_ >= 2) {
        command = NULL;
        while ((command = (Struct_020bf520_2*)data_02110a40.ElementAfter((SignedAllocatorHeader*)command)) != NULL) {
            if (command->player == player)
                break;
        }

        for (ch = 0; ch < command->unknown_10_; ch++) {
            VectorizedMemset(command->buffer[ch], 0, command->unknown_2c_);
        }

        data_02110a40.Remove((SignedAllocatorHeader*)command);
        player->unknown_11c_--;
        func_020bf458((SignedAllocatorHeader*)command);
    }

    command = (Struct_020bf520_2*)func_020bf418();

    command->player = player;
    command->status = status;
    command->unknown_10_ = arg1;
    for (ch = 0; ch < arg1; ch++) {
        command->buffer[ch] = buffer[ch];
    }
    command->unknown_2c_ = len;

    var2 = &data_02110560;
    if (status == 0 && data_021103b0.unknown_4_)
        var2 = data_021103b0.unknown_4_;

    player->unknown_11c_++;
    var2->unknown_4e0_.InsertAtEnd((SignedAllocatorHeader*)command);

    UnblockContexts(&var2->unknown_4c0_);
}
