#include <globaldefs.h>

extern "C" unsigned int strlen(const char* s);
extern "C" char* strcpy(char* dst, const char* src);
extern "C" int strcmp(const char* a, const char* b);
extern "C" int func_02005a94(const char* s);
extern "C" int func_020cf25c(void* date, void* time);
extern "C" long long func_020cf990(int date, unsigned char* time);

struct Struct_ov031_0221a218 {
    unsigned int year;
    unsigned int month;
    unsigned int day;
    unsigned int unknown_c_;
};

struct Struct_ov031_0221a218_2 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int second;
};

struct Struct_ov031_0224e688 {
    int unknown_0_;
    long long unknown_8_;
    long long offset;
};

extern char data_ov031_0224a224[];
extern const char* data_ov031_0224a1f4[12];
extern Struct_ov031_0224e688 data_ov031_0224e688;
extern int data_020f3390;

// USA: func_ov031_0221a218
extern "C" ARM int func_ov031_0221a218(const char* str) {
    Struct_ov031_0221a218 date;
    Struct_ov031_0221a218_2 time;
    char buf[32];
    long long var3;
    long long var4;
    int i;

    if (strlen(str) != strlen(data_ov031_0224a224) || str[7] != ' ' || str[11] != ' ' || str[16] != ' '
        || str[19] != ':' || str[22] != ':' || str[25] != ' ') {
        goto fail;
    }
    if (func_020cf25c(&date, &time) != 0) {
        goto fail;
    }
    var3 = func_020cf990((unsigned int)&date, (unsigned char*)&time);
    if (var3 == -1) {
        goto fail;
    }

    strcpy(buf, str);
    buf[7] = 0;
    buf[11] = 0;
    buf[16] = 0;
    buf[19] = 0;
    buf[22] = 0;
    buf[25] = 0;

    data_020f3390 = 0;
    date.year = func_02005a94(&buf[12]);
    if (data_020f3390 == 0x22) {
        goto fail;
    }
    date.year -= 2000;

    date.month = 13;
    i = 0;
    do {
        if (strcmp(data_ov031_0224a1f4[i], &buf[8]) == 0) {
            date.month = i + 1;
            break;
        }
    } while (++i < 12);
    if (date.month > 12) {
        goto fail;
    }

    data_020f3390 = 0;
    date.day = func_02005a94(&buf[5]);
    if (data_020f3390 == 0x22) {
        goto fail;
    }
    data_020f3390 = 0;
    time.unknown_0_ = func_02005a94(&buf[17]);
    if (data_020f3390 == 0x22) {
        goto fail;
    }
    data_020f3390 = 0;
    time.unknown_4_ = func_02005a94(&buf[20]);
    if (data_020f3390 == 0x22) {
        goto fail;
    }
    data_020f3390 = 0;
    time.second = func_02005a94(&buf[23]);
    if (data_020f3390 == 0x22) {
        goto fail;
    }

    var4 = func_020cf990((int)&date, (unsigned char*)&time);
    if (var4 == -1) {
        goto fail;
    }
    data_ov031_0224e688.offset = var3 - var4;
    data_ov031_0224e688.unknown_8_ = var3;
    data_ov031_0224e688.unknown_0_ = 1;
    return 1;
fail:
    return 0;
}
