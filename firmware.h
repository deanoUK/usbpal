/*
 * Linux driver for the RigiSystems USBPAL devices
 *
 * Author:	Torsten Schenk <torsten.schenk@zoho.com>
 *		Jurgen Kramer <>
 * Created:	 Jan 01, 2011
 * Copyright:	(C) Torsten Schenk
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef USBPAL_FIRMWARE_H
#define USBPAL_FIRMWARE_H

#include "common.h"

enum /* firmware state of device */
{
	FW_READY = 0,
	FW_NOT_READY = 1
};

int __devinit usbpal_fw_init(struct usb_interface *intf);
#endif /* USBPAL_FIRMWARE_H */

