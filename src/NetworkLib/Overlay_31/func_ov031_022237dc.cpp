#include <globaldefs.h>

struct Struct_ov031_02222ce4;
extern Struct_ov031_02222ce4** data_ov031_02250bf0;
extern "C" void func_ov031_022238cc(void);
extern "C" void* func_ov031_0223be70(int, int, int);
extern "C" void func_ov031_0223bbd8(void*, int, int, int);
extern "C" void func_ov031_0223bcc8(Struct_ov031_02222ce4*, int, int);

// USA: func_ov031_022237dc
extern "C" ARM void func_ov031_022237dc(int first, int second, int top, int bottom) {
    int resource = 6;
    func_ov031_022238cc();
    int i = 0;
    do {
        data_ov031_02250bf0[i] = (Struct_ov031_02222ce4*)func_ov031_0223be70(0, resource, 1);
        func_ov031_0223bcc8(data_ov031_02250bf0[i], -1, 1);
        i++;
        resource++;
    } while (i < 4);
    func_ov031_0223bbd8(data_ov031_02250bf0[0], -1, first, top);
    func_ov031_0223bbd8(data_ov031_02250bf0[1], -1, second, top);
    func_ov031_0223bbd8(data_ov031_02250bf0[2], -1, first, bottom);
    func_ov031_0223bbd8(data_ov031_02250bf0[3], -1, second, bottom);
}
