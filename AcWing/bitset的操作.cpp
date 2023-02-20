#include <iostream>
#include <bitset>

using namespace std;

const int N = 10;

int main(void)
{
    bitset<N> b("ab");

    cout << b[0] << " " << b[1] << endl;
    return 0;
}
/**
 * @brief bitset的定义和初始化


bitset<n> b;
b有n位，每位都为0

bitset<n> b(u);
b是unsigned long型u的一个副本

bitset<n> b(s);
b是string对象s中含有的位串的副本

bitset<n> b(s, pos, n);
b是s中从位置pos开始的n个位的副本


bitset的操作

b.any()
b中是否存在置为1的二进制位？

b.none()
b中不存在置为1的二进制位吗？

b.count()
b中置为1的二进制位的个数

b.size()
b中二进制位的个数

b[pos]
访问b中在pos处的二进制位

b.test(pos)
b中在pos处的二进制位是否为1？

b.set()
把b中所有二进制位都置为1

b.set(pos)
把b中在pos处的二进制位置为1

b.reset()
把b中所有二进制位都置为0

b.reset(pos)
把b中在pos处的二进制位置为0

b.flip()
把b中所有二进制位逐位取反

b.flip(pos)
把b中在pos处的二进制位取反

b.to_ulong()
用b中同样的二进制位返回一个unsigned long值

os << b
把b中的位集输出到os流
————————————————
版权声明：本文为CSDN博主「虚坏叔叔」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/biggbang/article/details/8660817
 *
 */