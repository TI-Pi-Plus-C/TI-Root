# ----------------------------
# Makefile Options
# ----------------------------

NAME = ROOTS
ICON = icon.png
DESCRIPTION = "v1.2.0 (C) TI-PI-Plus-C 2026"
COMPRESSED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
