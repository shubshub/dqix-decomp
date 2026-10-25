#include <globaldefs.h>

extern "C" void* __clear(void* dst, int count);
void NotifyLocalizedResourceLoad020dd040(int len, char* buf);
int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_FormatText(int a, int b, void* c, int d, int e, int f, int g);

struct BitField24a0_0215eec0 {
    unsigned int val : 12;
    unsigned int pad : 20;
};

// USA: func_ov002_0215eec0  (semantic: UpdateStatusCodeAndDispatch0215eec0)
extern "C" ARM void func_ov002_0215eec0(unsigned char* obj, int flag) {
    char buf[0x100];

    if (flag) {
        *(short*)(obj + 0x1c00 + 0x26) = -1;

        int idx = *(short*)(obj + 0x1b00 + 0xfa);
        if (idx >= 0 && idx < 0x20) {
            void* t = *(void**)(obj + idx * 4 + 0x24a0);
            struct BitField24a0_0215eec0* bf = (struct BitField24a0_0215eec0*)((char*)t + 4);
            *(short*)(obj + 0x1c00 + 0x26) = bf->val;
        }

        __clear(buf, 0x100);
        NotifyLocalizedResourceLoad020dd040(*(short*)(obj + 0x1c00 + 0x26), buf);

        int base = MessageSystem_GetInstance();
        MessageSystem_FormatText(base, 0xc, buf, flag, 0x74, 0, 0);
    }
}
