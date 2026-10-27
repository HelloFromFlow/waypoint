# waypoint

an absurdly simple file io utility for C++

coding examples:

reading from file by path:
```cpp
#include "waypoint.hpp"
#include <vector>
#include <iostream>

int main() {
  std::vector<std::string> lines;

  wp::read_filename("a.txt", lines);

  for (const auto& line : lines) {
    std::cout << line << '\n';
  }

  return 0;
}
```
writing to file via ofstream object:
```cpp
#include "waypoint.hpp"
#include <fstream>
#include <vector>

int main() {
  std::ofstream file("a.txt");

  std::vector<std::string> lines = {"Hello", "World!"};

  wp::write(file, lines);

  file.close();

  return 0;
}
```
