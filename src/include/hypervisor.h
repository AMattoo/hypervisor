/*
* ========== Copyright Header Begin ==========================================
*
* Hypervisor Software File: hypervisor.h
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
 * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

#ifndef _HYPERVISOR_H
#define	_HYPERVISOR_H

#pragma ident	"@(#)hypervisor.h	1.44	06/05/26 SMI"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Common Hypervisor definitions
 */

/*
 * Hypervisor software trap numbers
 */
#define	FAST_TRAP	0x80
#define	MMU_MAP_ADDR	0x83
#define	MMU_UNMAP_ADDR	0x84
#define	TTRACE_ADDENTRY	0x85
#define	CORE_TRAP	0xff


/*
 * Hypervisor function numbers for CORE_TRAP
 */
#define	API_SET_VERSION		0x00
#define	API_PUTCHAR		0x01
#define	API_EXIT		0x02
#define	API_GET_VERSION		0x03


/*
 * Hypervisor function numbers for FAST_TRAP
 */

/*
 * CPU/Memory APIs (Core API group)
 */
#define	MACH_EXIT		0x00
#define	MACH_DESC		0x01
#define	MACH_SIR		0x02
#define	MACH_SET_WATCHDOG	0x05

#define	CPU_START		0x10
#define	CPU_STOP		0x11
#define	CPU_YIELD		0x12
#define	CPU_QCONF		0x14
#define	CPU_QINFO		0x15
#define	CPU_MYID		0x16
#define	CPU_STATE		0x17
#define	CPU_SET_RTBA		0x18
#define	CPU_GET_RTBA		0x19

#define	MMU_TSB_CTX0		0x20
#define	MMU_TSB_CTXNON0		0x21
#define	MMU_DEMAP_PAGE		0x22
#define	MMU_DEMAP_CTX		0x23
#define	MMU_DEMAP_ALL		0x24
#define	MMU_MAP_PERM_ADDR	0x25
#define	MMU_FAULT_AREA_CONF	0x26
#define	MMU_ENABLE		0x27
#define	MMU_UNMAP_PERM_ADDR	0x28
#define	MMU_TSB_CTX0_INFO	0x29
#define	MMU_TSB_CTXNON0_INFO	0x2a
#define	MMU_FAULT_AREA_INFO	0x2b

#define	MEM_SCRUB		0x31
#define	MEM_SYNC		0x32

#define	CPU_MONDO_SEND		0x42

#define	TOD_GET			0x50
#define	TOD_SET			0x51

#define	CONS_GETCHAR		0x60
#define	CONS_PUTCHAR		0x61
#define	CONS_READ		0x62
#define	CONS_WRITE		0x63

#if 1 /* Not in spec */
#define	NVRAM_READ		0x70
#define	NVRAM_WRITE		0x71
#endif

#define	TTRACE_BUF_CONF		0x90
#define	TTRACE_BUF_INFO		0x91
#define	TTRACE_ENABLE		0x92
#define	TTRACE_FREEZE		0x93
#define	DUMP_BUF_UPDATE		0x94
#define	DUMP_BUF_INFO		0x95

#define	INTR_DEVINO2SYSINO	0xa0
#define	INTR_GETENABLED		0xa1
#define	INTR_SETENABLED		0xa2
#define	INTR_GETSTATE		0xa3
#define	INTR_SETSTATE		0xa4
#define	INTR_GETTARGET		0xa5
#define	INTR_SETTARGET		0xa6

/*
 * vPCI APIs (PCIe API group)
 */
#define	VPCI_IOMMU_MAP		0xb0
#define	VPCI_IOMMU_UNMAP	0xb1
#define	VPCI_IOMMU_GETMAP	0xb2
#define	VPCI_IOMMU_GETBYPASS	0xb3
#define	VPCI_CONFIG_GET		0xb4
#define	VPCI_CONFIG_PUT		0xb5
#define	VPCI_IO_PEEK		0xb6
#define	VPCI_IO_POKE		0xb7
#define	VPCI_DMA_SYNC		0xb8


