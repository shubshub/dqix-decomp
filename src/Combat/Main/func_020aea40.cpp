#include <globaldefs.h>
struct Token020aea40 { unsigned short value; };
extern "C" Token020aea40* Zone3D_GetInstance();
void SetOrClearElemFlag0x4ByKeys_020ae694(int, int, unsigned short);
extern unsigned char data_020e9148[], data_020e9149[], data_020e914a[];
// USA: func_020aea40
extern "C" ARM void func_020aea40(unsigned int index, int clear) {
    if (index <= 3) {
        if (Zone3D_GetInstance()->value != 0x164a) return;
    } else {
        if (index < 4 || index > 7) return;
        if (Zone3D_GetInstance()->value != 0x21ff) return;
    }
    if (!arg1) {
        func_020ae694(1, 0, data_020e9148[arg0 * 3]);
        func_020ae694(1, 0, data_020e9149[arg0 * 3]);
        func_020ae694(1, 0, data_020e914a[arg0 * 3]);
    } else {
        func_020ae694(0, 0, data_020e9148[arg0 * 3]);
        func_020ae694(0, 0, data_020e9149[arg0 * 3]);
        func_020ae694(0, 0, data_020e914a[arg0 * 3]);
    }
}
