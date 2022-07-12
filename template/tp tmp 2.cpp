#include <iostream>

template<typename itemType>
itemType getMinor(itemType lhItem, itemType rhItem)
{
    return ( lhItem < rhItem? lhItem : rhItem );
}
// function overload with diferents types...
template<typename ItemType, typename ItemTypeQ>
ItemType getMinor(ItemType lhItem, ItemTypeQ rhItem)
{
    return ( lhItem < rhItem ? lhItem : rhItem );
}

int main()
{
    std::cout << getMinor<int>(3, 5) << std::endl;
    std::cout << getMinor<float>(3.2f, 6.5f) << std::endl;
    std::cout << getMinor<double>(4.3, 2.3) << std::endl;
    std::cout << getMinor<char>('a', 'b') << std::endl;

    // Prueba con distintos tipos..

    std::cout << "prueba con distintos tipos: " 
              << getMinor<int, char>(3, 's') << std::endl;

    return 0;
}