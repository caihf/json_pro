#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

void readJsonFile(const char* pFileName)
{
    Json::Reader reader;
    Json::Value root;

    ifstream in(pFileName);

    assert(in.is_open());

    if (reader.parse(in, root)) {
        string name = root["name"].asString();
        int age = root["age"].asInt();
        cout<<"Name: "<<name<<", age: "<<age<<endl;

        // subparter
        string partner_name = root["partner"]["partner_name"].asString();
        int partner_age = root["partner"]["partner_age"].asInt();

        cout<<"PartnerName: "<<partner_name<<", PartnerAge: "<<partner_age<<endl;

        // read array
        for (unsigned int i = 0; i < root["achievement"].size(); ++i) {
            string ach = root["achievement"][i].asString();
            cout<<ach<<"\t";
        }
        cout<<endl;
    }
    
}

int main()
{
    readJsonFile("./tj.json");

    return 0;
}
