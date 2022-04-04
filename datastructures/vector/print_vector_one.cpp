#include<iostream>
#include<vector>

void print(std::vector <int> const &a) {
   std::cout << "The vector elements are : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}

int main() {
   std::vector<int> a = {2,4,3,5,6};
   print(a);
   return 0;
}