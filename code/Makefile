CC = g++
CXXFLAGS = -Wextra -std=c++11
LDFLAGS =
LIBS = -larmadillo
TARGET = ../bin/out
OBJDIR = obj/
SRCDIR = src/
HEADERS = headers/hermite.h
OBJS = $(OBJDIR)hermite.o $(OBJDIR)main.o

.Phony: clear all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.cxx $(HEADERS)
	$(CC) $(CXXFLAGS) $< -c -o $@

clear:
	rm -f $(TARGET)
	rm -f $(OBJS)