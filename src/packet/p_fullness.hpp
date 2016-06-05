#ifndef SLITHER_PACKET_FULLNESS_HPP
#define SLITHER_PACKET_FULLNESS_HPP

#include "p_base.hpp"

struct packet_fullness : public packet_base {
    packet_fullness() : packet_base(packet_t_set_fullness) {}

    uint16_t snakeId = 0; // 3-4, int16, Snake id
    uint8_t fullness = 0; // 5-7, int24, value / 16777215 -> fam

    constexpr size_t get_size() const noexcept { return 8; }
};

std::ostream& operator<<(std::ostream & out, const packet_fullness & p);

#endif //SLITHER_PACKET_FULLNESS_HPP
