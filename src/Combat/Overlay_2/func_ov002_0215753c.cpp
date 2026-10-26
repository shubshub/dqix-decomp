#include <globaldefs.h>

extern "C" void func_ov002_0215a658(void* obj, int val);
extern "C" void func_ov002_0215a7b4(void* obj, int val, int count, int val2, int flag);

// USA: func_ov002_0215753c
#if defined(jpn)
extern "C" ARM int func_ov002_0215753c(unsigned char* obj) {
    int result = -1;

    if (*(short*)(obj + 0x1ada) != 0) {
        goto end;
    }

    if (*(short*)(obj + 0x1ab8) >= 0) {
        signed char b = *(signed char*)(obj + 0x1ae8);
        result = 0x238e;
        func_ov002_0215a658(obj, b);
    }

    if (*(short*)(obj + 0x1aea) > 0) {
        if (*(short*)(obj + 0x1ab2) == 2) {
            signed char b2 = *(signed char*)(obj + 0x1ae8);
            short c = *(short*)(obj + 0x1aea);
            short e = *(short*)(obj + 0x1ab0);
            result = 0x2366;
            func_ov002_0215a7b4(obj, b2, c, e, 0);
        }
    }

    if (*(int*)(obj + 0x1a84) == 0x27) {
        result = 0x125d;
    }

end:
    return result;
}
#else
extern "C" ARM int func_ov002_0215753c(unsigned char* obj) {
    int result = -1;

    if (*(short*)(obj + 0x1c00 + 0x12) != 0) {
        goto end;
    }

    if (*(short*)(obj + 0x1b00 + 0xf0) >= 0) {
        signed char b = *(signed char*)(obj + 0x1c00 + 0x20);
        result = 0x238e;
        func_ov002_0215a658(obj, b);
    }

    if (*(short*)(obj + 0x1c00 + 0x22) > 0) {
        if (*(short*)(obj + 0x1b00 + 0xea) == 2) {
            signed char b2 = *(signed char*)(obj + 0x1c00 + 0x20);
            short c = *(short*)(obj + 0x1c00 + 0x22);
            short e = *(short*)(obj + 0x1b00 + 0xe8);
            result = 0x2366;
            func_ov002_0215a7b4(obj, b2, c, e, 0);
        }
    }

    if (*(int*)(obj + 0x1000 + 0xbbc) == 0x24) {
        result = 0x125d;
    }

end:
    return result;
}
#endif
