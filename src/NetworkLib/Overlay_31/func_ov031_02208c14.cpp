#include <globaldefs.h>

struct Struct_ov031_02208c14_2 {
    int length;
    unsigned char* data;
};

struct Struct_ov031_02208c14 {
    Struct_ov031_02208c14_2 unknown_0_;
    Struct_ov031_02208c14_2 unknown_8_;
    Struct_ov031_02208c14_2 unknown_10_;
    Struct_ov031_02208c14_2 unknown_18_;
    Struct_ov031_02208c14_2 unknown_20_;
    Struct_ov031_02208c14_2 coefficient;
};

extern "C" void func_ov031_0220c8d0(unsigned short* dst, unsigned char* src, int len, int outLen);
extern "C" void func_ov031_0220c92c(unsigned char* dst, unsigned short* src, int count, int words);
extern "C" unsigned int func_ov031_02207cf0();
extern "C" void func_ov031_02207d3c(unsigned int priority);
extern "C" int func_ov031_0220bb4c(unsigned short* arr, int len);
extern "C" void func_ov031_0220c6c4(unsigned short* result, unsigned short* base, unsigned short* arg2, int length, unsigned short* arg4);
extern "C" void func_ov031_0220bcbc(unsigned short* destination, unsigned short* left, unsigned short* right, int length);
extern "C" void func_ov031_0220be38(unsigned short* dst, unsigned short* b, unsigned short* c, int n);
extern "C" void func_ov031_0220bb7c(unsigned short* dst, unsigned short* a, unsigned short* b, int len);
extern "C" void func_ov031_0220bc7c(unsigned short* arr, int count);
extern "C" void func_ov031_0220c0dc(unsigned short* arg0, unsigned short* arg1,
    unsigned short* arg2, unsigned short* arg3, int count, unsigned short* work);
extern void* (*data_ov031_0224c994)(unsigned int);
extern int (*data_ov031_0224c9c0)(void*);

// USA: func_ov031_02208c14
extern "C" ARM void func_ov031_02208c14(unsigned char* out, unsigned char* input, Struct_ov031_02208c14* key) {
    int words;
    unsigned short* var1;
    unsigned short* number;
    unsigned short* var3;
    unsigned short* var4;
    unsigned short* m2;
    unsigned short* var6;
    unsigned short* message;
    unsigned short* work;
    unsigned int priority;
    if (key == 0 || key->unknown_0_.length == 0)
        return;
    words = (key->unknown_0_.length * 2) / 2 + 1;
    var1 = (unsigned short*)data_ov031_0224c994(words * 0x14);
    if (var1 == 0)
        return;
    number = var1 + words;
    var3 = number + words;
    var4 = var3 + words;
    m2 = var4 + words;
    var6 = m2 + words;
    message = var6 + words;
    work = message + words;
    func_ov031_0220c8d0(var1, input, key->unknown_0_.length, words);
    func_ov031_0220c8d0(number, key->unknown_18_.data, key->unknown_18_.length, words);
    func_ov031_0220c8d0(var6, key->unknown_8_.data, key->unknown_8_.length, words);
    priority = func_ov031_02207cf0();
    func_ov031_0220c6c4(var4, var1, number, words, var6);
    func_ov031_0220c8d0(number, key->unknown_20_.data, key->unknown_20_.length, words);
    func_ov031_0220c8d0(var6, key->unknown_10_.data, key->unknown_10_.length, words);
    func_ov031_0220c6c4(m2, var1, number, words, var6);
    func_ov031_02207d3c(priority);
    func_ov031_0220bcbc(var1, var4, m2, words);
    func_ov031_0220c8d0(number, key->coefficient.data, key->coefficient.length, words);
    func_ov031_0220be38(var3, var1, number, words);
    func_ov031_0220c8d0(number, key->unknown_10_.data, key->unknown_10_.length, words);
    func_ov031_0220be38(var1, var3, number, words);
    func_ov031_0220bb7c(var3, var1, m2, words);
    func_ov031_0220c8d0(number, key->unknown_0_.data, key->unknown_0_.length, words);
    if (func_ov031_0220bb4c(var3, words) < 0) {
        func_ov031_0220bc7c(var3, words);
        func_ov031_0220c0dc(0, var3, number, message, words, work);
        func_ov031_0220bcbc(message, number, message, words);
    } else {
        func_ov031_0220c0dc(0, var3, number, message, words, work);
    }
    func_ov031_0220c92c(out, message, 0x30, words);
    data_ov031_0224c9c0(var1);
}
