BEHAVIOR = BehaviorPattern

ALLFILE = Responsibility.o Command.o main.o

main:$(ALLFILE)
	g++ -o main $(ALLFILE)
main.o:
	g++ -c main.c -o main.o

Command.o:$(BEHAVIOR)/Command.h
	g++ -c $(BEHAVIOR)/Command.cc -o Command.o
Responsibility.o:$(BEHAVIOR)/Responsibility.h
	g++ -c $(BEHAVIOR)/Responsibility.cc -o Responsibility.o

clean:
	rm -rf *.o
