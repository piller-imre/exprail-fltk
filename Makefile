CC = g++

CFLAGS = -Iinclude -I../src -g -O2 -Wall
LDFLAGS = -lfltk -lfltk_images

SOURCES = \
	src/handlers.cpp \
	src/Editor.cpp \
    src/main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

EXECUTABLE = editor

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)