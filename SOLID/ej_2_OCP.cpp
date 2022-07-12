#include <iostream>
#include <vector>
#include <string>


class Product 
{
    std::string m_name;
    std::string m_color;
    std::string m_size;
public:
    Product(std::string name, std::string color, std::string size)
        : m_name(name), m_color(color), m_size(size) {/*end of initialization*/}
    ~Product() {}

    // Getters...
    std::string getSize()  { return m_size;  }
    std::string getColor() { return m_color; }
    std::string getName()  { return m_name;  }  
};

using Items = std::vector<Product*>;
/* #define ALL(C) begin(c), end(C) */

struct ProductFilter
{
    static Items by_color(Items items, const std::string e_color)
    {
        Items result;
        for (auto &&i : items)
            if (i->getColor() == e_color) result.push_back(i);
        return result;
    }
    static Items by_size(Items items, const std::string e_size)
    {
        Items result;
        for (auto &&i : items)
            if (i->getSize() == e_size) result.push_back(i);
        return result;
    }
    static Items by_size_and_color(Items items, const std::string e_size, const std::string e_color)
    {
        Items result;
        for (auto &&i : items)
            if (i->getSize() == e_size && i->getColor() == e_color) result.push_back(i);
        return result;
    }
};


int main()
{
    const Items allItems
    {
        new Product{"Apple", "Green", "Small"},
        new Product{"Tree", "Green", "Large"},
        new Product{"House", "Blue","Large"},
    };
    
    for (auto &&p : ProductFilter::by_color(allItems, "Green"))
        std::cout << p->getName() << " is green\n";
    
    for (auto &&p : ProductFilter::by_size_and_color(allItems,"Large", "Green"))
        std::cout << p->getName() << " is green & large\n";
    
    return 0;
}