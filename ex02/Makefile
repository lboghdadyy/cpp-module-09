CXX = c++ -Wall -Wextra -Werror -fsanitize=address -g3
RM=rm -rf
SOURCES = main.cpp Pmergeme.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Pmergeme.hpp
NAME = PmergeMe


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