BUILD_DIR := build

.DEFAULT_GOAL := run
.PHONY: configure compile run clean

configure:
	cmake -B $(BUILD_DIR)

compile: configure
	cmake --build $(BUILD_DIR)

run: configure
	clear
	cmake --build $(BUILD_DIR) --target run

clean:
	rm -rf $(BUILD_DIR) bin