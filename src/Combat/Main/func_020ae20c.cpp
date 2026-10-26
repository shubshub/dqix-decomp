#include <globaldefs.h>
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "World/Object3D.h"

struct Fields020407b4 {
    char unk0[0x44];
    int field44;
    int field48;
    int field4c;
};

extern "C" void func_020407b4(struct Fields020407b4* dst, int a, int b, int c);
extern "C" void func_0203db34(unsigned char* obj, int a, int b, int c);
extern "C" void* GameObject_GetFloorAttribute(void* obj);
extern "C" int func_0204bedc(unsigned short* obj);

// USA: func_020ae20c
extern "C" ARM void func_020ae20c(void* obj, struct Fields020407b4* b, int* v, int c) {
    if (b == NULL) return;

    func_020407b4(b, v[0], 0xffffd009, v[2]);
    func_0203db34((unsigned char*)b, 0, c, 0);

    int flag = 0xc;
    void* p = GameObject_GetFloorAttribute(obj);
    if (p != NULL) {
        if (func_0204bedc((unsigned short*)p))
            flag = 0x14;
    }

    RenderConfig::SetPolygonAttributes(1, 3, 1, 0, flag, 0x8000);
    {
        NSBXXInternalModel* target = ((Object3D*)b)->pModel_->rawInternalModel_;
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x30);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0xc0);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x3f000000);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x1f0000);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x8000);
    }
    ((Object3D*)b)->Draw(true);

    RenderConfig::SetPolygonAttributes(1, 3, 3, 0x3c, flag, 0x8000);
    {
        NSBXXInternalModel* target = ((Object3D*)b)->pModel_->rawInternalModel_;
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x30);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0xc0);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x3f000000);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x1f0000);
        NSBXX_Model_AdjustPolygonAttrMask(target, 0, 0x8000);
    }
    ((Object3D*)b)->Draw(true);
}
