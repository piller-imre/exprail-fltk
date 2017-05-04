CC = g++

CFLAGS = -Iinclude -I../src -g -O2 -std=c++11 -Wall -Wextra -Wpedantic -Wno-unused-parameter
LDFLAGS = -lfltk -lfltk_images

SOURCES = \
	src/handlers.cpp \
	src/Canvas.cpp \
	src/Curve.cpp \
	src/Drawer.cpp \
	src/Edge.cpp \
	src/Point.cpp \
	src/Editor.cpp \
	src/Expression.cpp \
	src/Graph.cpp \
	src/Node.cpp \
	src/Tokenizer.cpp \
	src/Parser.cpp \
	src/operations/Operation.cpp \
	src/operations/OperationFactory.cpp \
	src/operations/CreateNodeOperation.cpp \
	src/operations/SelectNodeOperation.cpp \
	src/operations/SelectEdgeOperation.cpp \
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
