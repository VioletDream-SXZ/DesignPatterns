BEHAVIOR = BehaviorPattern
TOOL = Tool

INCLUDEFILE = -I BehaviorPattern
ALLFILE = Responsibility.o Command.o Interpreter.o MomoeyTool.o \
		  Observer.o  Mediator.o Iterator.o             \
		  main.o

main:$(ALLFILE)
	g++ -o main $(ALLFILE) $(INCLUDEFILE)
main.o:
	g++ -c main.c -o main.o
Command.o:$(BEHAVIOR)/Command.h
	g++ -c $(BEHAVIOR)/Command.cc -o Command.o
Responsibility.o:$(BEHAVIOR)/Responsibility.h
	g++ -c $(BEHAVIOR)/Responsibility.cc -o Responsibility.o
Interpreter.o:
	g++ -c $(BEHAVIOR)/Interpreter.cc -o Interpreter.o
Mediator.o:
	g++ -c $(BEHAVIOR)/Mediator.cc -o Mediator.o
Observer.o:
	g++ -c $(BEHAVIOR)/Observer.cc -o Observer.o
Iterator.o:
	g++ -c $(BEHAVIOR)/Iterator.cc -o Iterator.o

MomoeyTool.o:
	g++ -c $(TOOL)/memoryTool.cc -o MomoeyTool.o

clean:
	rm -rf *.o
