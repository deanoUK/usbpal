/*
 * Linux driver for the RigiSystems USBPAL devices
 *
 * Author:	Torsten Schenk <torsten.schenk@zoho.com>
 *		Jurgen Kramer <>
 * Created:	Jan 01, 2011
 * Copyright:	(C) Torsten Schenk
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */
#ifndef USBPAL_COMM_H
#define USBPAL_COMM_H

#include "common.h"

enum /* settings for comm */
{
	COMM_RECEIVER_BUFSIZE = 64,
};

struct comm_runtime {
	struct usbpal_chip *chip;

	struct urb receiver;
	u8 receiver_buffer[COMM_RECEIVER_BUFSIZE];

	u8 serial; /* urb serial */

	void (*init_urb)(struct comm_runtime *rt, struct urb *urb, u8 *buffer,
			void *context, void(*handler)(struct urb *urb));
	/* writes control data to the device */
	int (*write8)(struct comm_runtime *rt, u8 request, u8 reg, u8 value);
	int (*write16)(struct comm_runtime *rt, u8 request, u8 reg,
			u8 vh, u8 vl);
};

int __devinit usbpal_comm_init(struct usbpal_chip *chip);
void usbpal_comm_abort(struct usbpal_chip *chip);
void usbpal_comm_destroy(struct usbpal_chip *chip);
#endif /* USBPAL_COMM_H */

