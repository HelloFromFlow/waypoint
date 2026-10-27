# waypoint

an absurdly simple file io utility for C++

coding examples:

reading from file by path:
```
#include "waypoint.hpp"
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
```
#include "waypoint.hpp"

int main() {
  std::ofstream file("a.txt");

  std::vector<std::string> lines = {"Hello", "World!"};

  wp::write(file, lines);

  file.close();

  return 0;
}
```
