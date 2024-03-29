CPPFLAGS=-Wall -Wextra -g3 -ggdb
LINKFLAGS=
EXENAME=15puzzle
fltkflags=`fltk-config --cxxflags --ldflags`
.PHONY: all
.PHONY: clean

all: $(EXENAME)
	@echo "Done"

$(EXENAME): $(EXENAME).cpp board.cpp
	g++ $(CPPFLAGS) $(LINKFLAGS) $< -o $(EXENAME) $(fltkflags)

clean:
	rm $(EXENAME)
	
