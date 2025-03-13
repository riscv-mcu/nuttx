/****************************************************************************
 * arch/risc-v/src/evalsoc.hardware/nuclei_memorymap.h
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

#ifndef __ARCH_RISCV_SRC_NUCLEI_HARDWARE_NUCLEI_MEMORYMAP_H
#define __ARCH_RISCV_SRC_NUCLEI_HARDWARE_NUCLEI_MEMORYMAP_H

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register Base Address ****************************************************/
#define NUCLEI_EVALSOC_IREGION_BASE  0x18000000
#define NUCLEI_EVALSOC_ECLIC_OFS    (0x20000)
#define NUCLEI_EVALSOC_TIMER_OFS    (0x30000)
#define NUCLEI_EVALSOC_SYSTM_BASE   (NUCLEI_EVALSOC_IREGION_BASE + NUCLEI_EVALSOC_TIMER_OFS)
#define NUCLEI_EVALSOC_ECLIC_BASE   (NUCLEI_EVALSOC_IREGION_BASE + NUCLEI_EVALSOC_ECLIC_OFS)

#define NUCLEI_EVALSOC_MTIME        (NUCLEI_EVALSOC_SYSTM_BASE)
#define NUCLEI_EVALSOC_MTIMECMP     (NUCLEI_EVALSOC_SYSTM_BASE + 8)



#define NUCLEI_EVALSOC_UART0_BASE   0x10013000  /* 0x10013000 - 0x10013fff: UART0 */
#define NUCLEI_EVALSOC_QSPI0_BASE   0x10014000  /* 0x10014000 - 0x10014fff: QSPI0 */
#define NUCLEI_EVALSOC_UART1_BASE   0x10023000  /* 0x10023000 - 0x10023fff: UART1 */

#endif /* __ARCH_RISCV_SRC_NUCLEI_HARDWARE_NUCLEI_MEMORYMAP_H */
