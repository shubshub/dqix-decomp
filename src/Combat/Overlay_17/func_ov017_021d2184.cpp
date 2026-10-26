#include <globaldefs.h>
#include "std_library_functions.h"


extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* obj);
extern "C" void* LinkMessageQueue_GetInstance(void);
extern "C" void* Scenario_GetInstance(void);
extern "C" void func_0205e330(void* a, void* b, int c);

struct Struct_ov017_021d2184 {
    unsigned char data[14];
    unsigned short len : 4;
    unsigned short id : 2;
    unsigned short index : 10;
};

struct Struct_ov017_021d2184_2 {
    unsigned char tag;
    unsigned char pad[3];
    struct Struct_ov017_021d2184 tail;
};

// USA: func_ov017_021d2184
extern "C" ARM void func_ov017_021d2184(unsigned short id) {
    if (LinkSession_IsHostOrSolo(LinkSession_GetInstance())) {
        struct Struct_ov017_021d2184_2 buf;
        void* p = LinkMessageQueue_GetInstance();
        struct Struct_ov017_021d2184* t = &buf.tail;
        buf.tag = 0x9c;
        t->id = id;
        char* src = (char*)Scenario_GetInstance() + 0x2cc;
        int remaining = 0x66;
        unsigned char index = 0;
        while (remaining > 0) {
            if (remaining > 14) {
                t->len = 14;
            } else {
                t->len = remaining;
            }
            t->index = index;
            memcpy(t->data, src, t->len);
            func_0205e330(p, &buf, 0);
            src += 14;
            remaining -= 14;
            index = (unsigned char)(index + 1);
        }
    }
}
