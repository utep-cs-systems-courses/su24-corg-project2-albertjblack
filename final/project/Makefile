CFLAGS		= -mmcu=msp430g2553 -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include

CC		= msp430-elf-gcc
AS		= msp430-elf-as

all: project.elf

project.elf: main.c stateMachines.o led.o wdInterruptHandler.o p2_interrupt_handler.o switches.o buzzer.o switch_state_1_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: project.elf
	msp430loader.sh project.elf

clean:
	rm -f *.o *.elf

led.o: led.c led.h

stateMachines.o: stateMachines.c stateMachines.h

buzzer.o: buzzer.c buzzer.h

switches.o: switches.c switches.h

wdInterruptHandler.o: wdInterruptHandler.c

p2_interrupt_handler.o: p2_interrupt_handler.c

switch_state_1_handler.o: switch_state_1_handler.s