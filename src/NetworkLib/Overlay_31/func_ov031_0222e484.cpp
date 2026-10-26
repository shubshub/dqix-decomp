#include <globaldefs.h>
#include <Resource/UiArrayEntry.h>

extern "C" void func_ov031_02227520(int*, int*);
extern "C" unsigned char func_ov031_02227548(void);
extern "C" void* func_ov031_0223c560(int, int);
extern "C" int func_020c7170(char*, unsigned long, const char*, ...);
extern "C" void func_ov031_0223dd60(void*, const void*, int);
extern "C" void func_ov031_0223c8d4(void*, int, int, int, int, void*, int);
extern "C" int func_ov031_022236d0(void);
extern "C" void func_ov031_0223c980(void*, int, int, int, int, int, int, int);
extern "C" void func_ov031_0223caec(void*);
extern int data_ov031_02290c9c;
extern unsigned char data_ov031_02248f2c[];
extern Struct_ov031_022276b4* data_ov031_02290c4c;
extern const char data_ov031_0224bb08[];
extern unsigned short data_ov031_02248f3e[];
extern const unsigned short data_ov031_02248f3c[];

// USA: func_ov031_0222e484
extern "C" ARM void func_ov031_0222e484(void) {
    int mode;
    char var1[8];
    unsigned short text[8];
    func_ov031_02227520(0, &mode);
    int value = data_ov031_02290c9c;
    int category;
    if (value >= -20099) category = 0;
    else if (value >= -20100) category = 2;
    else if (value >= -20101) category = 19;
    else if (value >= -20107) category = 2;
    else if (value >= -20108) category = 18;
    else if (value >= -20109) category = 2;
    else if (value >= -20110) category = 3;
    else if (value >= -20999) category = 2;
    else if (value >= -22999) category = 0;
    else if (value >= -23999) category = 19;
    else if (value >= -49999) category = 0;
    else if (value >= -50002) category = 7;
    else if (value >= -50003) category = 5;
    else if (value >= -50098) category = 0;
    else if (value >= -50099) category = mode == 2 ? 5 : 7;
    else if (value >= -51098) category = 0;
    else if (value >= -51099) category = mode == 2 ? 5 : 8;
    else if (value >= -51102) category = 9;
    else if (value >= -51103) category = 5;
    else if (value >= -51199) category = 0;
    else if (value >= -51299) category = 20;
    else if (value >= -51302) category = 21;
    else if (value >= -51303) category = 4;
    else if (value >= -51999) category = 0;
    else if (value >= -52002) category = 10;
    else if (value >= -52003) category = 22;
    else if (value >= -52099) category = 0;
    else if (value >= -52103) category = 11;
    else if (value >= -52199) category = 0;
    else if (value >= -52203) category = 11;
    else if (value >= -52299) category = 0;
    else if (value >= -52399) category = 2;
    else if (value >= -52999) category = 0;
    else if (value >= -53299) category = 2;
    else category = 0;
    void* object = func_ov031_0223c560(0, data_ov031_02248f2c[func_ov031_02227548()]);
    int lookup = func_ov031_022276b4(data_ov031_02290c4c, category);
    func_020c7170(var1, 8, data_ov031_0224bb08, -data_ov031_02290c9c);
    func_ov031_0223dd60(text, var1, 8);
    unsigned short y = data_ov031_02248f3e[func_ov031_02227548() * 2];
    unsigned short x = data_ov031_02248f3c[func_ov031_02227548() * 2];
    func_ov031_0223c8d4(object, x, y, 2, 10, text, 0);
    if (category != 0) func_ov031_0223c980(object, 13, 60, 230, 94, 2, func_ov031_022236d0(), lookup);
    func_ov031_0223caec(object);
}
