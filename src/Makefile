CC = clang
SOURCES = dot_click.m main.c
FRAMEWORKS:= -framework Cocoa -framework QuartzCore -framework Metal -framework MetalKit -framework AudioToolbox
LIBRARIES:= -lobjc
CFLAGS=-I../sokol -I../sokol/util -Wall -Werror -g -v $(SOURCES)
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=-o ../dot_click

all: dot_click.glsl.h crt.glsl.h $(SOURCES) ../dot_click

$(OUT): $(OBJECTS)
	$(CC) -o $(OBJECTS) $@ $(CFLAGS) $(LDFLAGS) $(OUT)

dot_click.glsl.h: dot_click.glsl
	../sokol-shdc --input dot_click.glsl --output dot_click.glsl.h --slang metal_macos

.m.o: 
	$(CC) -c -Wall $< -o $@

clean: 
	rm -rf ../dot_click.dSym ../dot_click dot_click.glsl.h crt.glsl.h

run: dot_click.glsl.h $(SOURCES) ../dot_click
	cd .. && ./dot_click
