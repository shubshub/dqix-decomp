#include <globaldefs.h>

struct Struct_ov031_0222d524 {
    char padding[8];
    unsigned char key[0x20];
};

extern Struct_ov031_0222d524* data_ov031_02290c94;

extern "C" void func_ov031_02227520(int* first, int* second);
extern "C" int func_ov031_0223dd34(unsigned char* bytes, int length);
extern "C" void func_ov031_0222336c(int, int, int);

// USA: func_ov031_0222d524
extern "C" ARM int func_ov031_0222d524() {
    int status;
    int mode;
    func_ov031_02227520(&status, &mode);
    if (mode == 1) {
        func_ov031_0222336c(0x35, -1, 0);
    }
    func_ov031_02227520(&status, &mode);
    if (status == 0) {
        return data_ov031_02290c94->key[0] != 0;
    }
    if (mode == 1) {
        if (data_ov031_02290c94->key[0] == 0) {
            return 0;
        }
    }
    int length = func_ov031_0223dd34(data_ov031_02290c94->key, 0x20);
    switch (length) {
    case 0:
    case 5:
    case 13:
    case 16:
        return 1;
    case 10:
    case 26:
    case 32:
        for (int i = 0; i < length; i++) {
            unsigned int c = data_ov031_02290c94->key[i];
            if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
