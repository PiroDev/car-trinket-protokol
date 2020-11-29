CXX := g++
OBJDIR := out
BINDIR := bin
SRCDIR := src
INCDIR := include
LFLAGS := -lcryptopp
CXX_FLAGS := -I${INCDIR} -std=c++17 -Wall -Werror -pedantic -Wextra
OBJECTS := $(OBJDIR)/car.o $(OBJDIR)/crypto_functions.o $(OBJDIR)/trinket.o

ifeq ($(mode), debug)
	CXX_FLAGS += -g3
	CXX_FLAGS += -ggdb
endif

ifeq ($(mode), release)
	CXX_FLAGS += -DNDEBUG -g0
endif

$(BINDIR)/trinket.exe : $(OBJDIR)/main.o $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CXX) $(CXX_FLAGS) $^ -o $@ $(LFLAGS) 

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCDIR)/*.h
	mkdir -p $(OBJDIR)
	$(CXX) $(CXX_FLAGS) -c $< -o $@

.PHONY : clean
clean :
	rm -rf bin out
