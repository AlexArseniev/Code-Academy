cc = gcc
source = main.c functions.c
compileFlag = -c
objects = main.o functions.o
exe = game.exe
linkFlag = -o

all: $(exe) 

$(exe) : $(objects)
	$(cc) $(objects) $(linkFlag) $(exe)

$(objects) : $(source)
	$(cc) $(compileFlag) $(source) 

clean: 
	del $(objects)
	del $(exe)
