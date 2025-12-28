EXEC := day2

BUILD_DIR := build
SRC_DIR := src

SRCS := main.cpp

OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

LDFLAGS := 

INC_DIRS := include

.PHONY: build
build: $(BUILD_DIR)/$(EXEC)

.PHONY: debug
debug:
	echo $(OBJS)

.PHONY: run
run: build
	$(BUILD_DIR)/$(EXEC) input.txt

.PHONY: test
test: build
	$(BUILD_DIR)/$(EXEC) test.txt

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

.PHONY: debug
debug:

# Link
$(BUILD_DIR)/$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(BUILD_DIR)/$(EXEC) $(LDFLAGS)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p build
	$(CXX) $(CPPFLAGS) -c $< -o $@

