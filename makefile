# Compiler and flags
CXX = g++                   
LDFLAGS =
CXXFLAGS = -I./src  # Include headers from the src directory

# Include the sources.mk file that contains the source files
include sources.mk  # Ensure sources.mk contains SRCS variable

# Define the object directory
OBJDIR = obj

# Define the object files based on the source files
OBJS = $(SRCS:src/%.cpp=$(OBJDIR)/%.o)

# Target executable
TARGET = poker

# Default target
all: $(TARGET)

# Rule to create the target executable from object files
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Rule to compile .cpp files into .o files and place them in the obj directory
$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(OBJDIR)
	@mkdir -p $(OBJDIR)/deck
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove compiled files
clean:
	rm -rf $(OBJDIR) $(TARGET)

# Rule to rebuild everything
rebuild: clean all