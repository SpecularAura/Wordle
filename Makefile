CC = gcc
CC_FLAGS = -g

#IDIRGLFW = dependencies/GLFW/include
#IDIRGlad = ../../dependencies/Glad/include
IDIR = dependencies/include 

INCLUDE = -I$(IDIR) #-I$(IDIRGLFW) -I$(IDIRGlad) 

LIBDIR = ../../dependencies/GLFW/lib-mingw-w64
LIBS = -L$(LIBDIR)

#LIBLINK = -lopengl32 $(LIBDIR)/libglfw3.a -lgdi32 #-mwindows
#_DEPS = testinclude.h
_DEPS = $(wildcard $(IDIR)/*.h)
#DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))
DEPS = $(_DEPS)

SRCDIR = dependencies/src
ODIR = build/bin/dependencies
#_CPP = testinclude.cpp
_CPP = $(wildcard $(SRCDIR)/*.c)
#CPP = $(patsubst %,$(SRCDIR)/%,$(_CPP))
CPP = $(_CPP)

#_OBJ = $(patsubst %.cpp,%.o,$(CPP))
_OBJ = $(patsubst $(SRCDIR)/%.c,$(ODIR)/%.o,$(CPP))
OBJ = $(_OBJ) #${ODIR}/glad.o
EXECUTABLE = main
EXECUTABLE_DIR = build/bin/$(EXECUTABLE)
MAIN = $(patsubst $(EXECUTABLE),$(EXECUTABLE).c,$(EXECUTABLE))

$(EXECUTABLE):$(OBJ)
	$(CC) $(CC_FLAGS) src/$(MAIN) $(INCLUDE) $(LIBS) $(OBJ) -o $(EXECUTABLE_DIR)

$(ODIR)/%.o:$(SRCDIR)/%.cpp $(DEPS) 
	$(CC) $(CC_FLAGS) -c $< $(INCLUDE)  -o $@
