#include <standardports.h>

#include <R7F711001.h>
#include <iodef.h>
#include <U5L_common_types.h>
#include <cpu_ss_workaround.h>
#include <stdlib.h>
#include <extclk.h>
#include <stdarg.h>
#include <stdio.h>

#define TOGGLE_WAIT 2450000

void LED (void){
    int i;
    PORT_inst_0->PKCPROT = UNLOCK_KCPROT;
    PORT_inst_0->PWE_b.PWEAP0 = 1;
    PORT_inst_0->PKCPROT = LOCK_KCPROT;
    PORT_inst_0->APM0_b.APM0_0 = 0;
    
    while(1) {
        PORT_inst_0->AP0_b.AP0_0 = 1;

        for (i = 0; i<TOGGLE_WAIT; i++)
            __asm("nop");

        PORT_inst_0->AP0_b.AP0_0 = 0;

        for (i = 0; i<TOGGLE_WAIT; i++)
            __asm("nop");
    }
}
