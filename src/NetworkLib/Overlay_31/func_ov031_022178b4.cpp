#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov031_02217604_5 {
    char unknown_0_[14];
    char token[7];
    char unknown_15_[4];
    char unknown_19_;
    char unknown_1a_[2];
    char unknown_1c_;
    char unknown_1d_;
    char unknown_1e_;
    char macAddress[13];
    char language[3];
    char birthday[5];
    char unknown_34_[13];
    char unknown_41_[13];
    char ssid[33];
    char unknown_6f_[14];
    unsigned short unknown_7e_[11];
};

extern "C" int func_020c7170(char* destination, unsigned long capacity, const char* format, ...);
extern "C" int func_ov031_02218604(void* obj, const char* key, void* val, int len);
extern "C" int func_ov031_02218528(void* obj, const char* key, const char* val);
extern "C" int func_02005aa8(void* s);

extern const char data_ov031_02249cd4[];
extern const char data_ov031_02249ce0[];
extern const char data_ov031_02249ce8[];
extern const char data_ov031_02249cf0[];
extern const char data_ov031_02249cf8[];
extern const char data_ov031_02249d00[];
extern const char data_ov031_02249d08[];
extern const char data_ov031_02249d10[];
extern const char data_ov031_02249d18[];
extern const char data_ov031_02249d20[];
extern const char data_ov031_02249d28[];
extern const char data_ov031_02249d30[];
extern const char data_ov031_02249d38[];
extern const char data_ov031_02249d40[];
extern const char data_ov031_02249d48[];
extern const char data_ov031_02249d50[];
extern const char data_ov031_02249d68[];
extern const char data_ov031_02249d74[];

// USA: func_ov031_022178b4
extern "C" ARM int func_ov031_022178b4(void* obj, Struct_ov031_02217604_5* arg1, int flag) {
    char buf[0x24];
    func_020c7170(buf, 0x21, data_ov031_02249cd4, 0x3, 1);
    if (func_ov031_02218604(obj, data_ov031_02249ce0, buf, strlen(buf)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249ce8, arg1->unknown_0_, strlen(arg1->unknown_0_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249cf0, arg1->token, strlen(arg1->token)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249cf8, arg1->unknown_41_, strlen(arg1->unknown_41_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d00, arg1->unknown_6f_, strlen(arg1->unknown_6f_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d08, arg1->unknown_15_, strlen(arg1->unknown_15_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d10, arg1->unknown_1a_, strlen(arg1->unknown_1a_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d18, &arg1->unknown_1d_, strlen(&arg1->unknown_1d_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d20, arg1->macAddress, strlen(arg1->macAddress)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d28, arg1->language, strlen(arg1->language)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d30, arg1->birthday, strlen(arg1->birthday)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d38, arg1->unknown_34_, strlen(arg1->unknown_34_)) != 0) return 0;
    if (func_ov031_02218604(obj, data_ov031_02249d40, arg1->unknown_7e_, func_02005aa8(arg1->unknown_7e_)*2) != 0) return 0;
    if (flag == 1) {
        if (func_ov031_02218604(obj, data_ov031_02249d48, arg1->ssid, strlen(arg1->ssid)) != 0) return 0;
    }
    func_020c7170(buf, 0x21, data_ov031_02249d50, 0x3, 1);
    if (func_ov031_02218528(obj, data_ov031_02249d68, buf) != 0) return 0;
    return func_ov031_02218528(obj, data_ov031_02249d74, arg1->unknown_15_) == 0;
}
