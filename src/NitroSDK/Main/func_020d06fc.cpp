#include <globaldefs.h>

#include "Filesystem/BackupDevice.h"
#include "NitroSDK/Filesystem/FSInnerDefs.h"
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/ProcessorContext.h"


extern "C" void OSi_ReferSymbol(unsigned int);
extern "C" void HaltSystem(void);
extern "C" void func_020d0fc4(CardReadManager* manager, int command, int arg);

// USA: func_020d06fc
extern "C" ARM int func_020d06fc(void* handle) {
    CardReadManager* manager = &data_021118e0;
    int var1;
    int var2;
    NitroHandle* var3;
    CardReadManager::CompletionCallback var4;

    OSi_ReferSymbol(0x2000bc4);
    if (handle == NULL) {
        HaltSystem();
    }

    VerifyCardReadManagerInitialized();

    var1 = DisableIRQInterrupts();
    if (manager->flags & (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS)) {
        do {
            BlockCurrentContext(&manager->ongoingReadBlock);
        } while (manager->flags & (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS));
    }
    manager->flags |= (1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS);
    manager->onComplete = NULL;
    manager->handle = NULL;
    SetIRQInterruptState(var1);

    func_020d0078((unsigned int) handle);

    data_021118e0.currentTaskExecutionContext = data_02111304.activeContext;

    func_020d0fc4(manager, 2, 1);

    manager->pSharedData->unknown_4[2] = 0;
    manager->pSharedData->unknown_4[3] = (int)&manager->unknown[0];
    manager->pSharedData->unknown_4[4] = 1;

    func_020d0fc4(manager, 6, 1);

    var4 = manager->onComplete;
    var3 = manager->handle;

    var2 = DisableIRQInterrupts();
    manager->flags &= ~((1 << READ_MANAGER_FLAG_HARDWARE_READ_IN_PROGRESS) | (1 << READ_MANAGER_FLAG_CONTEXT_HAS_TASK_PENDING) | (1 << CARTRIDGE_READ_CONTEXT_FLAG_6));
    UnblockContexts(&manager->ongoingReadBlock);
    if (manager->flags & (1 << CARTRIDGE_READ_CONTEXT_FLAG_4)) {
        MarkContextReadyAndSwitch(&manager->cartridgeReadContext);
    }
    SetIRQInterruptState(var2);

    if (var4 != NULL) {
        var4(var3);
    }

    return (manager->pSharedData->unknown_0 == 0) ? 1 : 0;
}
