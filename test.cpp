#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    ifstream in;
    in.open("lineitem.tbl");
    ofstream out;
    out.open("lineitem1.tbl");
    if (in.is_open()) {
        while (getline(in, s)) {
            int len = s.length();
            int i = len-1;
            //将最后一个竖号去掉才能满足postgresql的数据读取
            if (s[i] == '|') 
                s[i] = '\n';
            out << s;
        }
    }
    out.close();
    return 0;
}
