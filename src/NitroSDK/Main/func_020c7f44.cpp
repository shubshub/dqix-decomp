#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Interrupts.h"

struct Struct_020c7f44
{
    BlockedContextList unknown_0_;
    BlockedContextList unknown_8_;
    void** messages;
    int capacity;
    int first;
    int count;
};

// USA: func_020c7f44
extern "C" ARM int func_020c7f44(Struct_020c7f44* queue, void* message, int flags)
{
    int var0 = DisableIRQInterrupts();

    int capacity;
    if ((capacity = queue->capacity) <= queue->count)
    {
        do
        {
            if (!(flags & 1))
            {
                SetIRQInterruptState(var0);
                return false;
            }
            BlockCurrentContext(&queue->unknown_0_);
        } while ((capacity = queue->capacity) <= queue->count);
    }

    queue->first = (queue->first + capacity - 1) % capacity;
    queue->messages[queue->first] = message;
    queue->count++;

    UnblockContexts(&queue->unknown_8_);

    SetIRQInterruptState(var0);
    return true;
}
