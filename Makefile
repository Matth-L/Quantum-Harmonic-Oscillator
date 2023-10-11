MAKE = make

.PHONY: code doc clean

all: code doc

code:
	$(MAKE) -C code

doc:
	$(MAKE) -C doc

clean: 
	$(MAKE) -C code clean
	$(MAKE) -C doc clean