#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/Interrupts.h"

struct Struct_020d03fc {
    int result;
    unsigned int type;
    unsigned int id;
    unsigned int source;
    unsigned int destination;
    unsigned int length;
    unsigned char unknown_18_[8];
    unsigned int unknown_20_;
};

struct Struct_020d03fc_2 {
    Struct_020d03fc* command;
    unsigned char unknown_4_[0x18];
    unsigned int source;
    unsigned int destination;
    unsigned int length;
    unsigned int unknown_28_;
    int unknown_2c_;
    int unknown_30_;
    int unknown_34_;
    void (*callback)(void*);
    void* unknown_3c_;
    unsigned int unknown_40_;
    ProcessorContext unknown_48_;
    unsigned char unknown_110_[8];
    BlockedContextList unknown_118_;
    unsigned int flags;
    unsigned int unknown_124_;
    unsigned int unknown_128_;
    unsigned char cache[0x100];
};

struct Struct_021118e0 {
    Struct_020d03fc* command;
};

extern Struct_021118e0 data_021118e0;
#define BACKUP_MIDDLEWARE ((const void*)0x02000bc4)
extern "C" void OSi_ReferSymbol(const void*);
extern "C" int func_020d06e8();
extern "C" int func_020d0fc4(Struct_020d03fc_2*, int, int);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);

static inline bool inline_020d03fc(const Struct_020d03fc_2* manager) {
    return (manager->flags & 0x40) != 0;
}

static inline void inline_020d03fc_2(Struct_020d03fc_2* manager, int arg1) {
    void (*const callback)(void*) = manager->callback;
    void* const arg = manager->unknown_3c_;
    {
        const int var2 = DisableIRQInterrupts();
        manager->flags &= ~0x4c;
        UnblockContexts(&manager->unknown_118_);
        if (manager->flags & 0x10) MarkContextReadyAndSwitch(&manager->unknown_48_);
        SetIRQInterruptState(var2);
    }
    if (arg1 && callback) callback(arg);
}

// USA: func_020d03fc
extern "C" ARM void func_020d03fc(Struct_020d03fc_2* manager) {
    const int var0 = manager->unknown_2c_;
    const int var1 = manager->unknown_34_;
    const int var2 = manager->unknown_30_;
    unsigned int size = sizeof(manager->cache);
    OSi_ReferSymbol(BACKUP_MIDDLEWARE);
    if (var0 == 11) {
        size = func_020d06e8();
    } else if (var0 == 15) {
        size = data_021118e0.command->unknown_20_;
    }
    do {
        const unsigned int length = size < manager->length ? size : manager->length;
        manager->command->length = length;
        if (inline_020d03fc(manager)) {
            manager->flags &= ~0x40;
            manager->command->result = 7;
            break;
        }
        switch (var1) {
        case 0:
            InvalidateDataCacheRange(manager->cache, length);
            manager->command->source = manager->source;
            manager->command->destination = (unsigned int)manager->cache;
            break;
        case 1:
        case 2:
            VectorizedInvertedMemcpy((const void*)manager->source, manager->cache, length);
            CleanInvalidateCacheRange(manager->cache, length);
            DrainWriteBuffer();
            manager->command->source = (unsigned int)manager->cache;
            manager->command->destination = manager->destination;
            break;
        case 3:
            manager->command->source = manager->source;
            manager->command->destination = manager->destination;
            break;
        }
        if (!func_020d0fc4(manager, var0, var2)) break;
        if (var1 == 2) {
            if (func_020d0fc4(manager, 9, 1)) goto advanceChunk;
            break;
        } else if (var1 == 0) {
            VectorizedInvertedMemcpy(manager->cache, (void*)manager->destination, length);
        }
advanceChunk:
        manager->source += length;
        manager->destination += length;
        manager->length -= length;
    } while (manager->length > 0);
    inline_020d03fc_2(manager, 1);
}
