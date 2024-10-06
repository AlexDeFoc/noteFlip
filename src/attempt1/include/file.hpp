#pragma once

#include <string>
#include <vector>
#include <fstream>

class File {
private:
    std::string m_filepath;
    std::ifstream m_stream;

public:
    void open();

    void load(std::vector<std::string>& lines_list);

    void changePath(const std::string& filepath);

    void close();
};
