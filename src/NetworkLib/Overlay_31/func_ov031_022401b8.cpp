#include <globaldefs.h>

struct Struct_ov031_022401b8 { unsigned char pad[4]; struct Struct_ov031_022401b8* next; void* field8; };
extern void* data_ov031_02290fdc;

// USA: func_ov031_022401b8
extern "C" ARM void* func_ov031_022401b8(void* target) {
    struct Struct_ov031_022401b8* result = NULL;
    struct Struct_ov031_022401b8* head = (struct Struct_ov031_022401b8*)data_ov031_02290fdc;
    struct Struct_ov031_022401b8* cur;
    if (head != NULL) {
        if (head->field8 == target) {
            result = head;
        } else {
            for (cur = head->next; cur != head; cur = cur->next) {
                if (cur->field8 == target) {
                    result = cur;
                    break;
                }
            }
        }
    }
    return result;
}
