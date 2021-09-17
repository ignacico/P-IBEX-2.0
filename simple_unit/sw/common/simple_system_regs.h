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

#define POSIT_COOPROC_BASE 0x40000

#define POSIT_SINGLE_BASE 0x50000
#define POSIT_SINGLE_OP_A 0x50000
#define POSIT_SINGLE_OP_B 0x50008
#define POSIT_SINGLE_OUTPUT 0x50010

#endif  // SIMPLE_SYSTEM_REGS_H__
