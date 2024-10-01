TARGET = main

bin/$(TARGET) : $(TARGET).o functions.o
	g++ -o bin/$(TARGET) $(TARGET).o functions.o

$(TARGET).o : $(TARGET).cpp common.hpp
	g++ -c $(TARGET).cpp

functions.o : functions.cpp common.hpp
	g++ -c functions.cpp

.PHONY: clean
clean :
	rm -f *.o