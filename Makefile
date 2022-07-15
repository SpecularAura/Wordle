CC = g++
CC_FLAGS = -g -std=c++17

#IDIRGLFW = dependencies/GLFW/include
#IDIRGlad = ../../dependencies/Glad/include
IDIR = dependencies/include 

INCLUDE = -I$(IDIR) #-I$(IDIRGLFW) -I$(IDIRGlad) 

#LIBDIR = ../../dependencies/GLFW/lib-mingw-w64
#LIBS = -L$(LIBDIR)

#LIBLINK = -lopengl32 $(LIBDIR)/libglfw3.a -lgdi32 #-mwindows
#_DEPS = testinclude.h
_DEPS = $(wildcard $(IDIR)/*.h)
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
DEPS = $(_DEPS)

SRCDIR = dependencies/src
ODIR = debugbuild/dependencies
#_CPP = testinclude.cpp
_CPP = $(wildcard $(SRCDIR)/*.cpp)
_C   = $(wildcard $(SRCDIR)/*.c)
#CPP = $(patsubst %,$(SRCDIR)/%,$(_CPP))
CPP = $(_CPP) $(_C)

#_OBJ = $(patsubst %.cpp,%.o,$(CPP))
_CPPOBJ = $(patsubst $(SRCDIR)/%.cpp,$(ODIR)/%.o,$(_CPP))
_COBJ   = $(patsubst $(SRCDIR)/%.c,$(ODIR)/%.o,$(_C))
OBJ = $(_CPPOBJ) $(_COBJ) #${ODIR}/glad.o
EXECUTABLE = main
EXECUTABLE_DIR = debugbuild/$(EXECUTABLE)
MAIN = $(patsubst $(EXECUTABLE),$(EXECUTABLE).cpp,$(EXECUTABLE))

$(EXECUTABLE):$(OBJ)
	$(CC) $(CC_FLAGS) src/$(MAIN) $(INCLUDE) $(OBJ) -o $(EXECUTABLE_DIR)

$(ODIR)/%.o:$(SRCDIR)/%.c
	$(CC) $(CC_FLAGS) -c $< $(INCLUDE)  -o $@

$(ODIR)/%.o:$(SRCDIR)/%.cpp
	$(CC) $(CC_FLAGS) -c $< $(INCLUDE)  -o $@
