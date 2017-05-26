CC = g++

CFLAGS = -Iinclude -I../src -g -O2 -std=c++11 -Wall -Wextra -Wpedantic -Wno-unused-parameter
LDFLAGS = -lfltk -lfltk_images
TEST_LDFLAGS = -lgtest -lgtest_main -lpthread

SOURCES = \
	src/handlers.cpp \
	src/Canvas.cpp \
	src/Curve.cpp \
	src/Drawer.cpp \
	src/Edge.cpp \
	src/Point.cpp \
	src/Editor.cpp \
	src/Expression.cpp \
	src/Indicator.cpp \
	src/Grammar.cpp \
	src/Graph.cpp \
	src/Node.cpp \
	src/Token.cpp \
	src/Tokenizer.cpp \
	src/Parser.cpp \
	src/Validator.cpp \
	src/operations/Operation.cpp \
	src/operations/OperationFactory.cpp \
	src/operations/CreateNodeOperation.cpp \
	src/operations/SelectNodeOperation.cpp \
	src/operations/SelectEdgeOperation.cpp \
    src/main.cpp

TEST_SOURCES = \
	src/Point.cpp \
	src/Node.cpp \
	src/Edge.cpp \
	src/Graph.cpp \
	src/Expression.cpp \
	src/Grammar.cpp \
	src/Token.cpp \
	src/Tokenizer.cpp \
	src/Parser.cpp \
	test/Grammar_test.cpp \
	test/Tokenizer_test.cpp \
	test/Parser_test.cpp \
	test/Serialization_test.cpp

OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

EXECUTABLE = editor
TEST_EXECUTABLE = test_editor

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE) : $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJECTS)

test: $(TEST_SOURCES) $(TEST_EXECUTABLE)

$(TEST_EXECUTABLE) : $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(TEST_LDFLAGS) -o $@

clean_test:
	rm $(TEST_OBJECTS)

