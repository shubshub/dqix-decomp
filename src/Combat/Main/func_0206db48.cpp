#include <globaldefs.h>

#include "Combat/NodeLookup.h"
#include "Combat/WorkRecord.h"

// USA: func_0206db48
extern "C" ARM void func_0206db48(void *receiver, Struct_0206bf2c *record) {
    Struct_0206bf2c *node = (Struct_0206bf2c *) func_0206db20(receiver, record->field0);
    int category;
    if (record->unknown_a_2_) {
        category = 0;
    } else if (record->unknown_a_6_) {
        category = 1;
    } else if (record->unknown_46_ >= 0) {
        category = 2;
    } else if (record->field5 && !record->field8) {
        category = 3;
    } else if (record->field8) {
        category = 4;
    } else {
        category = 5;
    }
    if (node != 0) {
        while (node != 0) {
            int var2;
            if (node->unknown_a_2_) {
                var2 = 0;
            } else if (node->unknown_a_6_) {
                var2 = 1;
            } else if (node->unknown_46_ >= 0) {
                var2 = 2;
            } else if (node->field5 && !node->field8) {
                var2 = 3;
            } else if (node->field8) {
                var2 = 4;
            } else {
                var2 = 5;
            }
            bool before = false;
            if (category < var2) {
                before = true;
            } else if (category == var2) {
                if (category == 4 || category == 1) {
                    int key      = record->field4 * 1000 + record->field5 * 10 + record->field6;
                    int var5 = node->field4 * 1000 + node->field5 * 10 + node->field6;
                    if (key == var5 && record->field44 < node->field44) {
                        before = true;
                    } else if (key < var5) {
                        before = true;
                    }
                } else if (record->field44 < node->field44) {
                    before = true;
                }
            }
            if (before) {
                break;
            }
            node = node->unknown_70_;
        }
        if (node == 0) {
            return;
        }
        if (node->unknown_6c_ == 0) {
            if (node->unknown_64_ != 0) {
                node->unknown_64_->field68 = record;
            }
            if (node->field68 != 0) {
                node->field68->unknown_64_ = record;
            }
            record->unknown_64_ = node->unknown_64_;
            record->field68 = node->field68;
            node->unknown_64_   = 0;
            node->field68   = 0;
            if (record->unknown_64_ == 0) {
                *(Struct_0206bf2c **) receiver = record;
            }
        }
        if (node->unknown_6c_ != 0) {
            node->unknown_6c_->unknown_70_ = record;
        }
        record->unknown_6c_ = node->unknown_6c_;
        record->unknown_70_ = node;
        node->unknown_6c_   = record;
    } else {
        if (*(Struct_0206bf2c **) receiver != 0) {
            (*(Struct_0206bf2c **) receiver)->unknown_64_ = record;
        }
        record->field68            = *(Struct_0206bf2c **) receiver;
        *(Struct_0206bf2c **) receiver = record;
    }
}
