/****************************************************************************
 * arch/risc-v/src/nuclei-evalsoc/nuclei_head.S
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <arch/irq.h>

#include "chip.h"
#include "nuclei_memorymap.h"
#include "riscv_internal.h"

/****************************************************************************
 * Public Symbols
 ****************************************************************************/

  /* Imported symbols */

  .extern __trap_vec

  .section .text
  .global __start

__start:

  /* Set stack pointer to the idle thread stack */

  la   sp, NUCLEI_EVALSOC_IDLESTACK_TOP

  /* Disable all interrupts (i.e. timer, external) in mstatus mie */
  li t0, MSTATUS_MIE
  csrc CSR_MSTATUS, t0

#if defined(CONFIG_ARCH_HAVE_FPU) || defined(CONFIG_ARCH_HAVE_DPFPU)
  /* Init FS */
  li t0, MSTATUS_FS_INIT
  csrs CSR_MSTATUS, t0
#endif

  /* Initialize the Machine Trap Vector */
  la   t0, __trap_vec
  /* processor use CLIC Mode */
  ori t0, t0, 3
  csrw CSR_MTVEC, t0

  /* Jump to __nuclei_start */
  jal  x1, __nuclei_start

  /* We shouldn't return from __nuclei_start */
  .global _init
  .global _fini

_init:
_fini:

  /* These don't have to do anything since we use init_array/fini_array. */

  ret

