#include <iostream>

int main(int argc, char const* argv[])
{
    while(argc--)
        std::cout << argv[argc] << std::endl;
    return 0;
}
