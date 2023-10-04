tests: 
	echo 1
	$(CC) $(CXXFLAGS) -c $(SRCDIR)%.cxx -o $(OBJDIR)%.o
	$(CXXCC) -o  $(NAMETESTS).cpp $(TESTS)
	$(CC) $(CXXFLAGS) $(NAMETESTS).o $(OBJDIR)%.o -o $(NAMETESTS)
	$(CC) $(NAMETESTS).o $(OBJDIR)%.o -o $(NAMETESTS)