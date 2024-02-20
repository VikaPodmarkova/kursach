TARGET =  Server
SOURCES = $(wildcard *.cpp)
STD_SOURCES = $(filter-out test.cpp, $(SOURCES))
STD_OBJECTS = $(STD_SOURCES:%.cpp=%.o)
TEST_SOURCES = $(filter-out main.cpp, $(SOURCES))
TEST_OBJECTS = $(TEST_SOURCES:%.cpp=%.o)

CC = g++
CCFlags = -Wall
LIBS = -lcrypto++ -l boost_program_options
.PHONY: all test clean start

all:$(TARGET)
$(TARGET):$(STD_OBJECTS)
	$(CC) $^ $(LIBS) -o $@

$(TARGET)_test:$(TEST_OBJECTS)
	$(CC) $^ $(LIBS) -lUnitTest++ -o $@

test:$(TARGET)_test
	./$^


%.o:%.cpp
	$(CC) -c $(CCFlags) -o $@ $<

clean:
	rm -f *.o $(TARGET) $(TARGET)_test

start:
	sudo apt install libboost-program-options-dev
	make
