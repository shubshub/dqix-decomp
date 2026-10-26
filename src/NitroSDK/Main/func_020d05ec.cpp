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
extern "C" ARM int func_020d05ec(unsigned long src, unsigned long dst, unsigned long len, Type_020d05ec callback,
    void* arg, int arg5, int arg6, int arg7, int arg8)
{
    CardReadManager* const p = &data_021118e0;
    OSi_ReferSymbol(BACKUP_MIDDLEWARE);
    {
        const int var1 = DisableIRQInterrupts();
        if (p->flags & CARD_STAT_BUSY)
            do
                BlockCurrentContext(&p->ongoingReadBlock);
            while (p->flags & CARD_STAT_BUSY);
        p->flags |= CARD_STAT_BUSY;
        p->onComplete = (CardReadManager::CompletionCallback)callback;
        p->handle = (NitroHandle*)arg;
        SetIRQInterruptState(var1);
    }
    p->cartridgeReadOffset = src;
    p->writeDst = (unsigned char*)dst;
    p->writeLength = len;
    p->unknown_2c[0] = arg6;
    p->unknown_2c[1] = arg7;
    p->unknown_2c[2] = arg8;
    if (arg5)
    {
        SendTaskToReadContext(func_020d03fc);
        return true;
    }
    data_021118e0.currentTaskExecutionContext = data_02111304.activeContext;
    func_020d03fc(p);
    return p->pSharedData->unknown_0 == CARD_RESULT_SUCCESS;
}
