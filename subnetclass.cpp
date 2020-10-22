//class for subnet
#include <string>

using namespace std;

class SubnetCalc {

    string start_addr = "0.0.0.0";
    string end_addr = "0.0.0.0";
    int sz_mask = 0;
    string mask = "";
    string bmask = "1";

    string enter(string);
    void buildMask(void);
    void buildBMask(void);
    void buildEnd_addr(void);

    public:
        string fastMaskByAddr(string);
        string getbmask(){ return bmask;}
        string maskByCount(string);


};

string SubnetCalc::maskByCount(string count){
    int ones = 1;
    for( int i = 2; i< stoi(count);i = i*2){
        ones++;
    }
    string res = "";
    for(int i = 0; i < ones; i++){
        res.append("1");
    }
    
    sz_mask = 32 - res.length();
    buildBMask();
    buildMask();

    return mask;
}

string SubnetCalc::fastMaskByAddr(string addr){

    size_t loc = addr.find("/") + 1;
    string sub = addr.substr(loc, addr.length());

    sz_mask = stoi(sub);
    buildBMask();
    buildMask();

    return mask;
}

void SubnetCalc::buildBMask(void){
    string builder = "";
    for(int i = 0; i < 32; i++){
        if (i < sz_mask){
            builder.append("1");
        }else{
            builder.append("0");
        }
    }
    bmask = builder;
    
    return;
}

void SubnetCalc::buildMask(void){
    mask = to_string(stoi(bmask.substr(0,8),nullptr,2));
    mask.append(".");
    mask.append(to_string(stoi(bmask.substr(8,8),nullptr,2)));
    mask.append(".");
    mask.append(to_string(stoi(bmask.substr(16,8),nullptr,2)));
    mask.append(".");
    mask.append(to_string(stoi(bmask.substr(24,8),nullptr,2)));
    return;
}