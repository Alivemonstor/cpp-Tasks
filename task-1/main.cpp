#include <iostream>


int main(int argc, char* argv[])
{
	// outputting a boat using raw string literals
	
	std::cout << R"(
                   |
                  /|\
                 / | \  a boat
                /  |  \
               / - | - \
              /    |    \
             /-----|-----\
        |----\     |     /----|
          \------------------/
             \-----------/
    /\  /\  /\  /\  /\  /\  /\  /\  /\
   /  \/  \/  \/  \/  \/  \/  \/  \/  \
)";
    return 0;
}

