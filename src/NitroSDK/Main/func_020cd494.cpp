#include <globaldefs.h>
#include "NitroSDK/Filesystem/OverlayFSManagement.h"

struct Struct_020cd494
{
    Struct_020cd494* next;
    void (*destructor)(void* object);
    void* object;
};

int DisableIRQInterrupts();
int SetIRQInterruptState(int);

extern Struct_020cd494* data_020f33b0;

// USA: func_020cd494
extern "C" ARM void func_020cd494(const OverlayMetadata& overlay)
{
    for (;;)
    {
        Struct_020cd494* head = NULL;
        Struct_020cd494* tail = NULL;
        const unsigned int var2 = overlay.loadAddress;
        const unsigned int var3 = var2 + (overlay.uncompressedSize + overlay.bssSectionSize);

        {
            int var4 = DisableIRQInterrupts();
            Struct_020cd494* prev = NULL;
            Struct_020cd494* base = data_020f33b0;
            Struct_020cd494* entry = base;

            while (entry)
            {
                Struct_020cd494* next = entry->next;
                const unsigned int destructor = (unsigned int)entry->destructor;
                const unsigned int object = (unsigned int)entry->object;

                if (object == 0 && destructor >= var2 && destructor < var3 ||
                    object >= var2 && object < var3)
                {
                    if (!tail)
                    {
                        head = entry;
                    }
                    else
                    {
                        tail->next = entry;
                    }
                    if (base == entry)
                    {
                        base = data_020f33b0 = next;
                    }
                    tail = entry, entry->next = NULL;
                    if (prev)
                    {
                        prev->next = next;
                    }
                }
                else
                {
                    prev = entry;
                }
                entry = next;
            }
            SetIRQInterruptState(var4);
        }

        if (!head)
        {
            break;
        }

        do
        {
            Struct_020cd494* next = head->next;
            if (head->destructor)
            {
                head->destructor(head->object);
            }
            head = next;
        } while (head);
    }
}
