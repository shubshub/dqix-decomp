#include <globaldefs.h>

#if defined(jpn)
struct Struct020dfc40;
extern "C" void KeyTable_Reset(Struct020dfc40* p);
extern "C" void* KeyTable_Construct(void* p);
extern "C" int func_020e2168(char* destination, const char* arg1,
    int index, int variant, bool lock);
extern const char data_020f2b6c[];
struct Struct_020dcf7c { unsigned char pad[0x18]; };
#define func_020dcf7c func_020de968
extern "C" void func_020de968(int count, void* buf);
#else
extern char data_020f296c;
extern char data_020f297e;
extern "C" void func_020e54bc(int, void*, int, int, unsigned char, int);
#endif

// JPN: func_020de968
// USA: func_020dcf7c
extern "C" ARM void func_020dcf7c(int count, void* buf) {
#if defined(jpn)
    const char* var0;
    if (count > 0 && buf != NULL) {
        Struct_020dcf7c local;
        var0 = data_020f2b6c;
        *(char*)buf = 0;
        KeyTable_Construct(&local);
        KeyTable_Reset((Struct020dfc40*)&local);
    } else {
        return;
    }
    func_020e2168((char*)buf, var0, count, 0, true);
#else
    if (count <= 0) return;
    if (buf == NULL) return;
    func_020e54bc((int)buf, &data_020f296c, count, 0, 1, (int)&data_020f297e);
#endif
}
