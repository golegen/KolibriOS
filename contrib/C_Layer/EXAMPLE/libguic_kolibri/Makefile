NAME=boardmsg
CC = kos32-gcc
LD = kos32-ld

SDK_DIR:= $(abspath ../../../sdk)
CLAYER:= $(abspath ../../)

LDFLAGS = -static -S -nostdlib -T $(SDK_DIR)/sources/newlib/app.lds \
          --image-base 0 -lgcc /home/autobuild/tools/win32/lib/libdll.a\
          /home/autobuild/tools/win32/lib/libc.dll.a\
          /home/autobuild/tools/win32/lib/libapp.a

CFLAGS = -g -U_Win32 -U_WIN32 -U__MINGW32__

INCLUDES= -I. -I$(SDK_DIR)/sources/newlib/libc/include -I$(CLAYER)/INCLUDE
LIBPATH:= -L $(SDK_DIR)/lib -L /home/autobuild/tools/win32/mingw32/lib

OBJPATH = $(CLAYER)/OBJ

SOURCES =    boardmsg.c

OBJECTS =  $(patsubst %.c, %.o, $(SOURCES))

all:$(NAME)

$(NAME): $(OBJECTS) Makefile
	$(LD) $(LIBPATH) -o $@ $(OBJECTS) $(OBJPATH)/loadboxlib.obj $(LDFLAGS)
	#-ldll -lc.dll -lapp -Map $(NAME).map
	kos32-objcopy $@ -O binary

%.o : %.c Makefile
	$(CC) -c $(INCLUDES) $(CFLAGS) -o $@ $<

clean:
	-rm -f *.o
