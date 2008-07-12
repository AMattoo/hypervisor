/*
* ========== Copyright Header Begin ==========================================
*
* Hypervisor Software File: intr.h
* 
* Copyright (c) 2006 Sun Microsystems, Inc. All Rights Reserved.
* 
*  - Do no alter or remove copyright notices
* 
*  - Redistribution and use of this software in source and binary forms, with 
*    or without modification, are permitted provided that the following 
*    conditions are met: 
* 
*  - Redistribution of source code must retain the above copyright notice, 
*    this list of conditions and the following disclaimer.
* 
*  - Redistribution in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution. 
* 
*    Neither the name of Sun Microsystems, Inc. or the names of contributors 
* may be used to endorse or promote products derived from this software 
* without specific prior written permission. 
* 
*     This software is provided "AS IS," without a warranty of any kind. 
* ALL EXPRESS OR IMPLIED CONDITIONS, REPRESENTATIONS AND WARRANTIES, 
* INCLUDING ANY IMPLIED WARRANTY OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE OR NON-INFRINGEMENT, ARE HEREBY EXCLUDED. SUN 
* MICROSYSTEMS, INC. ("SUN") AND ITS LICENSORS SHALL NOT BE LIABLE FOR 
* ANY DAMAGES SUFFERED BY LICENSEE AS A RESULT OF USING, MODIFYING OR 
* DISTRIBUTING THIS SOFTWARE OR ITS DERIVATIVES. IN NO EVENT WILL SUN 
* OR ITS LICENSORS BE LIABLE FOR ANY LOST REVENUE, PROFIT OR DATA, OR 
* FOR DIRECT, INDIRECT, SPECIAL, CONSEQUENTIAL, INCIDENTAL OR PUNITIVE 
* DAMAGES, HOWEVER CAUSED AND REGARDLESS OF THE THEORY OF LIABILITY, 
* ARISING OUT OF THE USE OF OR INABILITY TO USE THIS SOFTWARE, EVEN IF 
* SUN HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* 
* You acknowledge that this software is not designed, licensed or
* intended for use in the design, construction, operation or maintenance of
* any nuclear facility. 
* 
* ========== Copyright Header End ============================================
*/
/*
 * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _ONTARIO_INTR_H
#define	_ONTARIO_INTR_H

#pragma ident	"@(#)intr.h	1.2	07/05/03 SMI"

#ifdef __cplusplus
extern "C" {
#endif

#include <fire.h>
#include <jbi_regs.h>
#include <iob.h>

#define	DEV_MONDO_INT			IOBINT
#define	DEV_MONDO_INT_ABUSY		J_INT_ABUSY
#define	DEV_MONDO_INT_ABUSY_BUSY	J_INT_BUSY_BUSY
#define	DEV_MONDO_INT_DATA0		J_INT_DATA0
#define	DEV_MONDO_INT_DATA1		J_INT_DATA1
#define	DEV_MONDO_INT_BUSY		J_INT_ABUSY
#define	DEV_DEVINO_SHIFT		FIRE_DEVINO_SHIFT

#define	NPCIEDEVS			2

#ifdef __cplusplus
}
#endif

#endif /* _ONTARIO_INTR_H */
