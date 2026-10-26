#include <globaldefs.h>

typedef unsigned char Type_0200df80_2;
#define EXACTION_ENDBIT  0x80
#define EXACTION_OPT1BIT 0x40
#define EXACTION_OPT2BIT 0x20
#define EXACTION_MASK    0x1F

#define REGCOND EXACTION_OPT1BIT
#define REGPTR  EXACTION_OPT2BIT

#define EXACTION_ENDOFLIST             0
#define EXACTION_BRANCH                1
#define EXACTION_DESTROYLOCAL          2
#define EXACTION_DESTROYLOCALCOND      3
#define EXACTION_DESTROYLOCALPOINTER   4
#define EXACTION_DESTROYLOCALARRAY     5
#define EXACTION_DESTROYBASE           6
#define EXACTION_DESTROYMEMBER         7
#define EXACTION_DESTROYMEMBERCOND     8
#define EXACTION_DESTROYMEMBERARRAY    9
#define EXACTION_DELETEPOINTER         10
#define EXACTION_DELETEPOINTERCOND     11
#define EXACTION_CATCHBLOCK            12
#define EXACTION_ACTIVECATCHBLOCK      13
#define EXACTION_TERMINATE             14
#define EXACTION_SPECIFICATION         15
#define EXACTION_DESTROYBASEVTTOBJECT  16
#define EXACTION_DESTROYBASEVTTPOINTER 17
#define EXACTION_DESTROYVLA            18
#define EXACTION_FREEVLA               19

typedef struct Struct_0200d958_5 {
    char*         unknown_0_;
    unsigned long unknown_4_;
    char*         unknown_8_;
} Struct_0200d958_5;

typedef short         Type_0200d958;
typedef unsigned char Type_0200d958_2;

typedef struct Struct_0200d958_6 {
    void* location;
    void* unknown_4_;
    void* dtor;
    void* unknown_c_;
    long  unknown_10_;
    void* unknown_14_;
} Struct_0200d958_6;

#define DTORARG_TYPE     short
#define DTORARG_PARTIAL  (0)
#define DTORARG_COMPLETE (-1)

#define DTORCALL_COMPLETE(dtor, objptr)          (((void (*)(void*, DTORARG_TYPE))dtor)(objptr, DTORARG_COMPLETE))
#define DTORCALL_PARTIAL(dtor, objptr)           (((void (*)(void*, DTORARG_TYPE))dtor)(objptr, DTORARG_PARTIAL))
#define DTORCALL_VTTOBJECT(dtor, objptr, vttptr) (((void (*)(void*, void*))dtor)(objptr, vttptr))

typedef struct Struct_0200d958_7 {
    unsigned long  unknown_0_[16];
    char*          unknown_40_;
    unsigned long  unknown_44_;
    unsigned long  unknown_48_;
    unsigned short unknown_4c_;
    bool           unknown_4e_;
    bool           unknown_4f_;
    bool           unknown_50_;
} Struct_0200d958_7;

typedef struct Struct_0200df80 {
    unsigned char* unknown_0_;
    void*          location;
    void*          dtor;
    Struct_0200d958_6*     unknown_c_;
    char*          unknown_10_;
    char*          unknown_14_;
    char*          unknown_18_;
    Struct_0200d958_7  target;
} Struct_0200df80;

typedef struct Struct_0200d958_8 {
    int unknown_0_;
} Struct_0200d958_8;

typedef struct Struct_0200df80_2 {
    char*                unknown_0_;
    char*                unknown_4_;
    char*                unknown_8_;
    Struct_0200d958_5* unknown_c_;
    Struct_0200d958_5* unknown_10_;
    Struct_0200d958_8  target;
} Struct_0200df80_2;

#define __FunctionPointer(info, context, fp)          (fp)
#define __LocalVariable(context, offset)              ((context)->unknown_18_ + (offset))
#define __Register(context, regno)                    ((context)->target.unknown_0_[regno])

inline char* __DecodeAddress(char* p, void** arg1) {
    unsigned long addr;

    addr = ((unsigned char*)p)[0] | (((unsigned char*)p)[1] << 8) | (((unsigned char*)p)[2] << 16) |
           (((unsigned char*)p)[3] << 24);

    *arg1 = (void*)addr;
    return (p + 4);
}

