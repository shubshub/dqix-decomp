#include <globaldefs.h>

#include "Combat/ObjectStateInitialization.h"

// Main, originally func_02032e58 (USA 0x02032e58, EUR 0x02032e68, JPN 0x02032990)
extern "C" ARM void GameObject_Initialize(void *gameObject) {
    ObjectStatePrefix *self = (ObjectStatePrefix*)gameObject;

    self->object.Initialize();
    self->object.unknown_0_ |= 2;
    self->object.EnableFlag(4);
    self->fieldBe     = 0;
    self->fieldBf     = 0;
    self->fieldC0     = 0;
    self->fieldAc     = 0;
    self->fieldAe     = 0;
    self->fieldB0     = 0x324;
    self->fieldB2     = 0;
    self->fieldB4     = 0x189;
    self->fieldB6     = 0x28;
    self->fieldB8     = 0;
    self->fieldC2Low  = 0;
    self->fieldC1Low  = 0;
    self->fieldC3     = 0;
    self->fieldC6     = 0;
    self->fieldC1High = 0;
    self->fieldC2Bit4 = 0;
    self->fieldBa     = 0;
    self->fieldBc     = 0;
    self->fieldE0Bit0 = 0;
    self->fieldC2Bit5 = 0;
    self->fieldC2Bit6 = 0;
    self->fieldC1Bit3 = 0;
    self->fieldC4Low  = 0;
    self->fieldC2Bit7 = 0;
    self->field124    = 0;
    self->field128    = 0;
    self->field12c    = 0;
    self->fieldBa     = 0x199;
    self->fieldE0Bit2 = 0;
    self->fieldE0Bit1 = 0;
    func_02032fb8(&self->firstHalfwords);
    func_02032fb8(&self->secondHalfwords);
    self->fieldC1Bit2 = 0;
    self->fieldE0Bit3 = 0;
    self->fieldE0Bit4 = 0;
    self->fieldE0Bit5 = 0;
    self->fieldC4High = 0;
}
