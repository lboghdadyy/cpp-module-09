CXX = c++ -Wall -Wextra -Werror 
RM=rm -rf
SOURCES = main.cpp
HEADERS = BitcoinExchange.hpp
OBJECTS = $(SOURCES:.cpp=.o)
NAME = btc

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
