#include <iostream>
#include <list>

template <typename itemType, typename itemTypeQ>    // 1.a
itemType getItemByType(itemTypeQ item)
{
    return ((itemType)item);
}

template <typename T>   // 1.b
class CollOfitems
{
private:
    std::list<T> items;
public:
    CollOfitems() {}
    void addItem(T item) {
        items.push_back(item);
    }
    void showItems() {
        for (auto &&i : items)
            std::cout << i << std::endl;        
    }
};

template <typename T, typename M> // 1.c
class ActC
{
private:
    T rawData;

public:
    ActC(T rawData) : rawData(rawData) {/* end of initialization*/}
    M getSomething() {
        return ("OPERARI SEQUITUR ESSE");
    }
};


int main()
{
    std::cout << getItemByType<int, float>(3.0f) << std::endl;    // 1.a

    std::cout << std::endl;

    CollOfitems<char> coll; // 1.b
    coll.addItem('a');
    coll.addItem('b');
    coll.showItems();   // 1.b

    std::cout << std::endl;
    
    ActC<int, std::string> actC(10); // 1.c
    std::cout << actC.getSomething(); //1.c

    return 0;
}