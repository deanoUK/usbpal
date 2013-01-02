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
#ifndef USBPAL_CHIP_H
#define USBPAL_CHIP_H

#include "common.h"

struct usbpal_chip {
	struct usb_device *dev;
	struct snd_card *card;
	int intf_count; /* number of registered interfaces */
	int regidx; /* index in module parameter arrays */
	bool shutdown;

	struct midi_runtime *midi;
	struct pcm_runtime *pcm;
	struct control_runtime *control;
	struct comm_runtime *comm;
};
#endif /* USBPAL_CHIP_H */

