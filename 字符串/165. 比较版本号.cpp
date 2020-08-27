//使用istringstream
class Solution {
public:
    int compareVersion(const string &version1, const string &version2) {
        istringstream v1(version1 + ".");
        istringstream v2(version2 + ".");
        int d1 = 0;
        int d2 = 0;
        char dot = '.';
        while (v1.good() || v2.good()) {
            if (v1.good()) v1 >> d1 >> dot;
            if (v2.good()) v2 >> d2 >> dot;
            if (d1 > d2) return 1;
            else if (d1 < d2) return -1;
            d1 = d2 = 0;
        }
        return 0;
    }
};

//istringstream 应用示例
// C++ program to illustrate std::istringstream 
// to tokenize the string 
#include <iostream> 
#include <sstream> 
#include <string> 
using std::istringstream; 
using std::string; 
using std::cout; 
  
// Driver Code 
int main() 
{ 
    // Input string 
    string str("abc, def,   ghi"); 
  
    // Object class of istringstream 
    istringstream my_stream(str); 
  
    // To store the stream string 
    string token; 
  
    size_t pos = -1; 
  
    // Traverse till stream is valid 
    while (my_stream >> token) { 
  
        // If ',' is found then tokenize 
        // the string token 
        while ((pos = token.rfind(',')) 
               != std::string::npos) { 
            token.erase(pos, 1); 
        } 
  
        // Print the tokenize string 
        cout << token << '\n'; 
    } 
} 


//双指针
