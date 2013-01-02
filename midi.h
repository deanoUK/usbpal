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

#ifndef USBPAL_MIDI_H
#define USBPAL_MIDI_H

#include "common.h"

enum {
	MIDI_BUFSIZE = 64
};

struct midi_runtime {
	struct usbpal_chip *chip;
	struct snd_rawmidi *instance;

	struct snd_rawmidi_substream *in;
	char in_active;

	spinlock_t in_lock;
	spinlock_t out_lock;
	struct snd_rawmidi_substream *out;
	struct urb out_urb;
	u8 out_serial; /* serial number of out packet */
	u8 out_buffer[MIDI_BUFSIZE];
	int buffer_offset;

	void (*in_received)(struct midi_runtime *rt, u8 *data, int length);
};

int __devinit usbpal_midi_init(struct usbpal_chip *chip);
void usbpal_midi_abort(struct usbpal_chip *chip);
void usbpal_midi_destroy(struct usbpal_chip *chip);
#endif /* USBPAL_MIDI_H */

