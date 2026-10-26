#include <globaldefs.h>

#define COMMAND_SYNC 0x60
#define COMMAND_UTILITY 0x61
#define COMMAND_SLEEP_START 0x62
#define COMMAND_SLEEP_END 0x63

#define RESULT_SEND_FAILED 1
#define RESULT_ERROR 2

#define PM_SUCCESS 0

typedef void (*Type_01ff8300_3)(unsigned long result, void* arg);

struct Struct_020ce308
{
    int lock;
    Type_01ff8300_3 callback;
    void* unknown_8_;
    void* work;
};

struct Struct_021117ec_5
{
    char unknown_0[0xc];
    volatile int unknown_c_;
    char unknown_10[0xc];
    Struct_020ce308 work;
};

extern Struct_021117ec_5 data_021117ec;

extern "C" void func_020ce240(int result);

// USA: func_020ce308
extern "C" ARM void func_020ce308(unsigned int tag, unsigned int data, unsigned int arg2)
{
    const unsigned short command = (data & 0x7f00) >> 8;
    unsigned short result = data & 0xff;
    if (arg2)
    {
        switch (command)
        {
        case COMMAND_UTILITY:
        case COMMAND_SLEEP_START:
            result = RESULT_SEND_FAILED;
            break;
        default:
            result = RESULT_ERROR;
            break;
        }
        func_020ce240(result);
        return;
    }
    switch (command)
    {
    case COMMAND_UTILITY:
        if (data_021117ec.work.work)
            *(unsigned short*)data_021117ec.work.work = result;
        result = PM_SUCCESS;
        break;
    case COMMAND_SYNC:
        result = PM_SUCCESS;
        break;
    case COMMAND_SLEEP_START:
        break;
    case COMMAND_SLEEP_END:
        data_021117ec.unknown_c_ = true;
        break;
    }
    func_020ce240(result);
}
