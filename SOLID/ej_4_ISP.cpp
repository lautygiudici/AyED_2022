#define interface struct
#define implement public


struct Document;

interface IPrinter {
    virtual void print(Document &doc) = 0;
    virtual void fax(Document &doc) = 0;
};
interface IScanner {
    virtual void scan(Document &doc) = 0;
};

class MultiFunctionPrinter : implement IPrinter, implement IScanner {
public:
    void print(Document &doc) override { }
    void fax(Document &doc)   override { }
    void scan(Document &doc)  override { }
};

class Scanner : implement IScanner {
public:
    void scan(Document &doc) override { /* Do scanning... */}
};
