#include<iostream>
using namespace std;

#include<fstream>
#include<sstream>
#include<json.h>
using namespace yazi::json;



int main()
{
    //基本类型的数据转换
/*     Json v1;//空值
    Json v2 = true;//bool值
    Json v3 = 123;//int
    Json v4 = 1.23;//double
    Json v5 = "hello world";//string


    bool b = v2;
    int i = v3;
    double  f = v4;
    const string & s = v5;
 */
//数组类型的数据转换
/* Json arr;
arr[0]=true;
arr[1]=123;

arr.append(1.23);
arr.append("hello world");
std::cout<< arr.str()<<std::endl;


bool b = arr[0];
int i=arr[1];
double f=arr[2];
const string & s = arr[3];
 */

//对象类型的api设计
/*     Json obj;
    obj["bool"] = true;
    obj["int"] = 123;
    obj["double"] = 1.23;
    obj["str"] = "hello world";

    std::cout<< obj.str() << std::endl; */

//数组类型
/*         Json arr;
        arr[0] = true;
        arr[1] = 123;
        arr[2] =1.23;
        arr[3] = "hello world"; */

/*     for(auto it = arr.begin(); it !=arr.end(); it++)
    {
        std::cout << (*it).str() << std::endl;
    }
 */

/*     std::cout<< arr.has(0) << std::endl;
    std::cout<< arr.has(4) <<std::endl;
    arr.remove(0);
    std::cout<< arr.str() <<std::endl;
 */


/*         Json arr;
        arr[0] = true;
        arr[1] = 123;
        arr[2] =1.23;
        
    
    Json obj;
    obj["bool"] = true;
    obj["int"] = 123;
    obj["double"] = 1.23;
    obj["arr"] = arr;
 
    std::cout<< obj.str() <<std::endl;
    obj.clear();

 */
/*     const string & str = "{\"a\": 1, \"b\": 2, \"c\": 3}";
    Json v; 
    v.parse(str);

    std::cout << v.str() << std::endl; */

    ifstream fin("./test.json");
    stringstream ss;
    ss << fin.rdbuf();
    const string & str =ss.str();

    
    

    Json v; 
    v.parse(str);

/*     bool isLogin = v["data"]["mid"];
    int current_level = v["data"]["level_info"]["current_level"]; */

    std::cout << v.str() << std::endl;
    
    return 0;


}