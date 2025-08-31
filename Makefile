# Compiler and flags
CC       := gcc
CFLAGS   := -O2 -Wall -Wextra -Werror -pedantic -MMD -MP
LDFLAGS  :=

# Directories
SRC_DIR  := src
OBJ_DIR  := obj
DEP_DIR  := dep

# Find all .c source files recursively
SRCS     := $(shell find $(SRC_DIR) -name '*.c')
OBJS     := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS     := $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRCS))

# Target executable
TARGET   := pmp

# Default build
all: $(TARGET)

# Run target
run: $(TARGET)
	@./$(TARGET)

# Push target (adjust path if needed)
push:
	@cp $(TARGET) ~/../usr/bin/

# Clean target
clean:
	@rm -rf $(OBJ_DIR) $(DEP_DIR)
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)


# Include dependency files
-include $(DEPS)

# Link objects into final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Compile each source into object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@) $(DEP_DIR)/$(dir $*)
	$(CC) $(CFLAGS) -c $< -o $@ -MF $(DEP_DIR)/$*.d

# Phony targets
.PHONY: all run clean push
