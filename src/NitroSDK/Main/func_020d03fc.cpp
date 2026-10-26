#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/Interrupts.h"

struct Struct_020d03fc {
    int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_;
    unsigned int unknown_c_;
    unsigned int unknown_10_;
    unsigned int unknown_14_;
    unsigned char unknown_18_[8];
    unsigned int unknown_20_;
};

struct Struct_020d03fc_2 {
    Struct_020d03fc* unknown_0_;
    unsigned char unknown_4_[0x18];
    unsigned int unknown_1c_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
    int unknown_2c_;
    int unknown_30_;
    int unknown_34_;
    void (*unknown_38_)(void*);
    void* unknown_3c_;
    unsigned int unknown_40_;
    ProcessorContext unknown_48_;
    unsigned char unknown_110_[8];
    BlockedContextList unknown_118_;
    unsigned int unknown_120_;
    unsigned int unknown_124_;
    unsigned int unknown_128_;
    unsigned char unknown_12c_[0x100];
};

struct Struct_021118e0 {
    Struct_020d03fc* unknown_0_;
};

extern Struct_021118e0 data_021118e0;
#define BACKUP_MIDDLEWARE ((const void*)0x02000bc4)
extern "C" void OSi_ReferSymbol(const void*);
int GetBattleSysInnerField1c_020d06e8();
extern "C" int func_020d0fc4(BackupManager020d03fc*, int, int);
extern "C" void VectorizedInvertedMemcpy(const void*, void*, unsigned int);

static inline bool inline_020d03fc(const Struct_020d03fc_2* arg0) {
    return (arg0->unknown_120_ & 0x40) != 0;
}

static inline void inline_020d03fc_2(Struct_020d03fc_2* arg0, int arg1) {
    void (*const var0)(void*) = arg0->unknown_38_;
    void* const var1 = arg0->unknown_3c_;
    {
        const int var2 = DisableIRQInterrupts();
        arg0->unknown_120_ &= ~0x4c;
        UnblockContexts(&arg0->unknown_118_);
        if (arg0->unknown_120_ & 0x10) MarkContextReadyAndSwitch(&arg0->unknown_48_);
        SetIRQInterruptState(var2);
    }
    if (arg1 && var0) var0(var1);
}

// USA: func_020d03fc
extern "C" ARM void func_020d03fc(BackupManager020d03fc* manager) {
    const int requestType = manager->requestType;
    const int requestMode = manager->requestMode;
    const int retryCount = manager->retryCount;
    unsigned int size = sizeof(manager->cache);
    OSi_ReferSymbol(BACKUP_MIDDLEWARE);
    if (requestType == 11) {
        size = GetBattleSysInnerField1c_020d06e8();
    } else if (requestType == 15) {
        size = data_021118e0.command->eraseUnitSize;
    }
    do {
        const unsigned int var4 = var3 < arg0->unknown_24_ ? var3 : arg0->unknown_24_;
        arg0->unknown_0_->unknown_14_ = var4;
        if (inline_020d03fc(arg0)) {
            arg0->unknown_120_ &= ~0x40;
            arg0->unknown_0_->unknown_0_ = 7;
            break;
        }
        switch (var1) {
        case 0:
            InvalidateDataCacheRange(arg0->unknown_12c_, var4);
            arg0->unknown_0_->unknown_c_ = arg0->unknown_1c_;
            arg0->unknown_0_->unknown_10_ = (unsigned int)arg0->unknown_12c_;
            break;
        case 1:
        case 2:
            VectorizedInvertedMemcpy((const void*)arg0->unknown_1c_, arg0->unknown_12c_, var4);
            CleanInvalidateCacheRange(arg0->unknown_12c_, var4);
            DrainWriteBuffer();
            arg0->unknown_0_->unknown_c_ = (unsigned int)arg0->unknown_12c_;
            arg0->unknown_0_->unknown_10_ = arg0->unknown_20_;
            break;
        case 3:
            arg0->unknown_0_->unknown_c_ = arg0->unknown_1c_;
            arg0->unknown_0_->unknown_10_ = arg0->unknown_20_;
            break;
        }
        if (!func_020d0fc4(arg0, var0, var2)) break;
        if (var1 == 2) {
            if (func_020d0fc4(arg0, 9, 1)) goto advanceChunk;
            break;
        } else if (var1 == 0) {
            VectorizedInvertedMemcpy(arg0->unknown_12c_, (void*)arg0->unknown_20_, var4);
        }
advanceChunk:
        arg0->unknown_1c_ += var4;
        arg0->unknown_20_ += var4;
        arg0->unknown_24_ -= var4;
    } while (arg0->unknown_24_ > 0);
    inline_020d03fc_2(arg0, 1);
}
