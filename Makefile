CC = g++
CFLAGS =
COPTFLAGS = -O3 -g
LDFLAGS =

default:
	@echo "=================================================="
	@echo "To build your sorting code, use:"
	@echo "  make queue_test           # For Queue"
	@echo "  make dlist_test  # For Doubly linked list"
	@echo ""
	@echo "To clean this subdirectory (remove object files"
	@echo "and other junk), use:"
	@echo "  make clean"
	@echo "=================================================="

# Queue testing driver 
queue_test: queue_test.o queue.o
	$(CC) $(COPTFLAGS) -o $@ $^

# Doubly linked list driver
dlist_test: dlist_test.o dlist.o
	$(CC) $(COPTFLAGS) -o $@ $^

%.o: %.cc
	$(CC) $(CFLAGS) $(COPTFLAGS) -o $@ -c $<

clean:
	rm -f core *.o *~ queue_test dlist_test

# eof