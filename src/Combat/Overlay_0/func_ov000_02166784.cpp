#include <globaldefs.h>

extern "C" int _ZN7Model3D7GetTEX0Ev(void* obj);
struct Struct_ov000_02161c0c_3;
extern "C" int func_ov000_021673e0(struct Struct_ov000_02161c0c_3* obj);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
extern "C" void NSBXX_Tex_WritePaletteVRAMOffset(void* obj, int value);
extern "C" void _ZN8Object3D23SetTexturePaletteOffsetEj(unsigned char* obj, int value);
struct NSBXXTex;
int StageTexFilePaletteData(NSBXXTex volatile*, bool);

// USA: func_ov000_02166784
extern "C" ARM void func_ov000_02166784(struct Struct_ov000_02161c0c_3* arg0, unsigned char* obj2, unsigned char* arg2) {
    int state = *(short*)(arg2 + 0x4);
    int tmp = state - 0xc0;
    void* field;
    int slot;
    if (tmp < 0) return;
    if (tmp > 0xc7) return;
    field = *(void**)(obj2 + 0x8);
    if (!field) return;
    field = (void*)_ZN7Model3D7GetTEX0Ev(field);
    if (!field) return;
    slot = func_ov000_021673e0(arg0);
    {
        unsigned short off = *(unsigned short*)((char*)field + 0x30);
        int len = *(int*)((char*)field + 0x38);
        CleanInvalidateCacheRange((char*)field + len, off << 3);
        NSBXX_Tex_WritePaletteVRAMOffset(field, slot);
        StageTexFilePaletteData((NSBXXTex volatile*)field, 1);
        _ZN8Object3D23SetTexturePaletteOffsetEj(arg2, slot);
    }
}
