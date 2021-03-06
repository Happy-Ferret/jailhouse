/*
 * Jailhouse, a Linux-based partitioning hypervisor
 *
 * Copyright (c) ARM Limited, 2014
 *
 * Authors:
 *  Jean-Philippe Brucker <jean-philippe.brucker@arm.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2.  See
 * the COPYING file in the top-level directory.
 */

/*
 * To ease the debugging, we can send a spurious hypercall, which should return
 * -ENOSYS, but appear in the hypervisor stats for this cell.
 */
static inline void heartbeat(void)
{
	asm volatile (
	"mov	x0, %0\n"
	"hvc	#0\n"
	: : "r" (0xbea7) : "x0");
}

void __attribute__((used)) vector_irq(void);
