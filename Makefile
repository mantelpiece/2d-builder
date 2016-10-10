CC = g++
CXX_FLAGS = -std=c++11 -Wall
LD_FLAGS = 
LIBS= -lSDL2

ENGINE_SRCS = src/engine/Engine.cpp \
			  src/engine/EventManager.cpp \
			  src/engine/Window.cpp
ENGINE_OBJS = $(ENGINE_SRCS:.cpp=.o)


# Main executable
MAIN = main
MAIN_SRC = src/main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

ALL_OBJS = $(MAIN_OBJ) $(ENGINE_OBJS)

.PHONY: depend clean

default: $(MAIN)
	@echo Built main executable

run: $(MAIN)
	./main

$(MAIN): $(ENGINE_OBJS) $(MAIN_OBJ)
	$(CC) $(CXX_FLAGS) -o $(MAIN) $(ALL_OBJS) $(LD_FLAGS) $(LIBS)

.cpp.o:
	$(CC) $(CXX_FLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
