#GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags)


all: nexutil

nexutil: nexutil.c ./libnexio/libnexio.a FORCE
	gcc -static -o nexutil nexutil.c bcmwifi_channels.c b64-encode.c b64-decode.c -DBUILD_ON_RPI -DVERSION=\"16ton\" -DUSE_NETLINK -I. -I./pinclude -I./libnexio -L./libnexio/ -lnexio -I./libargp

./libnexio/libnexio.a: FORCE
	cd libnexio && make


install: nexutil
	cp $< /usr/local/bin/

clean:
	rm -Rf libs
	rm -Rf local
	rm -Rf nexutil

FORCE:
	
