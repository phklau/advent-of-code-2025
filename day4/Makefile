EXEC := day4

BUILD_DIR := build
SRC_DIR := src

SRCS := main.cpp

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

LDFLAGS := 
CFLAGS = `pkg-config --cflags opencv4`
LIBS = `pkg-config --libs opencv4`

INC_DIRS := include

.PHONY: build
build: $(BUILD_DIR)/$(EXEC)

.PHONY: run
run: build
	$(BUILD_DIR)/$(EXEC) input.txt

.PHONY: test
test: build
	$(BUILD_DIR)/$(EXEC) test.txt

.PHONY: debug
debug:
	echo $(OBJS)

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

.PHONY: debug
debug:

# Link
$(BUILD_DIR)/$(EXEC): $(OBJS)
	$(CXX) $(OBJS) $(LIBS)-o $(BUILD_DIR)/$(EXEC) $(LDFLAGS)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p build
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

