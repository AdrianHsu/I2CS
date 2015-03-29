target = base8 base8_basic
CPPFLAGS = -O2 -std=c++11 -Wall

all: $(target)

base8_basic: base8_basic.cpp
	g++ $(CPPFLAGS) base8_basic.cpp -o $@
base8_bonus: base8.cpp
	g++ $(CPPFLAGS) base8.cpp -o $@

clean:
	rm -rf $(target)

run_basic:
	./base8_basic
run_bonus:
	./base8