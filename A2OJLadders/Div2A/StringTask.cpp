#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans="";
    for(auto value:s){
        if((value!='a'&& value!='e' && value!='i'  && value!='o'  && value!='u') && 
        (value!='A'  && value!='E'  && value!='I'  && value!='O'  && value!='U')){
            ans+='.'+string(1,tolower(value));
        }
    }
    cout<<ans<<endl;
    return 0;
}