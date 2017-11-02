/*************************************************************************
	> File Name: json.cpp
	> Author: 
	> Mail: 
	> Created Time: 2017年11月01日 星期三 17时48分35秒
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>

using namespace std;

int main()
{
    ifstream ifs("json.json");
    Json::Reader reader;
    Json::Value obj;

    reader.parse(ifs, obj);

    const Json::Value &student_info = obj["student_info"];

    for (int i = 0; i < student_info.size(); ++i) {
        for (int j = 0; j < student_info[i].size(); ++j) {
            cout<<student_info[i][j]["ID"].asInt()<<" "
            <<student_info[i][j]["Name"].asString()<<" "
            <<student_info[i][j]["Major"].asString()<<" "<<endl;
        }
        cout<<"================="<<endl;
    }
    return 0;
}

