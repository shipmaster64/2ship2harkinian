#include "global.h"

void func_801A5080(u16 arg0);

s32 func_801A5228(u8* arg0);
void func_801A53E8(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4);


void func_801A5680(u16 arg0);
void func_801A54D0(u16 arg0);
u8* func_801A54C4(void);

extern u8 D_801D8BE0;
extern OSVoiceHandle D_801FD5B8;

void func_801A4EB0(void) {
}

void func_801A4EB8(void) {
    u8* new_var;
    OSMesgQueue* msgQ;
    s32 index;
    u8 sp38[1];
    u8 i;

    if (D_801D8E3C != 0) {
        msgQ = PadMgr_LockSerialMesgQueue();
        osVoiceStopReadData(&D_801FD5B8);
        PadMgr_UnlockSerialMesgQueue(msgQ);
    }

    new_var = func_801A54C4();

    for (i = 0; i < 1; i++) {
        sp38[i] = new_var[i];
    }

    if (func_801A5228(&D_801D8BE0) == 0) {
        for (i = 0; i < 6; i++) {
            index = i / 8;
            if (((sp38[index] >> (i % 8)) & 1) == 1) {
                func_801A54D0(i);
            }

        }

        func_801A53E8(0x320, 2, 0x400, 0x1F4, 0x7D0);
        D_801D8E3C = 1;
    }
}

void func_801A4FD8(void) {
    s32 sp24;
    OSMesgQueue* msgQ;

    func_801A54D0(0xFFFF);
    if (D_801D8E3C != 0) {
        msgQ = PadMgr_LockSerialMesgQueue();
        osVoiceStopReadData(&D_801FD5B8);
        PadMgr_UnlockSerialMesgQueue(msgQ);

        sp24 = func_801A5228(&D_801D8BE0);
        func_801A54D0(0xFFFF);
        if (sp24 == 0) {
            func_801A53E8(0x320, 2, 0x400, 0x1F4, 0x7D0);
            D_801D8E3C = 1;
        }
        func_801A5080(5);
        func_801A5080(1);
    }
}

void func_801A5080(u16 arg0) {
    if ((D_801D8E3C != 0) && (arg0 < 6)) {
        func_801A5680(arg0);
    }
}

void func_801A50C0(u16 arg0) {
    if ((D_801D8E3C != 0) && (arg0 < 6)) {
        func_801A54D0(arg0);
    }
}

u16 func_801A5100(void) {
    return D_801D8E44;
}

u8 func_801A510C(void) {
    return D_801D8E3C;
}

#pragma GLOBAL_ASM("asm/non_matchings/code/code_801A4EB0/func_801A5118.s")
