# Standard programs to be used: compiler and its options
CC = g++
CFLAGS = -ggdb -Wall
LIBS = `pkg-config opencv4 --cflags --libs`

# File directory
DIR = ./project_cpp/
SRCDIR = $(DIR)src/
OBJDIR = $(DIR)build/
EXEDIR = $(DIR)bin/

# Binary files to generate: executables
BINDIR_SERVER= $(EXEDIR)server
BINDIR_CLIENT= $(EXEDIR)client

# Object files
OBJ_SERVER = $(OBJDIR)ServerSocket.o $(OBJDIR)Socket.o $(OBJDIR)simple_server_main.o $(OBJDIR)Point.o $(OBJDIR)Draw.o $(OBJDIR)Utils.o
OBJ_CLIENT = $(OBJDIR)ClientSocket.o $(OBJDIR)Socket.o $(OBJDIR)simple_client_main.o $(OBJDIR)Point.o $(OBJDIR)Draw.o $(OBJDIR)Utils.o

# "all" is the default target. Its dependencies are checked when you run the "make" command in the current directory. There may be more than one dependency
all : $(EXEDIR)server $(EXEDIR)client

#### Secondary rules to compile each of the dependencies

$(EXEDIR)server : $(OBJ_SERVER)
	$(CC) $(OBJ_SERVER) $(CFLAGS) -o $(BINDIR_SERVER) $(LIBS)

$(EXEDIR)client : $(OBJ_CLIENT)
	$(CC) $(OBJ_CLIENT) $(CFLAGS) -o $(BINDIR_CLIENT) $(LIBS)

$(OBJDIR)Socket.o : $(SRCDIR)Socket.cpp 
	$(CC) -c $(SRCDIR)Socket.cpp -o $(OBJDIR)Socket.o

$(OBJDIR)Point.o : $(SRCDIR)Point.cpp 
	$(CC) -c $(SRCDIR)Point.cpp -o $(OBJDIR)Point.o

$(OBJDIR)Draw.o : $(SRCDIR)Draw.cpp 
	$(CC) -c $(SRCDIR)Draw.cpp -o $(OBJDIR)Draw.o $(LIBS)

$(OBJDIR)Utils.o : $(SRCDIR)Utils.cpp 
	$(CC) -c $(SRCDIR)Utils.cpp -o $(OBJDIR)Utils.o 

#### Server

$(OBJDIR)ServerSocket.o : $(SRCDIR)ServerSocket.cpp
	$(CC) -c $(SRCDIR)ServerSocket.cpp -o $(OBJDIR)ServerSocket.o

$(OBJDIR)simple_server_main.o : $(SRCDIR)simple_server_main.cpp 
	$(CC) -c $(SRCDIR)simple_server_main.cpp -o $(OBJDIR)simple_server_main.o $(LIBS)

#### Client

$(OBJDIR)ClientSocket.o : $(SRCDIR)ClientSocket.cpp
	$(CC) -c $(SRCDIR)ClientSocket.cpp -o $(OBJDIR)ClientSocket.o

$(OBJDIR)simple_client_main.o : $(SRCDIR)simple_client_main.cpp 
	$(CC) -c $(SRCDIR)simple_client_main.cpp -o $(OBJDIR)simple_client_main.o $(LIBS)


# "clean" is a false target. It is used to delete the .o (object) and binary files
clean :
	rm $(OBJDIR)*.o $(BINDIR_SERVER) $(BINDIR_CLIENT)