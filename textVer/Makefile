CPPFLAGS=-Wall -Wextra -g3 -ggdb
LINKFLAGS=
EXENAME=15puzzle
.PHONY: all
.PHONY: clean

all: $(EXENAME)
	@echo "Done"

$(EXENAME): $(EXENAME).cpp board.cpp
	g++ $(CPPFLAGS) $(LINKFLAGS) $< -o $(EXENAME) 

clean:
	rm $(EXENAME)
	
