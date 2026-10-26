#include <globaldefs.h>
#include <NitroSDK/Interrupts.h>
#include <NitroSDK/Memory.h>
#include <NitroSDK/ProcessorContext.h>

struct Struct_020d19f4;

typedef unsigned long (*Type_020d19f4)(Struct_020d19f4* task);

struct Struct_020d19f4 {
    Type_020d19f4 task;
    Type_020d19f4 callback;
    unsigned long result;
    unsigned char* data;
    unsigned char* address;
    unsigned long offset;
    unsigned long size;
    unsigned char* dst;
    unsigned short unknown_20_;
    unsigned char busy;
    unsigned char param[1];
};

struct Struct_020d19f4_2 {
    unsigned char unknown_0_[0xc0];
    Struct_020d19f4* volatile list;
    Struct_020d19f4 unknown_c4_;
};

struct Struct_02112328 {
    Struct_020d19f4_2* unknown_0_;
    Struct_020d19f4 unknown_4_;
};

struct Struct_020d19f4_3 {
    unsigned long words[sizeof(Struct_020d19f4) / 4];
};

extern Struct_02112328 data_02112328;

// USA: func_020d19f4
extern "C" ARM void func_020d19f4(void* arg) {
    Struct_020d19f4_2* const p = (Struct_020d19f4_2*)arg;

    for (;;) {
        Struct_020d19f4 task;

        VectorizedMemset(&task, 0, sizeof(Struct_020d19f4));
        {
            int var2 = DisableIRQInterrupts();
            while (!p->list) {
                BlockCurrentContext(NULL);
            }
            *(Struct_020d19f4_3*)&task = *(Struct_020d19f4_3*)p->list;
            SetIRQInterruptState(var2);
        }

        if (task.task) {
            task.result = task.task(&task);
        }

        {
            int var3 = DisableIRQInterrupts();
            Type_020d19f4 callback = task.callback;

            data_02112328.unknown_4_.busy = false;
            if (callback) {
                callback(&task);
            }
            if (data_02112328.unknown_0_ == NULL) {
                break;
            }
            p->list = NULL;
            SetIRQInterruptState(var3);
        }
    }

    ContextExecutionReturnProc();
    return;
}
