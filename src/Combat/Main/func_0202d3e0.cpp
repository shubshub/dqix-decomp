#include <globaldefs.h>
#include "NitroSDK/RequestSubmission.h"

#if defined(jpn)
#define data_021023c0 data_02102100
#define data_020ef7a8 data_020ef698
#endif

struct Struct_0202d3e0 { unsigned short unknown_0_, status, command; };
struct Struct_021015a0_4 {
    char reserved[0x10];
    int state;
    int unknown_14_;
    void (*callback)(Struct_0202d3e0*);
    char unknown_1c_[0x34 - 0x1c];
    int mode;
};
extern Struct_021015a0_4 data_021015a0 __attribute__((aligned(4)));
struct Struct_021023c0;
extern Struct_021023c0 data_021023c0, data_02102be0;
extern int data_020ef7a8;
extern "C" void func_0202c848(int);
extern "C" void WH_Finalize();

// USA: func_0202d3e0
extern "C" ARM void func_0202d3e0(Struct_0202d3e0* input) {
    if (input->status != 0) {
        if (input->status != 15 && input->status != 9 && input->status != 13) {
            func_0202c848(input->status);
            data_021015a0.state = 9;
        }
    } else {
        switch (input->command) {
        case 10:
            if (data_021015a0.mode == 3) {
                if (data_021015a0.state == 6) break;
                if (data_021015a0.state == 4) {
                    int submitted;
                    if (data_021015a0.state == 6) submitted = 1;
                    else if (data_021015a0.state != 4) submitted = 0;
                    else {
                        data_021015a0.state = 6;
                        int result = func_020d68b4(&data_021023c0, 13);
                        if (result == 0) submitted = 1;
                        else { func_0202c848(result); submitted = 0; }
                    }
                    if (!submitted) WH_Finalize();
                    break;
                }
            } else if (data_021015a0.mode == 5) {
                int mask = 15;
                int result = func_020d5d34(&data_02102be0, 13, mask, 0x74, data_020ef7a8);
                if (result) {
                    func_0202c848(result);
                    WH_Finalize();
                } else {
                    data_021015a0.state = 5;
                    if (data_021015a0.callback) data_021015a0.callback(input);
                }
                break;
            }
            data_021015a0.state = 4;
            if (data_021015a0.callback) data_021015a0.callback(input);
            break;
        case 11:
        case 12:
        case 13:
            break;
        }
    }
}
