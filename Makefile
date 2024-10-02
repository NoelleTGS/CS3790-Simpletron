TARGET = main

all: bin/$(TARGET)

bin/$(TARGET) : $(TARGET).o functions.o
	mkdir -p bin
	g++ -o bin/$(TARGET) $(TARGET).o functions.o

$(TARGET).o : $(TARGET).cpp common.hpp
	g++ -c $(TARGET).cpp

functions.o : functions.cpp common.hpp
	g++ -c functions.cpp

.PHONY: clean
clean :
	rm -f *.o