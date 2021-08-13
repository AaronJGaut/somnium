.PHONY: all
all: | build
	cd build && cmake ..
	$(MAKE) -C build

.PHONY: clean
clean:
	rm -rf build

.PHONY: test
test:
	rl runtests test/cases

build:
	mkdir -p build
