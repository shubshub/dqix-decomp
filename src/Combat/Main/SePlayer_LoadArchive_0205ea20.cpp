#include <globaldefs.h>
#if defined(jpn)
#define data_020f057c data_020f05e4
#define data_ov031_02257180 data_ov031_02257960
#define data_020f0594 data_020f05fc
#endif

extern int data_020f057c;
extern int data_020f0594;
extern int data_ov031_02257180;

extern "C" void SoundPlayer_OpenArchive(void* obj, int addr, void* ovAddr, int size, int flag);

int SoundPlayer_SaveHeapState(void* obj);
int SoundPlayer_LoadGroup(void* obj, int index);

// Main, originally SetupContextForMode0205ea20 (USA 0x0205ea20, EUR 0x0205ea30, JPN 0x0205fd0c)
ARM void SePlayer_LoadArchive(void* objRaw, int mode) {
    char* obj = (char*)objRaw;
    int addr = 0;
    if (mode == 0x64) {
        addr = (int)&data_020f057c;
    } else if (mode == 0x65) {
        addr = (int)&data_020f0594;
    }
    if (addr != 0) {
        SoundPlayer_OpenArchive(obj, addr, &data_ov031_02257180, 0x4b000, 0);
    }
    *(int*)(obj + 0xb0) = SoundPlayer_SaveHeapState(obj);
    *(short*)(obj + 0xb4) = (short)mode;
    SoundPlayer_LoadGroup(obj, mode);
    int r = SoundPlayer_SaveHeapState(obj);
    *(int*)(obj + 0xc0) = r;
    *(int*)(obj + 0xb8) = r;
}
