CC = g++

CFLAGS = -std=c++17

CINCLUDE = -I/home/shasankbt/simplecpp/include

CGRAPHICS = -L/home/shasankbt/simplecpp/lib -lsprite -lX11

BLOCKS = blocks/basic_blocks.o blocks/square.o blocks/lin.o blocks/t_block.o blocks/z_blocks.o blocks/l_blocks.o

all: Tetris

Tetris : game.o gameFunctions.o $(BLOCKS)
	$(CC) $(CFLAGS) game.o gameFunctions.o $(BLOCKS) $(CINCLUDE) $(CGRAPHICS) -o Tetris 2> /dev/null


game.o : game.cpp gameFunctions.h blocks/blocks.h
	$(CC) $(CFLAGS) -c $< $(CINCLUDE) $(CGRAPHICS) 2> /dev/null

gameFunctions.o : gameFunctions.cpp blocks/blocks.h
	$(CC) $(CFLAGS) -c $< $(CINCLUDE) $(CGRAPHICS)

blocks/%.o : blocks/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(CINCLUDE) $(CGRAPHICS)

clean:
	rm -f *.o && rm -f blocks/*.o