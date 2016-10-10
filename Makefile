OBJS = src/main.cpp \
	   src/Engine.cpp \
	   src/EventManager.cpp \
       src/Window.cpp \

OBJ_NAME = main

CC = g++
CC_FLAGS = -std=c++11 -Wall
LD_FLAGS = -lSDL2

all: $(OBJS)
	$(CC) $(OBJS) $(CC_FLAGS) $(LD_FLAGS) -o $(OBJ_NAME)

run: $(OBJS) $(OBJ_NAME)
	./main
