/**
 *      @ File   : key_logger.cc
 *      @ Desc   : analyze input string and extract password.
 *                 assume that '<' is left arrow key, '>' is right arrow key, '-' is backspace.
 *      @ Author : Caelum
 *      @ Date   : 2018.01.25
 **/

#include<iostream>
#include<string>
#include<list>

#ifdef _TEST
void extract_password(std::string input);
#else
void extract_password(std::string &input);
#endif

int
main(void)
{
#ifdef _TEST
    std::cout << "First Test  : \"<<BP<A>>Cd-\"" << std::endl;
    extract_password(std::string("<<BP<A>>Cd-"));
    std::cout << std::endl;
    std::cout << "Second Test : \"ThIsIsS3Cr3t\"" << std::endl;
    extract_password(std::string("ThIsIsS3Cr3t"));
    std::cout << std::endl;
    std::cout << "Third Test  : \"-\"" << std::endl;
    extract_password(std::string("-"));
#else
    int trial = -1;
    std::string input_str;
    std::cin >> trial;
    for (int i=0; i<trial; ++i) {
        std::cin >> input_str;
        extract_password(input_str);
      }
#endif

}

#ifdef _TEST
void
extract_password(std::string input) 
#else
void
extract_password(std::string &input) 
#endif
{

        std::list<char> password;
        std::string password_str;
        std::list<char>::iterator iter=password.begin();
        std::list<char>::iterator tmp_iter;
    
        for (char &c : input) {
            switch(c) {
                case '-' : 
                    if(iter == password.begin())
                        break;
                    tmp_iter = iter;
                    tmp_iter--;
                    password.erase(tmp_iter);
                    break;
                case '<' :
                    if(iter != password.begin())
                        --iter;
                    break;
                case '>' :
                    if(iter != password.end())
                        ++iter;
                    break;
                default :
                    password.insert(iter, c);
                    break;
            }
        }

        for (iter=password.begin(); iter != password.end(); ++iter) 
            password_str.push_back(*iter);
        std::cout << password_str << std::endl;
}
