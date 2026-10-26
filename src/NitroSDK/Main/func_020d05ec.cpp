#include <globaldefs.h>
#include "NitroSDK/Filesystem/FSInnerDefs.h"
#include "NitroSDK/Interrupts.h"

#define BACKUP_MIDDLEWARE ((const void*)0x02000bc4)
#define CARD_STAT_BUSY 0x4
#define CARD_RESULT_SUCCESS 0

typedef void (*Type_020d05ec)(void* arg);

extern "C" void OSi_ReferSymbol(const void* symbol);
extern "C" void func_020d03fc(CardReadManager* p);

// USA: func_020d05ec
extern "C" ARM int func_020d05ec(unsigned long arg0, unsigned long arg1, unsigned long arg2, Type_020d05ec arg3,
    void* arg4, int arg5, int arg6, int arg7, int arg8)
{
    CardReadManager* const p = &data_021118e0;
    OSi_ReferSymbol(BACKUP_MIDDLEWARE);
    {
        const int var1 = DisableIRQInterrupts();
        if (var0->flags & CARD_STAT_BUSY)
            do
                BlockCurrentContext(&var0->ongoingReadBlock);
            while (var0->flags & CARD_STAT_BUSY);
        var0->flags |= CARD_STAT_BUSY;
        var0->onComplete = (CardReadManager::CompletionCallback)arg3;
        var0->handle = (NitroHandle*)arg4;
        SetIRQInterruptState(var1);
    }
    var0->cartridgeReadOffset = arg0;
    var0->writeDst = (unsigned char*)arg1;
    var0->writeLength = arg2;
    var0->unknown_2c[0] = arg6;
    var0->unknown_2c[1] = arg7;
    var0->unknown_2c[2] = arg8;
    if (arg5)
    {
        SendTaskToReadContext(func_020d03fc);
        return true;
    }
    data_021118e0.currentTaskExecutionContext = data_02111304.activeContext;
    func_020d03fc(var0);
    return var0->pSharedData->unknown_0 == CARD_RESULT_SUCCESS;
}
