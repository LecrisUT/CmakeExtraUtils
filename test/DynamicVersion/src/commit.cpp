#include <iostream>

#include "commit.h"
#include "version.h"

int main(){
    std::cout << "version: " << version << std::endl;
    std::cout << "commit: " << commit << std::endl;
    std::cout << "describe: " << describe << std::endl;
    return 0;
}