#include <iostream>
#include <cassert>

#define interface struct
#define implement public

interface IShape
{
    virtual uint32_t area() = 0;
    virtual uint32_t getWidth() = 0;
};

class Rectangle : implement IShape
{
public:
    Rectangle(uint32_t width, uint32_t height) 
        : m_width(width), m_height(height) {/*end of initialization*/}
    uint32_t area () { return m_width * m_height; }
    uint32_t getWidth() { return m_width; }
private:
    uint32_t m_width, m_height;
};

class Square: implement IShape
{
public:
    Square(uint32_t side) : m_side(side) {}
    uint32_t area() { return m_side * m_side; }
private:
    uint32_t getWidth() { return m_side; }
    uint32_t m_side;
};
void process(IShape* shape, uint32_t condicional) 
{
    assert(shape->area() == condicional); // Fails for Square &lt;--------------------
}
    
int main() {

    IShape* r = new Rectangle(10, 10);
    uint32_t rectangleCondition = (r->getWidth() * 10);
    process(r, rectangleCondition);

    IShape* s = new Square(5);
    uint32_t squareCondition = (s->getWidth() * 10);
    process(s, squareCondition);

    delete r;
    delete s;
    return EXIT_SUCCESS;
}