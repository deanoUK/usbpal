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

#ifndef USBPAL_CONTROL_H
#define USBPAL_CONTROL_H

#include "common.h"

enum {
	CONTROL_MAX_ELEMENTS = 32
};

enum {
	CONTROL_RATE_44KHZ,
	CONTROL_RATE_48KHZ,
	CONTROL_RATE_88KHZ,
	CONTROL_RATE_96KHZ,
	CONTROL_RATE_176KHZ,
	CONTROL_RATE_192KHZ,
	CONTROL_N_RATES
};

struct control_runtime {
	int (*update_streaming)(struct control_runtime *rt);
	int (*set_rate)(struct control_runtime *rt, int rate);
	int (*set_channels)(struct control_runtime *rt, int n_analog_out,
		int n_analog_in, bool spdif_out, bool spdif_in);

	struct usbpal_chip *chip;

	struct snd_kcontrol *element[CONTROL_MAX_ELEMENTS];
	bool opt_coax_switch;
	bool line_phono_switch;
	bool digital_thru_switch;
	bool usb_streaming;
	u8 output_vol[6];
	u8 ovol_updated;
	u8 output_mute;
	s8 input_vol[2];
	u8 ivol_updated;
};

int __devinit usbpal_control_init(struct usbpal_chip *chip);
void usbpal_control_abort(struct usbpal_chip *chip);
void usbpal_control_destroy(struct usbpal_chip *chip);
#endif /* USBPAL_CONTROL_H */

