#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class Journal 
{
    std::string m_title;
    std::vector<std::string> m_entries;
public:
    explicit Journal(const std::string& title) : m_title(title) {}
    void add_entries(const std::string& entry)
    {
        static uint32_t count = 1;
        m_entries.push_back(std::to_string(count++) + ": " + entry);
    }
    auto get_entries() const { return m_entries; }
};

void save(Journal journal ,const std::string& filename)
{
    std::ofstream ofs(filename);
    for (auto &&s : journal.get_entries())
        ofs << s << std::endl;
    ofs.close();
} 


int main()
{
    Journal journal("Dear XYZ");

    journal.add_entries("I ate a bug");
    journal.add_entries("I cried today");
    save(journal, "diary.txt");

    return 0;
}