#define	MSIQ_CONF		0xc0
#define	MSIQ_INFO		0xc1
#define	MSIQ_GETVALID		0xc2
#define	MSIQ_SETVALID		0xc3
#define	MSIQ_GETSTATE		0xc4
#define	MSIQ_SETSTATE		0xc5
#define	MSIQ_GETHEAD		0xc6
#define	MSIQ_SETHEAD		0xc7
#define	MSIQ_GETTAIL		0xc8

#define	MSI_GETVALID		0xc9
#define	MSI_SETVALID		0xca
#define	MSI_GETMSIQ		0xcb
#define	MSI_SETMSIQ		0xcc
#define	MSI_GETSTATE		0xcd
#define	MSI_SETSTATE		0xce

#define	MSI_MSG_GETMSIQ		0xd0
#define	MSI_MSG_SETMSIQ		0xd1
#define	MSI_MSG_GETVALID	0xd2
#define	MSI_MSG_SETVALID	0xd3

/*
 * Platform-specific APIs
 */

/*
 * Greatlakes platform service channels (SVC API group)
 */
#ifdef CONFIG_SVC
#define	SVC_SEND		0x80
#define	SVC_RECV		0x81
#define	SVC_GETSTATUS		0x82
#define	SVC_SETSTATUS		0x83
#define	SVC_CLRSTATUS		0x84
#endif

/*
 * Niagara-specific hcalls (Niagara Perf Regs API group)
 */
#define	NIAGARA_GET_PERFREG	0x100	/* Get Niagara JBUS/DRAM perf reg */
#define	NIAGARA_SET_PERFREG	0x101	/* Set Niagara JBUS/DRAM perf reg */

/*
 * Niagara MMU statistics (Niagara Perf Regs API group)
 */
#define	NIAGARA_MMUSTAT_CONF	0x102
#define	NIAGARA_MMUSTAT_INFO	0x103

/*
 * Niagara Crypto Service Request (Niagara Crypto API group)
 */
#define	NCS_REQUEST		0x110

/*
 * Fire-specific hcalls (Fire API group)
 */
#define	FIRE_GET_PERFREG	0x120
#define	FIRE_SET_PERFREG	0x121

/* ----------------------------------- */

/*
 * Simulation-only APIs (Core API group)
 */
#ifdef CONFIG_DISK
#define	DISK_READ		0xf0
#define	DISK_WRITE		0xf1
#endif

#ifdef DEBUG /* Not yet FWARCd */
#define	MMU_PERM_ADDR_INFO	0xfd
#endif

/*
 * Diagnostic hcalls (Diag and Test API group)
 */
#define	DIAG_RA2PA		0x200	/* diagnostic partitions only */
#define	DIAG_HEXEC		0x201	/* diagnostic partitions only */


/* ----------------------------------- */

/*
 * Hypervisor manifest constants
 */

/*
 * Version API groups
 * hcalls: API_SET_VERSION/API_GET_VERSION
 */
#define	API_GROUP_SUN4V		0x000
#define	API_GROUP_CORE		0x001
#define	API_GROUP_INTR		0x002
#define	API_GROUP_PCI		0x100
#define	API_GROUP_LDC		0x101
#define	API_GROUP_SVC		0x102
#define	API_GROUP_NCS		0x103
#define	API_GROUP_NIAGARA	0x200
#define	API_GROUP_FIRE		0x201
#define	API_GROUP_DIAG		0x300

#define	SUN4V_VERSION_INITIAL	1

/*
 * CPU States
 */
#define	CPU_STATE_INVALID	0x0
#define	CPU_STATE_STOPPED	0x1	/* cpu not started */
#define	CPU_STATE_RUNNING	0x2	/* cpu running guest code */
#define	CPU_STATE_ERROR		0x3	/* cpu is in the error state */
#define	CPU_STATE_LAST_PUBLIC	CPU_STATE_ERROR /* last valid state */

