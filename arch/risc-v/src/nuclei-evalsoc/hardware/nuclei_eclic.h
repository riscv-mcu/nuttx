/****************************************************************************
 * arch/risc-v/src/evalsoc.hardware/nuclei_eclic.h
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

#ifndef __ARCH_RISCV_SRC_NUCLEI_HARDWARE_NUCLEI_ECLIC_H
#define __ARCH_RISCV_SRC_NUCLEI_HARDWARE_NUCLEI_ECLIC_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "nuclei_memorymap.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Register offsets *********************************************************/

#define NUCLEI_EVALSOC_ECLIC_INTIP_OFFSET          0x1000
#define NUCLEI_EVALSOC_ECLIC_INTIE_OFFSET          0x1001
#define NUCLEI_EVALSOC_ECLIC_INTATTR_OFFSET        0x1002
#define NUCLEI_EVALSOC_ECLIC_INTCTL_OFFSET         0x1003

/* Register definitions *****************************************************/

#define NUCLEI_EVALSOC_ECLIC_INTIP      (NUCLEI_EVALSOC_ECLIC_BASE + NUCLEI_EVALSOC_ECLIC_INTIP_OFFSET)
#define NUCLEI_EVALSOC_ECLIC_INTIE      (NUCLEI_EVALSOC_ECLIC_BASE + NUCLEI_EVALSOC_ECLIC_INTIE_OFFSET)
#define NUCLEI_EVALSOC_ECLIC_INTATTR    (NUCLEI_EVALSOC_ECLIC_BASE + NUCLEI_EVALSOC_ECLIC_INTATTR_OFFSET)
#define NUCLEI_EVALSOC_ECLIC_INTCTL     (NUCLEI_EVALSOC_ECLIC_BASE + NUCLEI_EVALSOC_ECLIC_INTCTL_OFFSET)

#endif /* __ARCH_RISCV_SRC_NUCLEI_HARDWARE_NUCLEI_CLIC_H */
