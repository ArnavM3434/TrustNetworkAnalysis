# Requires the following project directory structure:
#  /bin
#  /obj
#  /src

# Use 'make remove' to clean up the hole project

# Name of target file
TARGET     = trustNet.exe

CXX        = clang++
#CXXFLAGS   = -std=c++11 \
#             -Weverything -Wall -Wextra -Werror -Wpointer-arith -Wcast-qual \
#             -Wno-missing-braces -Wempty-body -Wno-error=uninitialized \
#             -Wno-error=deprecated-declarations \
#             -pedantic-errors -pedantic \
#             -Os
CXXFLAGS = -g

LD         = clang++ -o
LDFLAGS    = -Wall -pedantic

#SRCDIR     = src
#OBJDIR     = obj
#BINDIR     = bin
SRCDIR = ./
OBJDIR = ./
BINDIOR = ./

SOURCES   := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES  := $(wildcard $(SRCDIR)/*.h)
OBJECTS   := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

RM         = rm -f

$(TARGET) : $(OBJECTS)
	@$(LD) $@ $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"



$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LD) $@ $(LDFLAGS) $(OBJECTS)
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(RM) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(RM) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"