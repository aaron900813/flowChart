FILES = \
    main.cpp \
	
OBJS = $(patsubst %.cpp, %.o, $(FILES))

DIR = $(foreach n,$(dir $(FILES)),.obj/$(n))

INCLUDES +=$(foreach n,$(dir $(FILES)),-I $(n))


EXENAME = cPCI5125Test
BIN = ./$(EXENAME)

CPPFLAGS= -g -Wall -O2
CPPFLAGS  +=  "-msse" -march=core2  -fomit-frame-pointer 
CPPFLAGS  +=  -Wall -Wundef -Wpointer-arith -fPIC

LIBS = -lcPCI5125


LIBPATH = \
-L ../Lib \

.PHONY:all
all : DIRS $(BIN)
$(BIN) :  $(OBJS)
	@echo "Linking" $(BIN)
	$(CXX) -o $@ $^ $(LIBPATH) $(LIBS)
	cp $(EXENAME) ../Lib -rf

.cpp.o :
	@echo "Compiling $<"
	$(CXX) $(CPPFLAGS) $(INCLUDES)  $(INCLUDE) -c $< -o $@ -I ../Include

DIRS :
	@mkdir -p $(DIR)

.PHONY:clean
clean:
	@echo "rm "$(OBJS)
	rm -f *.o cPCI5125Test