/*
 * Niagara JBUS/DRAM performance register ID
 *
 * hcalls: NIAGARA_SET_PERFREG/NIAGARA_GET_PERFREG
 */
#define	NIAGARA_PERFREG_JBUS_CTL	0x00
#define	NIAGARA_PERFREG_JBUS_COUNT	0x01
#define	NIAGARA_PERFREG_DRAM_CTL0	0x02
#define	NIAGARA_PERFREG_DRAM_COUNT0	0x03
#define	NIAGARA_PERFREG_DRAM_CTL1	0x04
#define	NIAGARA_PERFREG_DRAM_COUNT1	0x05
#define	NIAGARA_PERFREG_DRAM_CTL2	0x06
#define	NIAGARA_PERFREG_DRAM_COUNT2	0x07
#define	NIAGARA_PERFREG_DRAM_CTL3	0x08
#define	NIAGARA_PERFREG_DRAM_COUNT3	0x09

#define	NIAGARA_PERFREG_MAX		10

/*
 * MMU constants
 */

/* MMU map flags (MMU_MAP_ADDR/MMU_MAP_PERM_ADDR/etc) */
#define	MAP_DTLB	0x1
#define	MAP_ITLB	0x2

#define	NPERMMAPPINGS	8	/* MMU_MAP_PERM_ADDR */

#define	MMU_FAULT_AREA_SIZE	0x80 /* MMU_FAULT_AREA */
#define	MMU_FAULT_AREA_ALIGNMENT	64

/*
 * TSB description area (MMU_TSB_*)
 */
#define	TSBD_BYTES	32
#define	TSBD_SHIFT	5	/* log2(TSBD_BYTES) */
#define	TSBD_ALIGNMENT	8

#define	TSBD_IDXPGSZ_OFF 0	/* 2 bytes */
#define	TSBD_ASSOC_OFF	2	/* 2 bytes */
#define	TSBD_SIZE_OFF	4	/* 4 bytes */
#define	TSBD_CTX_INDEX	8	/* 4 bytes */
#define	TSBD_PGSZS_OFF	12	/* 4 bytes */
#define	TSBD_BASE_OFF	16	/* 8 bytes */
#define	TSBD_RSVD_OFF	24	/* 8 bytes */

#define	TSBD_CTX_IDX_SHARE	-1


/*
 * Permanent mapping table
 */
#define	PERMMAPINFO_BYTES	32 /* size of each entry in the list */
#define	PERMMAPINFO_VA		0 /* permanent mapping virtual address */
#define	PERMMAPINFO_CTX		8 /* permanent mapping context */
#define	PERMMAPINFO_TTE		16 /* permanent mapping's TTE */
#define	PERMMAPINFO_FLAGS	24 /* permanent mapping flags for this cpu */


/*
 * cpulists
 */
#define	CPULIST_ENTRYDONE	-1 /* item in list was completed */
#define	CPULIST_ENTRYSIZE	2 /* each item is 16 bits */
#define	CPULIST_ENTRYSIZE_SHIFT	1 /* cpulist index to offset */
#define	CPULIST_ALIGNMENT	CPULIST_ENTRYSIZE


/*
 * MEM_SCRUB / MEM_SYNC
 */
#define	MEMSYNC_ALIGNMENT	0x2000

/*
 * MACH_DESC
 */
#define	MACH_DESC_ALIGNMENT	0x10	/* 16-byte alignment */


/*
 * Hypervisor call status codes
 */
#define	EOK		0	/* No error */
#define	ENOCPU		1	/* Invalid CPU id */
#define	ENORADDR	2	/* Invalid real address */
#define	ENOINTR		3	/* Invalid interrupt id */
#define	EBADPGSZ	4	/* Invalid page size encoding */
#define	EBADTSB		5	/* Invalid TSB description */
#define	EINVAL		6	/* Invalid argument */
#define	EBADTRAP	7	/* Invalid function number */
#define	EBADALIGN	8	/* Invalid address alignment */
#define	EWOULDBLOCK	9	/* Call would block */
#define	ENOACCESS	10	/* No access to resource */
#define	EIO		11	/* I/O error */
#define	ECPUERROR	12	/* CPU is in error state */
#define	ENOTSUPPORTED	13	/* Function or request is not supported */
#define	ENOMAP		14	/* No mapping found */
#define	ETOOMANY	15	/* Hard resource limit exceeded */

