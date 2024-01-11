1:
	gcc	src/main1.c \
		src/screen.c \
		src/map.c \
		src/mech.c \
		src/colors.c \
		src/ellipse.c \
		src/debug.c	-I. -lncurses -ospheres
