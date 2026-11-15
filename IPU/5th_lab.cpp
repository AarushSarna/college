#include <iostream>
using namespace std;
class memory;
class CPU
{
private:
    int CPU_utilization;

public:
    CPU()
    {
        CPU_utilization = 0;
    }
    CPU(int num)
    {
        CPU_utilization = num;
    }
    friend void utility_check(const CPU &c, const memory &m);
};

class memory
{
private:
    int memory_utilization;

public:
    memory()
    {
        memory_utilization = 0;
    }
    memory(int num)
    {
        memory_utilization = num;
    }
    friend void utility_check(const CPU &c, const memory &m);
};

void utility_check(const CPU &c, const memory &m)
{
    if (c.CPU_utilization > m.memory_utilization)
    {
        cout << "CPU has higher utilization." << endl;
    }
    else if (c.CPU_utilization < m.memory_utilization)
    {
        cout << "Memory has higher utilization." << endl;
    }
    else
    {
        cout << "Both Are Equal." << endl;
    }
};
int main()
{
    int cpu_uti;
    int mem_uti;
    cout << "Enter value of CPU--> ";
    cin >> cpu_uti;
    cout << "Enter value of memory--> ";
    cin >> mem_uti;
    CPU cp(cpu_uti);
    memory me(mem_uti);
    utility_check(cp, me);
    return 0;
}