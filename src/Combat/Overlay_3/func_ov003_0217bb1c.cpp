#include <globaldefs.h>
#include <Resource/Script.h>

struct Struct_ov003_02180cd0 {
    signed char unknown_0_;
    int values[9];
};

extern Struct_ov003_02180cd0 data_ov003_02180cd0;
extern char data_ov003_02180cf8[16];
extern char data_ov003_02180d08[56];

// USA: func_ov003_0217bb1c
extern "C" ARM int func_ov003_0217bb1c(Script::Parameter* params, int count)
{
    int index = params[0].ToInt();
    if (index != data_ov003_02180cd0.unknown_0_) {
        return 1;
    }
    const char* name = params[1].ToString();
    const char* path = params[2].ToString();
    const char* var3 = strrchr(name, '/');
    if (var3 != NULL) {
        name = var3 + 1;
    }
    strcpy(data_ov003_02180cf8, name);
    strcpy(data_ov003_02180d08, path);
    data_ov003_02180cd0.values[0] = 4096.0f * params[3].ToFloat();
    data_ov003_02180cd0.values[1] = 4096.0f * params[4].ToFloat();
    data_ov003_02180cd0.values[2] = 4096.0f * params[5].ToFloat();
    data_ov003_02180cd0.values[3] = 4096.0f * params[6].ToFloat();
    data_ov003_02180cd0.values[4] = 4096.0f * params[7].ToFloat();
    data_ov003_02180cd0.values[5] = 4096.0f * params[8].ToFloat();
    data_ov003_02180cd0.values[6] = 4096.0f * params[9].ToFloat();
    data_ov003_02180cd0.values[7] = 4096.0f * params[10].ToFloat();
    data_ov003_02180cd0.values[8] = 4096.0f * params[11].ToFloat();
    return 1;
}
