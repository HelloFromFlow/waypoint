#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <filesystem>


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

    inline void read_filename(const std::filesystem::path& p, std::vector<std::string>& vec) {
        std::ifstream is(p);

        if (!is) {
            throw std::runtime_error(std::string("error opening file: ") + p.string());
        }

        read(is, vec);
    }

    inline std::vector<std::string> read_return_filename(const std::filesystem::path& p) {
        std::vector<std::string> vec;
        std::ifstream is(p);

        if (!is) {
            throw std::runtime_error(std::string("error opening file: ") + p.string());
        }

        read(is, vec);

        return vec;
    }


    inline void write(std::ostream& os, const std::vector<std::string>& vec) {
        for (const auto& str : vec) {
            os << str << '\n';
        }
    }

    inline void write_filename(const std::filesystem::path& p, const std::vector<std::string>& vec) {
        std::ofstream os(p);

        if (!os) {
            throw std::runtime_error(std::string("error opening file: ") + p.string());
        }

        write(os, vec);
    }
}