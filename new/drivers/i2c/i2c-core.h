/*
 * i2c-core.h - interfaces internal to the I2C framework
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/rwsem.h>

struct i2c_devinfo {
	struct list_head	list;
	int			busnum;
/*
	板级信息
*/
	struct i2c_board_info	board_info;
};

/* board_lock protects board_list and first_dynamic_bus_num.
 * only i2c core components are allowed to use these symbols.
 */
extern struct rw_semaphore	__i2c_board_lock;
extern struct list_head	__i2c_board_list;
extern int		__i2c_first_dynamic_bus_num;

