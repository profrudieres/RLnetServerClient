#ifndef __RLNET__
#define __RLNET__

#include <WebServer.h>

using string = const char*;
struct Args
{
    String args[10];
    String names[10];
    byte index;
    String GetName(const char* compareStr);
    String GetArg(const char* compareStr);
};

class RLnet : public WebServer{
    private:
    using fn = void();
    using fnArgs = void(Args *req, RLnet *res);
    public:
    void Connect(string ssid, string pass);
    void send(int codeHTTP, string typeHtml, string msg);
    void send(int codeHTTP, string msg);
    void send(string msg);
    void sendError(string msg);
    void get(string router, fnArgs f);
    void post(string router, fnArgs f);
    void listen(int port);
    void listen(int port, fn f);
};

#endif //__RLNET__