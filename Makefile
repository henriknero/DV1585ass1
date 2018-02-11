parser: lex.yy.c interpreter.tab.o main.cc
	g++ -g -oint interpreter.tab.o lex.yy.c main.cc
interpreter.tab.o: interpreter.tab.cc
	g++ -g -c interpreter.tab.cc
interpreter.tab.cc: interpreter.yy
	bison interpreter.yy
lex.yy.c: interpreter.ll interpreter.tab.cc
	flex interpreter.ll
clean: 
	rm -f interpreter.tab.* lex.yy.c* parser
