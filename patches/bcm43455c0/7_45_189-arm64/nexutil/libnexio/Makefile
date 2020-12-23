#GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags)

all: libs/armeabi/libnexio.a

libs/armeabi/libnexio.a: libnexio.c
	gcc -c libnexio.c -o libnexio.o -DBUILD_ON_RPI -DVERSION=\"$GIT_VERSION\" -I../../patches/include
	ar rcs libnexio.a libnexio.o

clean:
	rm -Rf libs
	rm -Rf local
	rm libnexio.a
	rm libnexio.o
