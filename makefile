BEHAVIOR = BehaviorPattern
TOOL = Tool

ALLFILE = Responsibility.o Command.o Interpreter.o MomoeyTool.o \
		  Observer.o                                    \
		  main.o

main:$(ALLFILE)
	g++ -o main $(ALLFILE)
main.o:
	g++ -c main.c -o main.o

Command.o:$(BEHAVIOR)/Command.h
	g++ -c $(BEHAVIOR)/Command.cc -o Command.o
Responsibility.o:$(BEHAVIOR)/Responsibility.h
	g++ -c $(BEHAVIOR)/Responsibility.cc -o Responsibility.o
Interpreter.o:
	g++ -c $(BEHAVIOR)/Interpreter.cc -o Interpreter.o
Observer.o:
	g++ -c $(BEHAVIOR)/Observer.cc -o Observer.o

MomoeyTool.o:
	g++ -c $(TOOL)/memoryTool.cc -o MomoeyTool.o

clean:
	rm -rf *.o
