

#include <iostream>
#include <string>

class StackException {
    public:
        StackException(std::string s) : str(s) {}
        ~StackException() {}
        void what() {
            std::cout << str << std::endl;
        }

    private:
        std::string str;
};
