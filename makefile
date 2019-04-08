BEHAVIOR = BehaviorPattern
TOOL = Tool

INCLUDEFILE = -I BehaviorPattern
ALLFILE = Responsibility.o Command.o Interpreter.o MomoeyTool.o  \
	  Observer.o  Mediator.o Iterator.o Visitor.o Strategy.o \
	  main.o

main:$(ALLFILE)
	g++ -o main $(ALLFILE) $(INCLUDEFILE)
main.o:
	g++ -c main.c -o main.o
## 命令模式
Command.o:$(BEHAVIOR)/Command.h
	g++ -c $(BEHAVIOR)/Command.cc -o Command.o
## 职责链模式
Responsibility.o:$(BEHAVIOR)/Responsibility.h
	g++ -c $(BEHAVIOR)/Responsibility.cc -o Responsibility.o
## 解释器模式
Interpreter.o:
	g++ -c $(BEHAVIOR)/Interpreter.cc -o Interpreter.o
## 中介者模式
Mediator.o:
	g++ -c $(BEHAVIOR)/Mediator.cc -o Mediator.o
## 观察者模式
Observer.o:
	g++ -c $(BEHAVIOR)/Observer.cc -o Observer.o
## 迭代器模式
Iterator.o:
	g++ -c $(BEHAVIOR)/Iterator.cc -o Iterator.o
## 访问者模式
Visitor.o:
	g++ -c $(BEHAVIOR)/Visitor.cc -o Visitor.o
## 策略模式
Strategy.o:
	g++ -c $(BEHAVIOR)/Strategy.cc -o Strategy.o

## 内存分配相关模块
MomoeyTool.o:
	g++ -c $(TOOL)/memoryTool.cc -o MomoeyTool.o

clean:
	rm -rf *.o
