CC = g++
CXXFLAGS = -Wextra -std=c++11
LDFLAGS =
LIBS = -larmadillo
TARGET = ../bin/out
BINDIR = ../bin/
OBJDIR = obj/
SRCDIR = src/
HEADERS = headers/hermite.h headers/solutions.h
OBJS = $(OBJDIR)hermite.o $(OBJDIR)solutions.o $(OBJDIR)main.o

.Phony: clear all

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.cxx $(HEADERS)
	$(CC) $(CXXFLAGS) $< -c -o $@

clear:
	rm -f $(BINDIR)*
	rm -f $(OBJS)