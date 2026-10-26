#include <globaldefs.h>

struct Struct_0207f0ac;
struct Struct_0207f0ac_2;
extern "C" Struct_0207f0ac_2* func_0207f0ac(Struct_0207f0ac* list, int id);

struct Struct_0207f524;
struct Struct_0207f6ac;
extern "C" Struct_0207f6ac* func_0207f6ac(Struct_0207f524* list, int id);

// USA: func_020809c4
extern "C" ARM void func_020809c4(void* obj, int id, int id2, short* out1, short* out2) {
    Struct_0207f0ac_2* e = func_0207f0ac((Struct_0207f0ac*)((char*)obj + 0xc), id);
    if (e == NULL) {
        return;
    }
    *out1 = (short)(*(short*)((char*)e + 0xa) << 3);
    *out2 = (short)(*(short*)((char*)e + 0xc) << 3);
    for (unsigned char i = 0; i < *(unsigned char*)((char*)e + 0x13); i++) {
        short* arr = *(short**)((char*)e);
        if (id2 == arr[i]) {
            Struct_0207f6ac* e2 = func_0207f6ac((Struct_0207f524*)((char*)obj + 4), id2);
            if (e2 == NULL) {
                return;
            }
            *out1 = *out1 + *(short*)((char*)e2 + 0x6);
            *out2 = *out2 + *(short*)((char*)e2 + 0x8);
            return;
        }
    }
}
