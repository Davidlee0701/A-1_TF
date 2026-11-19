/*
 * extclk.h
 *
 *  Created on: 29.10.2024
 *      Author: a5105882
 */

#ifndef SRC_MACRO_EXT_CLK_EXTCLK_H_
#define SRC_MACRO_EXT_CLK_EXTCLK_H_



typedef enum {
	SOURCE_CLOCK_PLL0 = 0,
	SOURCE_CLOCK_PLL1 = 1,
} SOURCE_CLOCK_E;

void CFG_EXTCLK0O_PORT(void);
void CFG_EXTCLK1O_PORT(void);

void Init_EXTCLK0O(void);
void Init_EXTCLK1O(SOURCE_CLOCK_E SrcClk);

#endif /* SRC_MACRO_EXT_CLK_EXTCLK_H_ */
