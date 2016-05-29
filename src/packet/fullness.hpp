#ifndef SLITHER_PACKET_FULLNESS_HPP
#define SLITHER_PACKET_FULLNESS_HPP

#include "base.hpp"

struct packet_fullness : public packet_base {
    packet_fullness() : packet_base(packet_t_set_fullness) {}

    uint16_t snakeId = 0; // 3-4, int16, Snake id
    float fullness = 0.0f; // 5-7, int24, value / 16777215 -> fam

    size_t get_size() { return 8; }
};

std::ostream& operator<<(std::ostream & out, const packet_fullness & p) {
    out << static_cast<packet_base>(p);
    out << write_uint16(p.snakeId);
    out << write_fp24(p.fullness);
    return out;
}

#endif //SLITHER_PACKET_FULLNESS_HPP