/*
 * Hypervisor call return values
 */

/* CONS_GETCHAR and CONS_PUTCHAR special character values (64-bit) */
#define	CONS_BREAK	-1
#define	CONS_HUP	-2	/* CONS_GETCHAR only */

#define	MAX_CHAR	255

/*
 * Traptrace header data structure offsets
 * TTRACE_HEADER_LAST_OFF is analogous to sun4u's TRAPTR_LAST_OFFSET
 * TTRACE_HEADER_OFFSET is analogous to sun4u's TRAPTR_OFFSET
 */
#define	TTRACE_HEADER_LAST_OFF	(0 * 8) /* 64-bits, last_offset (#bytes) */
#define	TTRACE_HEADER_OFFSET	(1 * 8) /* 64-bits, next offset (#bytes) */

/*
 * Traptrace record data structure offsets
 */
#define	TTRACE_ENTRY_TYPE	((0 * 8) + 0) /* 8-bits */
#define	TTRACE_ENTRY_HPSTATE	((0 * 8) + 1) /* 8-bits */
#define	TTRACE_ENTRY_TL		((0 * 8) + 2) /* 8-bits */
#define	TTRACE_ENTRY_GL		((0 * 8) + 3) /* 8-bits */
#define	TTRACE_ENTRY_TT		((0 * 8) + 4) /* 16-bits */
#define	TTRACE_ENTRY_TAG	((0 * 8) + 6) /* 16-bits */
#define	TTRACE_ENTRY_TSTATE	(1 * 8) /* 64-bits */
#define	TTRACE_ENTRY_TICK	(2 * 8) /* 64-bits */
#define	TTRACE_ENTRY_TPC	(3 * 8) /* 64-bits */
#define	TTRACE_ENTRY_F1		(4 * 8) /* 64-bits of entry-specific data */
#define	TTRACE_ENTRY_F2		(5 * 8) /* 64-bits of entry-specific data */
#define	TTRACE_ENTRY_F3		(6 * 8) /* 64-bits of entry-specific data */
#define	TTRACE_ENTRY_F4		(7 * 8) /* 64-bits of entry-specific data */

#define	TTRACE_RECORD_SIZE	(8 * 8) /* sizeof record data struct */
#define	TTRACE_RECORD_SZ_SHIFT	6	/* log2(TTRACE_RECORD_SIZE) */

#define	TTRACE_MINIMUM_ENTRIES	2	/* Control struct plus one record. */

#define	TTRACE_ALIGNMENT	(TTRACE_RECORD_SIZE)

/*
 * Definition of TTRACE_ENTRY_TYPE
 * All values not specified are reserved.
 */
#define	TTRACE_TYPE_UNDEF	0	/* entry data undefined */
#define	TTRACE_TYPE_HV		1	/* entry recorded by HV */
#define	TTRACE_TYPE_GUEST	255	/* guest entry, via TTRACE_ADDENTRY */

/*
 * TTRACE_ENTRY_TAG values defined for hypervisor trace entries.
 * The number space of this field is specific to the record's type.
 * Tag values used by the hypervisor are distinct from those
 * defined and used by guest software.
 */
#define	TTRACE_TAG_HVCONF	0xffff	/* continuation entry recorded by HV */

#define	INSTRUCTION_SIZE	4
#define	INSTRUCTION_ALIGNMENT	INSTRUCTION_SIZE

#define	DUMPBUF_ALIGNMENT	64

#define	MONDO_DATA_SIZE		64
#define	MONDO_DATA_ALIGNMENT	MONDO_DATA_SIZE

#define	MIN_QUEUE_ENTRIES	2

#ifdef __cplusplus
}
#endif

#endif /* _HYPERVISOR_H */
