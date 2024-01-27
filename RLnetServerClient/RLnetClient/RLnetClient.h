#ifndef __RLNETCLIENT__H__
#define __RLNETCLIENT__H__

#include <HTTPClient.h>

class RLnetClient: public HTTPClient{
    private:
    String url;
    using fn = void(String res);
    public:
    void Connect(const char* ssid, const char* pass, const char* urlP);
    void stateWiFi();
    void get(String router, String query, fn f);
    void post(String router, String query, fn f);
};

#endif //__RLNETCLIENT__H__