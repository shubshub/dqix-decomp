#include <globaldefs.h>
#include "NitroSDK/RequestSubmission.h"

#ifdef jpn
#define data_021023c0 data_02102100
#define data_020ef7a8 data_020ef698
#endif

struct Struct_0202cb50 {
    unsigned short field0;
    unsigned short result;
    unsigned short type;
};

struct Struct_021015a0 {
    char unknown_0_[0x10];
    int state;
    int field14;
    void (*callback)(Struct_0202cb50*);
    char unknown_1c_[0x18];
    int mode;
};

extern Struct_021015a0 data_021015a0 __attribute__((aligned(4)));
extern int data_021023c0;
extern int data_020ef7a8;
extern int data_02102be0;
extern "C" void func_0202c848(int);

// USA: func_0202cb50
extern "C" ARM void func_0202cb50(Struct_0202cb50* event)
{
    int result = event->result;
    if (result) {
        func_0202c848(result);
        data_021015a0.state = 9;
    } else {
        switch (event->type) {
        case 10:
            if (data_021015a0.mode == 2) {
                if (data_021015a0.state == 4) {
                    data_021015a0.state = 6;
                    int ok = func_020d68b4(&data_021023c0, 13);
                    if (!ok) ok = 1;
                    else {
                        func_0202c848(ok);
                        ok = 0;
                    }
                    if (!ok) data_021015a0.state = 9;
                    break;
                }
                if (data_021015a0.state != 6) goto fallback;
                break;
            } else if (data_021015a0.mode == 4) {
                int mask = 15;
                int status = func_020d5d34(&data_02102be0, 13, mask, 0x74, data_020ef7a8);
                if (status) {
                    func_0202c848(status);
                    data_021015a0.state = 9;
                } else {
                    data_021015a0.state = 5;
                    if (data_021015a0.callback) data_021015a0.callback(event);
                }
                break;
            }
        fallback:
            data_021015a0.state = 4;
            if (data_021015a0.callback) data_021015a0.callback(event);
            break;
        case 11:
        case 12:
        case 13:
            break;
        }
    }
}
