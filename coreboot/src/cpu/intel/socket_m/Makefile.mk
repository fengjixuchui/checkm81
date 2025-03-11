## SPDX-License-Identifier: GPL-2.0-only

subdirs-y += ../model_6ex
subdirs-y += ../model_6fx
subdirs-y += ../../x86/lapic
subdirs-y += ../microcode
subdirs-y += ../speedstep

bootblock-y += ../car/core2/cache_as_ram.S
bootblock-y += ../car/bootblock.c
postcar-y += ../car/p4-netburst/exit_car.S

romstage-y += ../car/romstage.c
