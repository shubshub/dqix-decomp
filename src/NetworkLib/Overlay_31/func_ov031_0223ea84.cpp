#include <globaldefs.h>

enum Enum_ov031_0223ea84_B {
    Enum_ov031_0223ea84_B_0, Enum_ov031_0223ea84_B_1, Enum_ov031_0223ea84_B_2, Enum_ov031_0223ea84_B_3,
    Enum_ov031_0223ea84_B_4, Enum_ov031_0223ea84_B_5, Enum_ov031_0223ea84_B_6, Enum_ov031_0223ea84_B_7, Enum_ov031_0223ea84_B_8
};
enum Enum_ov031_0223ea84 {
    Enum_ov031_0223ea84_0, Enum_ov031_0223ea84_1, Enum_ov031_0223ea84_2, Enum_ov031_0223ea84_3
};

struct Struct_ov031_0223ea84;
struct Struct_ov031_0223ea84_2 {
    int unknown_0_;
    Enum_ov031_0223ea84 mode;
    void (*callback)(Enum_ov031_0223ea84, Enum_ov031_0223ea84_B, int);
    void* unknown_c_;
    void* output;
    int unknown_14_;
    void* unknown_18_;
    void* unknown_1c_;
    void* unknown_20_;
};

struct Struct_ov031_02290dc0 {
    void (*unknown_0_)(void*);
};

extern Struct_ov031_02290dc0 data_ov031_02290dc0;
extern int data_ov031_02290dc4;
extern int data_ov031_02290dbc;
extern const unsigned char data_ov031_0224c6b4[];
extern const unsigned char data_ov031_0224c6c4[];
extern "C" int func_ov031_022411e4(Struct_ov031_0223ea84*, const void*, void**);
extern "C" int func_ov031_0223fb8c(const char*, int);
extern "C" int func_ov031_022412e8(Struct_ov031_0223ea84*, int*);
extern "C" int func_ov031_0223fb54(const unsigned char*, const unsigned char*, int);
extern "C" int func_ov031_0223e54c(char*, const char*, int);
extern "C" int func_ov031_0223f6ec(Struct_ov031_0223ea84*, Struct_ov031_0223ea84_2*);
extern "C" int func_ov031_0223f76c(Struct_ov031_0223ea84*, Struct_ov031_0223ea84_2*);
extern "C" int func_ov031_0223f740(Struct_ov031_0223ea84*, Struct_ov031_0223ea84_2*);
extern "C" void func_ov031_0223fa0c();
extern "C" void func_ov031_0223fa20();
extern "C" void func_ov031_02241060(Struct_ov031_0223ea84*);
extern "C" void func_ov031_0223faa8();
extern "C" void func_ov031_0223fad4(void*);

// USA: func_ov031_0223ea84
extern "C" ARM void func_ov031_0223ea84(int error, Struct_ov031_0223ea84* response, Struct_ov031_0223ea84_2* work) {
    void (*callback)(Enum_ov031_0223ea84, Enum_ov031_0223ea84_B, int) = work->callback;
    void* var1 = work->unknown_c_;
    Enum_ov031_0223ea84 mode = work->mode;
    int detail = -1;
    Enum_ov031_0223ea84_B result;
    void* var5;
    int encodedText;
    char var7[4];

    switch (error) {
    case 0:
        if (func_ov031_022411e4(response, data_ov031_0224c6b4, &var5) != 3) {
            result = Enum_ov031_0223ea84_B_3;
            break;
        } else {
            int code = func_ov031_0223fb8c((const char*)var5, 3);
            if (code == 302) {
                int found = 0;
                int len = func_ov031_022412e8(response, &encodedText);
                int i;
                if (len < 0) {
                    result = Enum_ov031_0223ea84_B_3;
                    break;
                }
                i = 0;
                if (len > 0) do {
                    int start = i;
                    const char* p = (const char*)encodedText + i;
                    int n;
                    int var15;
                    const char* q;
                    int var17;
                    while (*p != '=' && i < len) {
                        p++;
                        i++;
                    }
                    n = i - start;
                    i++;
                    if (n == 8) {
                        found = func_ov031_0223fb54((const unsigned char*)encodedText + start, data_ov031_0224c6c4, 8) == 0;
                    }
                    var15 = i;
                    q = (const char*)encodedText + i;
                    while (*q != '&' && *q != '\r' && *q != '\0' && i < len) {
                        q++;
                        i++;
                    }
                    var17 = i - var15;
                    i++;
                    if (found) {
                        if (var17 == 4) {
                            int m = func_ov031_0223e54c(var7, (const char*)encodedText + var15, var17);
                            var7[m] = '\0';
                            detail = func_ov031_0223fb8c(var7, m);
                        }
                        break;
                    }
                } while (i < len);
                result = detail < 0 ? Enum_ov031_0223ea84_B_3 : Enum_ov031_0223ea84_B_5;
            } else if (code <= 0 || code != 200) {
                result = Enum_ov031_0223ea84_B_3;
            } else {
                switch (mode) {
                case 1:
                    result = func_ov031_0223f6ec(response, work) ? Enum_ov031_0223ea84_B_0 : Enum_ov031_0223ea84_B_3;
                    break;
                case 2:
                    result = func_ov031_0223f76c(response, work) ? Enum_ov031_0223ea84_B_0 : Enum_ov031_0223ea84_B_3;
                    break;
                case 3:
                    result = func_ov031_0223f740(response, work) ? Enum_ov031_0223ea84_B_0 : Enum_ov031_0223ea84_B_3;
                    break;
                }
            }
        }
        break;
    case 8:
        result = Enum_ov031_0223ea84_B_6;
        break;
    case 6:
        result = Enum_ov031_0223ea84_B_4;
        break;
    default:
        result = Enum_ov031_0223ea84_B_3;
        break;
    }

    switch (mode) {
    case 1:
        break;
    case 2:
        if (work->unknown_20_ != 0) {
            data_ov031_02290dc0.unknown_0_(work->unknown_20_);
        }
        if (work->unknown_1c_ != 0) {
            data_ov031_02290dc0.unknown_0_(work->unknown_1c_);
        }
        data_ov031_02290dc0.unknown_0_(work->unknown_18_);
        break;
    case 3:
        data_ov031_02290dc0.unknown_0_(work->output);
        break;
    }
    func_ov031_0223fa0c();
    data_ov031_02290dc4 = -1;
    func_ov031_0223fa20();
    func_ov031_02241060(response);
    data_ov031_02290dc0.unknown_0_(work);
    func_ov031_0223faa8();
    if (result != 0) {
        data_ov031_02290dbc = result;
    }
    if (callback != 0) {
        callback(mode, result, detail);
    }
    if (var1) {
        func_ov031_0223fad4(var1);
    }
}
