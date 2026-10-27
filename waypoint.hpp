#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>



namespace wp {
    inline void read(std::istream& is, std::vector<std::string>& vec) {
        std::string buf;

        while (std::getline(is, buf)) {
            vec.push_back(std::move(buf));
        }
    }

    inline std::vector<std::string> read_return(std::istream& is) {
        std::vector<std::string> vec;

        read(is, vec);

        return vec;
    }

    inline void read_filename(const std::string& filename, std::vector<std::string>& vec) {
        std::ifstream is(filename);

        if (!is) {
            throw std::runtime_error(std::string("error opening file: ") + filename);
        }

        read(is, vec);
    }

    inline std::vector<std::string> read_return_filename(const std::string& filename) {
        std::vector<std::string> vec;
        std::ifstream is(filename);

        if (!is) {
            throw std::runtime_error(std::string("error opening file: ") + filename);
        }

        read(is, vec);

        return vec;
    }


    inline void write(std::ostream& os, const std::vector<std::string>& vec) {
        for (const auto& str : vec) {
            os << str << '\n';
        }
    }

    inline void write_filename(const std::string& filename, const std::vector<std::string>& vec) {
        std::ofstream os(filename);

        if (!os) {
            throw std::runtime_error(std::string("error opening file: ") + filename);
        }

        write(os, vec);
    }
}