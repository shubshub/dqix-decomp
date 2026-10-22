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
void SetElementFieldC2_0205deb4(struct Struct_0205d81c* s, int key, int value);
int GetActiveScaledSum0205d794(struct Struct_0205c570* s);
extern "C" int func_ov000_0217c594(void* obj, int limit);
void SePlayer_Play(struct SePlayer* obj, int a, int b);
void* FindElementByComputedKey021815e4(char* obj);
int GetAdjustedByteField0x1d6b_ov000_021815c8(void* obj);
extern "C" int func_020dd4c4(int id, void* node);
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(struct Struct0217f8c0* s);
extern "C" void func_ov000_02176634(void* obj, struct TableEntry0217f8c0* entry, int val, int arg1, int arg2);
int CheckFlagsOrField_0217c5f4_0217c5f4(void* obj);
void ResetEntryList0205d6a0(struct Entry_0205d6a0* a, int flag);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void func_ov000_02176e3c(void* obj, struct TableEntry0217f8c0* entry, int val, int arg1, int arg2, int one);

extern struct SePlayer g_sePlayer;

struct Struct_ov000_0217db4c {
    char unknown_0_[0x188];
    char unknown_188_[0x240 - 0x188];
    unsigned char unknown_240_;
    char unknown_241_[0x956 - 0x241];
    unsigned char unknown_956_;
#if defined(jpn)
    char unknown_957_[0x1f98 - 0x957];
#else
    char unknown1_957_[0x1d60 - 0x957];
#endif
    signed char unknown_1d60_[8];
    signed char unknown_1d68_;
    char unknown_1d69_[0x1d6f - 0x1d69];
    signed char unknown_1d6f_;
    char unknown_1d70_[2];
    unsigned short unknown_1d72_;
};

// USA: func_ov000_0217db4c
extern "C" ARM void func_ov000_0217db4c(struct Struct_ov000_0217db4c* arg0, int arg1, int arg2) {
    arg0->unknown_1d72_ |= 0x100;
    func_0205deb4((struct Struct_0205d81c*)arg0->unknown_188_, 0x21, 0);
    signed char var0 = arg0->unknown_1d6f_;
    int var1 = func_0205d794((struct Struct_0205c570*)arg0->unknown_188_);
    arg0->unknown_1d6f_ = var1;
    if (var0 != var1) {
        return;
    }
    if (func_ov000_0217c594(menu, 5)) {
        menu->field_0x956 = 0;
        SePlayer_Play(&g_sePlayer, 1, 0);
        menu->mode = 7;
        void* element = FindElementByComputedKey021815e4((char*)menu);
#if defined(jpn)
        int var3 = func_020dd4c4(func_ov000_021815c8(arg0), var2);
        if (var3 != 0) {
            for (unsigned char var4 = 0; data_ov000_02184704[var4] != 0; var4++) {
                if (var3 & data_ov000_02184704[var4]) {
                    arg0->unknown_1d68_++;
                    arg0->unknown_1d60_[arg0->unknown_1d68_] = 0x1f;
                    func_ov000_02176634(arg0, func_ov000_0217f8c0((struct Struct_ov000_021735d0_3*)arg0), 0x1f, arg1, arg2);
                    return;
                }
            }
            return;
        }
#else
        func_020dd4c4(func_ov000_021815c8(arg0), var2);
#endif
        arg0->unknown_1d68_++;
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 0x20;
        func_ov000_02176634(arg0, func_ov000_0217f8c0((struct Struct_ov000_021735d0_3*)arg0), arg0->unknown_1d60_[arg0->unknown_1d68_], arg1, arg2);
    } else if (func_ov000_0217c5f4(arg0)) {
        arg0->unknown_956_ = 0;
        func_0205d6a0((struct Struct_0205d6a0*)arg0->unknown_188_, 0);
        func_0205d6a0((struct Struct_0205d6a0*)arg0->unknown_188_, 0);
        arg0->unknown_1d60_[arg0->unknown_1d68_] = 0;
        arg0->unknown_1d68_--;
        func_ov000_0217c638(arg0, arg1, arg2);
        func_ov000_02176e3c(arg0, func_ov000_0217f8c0((struct Struct_ov000_021735d0_3*)arg0), arg0->unknown_1d60_[arg0->unknown_1d68_], arg1, arg2, 0);
    }
}
