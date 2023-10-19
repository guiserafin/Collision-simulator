CFLAGS=-I/usr/include/SDL2 -D_REENTRANT
LIBS=-pthread -lSDL2

all:
	$(CXX) -c window.cpp $(CFLAGS) 	
	$(CXX) -c sdl.cpp $(CFLAGS) 	
	$(CXX) -c poligono.cpp $(CFLAGS)
	# Compile and link the source and object files into a final executable binary
	$(CXX) main.cpp window.o sdl.o poligono.o $(CFLAGS) $(LIBS)

clean:
	rm *.o
	rm a.out
