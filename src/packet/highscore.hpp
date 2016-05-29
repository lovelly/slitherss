#ifndef SLITHER_PACKET_HIGHSCORE_HPP
#define SLITHER_PACKET_HIGHSCORE_HPP

#include "base.hpp"
#include "game/snake.hpp"

#include <memory>

struct packet_highscore : public packet_base {
    packet_highscore() : packet_base(packet_t_highscore) {}

    // 3-5	int24	J (for snake length calculation)
    // 6-8	int24	I (for snake length calculation; value / 16777215)
    // 9	int8	The length of the winners name
    // 10-?	string	Winners name
    std::shared_ptr<snake> winner;

    // ?-?	string	Winners message
    std::string message;

    size_t get_size() {
        return 9 + 1 + winner->name.length() + message.length();
    }
};

std::ostream& operator<<(std::ostream & out, const packet_highscore & p) {
    out << static_cast<packet_base>(p);
    out << write_uint24(p.winner->parts.size());
    out << write_fp24(p.winner->fullness);
    out << write_string(p.winner->name);
    // no len for message here
    for (const char c : p.message) {
        out.put(c);
    }
    return out;
}

#endif //SLITHER_PACKET_HIGHSCORE_HPP
