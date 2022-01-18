OBJS	= Amazones.o Arme.o Armure.o Guerriers.o Jeu.o Sorcieres.o Chateau.o Moines.o Objet.o Personnage.o main.o
SOURCE	= Amazones.cpp Arme.cpp Armure.cpp Guerriers.cpp Jeu.cpp Sorcieres.cpp Chateau.cpp Moines.cpp Objet.cpp Personnage.cpp main.cpp
HEADER	= Chateau.hpp Moines.hpp Objet.hpp Personnage.hpp Amazones.hpp Arme.hpp Armure.h Guerriers.hpp Jeu.hpp Sorcieres.hpp
OUT	= main.out
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Amazones.o: Amazones.cpp
	$(CC) $(FLAGS) Amazones.cpp

Arme.o: Arme.cpp
	$(CC) $(FLAGS) Arme.cpp

Armure.o: Armure.cpp
	$(CC) $(FLAGS) Armure.cpp

Guerriers.o: Guerriers.cpp
	$(CC) $(FLAGS) Guerriers.cpp

Jeu.o: Jeu.cpp
	$(CC) $(FLAGS) Jeu.cpp

Sorcieres.o: Sorcieres.cpp
	$(CC) $(FLAGS) Sorcieres.cpp

Chateau.o: Chateau.cpp
	$(CC) $(FLAGS) Chateau.cpp

Moines.o: Moines.cpp
	$(CC) $(FLAGS) Moines.cpp

Objet.o: Objet.cpp
	$(CC) $(FLAGS) Objet.cpp

Personnage.o: Personnage.cpp
	$(CC) $(FLAGS) Personnage.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

test : all
	./main.out

clean:
	rm -f $(OBJS) $(OUT)