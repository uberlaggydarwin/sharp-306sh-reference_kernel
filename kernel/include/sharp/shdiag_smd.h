/* include/sharp/shdiag_smd.h
 *
 * Copyright (C) 2010 Sharp Corporation
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _SHDIAG_SMD_H_
#define _SHDIAG_SMD_H_

/*
 * Defines
 */

#define SHDIAG_SMD_DEVFILE "/dev/smd_read"

#define SHDIAG_IOC_MAGIC 's'
#define SHDIAG_IOCTL_SET_QXDMFLG     _IOW  (SHDIAG_IOC_MAGIC,  1, unsigned char)
#define SHDIAG_IOCTL_SET_PROADJ      _IOW  (SHDIAG_IOC_MAGIC,  2, struct shdiag_procadj)
#define SHDIAG_IOCTL_GET_HW_REVISION _IOR  (SHDIAG_IOC_MAGIC,  3, unsigned long)
#define SHDIAG_IOCTL_SET_HAPTICSCAL  _IOW  (SHDIAG_IOC_MAGIC,  4, struct shdiag_hapticscal)
#define SHDIAG_IOCTL_SET_GPIO_PULL   _IOW  (SHDIAG_IOC_MAGIC,  5, struct shdiag_gpio)
#define SHDIAG_IOCTL_GET_SBST        _IOR  (SHDIAG_IOC_MAGIC,  6, unsigned int)
#define SHDIAG_IOCTL_GET_DDRINFO     _IOR  (SHDIAG_IOC_MAGIC,  7, unsigned char[2])


/* SHDIAG BOOT MODE */
#define D_SHDIAG_BOOT_NORMAL			0x00	/* Normal Mode    */
#define D_SHDIAG_BOOT_FUNC				0x01	/* Function Mode  */
#define D_SHDIAG_BOOT_HW				0x02	/* H/W Check Mode */
#define D_SHDIAG_BOOT_BIND				0x03	/* BIND Mode      */
#define D_SHDIAG_BOOT_SHIP				0x04	/* SHIP Mode      */
#define D_SHDIAG_BOOT_MENU				0x05	/* MENU Mode      */
#define D_SHDIAG_BOOT_AGING				0x06	/* Aging Mdoe     */
#define D_SHDIAG_BOOT_MANUAL			0x10	/* ManualMode     */
#define D_SHDIAG_BOOT_VERCHK			0x20	/* Version Check  */

/*
 * TYPES
 */

struct smem_comm_mode {
	unsigned short BootMode;
	unsigned long UpDateFlg;
};

struct shdiag_procadj {
    unsigned long proxcheckdata_min;
    unsigned long proxcheckdata_max;
};

#define SHDIAG_HAPTICSCAL_SIZE 0x03
struct shdiag_hapticscal {
	unsigned char buf[SHDIAG_HAPTICSCAL_SIZE];
};

struct shdiag_gpio {
    unsigned long port;
    unsigned long pull;
};

/*End of File*/
#endif /* _SHDIAG_SMD_H_ */
