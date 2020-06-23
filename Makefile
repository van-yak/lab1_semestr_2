SRC = Players.o List.o main.o
TARGET = lab3
all: $(TARGET)

main.o: main.cpp
	g++ -Wall -g -c -o main.o main.cpp

List.o: List.cpp
	g++ -Wall -g -c -o List.o List.cpp

Players.o: Players.cpp
	g++ -Wall -g -c -o Players.o Players.cpp

$(TARGET): $(SRC)
	g++ -o $(TARGET) $(SRC)

clean:
	rm -rf $(SRC)
