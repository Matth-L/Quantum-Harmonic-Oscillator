CC = g++
TARGET = out

.Phony: clear

all: $(TARGET)

$(TARGET): main.o
	$(CC) $^ -o $@

main.o: src/main.cxx
	$(CC) $< -c $@

clear:
	rm -f $(TARGET)
	rm -f main.o