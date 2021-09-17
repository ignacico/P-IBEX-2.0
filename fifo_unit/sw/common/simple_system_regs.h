// Copyright lowRISC contributors.
// Licensed under the Apache License, Version 2.0, see LICENSE for details.
// SPDX-License-Identifier: Apache-2.0

#ifndef SIMPLE_SYSTEM_REGS_H__
#define SIMPLE_SYSTEM_REGS_H__

#define SIM_CTRL_BASE 0x20000
#define SIM_CTRL_OUT 0x0
#define SIM_CTRL_CTRL 0x8

#define TIMER_BASE 0x30000
#define TIMER_MTIME 0x0
#define TIMER_MTIMEH 0x4
#define TIMER_MTIMECMP 0x8
#define TIMER_MTIMECMPH 0xC

//#define POSIT_COOPROC_BASE 0x40000

#define POSIT_COOPROC_BASE 0x40000
#define POSIT_COOPROC_OP_A 0x40004
#define POSIT_COOPROC_OP_B 0x40008
#define POSIT_COOPROC_OP_CODE 0x4000C
#define POSIT_COOPROC_ADD 0x40010
#define POSIT_COOPROC_MUL 0x40014
#define POSIT_COOPROC_DIV 0x40018

#endif  // SIMPLE_SYSTEM_REGS_H__
