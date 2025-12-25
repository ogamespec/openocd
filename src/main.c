// SPDX-License-Identifier: GPL-2.0-or-later

/***************************************************************************
 *   Copyright (C) 2005 by Dominic Rath                                    *
 *   Dominic.Rath@gmx.de                                                   *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include "openocd.h"
#include "helper/system.h"

/* This is the main entry for developer PC hosted OpenOCD.
 *
 * OpenOCD can also be used as a library that is linked with
 * another application(not mainstream yet, but possible), e.g.
 * w/as an embedded application.
 *
 * Those applications will have their own main() implementation
 * and use bits and pieces from openocd.c. */

#ifndef __GNUC__
// You need to manually call all methods marked as __attribute__ ((constructor))
void hl_constructor(void);
void jtag_constructor(void);
void swim_constructor(void);
void swd_constructor(void);
void dapdirect_constructor(void);
void arm_gdb_dummy_init(void);
void init_ctors()
{
	hl_constructor();
	jtag_constructor();
	swim_constructor();
	swd_constructor();
	dapdirect_constructor();
	arm_gdb_dummy_init();
}
#endif

int main(int argc, char *argv[])
{
	/* disable buffering otherwise piping to logs causes problems work */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

#ifndef __GNUC__
	init_ctors();
#endif

	return openocd_main(argc, argv);
}
