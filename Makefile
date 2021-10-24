CC = g++
CFLAGS = -g -std=c++11
TARGET = scanner
OBJS = main.o scanner.o testScanner.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)

main.o: main.cpp 
	$(CC) $(CFLAGS) -c main.cpp

scanner.o: scanner.cpp 
	$(CC) $(CFLAGS) -c scanner.cpp

testScanner.o: testscanner.cpp 
	$(CC) $(CFLAGS) -c testscanner.cpp

clean: 
	/bin/rm -f *.o $(TARGET)


