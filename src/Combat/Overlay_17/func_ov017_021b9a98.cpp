#include <globaldefs.h>


extern "C" void* func_0202ae18(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
extern "C" void func_0202c288(void* obj);
extern "C" void* Scenario_GetInstance(void);
int Scenario_RunTrigger(void* a, int mode, void* c);
extern "C" void EventQuery_RunQueuedCommands(void* p);
struct Obj_021b994c;
void ResetFieldsToDefault_021b994c(struct Obj_021b994c* obj);

struct Struct_0202c1a4 {
    char unknown_0_[0x100d];
    unsigned char unknown_100d_;
};

struct Struct_02061c04_11 {
    char unknown_0_[0x12c];
    unsigned int unknown_12c_;
    unsigned char unknown_130_;
    unsigned char unknown_131_;
    unsigned char unknown_132_;
    unsigned char unknown_133_;
    char unknown_134_[0x136 - 0x134];
    unsigned char unknown_136_;
};

struct Struct_ov017_021b9a98 { char unknown_0_[0x34]; };

// USA: func_ov017_021b9a98
extern "C" ARM void func_ov017_021b9a98(Struct_02061c04_11* arg0, int arg1, unsigned char arg2, unsigned char arg3, unsigned short arg4) {
    Struct_0202c1a4* var0 = (Struct_0202c1a4*)func_0202ae18();
    signed char var1 = func_0202c1a4(var0);
    if (arg2 != var1 && arg2 != 4) return;

    if (arg0->unknown_130_ == 0) return;

    func_0202c288(var0);

    int var2 = arg0->unknown_131_ + 1;
    arg0->unknown_131_ = (unsigned char)var2;
    if ((var2 & 0xff) >= var0->unknown_100d_ - 1) arg0->unknown_130_ = 0;

    if (obj->field136 == 0) {
        if (flag == 0) {
            obj->field133 = 0;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list = Scenario_GetInstance();
            LocalBuf021b9a98 c;
            if (Scenario_RunTrigger(list, 0x1a, &c)) {
                EventQuery_RunQueuedCommands(&c);
            }
            func_ov017_021b994c(arg0);
            arg0->unknown_136_ = 1;
        } else {
            int var5 = arg0->unknown_132_ + 1;
            arg0->unknown_132_ = (unsigned char)var5;
            if ((var5 & 0xff) < var0->unknown_100d_ - 1) return;

            obj->field133 = 1;
            *(short*)((char*)obj + 0x134) = (short)obj->field12c;
            void* list2 = Scenario_GetInstance();
            LocalBuf021b9a98 c2;
            if (Scenario_RunTrigger(list2, 0x1a, &c2)) {
                EventQuery_RunQueuedCommands(&c2);
            }
            func_ov017_021b994c(arg0);
            arg0->unknown_136_ = 1;
        }
    }
}
