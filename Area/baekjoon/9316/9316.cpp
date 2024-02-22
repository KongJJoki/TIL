#include <iostream>

int main()
{
    int nN{};
    std::cin >> nN;

    for(int i = 0; i < nN; i++)
    {
        std::cout << "Hello World, Judge " << i + 1 << "!" << '\n';
    }
}