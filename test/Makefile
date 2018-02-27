test : test.o fsm.o
	gcc -Wall test.o fsm.o -o test
#编译(不链接).c生成.o文件，通过-DDEBUG开启DEBUG编译选项
fsm.o : ../src/fsm.c ../src/fsm.h
	gcc -Wall -DDEBUG -c ../src/fsm.c -o fsm.o
test.o : test.c
	gcc -Wall -c test.c -o test.o
#删除.o文件
.PHONY : clean
clean:
	rm -f *.o
