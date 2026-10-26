#include <globaldefs.h>

#include "Combat/Main/MessageSlotTable.h"

// USA: func_020dd9b4
extern "C" ARM void func_020dd9b4(Struct_020dd7ac *table, unsigned int kind, void *arg2, void *arg3) {
    if (arg2 == 0 || arg3 == 0) {
        return;
    }
    if (kind >= 12) {
        return;
    }
    switch (kind) {
        case 0:
            *(unsigned short *) arg2  = table->f3c;
            *(unsigned short *) arg3 = table->unknown_3e_;
            return;
        case 1:
            *(unsigned short *) arg2  = table->f40;
            *(unsigned short *) arg3 = table->unknown_42_;
            return;
        case 2:
            *(int *) arg2  = table->unknown_44_;
            *(int *) arg3 = table->unknown_48_;
            return;
        case 3:
            *(int *) arg2  = table->unknown_4c_;
            *(int *) arg3 = table->unknown_50_;
            return;
        case 4:
            *(int *) arg2  = table->unknown_54_;
            *(int *) arg3 = table->unknown_58_;
            return;
        case 5:
            *(int *) arg2  = table->unknown_5c_;
            *(int *) arg3 = table->f60;
            return;
        case 6:
            *(unsigned short *) arg2  = table->f64;
            *(unsigned short *) arg3 = table->unknown_66_;
            return;
        case 7:
            *(unsigned short *) arg2  = table->f68;
            *(unsigned short *) arg3 = table->unknown_6a_;
            return;
        case 8:
            *(unsigned short *) arg2  = table->f6c;
            *(unsigned short *) arg3 = table->unknown_6e_;
            return;
        case 9:
            *(unsigned short *) arg2  = table->unknown_70_;
            *(unsigned short *) arg3 = table->unknown_72_;
            return;
        case 10:
            *(unsigned short *) arg2  = table->unknown_74_;
            *(unsigned short *) arg3 = table->unknown_76_;
            return;
        case 11:
            *(unsigned short *) arg2  = table->unknown_78_;
            *(unsigned short *) arg3 = table->unknown_7a_;
            return;
    }
}
