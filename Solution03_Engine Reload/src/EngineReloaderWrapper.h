#ifndef _ENGINE_RELOADER_WRAPPER_H__
#define _ENGINE_RELOADER_WRAPPER_H__

#include "EngineReloader.h"

class EngineReloaderWrapper : public EngineReloader
{
public:
    EngineReloaderWrapper();
    ~EngineReloaderWrapper();
private:
    virtual void setContextProperies( QQmlContext * pQmlContext );
    virtual void registerToQml();
    void Clear();
};


#endif//_ENGINE_RELOADER_WRAPPER_H__
