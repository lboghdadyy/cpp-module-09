CXX = c++ -Wall -Wextra -Werror --std=c++98
RM=rm -rf
SOURCES = main.cpp 

OBJECTS = $(SOURCES:.cpp=.o)
NAME = RPN
HEADERS = RPN.hpp
all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean