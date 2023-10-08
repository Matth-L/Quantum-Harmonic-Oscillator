CC = g++ -std=c++11
CXX = cxxtestgen --error-printer
HEADERSDIR = ../code/headers/
OBJDIR = obj/
BINDIR = bin/
HEADERS = $(HEADERSDIR)hermite.h 
SRCDIR = ../code/src/
HEADERSTEST = hermiteTest.h
# le fichier intermédiaire généré par cxxtestgen
CXXTEST = hermiteTest.cpp
OBJS= $(OBJDIR)hermite.o 
OBJSTEST= $(OBJDIR)hermiteTest.o
TARGET = $(BINDIR)test_Hermite

$(TARGET): $(OBJSTEST) $(OBJS)
	$(CC) -o $@ $^

#création du .o à partir des .h pour les HEADERS
$(OBJDIR)%.o: $(SRCDIR)%.cxx $(HEADERSDIR)%.h
	$(CC) -c $< -o $@

# création du fichier cpp à partir du .h
$(CXXTEST): $(HEADERSTEST)
	$(CXX) -o $@ $< 

#création du .o pour les cpp générés par cxxtestgen
$(OBJDIR)%.o: %.cpp
	$(CC) -c $< -o $@ -I $(HEADERSDIR)

.PHONY: all clean 

clean : 
	rm -rf $(CXXTEST)
	rm -rf $(OBJDIR)*.o
	rm -rf $(TARGET)
	
