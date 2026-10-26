#include <globaldefs.h>
#include "NitroSDK/WirelessScanDescriptor.h"

struct Struct_ov031_0220ee50_2 {
    int field0;
    Struct_ov031_0220ec04_2* head;
};

struct Struct_ov031_0220ee50 {
    char padding[0x2270];
    Struct_ov031_0220ee50_2* list;
    unsigned int state;
};

extern "C" int func_ov031_0220d60c(void);

// USA: func_ov031_0220ee50
extern "C" ARM Struct_ov031_0220ec04_2* func_ov031_0220ee50(int id) {
    Struct_ov031_0220ee50* context = (Struct_ov031_0220ee50*)func_ov031_0220d60c();
    Struct_ov031_0220ee50_2* list = context->list;
    Struct_ov031_0220ec04_2* node = NULL;
    if (list != NULL && context->state > 12) {
        node = list->head;
        if (node != NULL) {
            do {
                if (node->index == id) break;
                node = node->next;
            } while (node != NULL);
        }
    }
    return node;
}
