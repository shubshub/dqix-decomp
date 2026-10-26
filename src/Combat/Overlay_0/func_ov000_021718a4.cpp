#include <globaldefs.h>

extern "C" void* func_ov000_02170cf8(char* arg0, int arg1);
extern "C" int func_ov000_02171210(void* arg0, void* arg1);
extern "C" void* __clear(void* arg0, int arg1);
extern "C" void func_020e4864(int arg0, void* arg1, int arg2, int arg3, int arg4, int arg5);
extern "C" void func_0206819c(const char* arg0, char* arg1, int arg2);

struct Obj0203c108;
void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

// USA: func_ov000_021718a4
extern "C" ARM void func_ov000_021718a4(void* arg0) {
    unsigned char* var0 = (unsigned char*)arg0 + 8;
    unsigned short var1 = *(unsigned short*)(var0 + 0x1e);
    void* var2 = func_ov000_02170cf8((char*)arg0, var1);
    if (var2 == 0) return;

    signed char var3 = *(signed char*)(var0 + 0x10);
    var3 = var3 + 1;
    *(signed char*)(var0 + 0x10) = var3;

    int var4 = func_ov000_02171210(var2, arg0);

    signed char var5 = *(signed char*)(var0 + 0x10);
    unsigned char* var6 = var0 + var5;
    var6[8] = (unsigned char)var4;

#if defined(jpn)
    CachedTextLabel_SetText((struct Obj0203c108*)((char*)self + 0x50), *(char**)entry);
#else
    char var7[0x80];
    __clear(var7, 0x80);
    char var8[0x80];
    __clear(var8, 0x80);

    func_020e4864(*(int*)var2, var7, 1, 0, 0, 0);

    CopyTextAndUppercaseIfFlagged0206819c(buf1, buf2, 0);
    CachedTextLabel_SetText((struct Obj0203c108*)((char*)self + 0x50), buf2);
#endif
}
