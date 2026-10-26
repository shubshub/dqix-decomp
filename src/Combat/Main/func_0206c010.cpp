#include <globaldefs.h>

#include "Combat/WorkRecord.h"
#include "Combat/NodeLookup.h"

#include "Memory/SafeAllocator.h"
#include "Resource/Script.h"



struct Struct_02108cec {
    unsigned char pad0[0xa];
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    void* unknown_10_;
    void* unknown_14_;
};
extern struct Struct_02108cec data_02108cec;

// USA: func_0206c010
extern "C" ARM int func_0206c010(Script::Parameter* params, int count) {
    struct Struct_0206bf2c* rec;
    Script::Parameter* p;
    int id;

    data_02108cec.unknown_a_ = data_02108cec.unknown_a_ + 1;
    id = params[0].ToInt();
    if (id != data_02108cec.unknown_c_) {
        return 1;
    }
    rec = (struct Struct_0206bf2c*)((SafeAllocator*)data_02108cec.unknown_14_)->Allocate(0x78);
    if (rec == 0) {
        return 0;
    }
    func_0206bf2c(rec);
    rec->field2 = (unsigned short)id;
    rec->field0 = (unsigned char)params[1].ToInt();
    if (count < 3) {
        func_0206dd68(data_02108cec.unknown_10_, rec->field0);
        return 1;
    }
    p = params[2].ToVec3fix((Vector3fix*)rec->pad10);
    rec->field1c = (unsigned short)(int)(4096.0f * p->ToFloat());
    if (count > 6) {
        rec->unknown_1e_ = (unsigned char)p[1].ToInt();
    }
    rec->field44 = data_02108cec.unknown_a_;
    func_0206db48(data_02108cec.unknown_10_, rec);
    return 1;
}
