#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

#define interface struct
#define implement public


enum class Relationship { parent, child, sibling };

interface IPerson
{
	virtual string getName() = 0;
};
interface IRelationships
{
	virtual void add_parent_and_child(IPerson* person1, Relationship relation, IPerson* person2)   = 0;
	virtual std::vector<tuple<IPerson*, Relationship, IPerson*>> getRelations() = 0;
};
interface IResearch
{
	virtual void searchRelations(IRelationships* relations, string name, Relationship relation) = 0;	
};


class Person : implement IPerson
{
private:
	string name;
public:
	Person(string name) : name(name) {/*end of initialization*/}
	string getName()
	{
		return name;
	}
};
class Relationships : implement IRelationships// Low-level 
{  
private:
    vector<tuple<IPerson*, Relationship, IPerson*>> m_relations;
public:
	Relationships() {/*end of initialization*/}
    void add_parent_and_child(IPerson* person1, Relationship relation, IPerson* person2) 
    {
        m_relations.push_back({person1, relation, person2});
        m_relations.push_back({person2, relation, person1});
    }
    std::vector<tuple<IPerson*, Relationship, IPerson*>> getRelations() { return m_relations; }
};
class Research : implement IResearch // High-level 
{  
private:
	
public:
    Research() {/*end of initialization*/}
    void searchRelations(IRelationships* relations, string name, Relationship relation)
	{
    	for (auto &&[first, rel, second] : relations->getRelations()) // Need C++17 here 
        {
            if (first->getName() == name && rel == relation)
                cout << name << " has a child called: " << second->getName() << endl;
        }
	}
};


int main() 
{
    IPerson* parent = new Person("John");
    IPerson* child1 = new Person("Rogger");
    IPerson* child2 = new Person("Matt");

    IRelationships* relationships = new Relationships;

    relationships->add_parent_and_child(parent, Relationship::parent, child1);
    relationships->add_parent_and_child(parent, Relationship::child, child2);

    IResearch* research = new Research();
    
    research->searchRelations(relationships, "John", Relationship::parent);
    
	delete parent;
    delete child1;
    delete child2;
    delete relationships;
    delete research;

    return 0;
}