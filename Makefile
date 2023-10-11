MAKE = make

.PHONY: code doc clean

all: code doc

code:
	$(MAKE) -C code

doc:
	$(MAKE) -C doc

style : 
	astyle -A1 --recursive *.cxx *.h
	find . -type f -name '*.orig' -delete

clean: 
	$(MAKE) -C code clean
	$(MAKE) -C doc clean