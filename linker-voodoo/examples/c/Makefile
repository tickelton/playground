DIRS = a o so

all: $(DIRS)
	gcc -Ih/ -fPIC -c -o main/main.o main/main.c
	gcc -c -Ih/ -fPIC -o o/foolib.o src/foolib.c
	ar rcs a/libfoo.a o/foolib.o
	gcc -shared -Ih/ -fPIC -o so/libfoo.so o/foolib.o
	gcc -o main/main_static main/main.o a/libfoo.a
	gcc -o main/main_shared -Lso/ main/main.o -lfoo

$(DIRS):
	[ -e $@ ] || mkdir $@
clean:
	rm -f a/libfoo.a o/foolib.o so/libfoo.so main/main.o main/main_shared main/main_static

