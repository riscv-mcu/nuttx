/****************************************************************************
 * arch/risc-v/src/nuclei-evalsoc/nuclei_start.c
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

#include <stdint.h>

#include <nuttx/init.h>
#include <arch/board/board.h>

#include "nuclei_clockconfig.h"
#include "evalsoc.h"
#include "chip.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#ifdef CONFIG_DEBUG_FEATURES
#  define showprogress(c) riscv_lowputc(c)
#else
#  define showprogress(c)
#endif

/* Nuclei cpu enable cache */
void nuclei_enable_cache(void)
{
  uint32_t mcfg;

  mcfg = READ_CSR(CSR_MCFG_INFO);
  if (mcfg & MCFG_INFO_IC_SUPPORT) {
    /* enable icache */
    SET_CSR(CSR_MCACHE_CTL, MCACHE_CTL_IC_EN);
  }
  if (mcfg & MCFG_INFO_DC_SUPPORT) {
    /* enable dcache */
    SET_CSR(CSR_MCACHE_CTL, MCACHE_CTL_DC_EN);
  }
}

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: __nuclei_start
 ****************************************************************************/

void __nuclei_start(void)
{
  const uint32_t *src;
  uint32_t *dest;

  nuclei_enable_cache();
  /* Clear .bss.  We'll do this inline (vs. calling memset) just to be
   * certain that there are no issues with the state of global variables.
   */

  for (dest = (uint32_t *)_sbss; dest < (uint32_t *)_ebss; )
  {
      *dest++ = 0;
  }

  /* Move the initialized data section from his temporary holding spot in
   * FLASH into the correct place in SRAM.  The correct place in SRAM is
   * give by _sdata and _edata.  The temporary location is in FLASH at the
   * end of all of the other read-only data (.text, .rodata) at _eronly.
   */

  for (src = (const uint32_t *)_eronly,
       dest = (uint32_t *)_sdata; dest < (uint32_t *)_edata;
      )
  {
      *dest++ = *src++;
  }

  /* Setup PLL */

  nuclei_clockconfig();

  /* Configure the UART so we can get debug output */

  nuclei_lowsetup();

  showprogress('A');

#ifdef USE_EARLYSERIALINIT
  riscv_earlyserialinit();
#endif

  showprogress('B');

  /* Do board initialization */

  nuclei_boardinitialize();

  showprogress('C');

  /* Call nx_start() */

  nx_start();

  /* Shouldn't get here */

  for (; ; );
}
