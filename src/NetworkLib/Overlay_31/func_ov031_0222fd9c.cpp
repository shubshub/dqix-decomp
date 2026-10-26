#include <globaldefs.h>

extern "C" char* func_ov031_02235c70(void);

// USA: func_ov031_0222fd9c
extern "C" ARM int func_ov031_0222fd9c(int idx) {
    unsigned char* obj = (unsigned char*)func_ov031_02235c70();
    int result = 1;
    switch (idx) {
    case 7:
        if (obj[0xf5] == 0) result = 0;
        break;
    case 0:
    case 1: {
        unsigned char t = (unsigned char)(obj[0xe7] + 0xff);
        if (t <= 1) result = 0;
        break;
    }
    case 4:
    case 5:
    case 6:
        if (obj[0xf5] != 0) result = 0;
        break;
    case 9:
    case 10:
        if (obj[0xf6] != 0) result = 0;
        break;
    }
    return result;
}
