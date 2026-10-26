#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Interrupts.h"

struct Struct_ov027_021dd218 {
    Struct_ov027_021dd218* next;
    unsigned int unknown_4_0_ : 1;
    unsigned int priority : 31;
    void (*unknown_8_)(Struct_ov027_021dd218*);
    void (*unknown_c_)(Struct_ov027_021dd218*);
};

struct Struct_ov027_021dd218_2 {
    ProcessorContext ctx;
    Struct_ov027_021dd218* volatile unknown_c8_;
    Struct_ov027_021dd218 unknown_cc_;
};

// USA: func_ov027_021dd218
extern "C" ARM void func_ov027_021dd218(Struct_ov027_021dd218_2* obj) {
    for (;;) {
        Struct_ov027_021dd218* node = NULL;
        {
            int state = DisableIRQInterrupts();
            while (obj->unknown_c8_ == NULL) {
                ChangeContextPriority((ProcessorContext*)obj, 0);
                BlockCurrentContext(NULL);
            }
            node = obj->unknown_c8_;
            obj->unknown_c8_ = obj->unknown_c8_->next;
            ChangeContextPriority((ProcessorContext*)obj, node->priority);
            SetIRQInterruptState(state);
        }

        if (node->unknown_8_ != NULL) node->unknown_8_(node);

        {
            int state = DisableIRQInterrupts();
            void (*var3)(Struct_ov027_021dd218*) = node->unknown_c_;
            const unsigned int var4 = GetContextPriority((ProcessorContext*)obj);
            unsigned int var5;
            if (obj->unknown_c8_ == NULL) {
                var5 = 0;
            } else if (var4 < obj->unknown_c8_->priority) {
                var5 = obj->unknown_c8_->priority;
            } else {
                var5 = var4;
            }
            if (var5 != var4) {
                ChangeContextPriority((ProcessorContext*)obj, var5);
            }

            node->next = NULL;
            node->unknown_4_0_ = 0;
            if (var3 != NULL) var3(node);

            if (node == &obj->unknown_cc_) break;
            SetIRQInterruptState(state);
        }
    }
    ContextExecutionReturnProc();
}
