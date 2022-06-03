CC = gcc
SRCS = menu.c main.c menu.h StringPro.c StringPro.h StringProInfo.c StringProInfo.h
CFLAGS = -c -Wall -std=c99
LDFLAGS = -std=c99
OBJS = $(SRCS: .c = .o)
EXE = main

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJS) $(EXE)