extern "C" char* func_0200d958(char* p, long* arg1);
extern "C" char* func_0200d9e4(char* p, unsigned long* arg1);
extern "C" char* func_0200f1a0(Struct_0200df80* context, Struct_0200df80_2* info);
extern "C" void func_0200f1fc(Struct_0200df80* context, Struct_0200df80_2* info);
extern "C" void func_0200dad4(char* arg0, Struct_0200df80_2* info);
extern "C" void func_0200efb8(void);

enum {
    Enum_0200df80_0  = 0,
    Enum_0200df80_1 = 1
};

typedef void (*Type_0200d958_3)(void*);

typedef struct Struct_0200d958_9 {
    Struct_0200df80_2 info;
    Struct_0200df80  context;
} Struct_0200d958_9;

typedef struct Struct_0200d958_10 {
    char*         unknown_0_;
    unsigned long unknown_4_;
    long          unknown_8_;
} Struct_0200d958_10;

typedef struct Struct_0200d958_11 {
    long unknown_0_;
} Struct_0200d958_11;

typedef struct Struct_0200d958_12 {
    unsigned long unknown_0_;
    unsigned long unknown_4_;
    long          unknown_8_;
    char*         unknown_c_;
} Struct_0200d958_12;

inline void inline_0200d958(char* arg0, Struct_0200d958_10* cb) {
    arg0 += sizeof(Type_0200df80_2);
    arg0 = __DecodeAddress(arg0, (void**)&cb->unknown_0_);
    arg0 = func_0200d9e4(arg0, &cb->unknown_4_);
    arg0 = func_0200d958(arg0, &cb->unknown_8_);
}

inline void inline_0200d958_2(char* arg0, Struct_0200d958_11* arg1) {
    arg0 += sizeof(Type_0200df80_2);
    arg0 = func_0200d958(arg0, &arg1->unknown_0_);
}

inline void inline_0200d958_3(char* arg0, Struct_0200d958_12* arg1) {
    arg0 += sizeof(Type_0200df80_2);
    arg0        = func_0200d9e4(arg0, &arg1->unknown_0_);
    arg0        = func_0200d9e4(arg0, &arg1->unknown_4_);
    arg0        = func_0200d958(arg0, &arg1->unknown_8_);
    arg1->unknown_c_ = arg0;
}

inline void inline_0200df80_11(Struct_0200df80_2* info, Struct_0200df80* context) {
    long target;
    func_0200d958(info->unknown_8_ + sizeof(Type_0200df80_2), &target);
    info->unknown_8_ += target;
}

