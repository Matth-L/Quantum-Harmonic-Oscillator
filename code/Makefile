CC = g++
CXXFLAGS = -Wextra -std=c++11
LDFLAGS =
LIBS = -larmadillo
TARGET = ../bin/out
OBJDIR = obj/
SRCDIR = src/
HEADERS = headers/hermite.h headers/solutions.h
OBJS = $(OBJDIR)hermite.o $(OBJDIR)solutions.o $(OBJDIR)main.o


TESTDIR = tests/
NAMETESTS = hermiteTest
TESTS = $(TESTDIR)hermiteTest.h
CXXCC = cxxtestgen --error-printer

.Phony: clear all tests

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

$(OBJDIR)%.o: $(SRCDIR)%.cxx $(HEADERS)
	$(CC) $(CXXFLAGS) $< -c -o $@

clear:
	rm -f $(TARGET)
	rm -f $(OBJS)