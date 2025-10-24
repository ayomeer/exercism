#include <string>

namespace log_line {

std::string message(std::string line) {
    // return the message (the part after '[INFO]:', '[WARNING]:', '[ERROR]:')
    size_t idx_message_start = line.find("]: ") + 3; // +3 for moving at end of found string
    return line.substr(idx_message_start, line.size());
}

std::string log_level(std::string line) {
    // return the log level
    size_t idx_level_start = line.find("[")+1;
    size_t idx_level_end = line.find("]: ")-1;
    
    return line.substr(idx_level_start, idx_level_end);
}

std::string reformat(std::string line) {
    // return the reformatted message
    std::string reformatted = message(line) + " (" + log_level(line) + ")";
    return reformatted;
}

}  // namespace log_line
