#include <file.hpp>

void File::open() {
    m_stream.open(m_filepath);
}

void File::load(std::vector<std::string>& lines_list) {
    std::string line;
    while(std::getline(m_stream, line)) {
        lines_list.push_back(line);
    }
}

void File::changePath(const std::string& filepath) {
    m_filepath = filepath;
}

void File::close() {
    m_stream.close();
}
