#include <iostream>
using namespace std;
class string_functions{
    private:
    string chr;
    public:
        string_functions(){
            chr="sample string";
        }
        string_functions(string str_input){
            chr=str_input;
        }f
        string_functions operator + (string_functions sf){
            return string_functions(chr+sf.chr);
        }
        string_functions operator = (string_functions sf){
            chr=sf.chr;
            return *this;
        }
        string_functions operator <= (string_functions sf){
            if(chr.length()<=sf.chr.length()){
                cout<<chr<<"is smaller"<<endl;
                return *this;
            }
            else{
                return sf;
            }
        }
        int string_length(){
            return chr.length();
        }
        string_functions lowercase(){
            for(int i=0;i<chr.length();i++){
                if(chr[i]>='A' && chr[i]<='Z'){
                    chr[i]=chr[i]+32;
                }
            }
            return *this;
        }
};
int main(){
    string_functions sf1("Hello");
    string_functions sf2("World");
    string_functions sf3;
    sf3=sf1+sf2;
    cout<<"Concatenated string: "<<sf3.string_length()<<endl;
    sf3.lowercase();
    cout<<"Lowercase string length: "<<sf3.string_length()<<endl;
    sf1<=sf2;
    return 0;
}