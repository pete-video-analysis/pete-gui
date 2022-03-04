# Detect platform
ifeq ($(OS),Windows_NT)
	object     := obj
	static     := lib
	executable := .exe
else
	object     := o
	static     := a
	executable := 
endif

# Use only gcc
CC := gcc
CFLAGS :=
LIBS := glfw GLX_mesa

source_files := $(wildcard src/*.c)
obj_files := $(source_files:src/%.c=build/%.$(object))

.PHONY: build/pete$(executable)

build/pete$(executable): $(obj_files) core/build/libpete.$(static)
	$(CC) -o $@ $(obj_files) core/build/libpete.$(static) $(LIBS:%=-l%)

build/%.$(object): src/%.c
	$(CC) -Iinclude -Icore/include $(CFLAGS) -c $< -o $@

core/build/libpete.$(static):
	cd core; make static

clean:
	rm $(wildcard build/*)