CC=gcc
CFLAGS=-I./include
DEPS = include/resume.h include/utils.h
OBJ = src/main.c src/resume.c src/utils.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

resume_analyzer: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f resume_analyzer
