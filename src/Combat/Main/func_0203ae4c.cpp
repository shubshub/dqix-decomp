#include <globaldefs.h>

extern "C" int func_020becd4(void* obj);
extern "C" int SoundPlayer_StopStream(void* obj, void* target, int arg2);
extern "C" int func_0203ad14(void* obj, int key, void* target, int arg3);
typedef int (*Type_0203ae4c)(void*, short, void*, int);

// USA: func_0203ae4c
extern "C" ARM void func_0203ae4c(void* obj, int arg1, void* target) {
    char* p = (char*)obj;

    if (*(void**)p == NULL) {
        return;
    }

    {
        short var1 = *(short*)(p + 0xa4);
        if (var1 < 0) {
            return;
        }

        if (arg1 != 0) {
            int var2;
            short savedKey;
            int result;

            if (target != NULL) {
                var2 = func_020becd4(target);
            } else {
                var2 = func_020becd4(p + 0x9c);
            }

            savedKey = *(short*)(p + 0xa4);
            result = SoundPlayer_StopStream(obj, target, 0);
            *(int*)(p + 0xa8) = result;
            *(short*)(p + 0xa4) = savedKey;

            if (*(int*)(p + 0xa8) == var2) {
                *(short*)(p + 0xa4) = -1;
            }
        } else {
            int rec = *(int*)(p + 0xa8);
            if (rec != 0) {
                ((Type_0203ae4c)func_0203ad14)(obj, var1, target, rec);
            }
        }
    }
}
