#include <globaldefs.h>

#if defined(jpn)
extern unsigned int data_ov000_02184704[4];
#endif

struct Struct_0205d81c;
struct Struct_0205c570;
struct Entry_0205d6a0;
struct SePlayer;
struct TableEntry0217f8c0;
struct Struct0217f8c0;
extern "C" void Window_SetPanePalette(struct Struct_0205d81c* s, int key, int value);
extern "C" int Window_GetSelectedIndex(struct Struct_0205c570* s);
extern "C" int func_ov000_0217c594(void* obj, int limit);
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern "C" void* func_ov000_021815e4(char* obj);
extern "C" int func_ov000_021815c8(void* obj);
extern "C" int func_020dd4c4(int id, void* node);
extern "C" struct TableEntry0217f8c0* func_ov000_0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02176634(void* obj, struct TableEntry0217f8c0* entry, int val, int arg3, int arg4);
extern "C" int func_ov000_0217c5f4(void* obj);
extern "C" void Window_ClosePane(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(void* obj, struct TableEntry0217f8c0* entry, int val, int arg3, int arg4, int one);

extern struct SePlayer g_sePlayer;

struct Struct_ov000_0217db4c {
    char unknown_0_[0x188];
    char list[0x240 - 0x188];
    unsigned char mode;
    char unknown_241_[0x956 - 0x241];
    unsigned char unknown_956_;
#if defined(jpn)
    char unknown_957_[0x1f98 - 0x957];
#else
    char unknown1_957_[0x1d60 - 0x957];
#endif
    signed char unknown_1d60_[8];
    signed char depth;
    char unknown_1d69_[0x1d6f - 0x1d69];
    signed char activeSum;
    char unknown_1d70_[2];
    unsigned short flags;
};

// USA: func_ov000_0217db4c
extern "C" ARM void func_ov000_0217db4c(struct Struct_ov000_0217db4c* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    Window_SetPanePalette((struct Struct_0205d81c*)menu->list, 0x21, 0);
    signed char prev = menu->activeSum;
    int sum = Window_GetSelectedIndex((struct Struct_0205c570*)menu->list);
    menu->activeSum = sum;
    if (prev != sum) {
        return;
    }
    if (func_ov000_0217c594(menu, 5)) {
        menu->unknown_956_ = 0;
        SePlayer_Play(&g_sePlayer, 1, 0);
        menu->mode = 7;
        void* element = func_ov000_021815e4((char*)menu);
#if defined(jpn)
        int result = func_020dd4c4(func_ov000_021815c8(menu), element);
        if (result != 0) {
            for (unsigned char i = 0; data_ov000_02184704[i] != 0; i++) {
                if (result & data_ov000_02184704[i]) {
                    menu->depth++;
                    menu->unknown_1d60_[menu->depth] = 0x1f;
                    func_ov000_02176634(menu, func_ov000_0217f8c0((struct Struct0217f8c0*)menu), 0x1f, arg1, arg2);
                    return;
                }
            }
            return;
        }
#else
        func_020dd4c4(func_ov000_021815c8(menu), element);
#endif
        menu->depth++;
        menu->unknown_1d60_[menu->depth] = 0x20;
        func_ov000_02176634(menu, func_ov000_0217f8c0((struct Struct0217f8c0*)menu), menu->unknown_1d60_[menu->depth], arg1, arg2);
    } else if (func_ov000_0217c5f4(menu)) {
        menu->unknown_956_ = 0;
        Window_ClosePane((struct Entry_0205d6a0*)menu->list, 0);
        Window_ClosePane((struct Entry_0205d6a0*)menu->list, 0);
        menu->unknown_1d60_[menu->depth] = 0;
        menu->depth--;
        func_ov000_0217c638(menu, arg1, arg2);
        func_ov000_02176e3c(menu, func_ov000_0217f8c0((struct Struct0217f8c0*)menu), menu->unknown_1d60_[menu->depth], arg1, arg2, 0);
    }
}
