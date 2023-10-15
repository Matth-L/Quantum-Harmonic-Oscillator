MAKE = make

.PHONY: code doc clean tests style 

all: code doc tests

code:
	$(MAKE) -C code

doc:
	$(MAKE) -C doc

tests: 
	$(MAKE) -C tests

style : 
	astyle -A1 --recursive *.cxx *.h 
	find . -type f -name '*.orig' -delete

clean: 
	$(MAKE) -C code clean
	$(MAKE) -C tests clean
	$(MAKE) -C doc clean
