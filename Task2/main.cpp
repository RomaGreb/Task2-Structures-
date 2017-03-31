#include <iostream>
#include"AnyType.h"

using namespace ISXAnyType;

int main()
{
    AnyType var1(true);
    std::cout << var1 << std::endl;
    var1 = false;
    std::cout << var1 << std::endl;
    var1 = 2.47;
    std::cout << var1 << std::endl;
    std::cout << var1.getTypeName() << std::endl;
    var1 = (signed char)'r';
    std::cout << var1 << std::endl;
    std::cout << var1.getTypeName() << std::endl;
    signed char sc = var1.getSignedChar();
    std::cout << sc << std::endl;

    try
    {
        int j = var1.getInt();
    }
    catch(Error& er)
    {
        std::cout << er.what() << std::endl;
    }
    AnyType var2 = 26;
    AnyType::Swap(var2,var1);
    std::cout << var2 << ' ' << var1 << std::endl;

    return 0;
}
