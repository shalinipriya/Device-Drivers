/*
 * lmm_avail.c
 * Modified for use in 15-410 at CMU
 * Zachary Anderson(zra)
 */

/*
 * Copyright (c) 1995, 1998-1999 University of Utah and the Flux Group.
 * All rights reserved.
 * 
 * This file is part of the Flux OSKit.  The OSKit is free software, also known
 * as "open source;" you can redistribute it and/or modify it under the terms
 * of the GNU General Public License (GPL), version 2, as published by the Free
 * Software Foundation (FSF).  To explore alternate licensing terms, contact
 * the University of Utah at csl-dist@cs.utah.edu or +1-801-585-3271.
 * 
 * The OSKit is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GPL for more details.  You should have
 * received a copy of the GPL along with the OSKit; see the file COPYING.  If
 * not, write to the FSF, 59 Temple Place #330, Boston, MA 02111-1307, USA.
 */

#include "lmm.h"

int lmm_avail(lmm_t *lmm, lmm_flags_t flags)
{
	struct lmm_region *reg;
	int count;

	count = 0;
	for (reg = lmm->regions; reg; reg = reg->next)
	{
		CHECKREGPTR(reg);

		/* Don't count inapplicable regions.  */
		if (flags & ~reg->flags)
			continue;

		count += reg->free;
	}
	return count;
}

