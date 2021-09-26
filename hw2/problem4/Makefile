# all:cache_test_write1 cache_test_read1_write1 cache_test_read2_write1
# cache_test_write1:cache_test_write1.c
# 	gcc -O3 -g -o cache_test_write1 cache_test_write1.c

# cache_test_read1_write1:cache_test_read1_write1.c
# 	gcc -O3 -g -o cache_test_read1_write1 cache_test_read1_write1.c

# cache_test_read2_write1:cache_test_read2_write1.c
# 	gcc -O3 -g -o cache_test_read2_write1 cache_test_read2_write1.c
SOURCE = $(wildcard *.cpp)
TARGETS = $(patsubst %.cpp, %, $(SOURCE))

CC = g++
CFLAGS = -g -O3

all:$(TARGETS)

$(TARGETS):%:%.cpp
	$(CC) $(CFLAGS) -o $@ $^
.PHONY:clean all
clean:
	-rm -rf $(TARGETS)