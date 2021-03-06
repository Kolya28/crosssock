#ifndef __IPADDRES_H__
#define __IPADDRES_H__

#include <string>
#include <crosssock/OS.hpp>
#include <crosssock/Config.hpp>

namespace crs
{

    class CROSSSOCK_DLL IPAddress
    {
    public:
        static const IPAddress broadcast, any, loopback, none;

        inline bool operator==(const IPAddress &r) const { return memcmp(&addr, &r.addr, sizeof(addr)) == 0; }

        IPAddress(const std::string &str);
        IPAddress(uint32_t address);
        inline bool is_none() const { return *this == none; }
        
        in_addr addr;
    };

} // namespace crs

#endif // __IPADDRES_H__