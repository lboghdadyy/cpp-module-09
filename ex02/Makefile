CXX = c++ -Wall -Wextra -Werror -std=c++98
RM=rm -rf
SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = PmergeMe.hpp
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(NAME)

%.o: %.cpp .hpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean