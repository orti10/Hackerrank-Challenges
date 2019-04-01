//Attribute Parser


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
using namespace std;



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
  int n,q;
    cin>>n>>q;
    cin.ignore();

    map<string,string> db;
    string inputstr, index="", buff;
    string tag,attribute,value;
    size_t position,npos;

    //proc n/database
    for(int i = n; i>0; i--){
        getline(cin,inputstr);
        stringstream ss(inputstr);

        while(ss>>buff){
            //cout<<buff<<endl;//testing

            //closing </tag1>
            if(buff[1] == '/'){
                position = buff.find('>');
                //cout<<position<<endl;//testing
                tag = buff.substr(2,position-2);
                //cout<<index<<endl;//testing
                if(index == tag){
                    index = "";
                }else{
                    position = index.find(tag);
                    index = index.substr(0,position-1);
                }
                
                //cout<<position<<endl<<index<<endl;//testing
            }
            //tag name <tag1... ...>
            else if(buff[0] == '<'){
                if(buff.find('>') == npos){
                    tag = buff.substr(1); //extract from pos[1] to end
                }else{
                    position = buff.find_last_of('>');
                    tag = buff.substr(1,position-1);
                }
                
                //cout<<tag<<endl;//testing
                index = (index.empty())? tag : (index+'.'+tag);//if not first tag +'.'
                //cout<<index<<endl;//testing
            }
            //value <... = "value">
            else if(buff[0] == '"'){
                //last valve <... ... "value">
                position = buff.find_last_of('"');
                value = buff.substr(1,position-1);
                //store in database / mapping
                db[index+'~'+attribute] = value;
                //cout<<index<<'~'<<attribute<<"="<<value<<endl;//testing
            }
            //attribute <>
            else if(buff != "="){
                attribute = buff;
                //index = index+'~'+attribute;//tag1~attr formatting
            }

        }


    }

    //process queries
    for (int i = q; i>0; i--){
        getline(cin,inputstr);
        if(db.find(inputstr) == db.end()){
            cout<<"Not Found!"<<endl;
        }
        else{
            cout<<db[inputstr]<<endl;
        }
    }
    return 0;
}
