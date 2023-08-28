#include "MutantStack.hpp"
#include <list>
#include <vector>

int main()
{
{
MutantStack<int> mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
std::cout << "\n\nhere\n";
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
MutantStack<int> t(mstack);
// return 0;
// t = mstack;
it = t.begin();
ite = t.end();

std::cout << "\n\nhere\n";

while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
}
std::cout << "\n\n List:\n";
{
std::list<int> mstack;
mstack.push_front(5);
mstack.push_front(17);
std::cout << mstack.front() << std::endl;
mstack.pop_front();
std::cout << mstack.size() << std::endl;
mstack.push_front(3);
mstack.push_front(5);
mstack.push_front(737);
//[...]
mstack.push_front(0);
std::list<int>::iterator it = mstack.begin();
std::list<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::list<int> s(mstack);
}

std::cout << "\n\n vector:\n";
{
std::vector<int> mstack;
mstack.insert(mstack.begin(), 5);
mstack.insert(mstack.begin(), 17);
std::cout << mstack.front() << std::endl;
mstack.erase(mstack.begin());
std::cout << mstack.size() << std::endl;
mstack.insert(mstack.begin(), 3);
mstack.insert(mstack.begin(), 5);
mstack.insert(mstack.begin(), 737);
//[...]
mstack.insert(mstack.begin(), 0);
std::vector<int>::iterator it = mstack.begin();
std::vector<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::vector<int> s(mstack);
}

}