#ifndef __WINSOCK2__OS_H__
#define __WINSOCK2__OS_H__

#include <stdexcept>

#include <ws2tcpip.h>

#include <crosssock/Config.hpp>

namespace crs
{

    class CROSSSOCK_DLL OS
    {
    public:
        static sockaddr_in create_sockaddr(const in_addr &addr, uint16_t port);
        static void close(SOCKET s);

    private:
        OS() {}

        class _WinSockInitializer
        {
        public:
            _WinSockInitializer();
            ~_WinSockInitializer();
        };

        static _WinSockInitializer WinSockInitializer;
    };
} // namespace crs

#endif // __WINSOCK2__OS_H__