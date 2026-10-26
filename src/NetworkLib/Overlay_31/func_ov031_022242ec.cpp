#include <globaldefs.h>

struct Struct_ov031_022489c4 { unsigned short x, y; };
struct Struct_ov031_022493b8 { unsigned short x, y, x2, y2; };
extern Struct_ov031_022493b8 data_ov031_022493b8;
extern "C" void func_ov031_0223cb34(Struct_ov031_022489c4*, Struct_ov031_022489c4*, Struct_ov031_022493b8*);
extern "C" void func_ov031_02236878(int);

struct Struct_ov031_022242ec {
    char unknown_0_[0x11e];
    signed char selection;
    char unknown_11f_[4];
    unsigned char mode;
    unsigned char enabled;
};
extern Struct_ov031_022242ec* data_ov031_02250bfc;
extern Struct_ov031_022489c4 data_ov031_02248a0c[47];
extern Struct_ov031_022489c4 data_ov031_022489c8;
extern Struct_ov031_022489c4 data_ov031_022489f4[4];
extern Struct_ov031_022489c4 data_ov031_022489e4[4];
extern int data_ov031_0224b43c[4];
extern Struct_ov031_022489c4 data_ov031_022489dc[2];
extern Struct_ov031_022489c4 data_ov031_022489c4;
extern "C" int func_ov031_0223d49c(Struct_ov031_022493b8*);

// USA: func_ov031_022242ec
extern "C" ARM void func_ov031_022242ec() {
    Struct_ov031_022493b8 bounds;
    if (!func_ov031_0223d49c(&data_ov031_022493b8)) return;
    data_ov031_02250bfc->selection = -1;
    {
        Struct_ov031_022489c4* var1;
        Struct_ov031_022489c4* origin;
        int index;
        origin = data_ov031_02248a0c;
        var1 = &data_ov031_022489c8;
        index = 0;
        do {
            func_ov031_0223cb34(origin, var1, &bounds);
            if (func_ov031_0223d49c(&bounds)) {
                if (!data_ov031_02250bfc->enabled) {
                    func_ov031_02236878(9);
                    return;
                }
                func_ov031_02236878(0);
                data_ov031_02250bfc->selection = index;
                return;
            }
            ++index; ++origin;
        } while (index < 47);
    }
    {
        Struct_ov031_022489c4* var4;
        Struct_ov031_022489c4* origin;
        int index;
        var4 = data_ov031_022489f4;
        origin = data_ov031_022489e4;
        index = 0;
        do {
            func_ov031_0223cb34(origin, var4, &bounds);
            if (func_ov031_0223d49c(&bounds)) {
                if ((index == 3 && !data_ov031_02250bfc->mode) || (index == 2 && !data_ov031_02250bfc->enabled)) {
                    func_ov031_02236878(9);
                    return;
                }
                func_ov031_02236878(data_ov031_0224b43c[index]);
                data_ov031_02250bfc->selection = index + 47;
                return;
            }
            ++index; ++var4; ++origin;
        } while (index < 4);
    }
    {
        Struct_ov031_022489c4* var7;
        Struct_ov031_022489c4* origin;
        int index;
        origin = data_ov031_022489dc;
        var7 = &data_ov031_022489c4;
        index = 0;
        do {
            func_ov031_0223cb34(origin, var7, &bounds);
            if (func_ov031_0223d49c(&bounds)) {
                func_ov031_02236878(0);
                data_ov031_02250bfc->selection = index + 51;
                return;
            }
            ++index; ++origin;
        } while (index < 2);
    }
}
