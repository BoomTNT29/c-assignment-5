CC=g++
OBJS=main.o functions.o zoo-species.o input-prog.o

main: $(OBJS)
	$(CC) $(OBJS) -o main

%.o: %.cpp
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS) main