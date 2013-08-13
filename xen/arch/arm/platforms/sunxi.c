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

static const struct dt_device_match sunxi_blacklist_dev[] __initconst =
{
    /*
     * These UARTs share a page with the Xen console UART, so we don't
     * want to map them through.
     */
    DT_MATCH_PATH("/soc@01c00000/serial@01c28000"),
    DT_MATCH_PATH("/soc@01c00000/serial@01c28400"),
    DT_MATCH_PATH("/soc@01c00000/serial@01c28800"),
    DT_MATCH_PATH("/soc@01c00000/serial@01c28c00"),
    { /* sentinel */ },
};

PLATFORM_START(sunxi, "Allwinner A20")
    .compatible = sunxi_dt_compat,
    .blacklist_dev = sunxi_blacklist_dev,
PLATFORM_END

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * indent-tabs-mode: nil
 * End:
 */
