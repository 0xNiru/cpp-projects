CXX = g++
TARGET = todo
SRC = todo.cpp

all: $(TARGET)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

$(TARGET) : $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
