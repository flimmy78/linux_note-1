/*
 * GCC stack protector support.
 *
 * Stack protector works by putting predefined pattern at the start of
 * the stack frame and verifying that it hasn't been overwritten when
 * returning from the function.  The pattern is called stack canary
 * and gcc expects it to be defined by a global variable called
 * "__stack_chk_guard" on ARM.  This unfortunately means that on SMP
 * we cannot have a different canary value per task.
 */

#ifndef _ASM_STACKPROTECTOR_H
#define _ASM_STACKPROTECTOR_H 1

#include <linux/random.h>
#include <linux/version.h>

extern unsigned long __stack_chk_guard;

/*
 * Initialize the stackprotector canary value.
 *
 * NOTE: this must only be called from functions that never return,
 * and it must always be inlined.
 */
 /**
 * 在初始任务的栈中，放入用于检测堆栈返回值攻击的canary值。
 */
static __always_inline void boot_init_stack_canary(void)
{
	unsigned long canary;

	/* Try to get a semi random initial value. */
	/* 生成随机的小整数，作为canary值 */
	get_random_bytes(&canary, sizeof(canary));
	canary ^= LINUX_VERSION_CODE;
	
	/* 记录当前线程(idle线程)的canary值。*/
	current->stack_canary = canary;
	__stack_chk_guard = current->stack_canary;
}

#endif	/* _ASM_STACKPROTECTOR_H */