inline void inline_0200df80_12(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    long  local;
    void* dtor;

    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &local);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), __LocalVariable(context, local));
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_13(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*           var0 = info->unknown_8_;
    int             var1;
    long            cond, local;
    void*           dtor;
    Type_0200d958_2 var5;

    var1 = *(Type_0200df80_2*)var0 & REGCOND;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &cond);
    var0 = func_0200d958(var0, &local);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var5 = (Type_0200d958_2)__Register(context, cond);
        else
            var5 = *(Type_0200d958_2*)__LocalVariable(context, cond);

        if (var5) {
            DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), __LocalVariable(context, local));
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_14(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    int   var1;
    long  ptr;
    void *dtor, *var4;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &ptr);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var4 = (void*)__Register(context, ptr);
        else
            var4 = *(void**)__LocalVariable(context, ptr);

        DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), var4);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_15(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*         var0 = info->unknown_8_;
    long          array;
    unsigned long var2, var3, i;
    void*         dtor;
    char*         var6;

    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &array);
    var0 = func_0200d9e4(var0, &var2);
    var0 = func_0200d9e4(var0, &var3);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        var6 = (char*)__LocalVariable(context, array);
        for (var6 += var2 * var3, i = var2; i > 0; i--) {
            var6 -= var3;
            DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), var6);
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_16(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*         var0 = info->unknown_8_;
    int           var1, var2;
    long          var3, ptr2;
    unsigned long var5, var6, i;
    void*         dtor;
    char *        var9, *var10;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0      = func_0200d958(var0, &var3);
    var2 = *(unsigned char*)var0 & REGPTR;
    var0 += sizeof(char);
    var0 = func_0200d958(var0, &ptr2);
    var0 = func_0200d9e4(var0, &var6);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var9 = (char*)__Register(context, var3);
        else
            var9 = *(char**)__LocalVariable(context, var3);

        if (var2)
            var10 = (char*)__Register(context, ptr2);
        else
            var10 = *(char**)__LocalVariable(context, ptr2);

        var5 = (unsigned long)var10 / var6;
        for (var9 += (unsigned long)var10, i = var5; i > 0; i--) {
            var9 -= var6;
            DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), var9);
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_17(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    int   var1;
    long  var2, var3;
    long* var4;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &var2);

    if (apply) {
        if (var1)
            var4 = (long*)__Register(context, var2);
        else
            var4 = *(long**)__LocalVariable(context, var2);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_18(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    int   var1;
    long  ptr, offset, var4;
    void* dtor;
    char *var6, *var7;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &ptr);
    var0 = func_0200d958(var0, &offset);
    var0 = __DecodeAddress(var0, (void**)&var7);
    var0 = func_0200d958(var0, &var4);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var6 = (char*)__Register(context, ptr);
        else
            var6 = *(char**)__LocalVariable(context, ptr);

        DTORCALL_VTTOBJECT(__FunctionPointer(info, context, dtor), var6 + offset, var7 + var4);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    int   var1, var2;
    long  var3, ptr2, offset, var6;
    void* dtor;
    char *var8, *var9;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0      = func_0200d958(var0, &var3);
    var0      = func_0200d958(var0, &offset);
    var2 = *(unsigned char*)var0 & REGPTR;
    var0 += sizeof(char);
    var0 = func_0200d958(var0, &ptr2);
    var0 = func_0200d958(var0, &var6);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var8 = (char*)__Register(context, var3);
        else
            var8 = *(char**)__LocalVariable(context, var3);

        if (var2)
            var9 = (char*)__Register(context, ptr2);
        else
            var9 = *(char**)__LocalVariable(context, ptr2);

        DTORCALL_VTTOBJECT(__FunctionPointer(info, context, dtor), var8 + offset, var9 + var6);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_2(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    int   var1;
    long  ptr, offset;
    void* dtor;
    char* var5;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &ptr);
    var0 = func_0200d958(var0, &offset);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var5 = (char*)__Register(context, ptr);
        else
            var5 = *(char**)__LocalVariable(context, ptr);

        DTORCALL_PARTIAL(__FunctionPointer(info, context, dtor), var5 + offset);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_3(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    int   var1;
    long  ptr, offset;
    void* dtor;
    char* var5;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &ptr);
    var0 = func_0200d958(var0, &offset);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var5 = (char*)__Register(context, ptr);
        else
            var5 = *(char**)__LocalVariable(context, ptr);

        DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), var5 + offset);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_4(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*               var0 = info->unknown_8_;
    int                 var1, var2;
    long                cond, ptr, offset;
    void*               dtor;
    char*               var7;
    Type_0200d958 var8;

    var2 = *(Type_0200df80_2*)var0 & REGCOND;
    var1  = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &cond);
    var0 = func_0200d958(var0, &ptr);
    var0 = func_0200d958(var0, &offset);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var2)
            var8 = (Type_0200d958)__Register(context, cond);
        else
            var8 = *(Type_0200d958*)__LocalVariable(context, cond);

        if (var8) {
            if (var1)
                var7 = (char*)__Register(context, ptr);
            else
                var7 = *(char**)__LocalVariable(context, ptr);

            DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), var7 + offset);
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_5(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*         var0 = info->unknown_8_;
    int           var1;
    long          ptr, offset;
    unsigned long var4, var5, i;
    void*         dtor;
    char*         var8;

    var1 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &ptr);
    var0 = func_0200d958(var0, &offset);
    var0 = func_0200d9e4(var0, &var4);
    var0 = func_0200d9e4(var0, &var5);
    var0 = __DecodeAddress(var0, &dtor);

    if (apply) {
        if (var1)
            var8 = (char*)__Register(context, ptr) + offset;
        else
            var8 = *(char**)__LocalVariable(context, ptr) + offset;

        for (var8 += var4 * var5, i = var4; i > 0; i--) {
            var8 -= var5;
            DTORCALL_COMPLETE(__FunctionPointer(info, context, dtor), var8);
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_6(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char* var0 = info->unknown_8_;
    long  ptr;
    void* var2;
    char* var3;
    int   var4;

    var4 = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &ptr);
    var0 = __DecodeAddress(var0, &var2);

    if (apply) {
        if (var4)
            var3 = (char*)__Register(context, ptr);
        else
            var3 = *(char**)__LocalVariable(context, ptr);

        ((Type_0200d958_3)__FunctionPointer(info, context, var2))(var3);
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_7(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*           var0 = info->unknown_8_;
    long            cond, ptr;
    void*           var3;
    char*           var4;
    int             var5, var6;
    Type_0200d958_2 var7;

    var6 = *(Type_0200df80_2*)var0 & REGCOND;
    var5  = *(Type_0200df80_2*)var0 & REGPTR;
    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &cond);
    var0 = func_0200d958(var0, &ptr);
    var0 = __DecodeAddress(var0, &var3);

    if (apply) {
        if (var6)
            var7 = (Type_0200d958_2)__Register(context, cond);
        else
            var7 = *(Type_0200d958_2*)__LocalVariable(context, cond);

        if (var7) {
            if (var5)
                var4 = (char*)__Register(context, ptr);
            else
                var4 = *(char**)__LocalVariable(context, ptr);

            ((Type_0200d958_3)__FunctionPointer(info, context, var3))(var4);
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_8(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*         var0 = info->unknown_8_;
    void*         var1;
    unsigned long var2;
    long          var3;

    var0 += sizeof(Type_0200df80_2);
    var0 = __DecodeAddress(var0, &var1);
    var0 = func_0200d9e4(var0, &var2);
    var0 = func_0200d958(var0, &var3);

    if (apply) {
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_9(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*      var0 = info->unknown_8_;
    long       var1;
    Struct_0200d958_6* var2;

    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d958(var0, &var1);

    if (apply) {
        var2 = (Struct_0200d958_6*)__LocalVariable(context, var1);
        if (var2->dtor) {
            if (context->location == var2->location) {
                context->dtor = var2->dtor;
            } else
                DTORCALL_COMPLETE(var2->dtor, var2->location);
        }
    }

    info->unknown_8_ = var0;
}

inline void inline_0200df80_10(int apply, Struct_0200df80_2* info, Struct_0200df80* context) {
    char*         var0 = info->unknown_8_;
    unsigned long var1, var2;
    long          var3;

    var0 += sizeof(Type_0200df80_2);
    var0 = func_0200d9e4(var0, &var1);
    var0 = func_0200d9e4(var0, &var2);
    var0 = func_0200d958(var0, &var3);
    var0 += var1 * sizeof(char*);

    if (apply) {
    }

    info->unknown_8_ = var0;
}


// USA: func_0200df80
extern "C" ARM void func_0200df80(Struct_0200df80* context, Struct_0200df80_2* info, char* arg2) {
    Type_0200df80_2 action;

#pragma exception_terminate

    while (true) {
        if (info->unknown_8_ == 0) {
            func_0200dad4(func_0200f1a0(context, info), info);

            if (!info->unknown_4_) {
                func_0200efb8();
            }
            func_0200f1fc(context, info);

            if (info->unknown_8_ == 0) {
                continue;
            }
        }

        action = *(Type_0200df80_2*)info->unknown_8_;

        switch (action & EXACTION_MASK) {
            case EXACTION_BRANCH:
                inline_0200df80_11(info, context);
                break;
            case EXACTION_DESTROYLOCAL:
                inline_0200df80_12(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYLOCALCOND:
                inline_0200df80_13(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYLOCALPOINTER:
                inline_0200df80_14(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYLOCALARRAY:
                inline_0200df80_15(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYBASE:
                inline_0200df80_2(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYMEMBER:
                inline_0200df80_3(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYMEMBERCOND:
                inline_0200df80_4(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYMEMBERARRAY:
                inline_0200df80_5(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DELETEPOINTER:
                inline_0200df80_6(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DELETEPOINTERCOND:
                inline_0200df80_7(Enum_0200df80_1, info, context);
                break;
            case EXACTION_CATCHBLOCK:
                if (arg2 == info->unknown_8_)
                    return;
                inline_0200df80_8(Enum_0200df80_0, info, context);
                break;
            case EXACTION_ACTIVECATCHBLOCK:
                inline_0200df80_9(Enum_0200df80_1, info, context);
                break;
            case EXACTION_SPECIFICATION:
                if (arg2 == info->unknown_8_)
                    return;
                inline_0200df80_10(Enum_0200df80_0, info, context);
                break;
            case EXACTION_DESTROYBASEVTTOBJECT:
                inline_0200df80_18(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYBASEVTTPOINTER:
                inline_0200df80(Enum_0200df80_1, info, context);
                break;
            case EXACTION_DESTROYVLA:
                inline_0200df80_16(Enum_0200df80_1, info, context);
                break;
            case EXACTION_FREEVLA:
                inline_0200df80_17(Enum_0200df80_1, info, context);
                break;
            default:
                func_0200efb8();
        }

        if (action & EXACTION_ENDBIT) {
            info->unknown_8_ = 0;
        }
    }
}

