/*
 * xen/arch/arm/platforms/sunxi.c
 *
 * SUNXI (AllWinner A20/A31) specific settings
 *
 * Copyright (c) 2013 Citrix Systems.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <asm/p2m.h>
#include <xen/config.h>
#include <asm/platform.h>
#include <xen/mm.h>
#include <xen/device_tree.h>

static const char const *sunxi_dt_compat[] __initdata =
{
    "allwinner,sun7i-a20",
    NULL
};

PLATFORM_START(sunxi, "Allwinner A20")
    .compatible = sunxi_dt_compat,
PLATFORM_END

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
