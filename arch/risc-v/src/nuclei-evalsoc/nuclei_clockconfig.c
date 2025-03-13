/****************************************************************************
 * arch/risc-v/src/nuclei-evalsoc/nuclei_clockconfig.c
 *
 * SPDX-License-Identifier: Apache-2.0
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
#include <assert.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <arch/board/board.h>

#include "riscv_internal.h"
#include "nuclei_clockconfig.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

#define EXT_OSC 16000000

static uint32_t sysclk;
/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: nuclei_get_hfclk
 ****************************************************************************/

uint32_t nuclei_get_hfclk(void)
{
    return sysclk;
}

/****************************************************************************
 * Name: nuclei_clockconfig
 ****************************************************************************/

void nuclei_clockconfig(void)
{
   sysclk = EXT_OSC;
}
