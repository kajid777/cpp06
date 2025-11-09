# 42風の基本的なMakefile。実行ファイルを生成します。

NAME := convert
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
RM := rm -f

SRCS := main.cpp ScalarConverter.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


