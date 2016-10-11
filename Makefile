CC = g++
CXX_FLAGS = -std=c++11 -Wall
LD_FLAGS = 
LIBS= -lSDL2

ENGINE_SRCS = src/engine/Engine.cpp \
			  src/engine/EventManager.cpp \
			  src/engine/Window.cpp \
			  src/engine/RenderSystem.cpp

ENGINE_OBJS = $(ENGINE_SRCS:.cpp=.o)


# Main executable
MAIN = main
MAIN_SRC = src/main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

ALL_OBJS_T = $(ENGINE_OBJS) $(MAIN_OBJ)
ALL_OBJS = $(subst src, obj, $(ALL_OBJS_T))

DIRS = obj obj/engine

.PHONY: depend clean clobber

default: $(MAIN)
	@echo Built main executable

run: $(MAIN)
	./main

$(MAIN):  $(DIRS) $(ALL_OBJS) # $(ENGINE_OBJS) $(MAIN_OBJ)
	$(CC) $(CXX_FLAGS) -o $(MAIN) $(ALL_OBJS) $(LD_FLAGS) $(LIBS)

obj/%.o: src/%.cpp
	$(CC) $(CXX_FLAGS) -c $< -o $(@:src=obj)

src/%.cpp: src/%.h

$(DIRS):
	-mkdir $(DIRS)

clean:
	-$(RM) $(ALL_OBJS)

clobber: clean
	-$(RM) $(MAIN)
