/*
 * drivers/video/tegra/dc/edid_quirks.c
 *
 * Copyright (c) 2015, NVIDIA CORPORATION, All rights reserved.
 * Author: Anshuman Nath Kar <anshumank@nvidia.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "edid.h"

static const struct hdmi_blacklist {
	char manufacturer[4];
	u32 model;
	u32 quirks;
} edid_blacklist[] = {
	/* Samsung UN55HU6840 */
	{ "SAM", 2994, TEGRA_EDID_QUIRK_BUMPUP_594PCLK },
};

u32 tegra_edid_lookup_quirks(const char *manufacturer, u32 model)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(edid_blacklist); i++)
		if (!strcmp(edid_blacklist[i].manufacturer, manufacturer) &&
			edid_blacklist[i].model == model)
			return edid_blacklist[i].quirks;

	return TEGRA_EDID_QUIRK_NONE;
}
