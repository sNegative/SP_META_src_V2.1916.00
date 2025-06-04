#ifndef SPMETA_MISC_ICONN_LISTENER_
#define SPMETA_MISC_ICONN_LISTENER_

namespace SPMETA
{

enum BootMode
{
    META,
    ADVMETA,
};

class IConnectionListener
{
public:
    virtual void OnConnected(BootMode mode) = 0;
    virtual void OnDisconnected(BootMode mode) = 0;
};

}

#endif