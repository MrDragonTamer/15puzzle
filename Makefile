CPPFLAGS=-Wall -Wextra
LINKFLAGS=
EXENAME=15puzzle
.PHONY: all

all: $(EXENAME)
	@echo "Done"

$(EXENAME): $(EXENAME).cpp
	g++ $(CPPFLAGS) $(LINKFLAGS) $< -o $(EXENAME) 


	
