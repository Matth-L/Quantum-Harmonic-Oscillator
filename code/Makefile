CC = g++
CXXFLAGS = -Wextra -std=c++11
LDFLAGS =
LIBS = -larmadillo
TARGET = ../bin/out
OBJDIR = obj/
OBJS = $(OBJDIR)main.o

.Phony: clear all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

$(OBJDIR)%.o: src/%.cxx
	$(CC) $(CXXFLAGS) $< -c -o $@

clear:
	rm -f $(TARGET)
	rm -f $(OBJS)