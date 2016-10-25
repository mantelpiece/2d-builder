CC = g++
CXX_FLAGS = -std=c++11 -Wall
LD_FLAGS = 
LIBS= -lSDL2 -lSDL2_image
INCLUDES = -Isrc/ -Isrc/engine -Isrc/engine/systems

ENGINE_SRCS = src/engine/Engine.cpp \
			  src/engine/EventManager.cpp \
			  src/engine/RendererManager.cpp \
			  src/engine/Window.cpp
ENGINE_OBJS = $(ENGINE_SRCS:.cpp=.o)

ECS_SRCS = src/engine/systems/EntityManager.cpp
ECS_OBJS = $(ECS_SRCS:.cpp=.o)

# Main executable
MAIN = main
MAIN_SRC = src/main.cpp
MAIN_OBJ = $(MAIN_SRC:.cpp=.o)

ALL_OBJS_T = $(ECS_OBJS) $(ENGINE_OBJS) $(MAIN_OBJ)
ALL_OBJS = $(subst src, obj, $(ALL_OBJS_T))

DIRS = obj obj/engine obj/engine/systems

.PHONY: depend clean clobber

default: $(MAIN)
	@echo Built main executable

run: $(MAIN)
	./main

$(MAIN):  $(DIRS) $(ALL_OBJS)
	$(CC) $(CXX_FLAGS) -o $(MAIN) $(ALL_OBJS) $(LD_FLAGS) $(LIBS)

obj/%.o: src/%.cpp src/%.h
	$(CC) $(CXX_FLAGS) $(INCLUDES) -c $< -o $(@)

obj/%.o: src/%.cpp
	$(CC) $(CXX_FLAGS) $(INCLUDES) -c $< -o $(@)

$(DIRS):
	-mkdir $(DIRS)

clean:
	-$(RM) $(ALL_OBJS)

clobber: clean
	-$(RM) $(MAIN)
