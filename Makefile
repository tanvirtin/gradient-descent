OBJ = main.o GradientDescent.o

gd: $(OBJ)
	g++ -o gd $(OBJ)

main.o: main.cc GradientDescent.h
	g++ -c main.cc

GradientDescent.o: GradientDescent.h GradientDescent.cc
	g++ -c GradientDescent.cc

clean:
	rm -f *.o gd