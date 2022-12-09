#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::cout << "Input string \n";
    
    std::stack <char> st;
    
    std::string s;
    
    std::getline(std::cin , s); 
    
    for (int i = 0 ; i < s.length(); i ++)
    {
        if (s[i] == 40 || s[i] == 91 || s[i] == 123)
        {
            st.push(s[i]);
        }
        else
        {
            if (s[i] == 41 || s[i] == 93 || s[i] == 125)
            {
                if (st.empty())
                {
                    std::cout << "False";
                    return 0;
                }
                else
                {
                    if ((s[i] == 41 && st.top() == 40) || (s[i] == 93 && st.top() == 91) || (s[i] == 125 && st.top() == 123))
                    {
                        st.pop();
                    }
                    else
                    {
                        std::cout << "False";
                        return 0;
                    }
                }
            }
        }
    }
    std::cout << "True";
}